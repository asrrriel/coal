#include "ast.h"
#include <stdio.h>
#include <stdlib.h>


ast_node_t *ast_new_integer_literal(int value) {
    ast_node_t *node = calloc(1, sizeof(ast_node_t));
    node->type = ASTTYPE_INTEGER_LITERAL;
    node->integer_literal = value;
    return node;
}

ast_node_t *ast_new_identifier(char *text, int len) {
    ast_node_t *node = calloc(1, sizeof(ast_node_t));
    node->type = ASTTYPE_IDENTIFIER;
    node->identifier.text = text;
    node->identifier.len = len;
    return node;
}

ast_node_t *ast_new_declaration(ast_node_t *name, ast_node_t* type, ast_node_t *value) {
    ast_node_t *node = calloc(1, sizeof(ast_node_t));
    node->type = ASTTYPE_DEFINITION;
    node->definition.name = name;
    node->definition.type = type;
    node->definition.val_exp = value;
    return node;
}

ast_node_t *ast_new_qualifier(char which) {
    ast_node_t *node = calloc(1, sizeof(ast_node_t));
    node->type = ASTTYPE_QUALIFIER;
    node->qualifier.which = which;
    return node;
}

ast_node_t *ast_new_vartype(char *basetype) {
    ast_node_t *node = calloc(1, sizeof(ast_node_t));
    node->type = ASTTYPE_TYPE;
    node->vartype.basetype = basetype;
    node->vartype.qualifiers = NULL;
    node->vartype.modifiers[0] = 0;
    node->vartype.num_qualifiers = 0;
    node->vartype.num_modifiers = 0;
    return node;
}

ast_node_t *ast_amend_vartype_qualifier(ast_node_t *node, ast_node_t *qualifier) {
    if (node->vartype.qualifiers == NULL) {
        node->vartype.qualifiers = calloc(1, sizeof(ast_node_t*));
    } else {
        node->vartype.qualifiers = realloc(node->vartype.qualifiers, (node->vartype.num_qualifiers + 1) * sizeof(ast_node_t*)); 
    }
    node->vartype.num_qualifiers++;
    if ( node->vartype.qualifiers == NULL) {
        printf("Failed to allocate qualifier\n");
    }
    printf("num_qualifiers: %d\n", node->vartype.num_qualifiers);
    node->vartype.qualifiers[node->vartype.num_qualifiers - 1] = *qualifier;
    free(qualifier);
    return node;
}

ast_node_t *ast_amend_pointer(ast_node_t *vartype){
    vartype->vartype.modifiers[vartype->vartype.num_modifiers++] = MODIFIER_POINTER;
    return vartype;
}

ast_node_t *ast_amend_array(ast_node_t *vartype, ast_node_t *array_size){
    vartype->vartype.modifiers[vartype->vartype.num_modifiers++] = MODIFIER_ARRAY;
    if (vartype->vartype.array_size == NULL) {
        vartype->vartype.array_size = calloc(1, sizeof(ast_node_t*));
    } else {
        vartype->vartype.array_size = realloc(vartype->vartype.array_size, (vartype->vartype.num_array_size + 1) * sizeof(ast_node_t*));
    }
    vartype->vartype.num_array_size++;
    if ( vartype->vartype.array_size == NULL) {
        printf("Failed to allocate array size\n");
    }
    printf("num_array_size: %d\n", vartype->vartype.num_array_size);
    vartype->vartype.array_size[vartype->vartype.num_array_size - 1] = *array_size;
    free(array_size);
    return vartype;
}


ast_node_t *ast_new_binary_node(uint8_t type, ast_node_t *left, ast_node_t *right) {
    ast_node_t *node = calloc(1, sizeof(ast_node_t));
    node->type = type;
    node->binary_exp.left = left;
    node->binary_exp.right = right;
    return node;
}

ast_node_t *ast_new_unary_node(uint8_t type, ast_node_t *right) {
    ast_node_t *node = calloc(1, sizeof(ast_node_t));
    node->type = type;
    node->unary_exp.right = right;
    return node;
}


ast_node_t *ast_new_trinary_node(ast_node_t *condition, ast_node_t *true_exp, ast_node_t *false_exp) {
    ast_node_t *node = calloc(1, sizeof(ast_node_t));
    node->type = ASTTYPE_TRINARY;
    node->trinary_exp.condition = condition;
    node->trinary_exp.true_exp = true_exp;
    node->trinary_exp.false_exp = false_exp;
    return node;
}

