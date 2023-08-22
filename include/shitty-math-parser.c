#include <shitty-math-parser.h>

bool is_operator (char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

char* states[] = {"ExpectingOperand", "ExpectingComma", "ExpectingOperator", "ExpectingLeftParanthesis", "ExpectingRightParanthesis", "Default", "Error"};

void set_state (State* state, State* prev_state, State new_state) {
    *prev_state = *state;
    *state = new_state;
}

bool state_is (State* state, State expected_state) {
    return *state == expected_state;
}

ParseTree* create_parse_tree (ParseTree* parent) {
    ParseTree* parse_tree = malloc(sizeof(ParseTree));
    parse_tree->left = NULL;
    parse_tree->right = NULL;
    parse_tree->parent = parent;
    parse_tree->token = NULL;
    return parse_tree;
}

Token* create_token (size_t start, size_t end, TokenType type) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->start = start;
    token->end = end;
    token->type = type;
    return token;
}

bool is_delimiter (char c) {
    return c == ')' || c == '(' || is_operator(c) || c == ',';
}

bool is_number (char c) {
    return (c >= '0' && c <= '9') || c == '.' || c == '-' || c == '+';
}

bool is_letter (char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char* token_types[] = {"Number", "Variable", "Function", "Operator", "None"};

int priority (char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '^':
            return 2;
        case '%':
            return 3;
        default:
            return -1;
    }
}

void print_value (size_t start, size_t end, char* expression) {
    for (size_t i = start; i < end + 1; i++) {
        printf("%c", expression[i]);
    }
}


bool is_variable (Parser* parser, size_t start, size_t end, char* expression) {
    char data[end - start + 2];
    for (size_t i = parser->tree->token->start, j = 0; i < parser->tree->token->end + 1; i++, j++) {
        data[j] = expression[i];
    }
    data[end - start + 1] = '\0';
    for (int i = 0; i < parser->variables->length; i++) {
        if (strcmp(data, parser->variables->names[i]) == 0) {
            return true;
        }
    }
    return false;
}


bool is_function (Parser* parser, size_t start, size_t end, char* expression) {
    char data[end - start + 2];
    for (size_t i = start, j = 0; i < end + 1; i++, j++) {
        data[j] = expression[i];
    }
    data[end - start + 1] = '\0';
    for (int i = 0; i < parser->functions->length; i++) {
        printf("\n%s : %s\n", data, parser->functions->names[i]);
        if (strcmp(data, parser->functions->names[i]) == 0) {
            return true;
        }
    }
    return false;
}


void parse (Parser* parser, char* expression) {
    printf("%lf", pow(2, 3));

    // Print out expression to parse
    printf("Lexing: %s\n", expression);

    // State Management
    State s = ExpectingOperand;
    State ps = Default;
    State* state = &s;
    State* prev_state = &ps;

    // Get length
    size_t length = strlen(expression);

    // Create a parse tree
    free(parser->tree);
    parser->tree = create_parse_tree(NULL);;
    ParseTree* current = parser->tree;

    for (size_t i = 0; i < length; i++) {
        // Log the state
        // printf("\n%s, %s", states[*state], states[*prev_state]);
        char c = expression[i];

        if (c == ' ') {
            continue;
        }

        else if (c == '(') {
            current->left = create_parse_tree(current);
            current = current->left;
        }

        else if (c == ')') {
            if (current->parent != NULL)
            current = current->parent;
        }

        else if (is_operator(c) && !is_number(expression[i + 1])) {
            current->token = create_token(i, i, Token_Operator);
            current->right = create_parse_tree(current);
            current = current->right;
            set_state(state, prev_state, ExpectingOperand);
        }

        else if (is_letter(c)) {
            size_t start = i;
            size_t end = i;
            size_t offset = 0;
            while (is_letter(expression[i + 1])) {
                i++;
                end++;
                offset++;
            }
            if (is_function(parser, start, end, expression)) {
                while (expression[i + 1] != ')') {
                    i++;
                    end++;
                }
                current->token = create_token(start + offset + 2, end, Token_Function);
                current = current->parent;
                set_state(state, prev_state, ExpectingOperator);
            }
            else {
                current->token = create_token(start, end, Token_Variable);
                current = current->parent;
                set_state(state, prev_state, ExpectingOperator);
            }
        }

        // is_function case
        // is_variable case

        else {
            size_t start = i;
            size_t end = i;
            while (is_number(expression[i + 1])) {
                end++;
                i++;
            }
            current->token = create_token(start, end, Token_Number);
            current = current->parent;
            set_state(state, prev_state, ExpectingOperator);
        }
    }
}

double calculate (double a, char operator, double b) {
    switch (operator) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
        case '%':
            return (int)a % (int)b;
            break;
        default:
            printf("Invalid operator: %c", operator);
            return 0;
    }
}


