#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef enum {
    Number, Variable, Function, Operator, None
} TokenType;

typedef enum {
    ExpectingOperand, ExpectingComma, ExpectingOperator, ExpectingLeftParenthesis, ExpectingRightParenthesis, Default, Error
} State;


typedef struct ParseTreeStruct {
    struct ParseTreeStruct* left;
    struct ParseTreeStruct* right;
    struct ParseTreeStruct* parent;
    char data;
    TokenType type;
} ParseTree;

ParseTree* parse_expr (char* expression);

double evaluate_expr (ParseTree* parse_tree);