#include <stdio.h>

static char input[2048];

int main(int argc, char** argv) {
    /* Print version and exit information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while(1) {

        /* Output prompt */
        fputs("lispy> ", stdout);

        /* Read line of input, max size 2048 */
        fgets(input, 2048, stdin);

        /* Echo back to use */
        printf("No you're a %s", input);
    }

    return 0;
}