double evaluate_expr_recursion (Parser* parser, ParseTree* parse_tree, char* expression) {
    if (parse_tree == NULL) {
        return -1;
    }
    if (parse_tree->left == NULL && parse_tree->right == NULL) {
        char data[parse_tree->token->end - parse_tree->token->start + 2];
        for (size_t i = parse_tree->token->start, j = 0; i < parse_tree->token->end + 1; i++, j++) {
            data[j] = expression[i];
        }
        data[parse_tree->token->end - parse_tree->token->start + 1] = '\0';
        if (parse_tree->token->type ==  Token_Variable) {
            for (int i = 0; i < parser->variables->length; i++) {
                if (strcmp(data, parser->variables->names[i]) == 0) {
                    return parser->variables->values[i];
                }
            }
        }
        else if (parse_tree->token->type == Token_Function) {

            size_t start = parse_tree->token->start;
            size_t end = parse_tree->token->end;
            char data[end - start + 2];
            for (size_t i = start, j = 0; i < end + 1; i++, j++) {
                data[j] = expression[i];
            }
            data[end - start + 1] = '\0';

            size_t cur = start;

            Parser* temp_parser = create_parser();
            temp_parser->variables = parser->variables;
            temp_parser->functions = parser->functions;

            double* args = (double*)malloc(sizeof(double));
            size_t args_length = 0;
            bool should_stop = false;
            while (!should_stop) {
                size_t delim = cur;
                while (expression[cur + 1] != ',') {
                    if (delim == end) {
                        should_stop = true;
                        delim = end;
                        break;

                    }
                    delim++;
                }
                char temp[delim - cur + 2];
                for (size_t i = cur, j = 0; i < delim + 1; i++, j++) {
                    temp[j] = expression[i];
                }
                temp[delim - cur + 1] = '\0';
//                printf("\n\nheheboi: %s\n\n", temp);
                parse(temp_parser, temp);
                double res = evaluate_expr(temp_parser, temp);
                args = realloc(args, sizeof(double) * (args_length + 1));
                if (args == NULL) {
                    should_stop = true;
                    break;
                }
                args[args_length] = res;
                args_length++;
                cur = delim + 2;
            }
            return parser->functions->definitions[0](args, args_length);
        }
        else {
            return strtod(data, NULL);
        }
    }
    double val1 = evaluate_expr_recursion(parser, parse_tree->left, expression);
    double val2 = evaluate_expr_recursion(parser, parse_tree->right, expression);
    return calculate(val1, expression[parse_tree->token->start], val2);
    return -1;
}

double evaluate_expr (Parser* parser, char* expression) {
    return evaluate_expr_recursion(parser, parser->tree, expression);
}

void add_variable (Parser* parser, char* name, double value) {
    if (name == NULL) return;
    if (strlen(name) == 0) return;
    Variables* vars = parser->variables;
    if (vars->length == 0) {
        vars->names = (char**)malloc(sizeof(char*));
        vars->values = (double*)malloc(sizeof(double));
    }
    else {
        vars->names = (char**)realloc(vars->names, sizeof(char*) * (vars->length + 1));
        vars->values = (double*)realloc(vars->values, sizeof(double) * (vars->length + 1));
    }
    // handle case if malloc/realloc fails
    if (vars->names == NULL) return;
    if (vars->values == NULL) return;

    size_t name_length = strlen(name);
    char* copy = (char*)malloc(sizeof(char) * (name_length + 1));
    strcpy(copy, name);
    copy[name_length] = '\0';
    vars->names[vars->length] = copy;
    vars->values[vars->length] = value;
    vars->length++;
}

void add_function (Parser* parser, char* name, void* definition) {
    if (name == NULL) return;
    if (strlen(name) == 0) return;
    Functions* fns = parser->functions;
    if (fns->length == 0) {
        fns->names = (char**)malloc(sizeof(char*));
        fns->definitions = (ParserFunction*)malloc(sizeof(ParserFunction));
    }
    else {
        fns->names = (char**)realloc(fns->names, sizeof(char*) * (fns->length + 1));
        fns->definitions = (double*)realloc(fns->definitions, sizeof(ParserFunction) * (fns->length + 1));
    }
    // handle case if malloc/realloc fails
    if (fns->names == NULL) return;
    if (fns->definitions == NULL) return;

    size_t name_length = strlen(name);
    char* copy = (char*)malloc(sizeof(char) * (name_length + 1));
    strcpy(copy, name);
    copy[name_length] = '\0';
    fns->names[fns->length] = copy;
    fns->definitions[fns->length] = (ParserFunction)definition;
    fns->length++;
}

Parser* create_parser () {
    Parser* parser = (Parser*)malloc(sizeof(Parser));
    parser->variables = (Variables*)malloc(sizeof(Variables));
    parser->functions = (Functions*)malloc(sizeof(Functions));
    parser->variables->length = 0;
    parser->variables->names = NULL;
    parser->variables->values = NULL;
    parser->functions->length = 0;
    parser->functions->names = NULL;
    parser->functions->definitions = NULL;
    parser->tree = NULL;
    return parser;
}

void destroy_parser (Parser* parser) {
    free(parser->tree);
    for (size_t i = 0; i < parser->variables->length; i++) {
        free(parser->variables->names[i]);
        parser->variables->names[i] = NULL;
    }
    free(parser->variables->names);
    parser->variables->names = NULL;
    free(parser->variables->values);
    parser->variables->values = NULL;


    for (size_t i = 0; i < parser->functions->length; i++) {
        free(parser->functions->names[i]);
        parser->functions->names[i] = NULL;
    }
    free(parser->functions->names);
    parser->functions->names = NULL;
    free(parser->functions->definitions);
    parser->functions->definitions = NULL;
    free(parser);
}