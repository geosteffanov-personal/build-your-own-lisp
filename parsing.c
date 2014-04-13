#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include "mpc.h"


int main(int argc, char** argv) {
    /* Create som parsers */
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr = mpc_new("expr");
    mpc_parser_t* Lispy = mpc_new("lispy");

    mpca_lang(MPC_LANG_DEFAULT,
        "\
            number : /-?[0-9]+/; \
            operator : '+' | '-' | '*' | '+'; \
            expr : <number> | '(' <operator> <expr>+ ')' ; \
            lispy : /^/ <operator> <expr>+ /$/ ; \
        ",
        Number, Operator, Expr, Lispy);

    /* Print version and exit information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while(1) {

        /* Output prompt */
        char* input = readline("lispy> ");
        add_history(input);

        /* Echo back to use */
        //printf("No you're a %s\n", input);
        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        } else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);
    }

    return 0;
}