// Helper function to print each node
void ast_print(ast_node_t *node, int depth) {
    if (node == NULL) return;

    // Print indentation based on depth
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    // Print the node type
    switch (node->type) {
        case ASTTYPE_INTEGER_LITERAL:
            printf("Integer Literal: %d\n", node->integer_literal);
            break;
        case ASTTYPE_FLOAT_LITERAL:
            printf("Float Literal: %f\n", node->float_literal);
            break;
        case ASTTYPE_STRING_LITERAL:
            printf("String Literal: \"%s\"\n", node->string_literal.text);
            break;
        case ASTTYPE_IDENTIFIER:
            printf("Identifier: \"%s\"\n", node->identifier.text);
            break;
        case ASTTYPE_ASSIGNMENT:
            printf("Assignment\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_ADDITION:
            printf("Addition\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_SUBTRACTION:
            printf("Subtraction\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_MULTIPLICATION:
            printf("Multiplication\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_DIVISION:
            printf("Division\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_MODULO:
            printf("Modulo\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_BINARY_AND:
            printf("Binary AND\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_BINARY_OR:
            printf("Binary OR\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_BINARY_XOR:
            printf("Binary XOR\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_BINARY_NOT:
            printf("Binary NOT\n");
            ast_print(node->unary_exp.right, depth + 1);
            break;
        case ASTTYPE_LOGICAL_AND:
            printf("Logical AND\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_LOGICAL_OR:
            printf("Logical OR\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_LOGICAL_NOT:
            printf("Logical NOT\n");
            ast_print(node->unary_exp.right, depth + 1);
            break;
        case ASTTYPE_EQUAL:
            printf("Equal\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_NOT_EQUAL:
            printf("Not Equal\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_GREATER_THAN:
            printf("Greater Than\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_GREATER_THAN_EQUAL:
            printf("Greater Than Equal\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_LESS_THAN:
            printf("Less Than\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_LESS_THAN_EQUAL:
            printf("Less Than Equal\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_LEFT_SHIFT:
            printf("Left Shift\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        case ASTTYPE_RIGHT_SHIFT:
            printf("Right Shift\n");
            ast_print(node->binary_exp.left, depth + 1);
            ast_print(node->binary_exp.right, depth + 1);
            break;
        default:
            printf("Unknown Node Type\n");
            break;
    }
}

void ast_print_all(ast_node_t *ast) {
    ast_print(ast, 0);  // Start with depth 0
}

void ast_free_all(ast_node_t *ast) {
    if (ast == NULL) return;
    switch(ast->type) {
        case ASTTYPE_IDENTIFIER:
        case ASTTYPE_STRING_LITERAL:
            free(ast->identifier.text);
            break;
        case ASTTYPE_ASSIGNMENT:
        case ASTTYPE_ADDITION:
        case ASTTYPE_SUBTRACTION:
        case ASTTYPE_MULTIPLICATION:
        case ASTTYPE_DIVISION:
        case ASTTYPE_MODULO:
        case ASTTYPE_BINARY_AND:
        case ASTTYPE_BINARY_OR:
        case ASTTYPE_BINARY_XOR:
        case ASTTYPE_LOGICAL_AND:
        case ASTTYPE_LOGICAL_OR:
        case ASTTYPE_EQUAL:
        case ASTTYPE_NOT_EQUAL:
        case ASTTYPE_GREATER_THAN:
        case ASTTYPE_GREATER_THAN_EQUAL:
        case ASTTYPE_LESS_THAN:
        case ASTTYPE_LESS_THAN_EQUAL:
        case ASTTYPE_LEFT_SHIFT:
        case ASTTYPE_RIGHT_SHIFT:
            ast_free_all(ast->binary_exp.left);
            ast_free_all(ast->binary_exp.right);
            break;
        case ASTTYPE_BINARY_NOT:
            ast_free_all(ast->unary_exp.right);
            break;
        case ASTTYPE_LOGICAL_NOT:
            ast_free_all(ast->unary_exp.right);
            break;
        // no tinary nodes yet
    }
    free(ast);
}