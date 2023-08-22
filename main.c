#include <stdio.h>
#include <shitty-math-parser.h>
#include <math.h>

char* token_types_2[] = {"Number", "Variable", "Function", "Operator", "None"};

void traverse_inorder (Parser* parser, ParseTree* parse_tree, char* expression) {
    if (parse_tree == NULL) {
        printf("parse tree is NULL");
        return;
    }
    if (parse_tree->left != NULL) traverse_inorder(parser, parse_tree->left, expression);

    if (parse_tree != NULL) {
        char data[parse_tree->token->end - parse_tree->token->start + 2];
//        for (size_t i = parse_tree->token->start, j = 0; i < parse_tree->token->end + 1; i++, j++) {
//            data[j] = expression[i];
//        }
//        data[parse_tree->token->end - parse_tree->token->start + 1] = '\0';
//        if (parse_tree->token->type == Token_Variable) {
//                for (int i = 0; i < parser->variables->length; i++) {
//                    if (strcmp(data, parser->variables->names[i]) == 0) {
//                        printf("%lf", parser->variables->values[i]);
//                    }
//                }
//        }
//        else
        print_value(parse_tree->token->start, parse_tree->token->end, expression);
    }
    if (parse_tree->right != NULL) traverse_inorder(parser, parse_tree->right, expression);
}

int main() {

    // there must be spaces between operand and operator
    // when using unary operator on number like -4, there must be no space
    // brackets must be complete
    // variable/function names must be all letters. no underscores/numbers/etc.

    Parser* parser = create_parser();
    add_variable(parser, "abc", 10.0);
    add_variable(parser, "x", 69);
    add_function(parser, "power", pow);

    char expr1[] = "(2 + power(2, 3))";
    char expr2[] = "x";

    char* expression = expr1;
    parse(parser, expression);
    printf("\n");
    // traverse_inorder(parser, parser->tree, expression);
    printf("\n%lf", evaluate_expr(parser, expression));
    destroy_parser(parser);
    return 0;
}
