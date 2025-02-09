#ifndef __AST_H__
#define __AST_H__

#include <stddef.h>
#include <stdint.h>

#define ASTTYPE_INTEGER_LITERAL     0
#define ASTTYPE_FLOAT_LITERAL       1
#define ASTTYPE_STRING_LITERAL      2
#define ASTTYPE_IDENTIFIER          3
#define ASTTYPE_DEFINITION          4
#define ASTTYPE_TYPE                5
#define ASTTYPE_ASSIGNMENT          6
#define ASTTYPE_ADDITION            7
#define ASTTYPE_SUBTRACTION         8
#define ASTTYPE_MULTIPLICATION      9
#define ASTTYPE_DIVISION            10
#define ASTTYPE_MODULO              11
#define ASTTYPE_BINARY_AND          12
#define ASTTYPE_BINARY_OR           13
#define ASTTYPE_BINARY_XOR          14
#define ASTTYPE_BINARY_NOT          15
#define ASTTYPE_LOGICAL_AND         16
#define ASTTYPE_LOGICAL_OR          17
#define ASTTYPE_LOGICAL_NOT         18
#define ASTTYPE_EQUAL               19
#define ASTTYPE_NOT_EQUAL           20
#define ASTTYPE_GREATER_THAN        21
#define ASTTYPE_GREATER_THAN_EQUAL  22
#define ASTTYPE_LESS_THAN           23
#define ASTTYPE_LESS_THAN_EQUAL     24
#define ASTTYPE_LEFT_SHIFT          25
#define ASTTYPE_RIGHT_SHIFT         26
#define ASTTYPE_QUALIFIER           27
#define ASTTYPE_ADDRESS_OF          28
#define ASTTYPE_DEREFERENCE         29
#define ASTTYPE_INCREMENT           30
#define ASTTYPE_DECREMENT           31
#define ASTTYPE_TRINARY             32

#define QUALIFIER_CONST     0
#define QUALIFIER_VOLATILE  1
#define QUALIFIER_RESTRICT  2
#define QUALIFIER_STATIC    3
#define QUALIFIER_EXTERN    4
#define QUALIFIER_REGISTER  5
#define QUALIFIER_AUTO      6
#define QUALIFIER_LONG      7
#define QUALIFIER_SHORT     8
#define QUALIFIER_SIGNED    9
#define QUALIFIER_UNSIGNED  10

#define MODIFIER_NONE 0
#define MODIFIER_POINTER 1
#define MODIFIER_ARRAY 1


typedef struct __ast_node {
    uint8_t type;
    union {
        struct {
            char *text;
            int len;
        } identifier;
        struct {
            struct __ast_node *type;
            struct __ast_node *name;
            struct __ast_node *val_exp;
        } definition;
        struct {
            char which;
        } qualifier;
        struct {
            struct __ast_node *qualifiers;  // Linked list or array
            size_t num_qualifiers;
            char* basetype;
            uint8_t modifiers[16];
            size_t num_modifiers;
            struct __ast_node *array_size;
            size_t num_array_size;
        }vartype;
        struct {
            char *text;
            int len;
        } string_literal;
        int integer_literal;
        double float_literal;
        struct {

            struct __ast_node *left;
            struct __ast_node *right;
        } binary_exp;
        struct {
            struct __ast_node *right;
        } unary_exp;
        struct {
            struct __ast_node *condition;
            struct __ast_node *true_exp;
            struct __ast_node *false_exp;
        } trinary_exp;
    };
} ast_node_t;

ast_node_t *ast_new_integer_literal(int value);

ast_node_t *ast_new_identifier(char *text, int len);
ast_node_t *ast_new_qualifier(char which);
ast_node_t *ast_new_vartype(char *basetype);
ast_node_t *ast_amend_vartype_qualifier(ast_node_t *vartype, ast_node_t *qualifier);
ast_node_t *ast_amend_pointer(ast_node_t *vartype);
ast_node_t *ast_amend_array(ast_node_t *vartype, ast_node_t *array_size);

ast_node_t *ast_new_declaration(ast_node_t *name, ast_node_t *vartype, ast_node_t *value);

ast_node_t *ast_new_binary_node(uint8_t type, ast_node_t *left, ast_node_t *right);
ast_node_t *ast_new_unary_node(uint8_t type, ast_node_t *right);
ast_node_t *ast_new_trinary_node(ast_node_t *condition, ast_node_t *true_exp, ast_node_t *false_exp);

void        ast_print_all(ast_node_t *ast);
void        ast_free_all(ast_node_t *ast);

ast_node_t *parse(char *input);

#endif // __AST_H__