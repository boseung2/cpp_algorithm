#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

struct termios orig_termios;

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON); // no echo, no canonical mode
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int read_key() {
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1) return -1;

    if (c == '\033') { // ESC
        char seq[2];
        if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\033';
        if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\033';

        if (seq[0] == '[') {
            if (seq[1] == 'C') return 'R'; // Right arrow
            if (seq[1] == 'D') return 'L'; // Left arrow
        }
        return -1;
    }

    return c;
}

void clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

void print_space(int x) {
    for(int i = 0; i < x; i++)
        printf(" ");
}

void print_man(int x, int frame, int y_offset) {
    for (int i = 0; i < y_offset; i++) printf("\n");
    if(frame % 2 == 0) {
        print_space(x); printf(" @ \n");
        print_space(x); printf("|||\n");
        print_space(x); printf(" | \n");
        print_space(x); printf("| |\n");
    } else {
        print_space(x); printf(" @ \n");
        print_space(x); printf("-|-\n");
        print_space(x); printf(" | \n");
        print_space(x); printf("/ -\n");
    }
    fflush(stdout);
}

int main(void) {
    int x = 0;
    int frame = 0;
    int jumping = 0;
    int jump_height = 0;

    enable_raw_mode();

    while(1) {
        if (jumping) {
            clear_screen();

            int delta = (jump_height <= 6) ? jump_height : (12 - jump_height);
            int y_offset = 7 - delta;

            print_man(x, 1, y_offset);
            usleep(200000);

            jump_height++;
            if (jump_height > 12) {
                jumping = 0;
                jump_height = 0;
            }
            continue;
        }

        clear_screen();
        print_man(x, frame, 7);

        int key = read_key();

        if (key == 'L' && x > 0) {
            x--;
            frame++;
        }
        else if (key == 'R') {
            x++;
            frame++;
        }
        else if (key == ' ') {
            jumping = 1;
            jump_height = 0;
            frame = 1;
        }
    }

    return 0;
}