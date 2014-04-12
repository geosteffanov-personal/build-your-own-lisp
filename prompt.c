#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

int main(int argc, char** argv) {
    /* Print version and exit information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while(1) {

        /* Output prompt */
        char* input = readline("lispy> ");
        add_history(input);

        /* Echo back to use */
        printf("No you're a %s\n", input);

        free(input);
    }

    return 0;
}
