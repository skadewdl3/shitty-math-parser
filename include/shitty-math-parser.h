#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef enum {
    Token_Number, Token_Variable, Token_Function, Token_Operator, Token_None
} TokenType;

typedef enum {
    ExpectingOperand, ExpectingComma, ExpectingOperator, ExpectingLeftParenthesis, ExpectingRightParenthesis, Default, Error, GotLeftParenthesis, GotRightParenthesis
} State;

typedef struct TokenStruct {
    size_t start;
    size_t end;
    TokenType type;
} Token;

typedef struct ParseTreeStruct {
    struct ParseTreeStruct* left;
    struct ParseTreeStruct* right;
    struct ParseTreeStruct* parent;
    Token* token;
} ParseTree;

typedef struct {
    char* name;
    double value;
} Variable;

typedef struct {
    int length;
    char** names;
    double* values;
} Variables;

typedef double (*ParserFunction)(double a, ...);

typedef struct {
    int length;
    char** names;
    ParserFunction* definitions;
} Functions;

typedef struct {
    ParseTree* tree;
    Variables* variables;
    Functions* functions;
} Parser;


void parse (Parser*, char*);

Parser* create_parser ();

double evaluate_expr (Parser*, char*);

void add_variable (Parser*, char*, double);

void add_function (Parser*, char*, void*);

void print_value(size_t, size_t, char*);

void destroy_parser (Parser* parser);