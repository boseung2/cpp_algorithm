#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ms;

#define WIDTH 33
#define XMAX (WIDTH - 1)
#define YMIN 1
#define YMAX 5

void gotoxy(int x, int y) {
    // ANSI escape sequence: move cursor to (row, col), 1-based
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}

void hide_cursor(void) {
    // ANSI escape: hide cursor
    printf("\033[?25l");
    fflush(stdout);
}

void show_cursor(void) {
    // ANSI escape: show cursor
    printf("\033[?25h");
    fflush(stdout);
}

// Clear everything except the very top line (row 0)
void clear_except_top(void) {
    // Move cursor to the second line (row 1 in 0-based => row 2 in ANSI 1-based)
    printf("\033[2;1H");
    // Clear from cursor to end of screen
    printf("\033[J");
    fflush(stdout);
}

typedef struct {
    int x;
    int y;
} Point;

static void append_point(Point *route, int *len, int x, int y) {
    if (*len > 0) {
        Point prev = route[*len - 1];
        if (prev.x == x && prev.y == y) return; // avoid consecutive duplicates
    }
    route[*len].x = x;
    route[*len].y = y;
    (*len)++;
}

// Build one lap route (clockwise or counter-clockwise).
// The route starts at (0, YMIN) and returns to it, but we do NOT append the final
// duplicate start point, so stepping wraps naturally.
static int build_clockwise(Point *route) {
    int len = 0;

    // top edge: (0,YMIN) -> (XMAX,YMIN)
    for (int x = 0; x <= XMAX; x++) append_point(route, &len, x, YMIN);

    // right edge: (XMAX,YMIN+1) -> (XMAX,YMAX)
    for (int y = YMIN + 1; y <= YMAX; y++) append_point(route, &len, XMAX, y);

    // bottom edge: (XMAX-1,YMAX) -> (0,YMAX)
    for (int x = XMAX - 1; x >= 0; x--) append_point(route, &len, x, YMAX);

    // left edge: (0,YMAX-1) -> (0,YMIN+1)
    for (int y = YMAX - 1; y >= YMIN + 1; y--) append_point(route, &len, 0, y);

    return len;
}

static int build_counter_clockwise(Point *route) {
    int len = 0;

    // left edge down: (0,YMIN) -> (0,YMAX)
    for (int y = YMIN; y <= YMAX; y++) append_point(route, &len, 0, y);

    // bottom edge right: (1,YMAX) -> (XMAX,YMAX)
    for (int x = 1; x <= XMAX; x++) append_point(route, &len, x, YMAX);

    // right edge up: (XMAX,YMAX-1) -> (XMAX,YMIN)
    for (int y = YMAX - 1; y >= YMIN; y--) append_point(route, &len, XMAX, y);

    // top edge left: (XMAX-1,YMIN) -> (1,YMIN)
    for (int x = XMAX - 1; x >= 1; x--) append_point(route, &len, x, YMIN);

    return len;
}

// Draw `count` stars following the route backwards from headIndex, wrapping across corners.
static void draw_trail(const Point *route, int routeLen, int headIndex, int count) {
    for (int k = 0; k < count; k++) {
        int idx = headIndex - k;
        while (idx < 0) idx += routeLen; // wrap
        idx %= routeLen;

        gotoxy(route[idx].x, route[idx].y);
        putchar('*');
    }
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    printf("Start!! column size: %d, 별표(*)속도(ms) : ", WIDTH);
    
    gotoxy(0, 0);
    printf("start!! column size: %d, 별표(*)속도(ms) : %d", WIDTH, ms);
    fflush(stdout);

    hide_cursor();

    // Build a full cycle route: clockwise lap + counter-clockwise lap
    // Clockwise perimeter length: 2*(WIDTH-1) + 2*(YMAX-YMIN)
    const int perimLen = 2 * (WIDTH - 1) + 2 * (YMAX - YMIN);
    const int routeCap = perimLen * 2;

    Point *route = (Point *)malloc(sizeof(Point) * routeCap);
    if (!route) return 0;

    int cwLen = build_clockwise(route);
    int ccwLen = build_counter_clockwise(route + cwLen);
    int routeLen = cwLen + ccwLen;

    // If something went unexpected, guard
    if (routeLen <= 0) return 0;

    int starCount = 1;
    // The number of UNIQUE drawable cells on the rectangle border is the perimeter length.
    // Once we reach this, there is no new space to fill, so reset.
    const int maxStars = perimLen;

    int headIndex = 0;

    // Arrival-edge detection for the top-left corner (0, YMIN)
    bool wasAtCorner = true; // route starts at corner, so don't increment immediately

    while (1) {
        clear_except_top();

        Point head = route[headIndex];

        bool isAtCorner = (head.x == 0 && head.y == YMIN);
        if (isAtCorner && !wasAtCorner) {
            starCount++;
            if (starCount > maxStars) starCount = 1;
        }
        wasAtCorner = isAtCorner;

        draw_trail(route, routeLen, headIndex, starCount);

        usleep(ms * 1000);

        headIndex++;
        if (headIndex >= routeLen) headIndex = 0;
    }

    show_cursor();

    // unreachable
    free(route);
    return 0;
}