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
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}

void hide_cursor(void) {
    printf("\033[?25l");
    fflush(stdout);
}

void show_cursor(void) {
    printf("\033[?25h");
    fflush(stdout);
}


void clear_except_top(void) {
    printf("\033[2;1H");
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
        if (prev.x == x && prev.y == y) return;
    }
    route[*len].x = x;
    route[*len].y = y;
    (*len)++;
}

static int build_clockwise(Point *route) {
    int len = 0;

    for (int x = 0; x <= XMAX; x++) append_point(route, &len, x, YMIN);

    for (int y = YMIN + 1; y <= YMAX; y++) append_point(route, &len, XMAX, y);

    for (int x = XMAX - 1; x >= 0; x--) append_point(route, &len, x, YMAX);

    for (int y = YMAX - 1; y >= YMIN + 1; y--) append_point(route, &len, 0, y);

    return len;
}

static int build_counter_clockwise(Point *route) {
    int len = 0;

    for (int y = YMIN; y <= YMAX; y++) append_point(route, &len, 0, y);

    for (int x = 1; x <= XMAX; x++) append_point(route, &len, x, YMAX);

    for (int y = YMAX - 1; y >= YMIN; y--) append_point(route, &len, XMAX, y);

    for (int x = XMAX - 1; x >= 1; x--) append_point(route, &len, x, YMIN);

    return len;
}

static void draw_trail(const Point *route, int routeLen, int headIndex, int count) {
    for (int k = 0; k < count; k++) {
        int idx = headIndex - k;
        while (idx < 0) idx += routeLen;
        idx %= routeLen;

        gotoxy(route[idx].x, route[idx].y);
        putchar('*');
    }
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    printf("Start!! column size: %d, 별표(*)속도(ms) : ", WIDTH);
    scanf("%d", &ms);
    
    gotoxy(0, 0);
    printf("start!! column size: %d, 별표(*)속도(ms) : %d", WIDTH, ms);
    fflush(stdout);

    hide_cursor();

    // 테두리 길이 계산
    // 중복 제외 점 개수
    const int perimLen = 2 * (WIDTH - 1) + 2 * (YMAX - YMIN);
    // route 배열 크기
    const int routeCap = perimLen * 2;

    // 이동 경로 배열 생열
    Point *route = (Point *)malloc(sizeof(Point) * routeCap);
    if (!route) return 0;

    // 이동 경로 생성
    int cwLen = build_clockwise(route);
    int ccwLen = build_counter_clockwise(route + cwLen);
    int routeLen = cwLen + ccwLen;

    if (routeLen <= 0) return 0;

    // 별 개수 및 인덱스 초기화
    int starCount = 1;
    const int maxStars = perimLen;
    int headIndex = 0;
    bool wasAtCorner = true;

    while (1) {
        clear_except_top();

        // 현재 머리 위치
        Point head = route[headIndex];

        // (0, 1) 도착하는 순간 별표 개수 증가
        bool isAtCorner = (head.x == 0 && head.y == YMIN);
        if (isAtCorner && !wasAtCorner) {
            starCount++;
            // 별 개수 최대치 초과 시 1로 초기화
            if (starCount > maxStars) starCount = 1;
        }
        wasAtCorner = isAtCorner;

        // 별표 그리기
        draw_trail(route, routeLen, headIndex, starCount);

        usleep(ms * 1000);

        headIndex++;
        if (headIndex >= routeLen) headIndex = 0;
    }

    show_cursor();

    free(route);
    return 0;
}