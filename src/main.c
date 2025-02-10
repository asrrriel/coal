#include <stdio.h>
#include "ast.h"

int main(int argc, char *argv[]) {
    //test statement
    ast_node_t *root = parse("const int asdf = (asdf++ != 123 & 69 > 0b10000000 < 420 && asdf || !(asdf == 69420 | 0xff)) ? ~123 * 2%10 + (*pp)-- : (6 + 9 / 42) ^ 10");
    //ast_node_t *root = parse("auto double int struct break else long switch case enum register typedef char extern return union const float short unsigned continue for signed void default goto sizeof volatile do if static while _Bool _Imaginary restrict _Complex inline");

    ast_print_all(root);

    return 0;
}