#include <shitty-math-parser.h>

bool is_operator (char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

char* states[] = {"ExpectingOperand", "ExpectingComma", "ExpectingOperator", "ExpectingLeftParanthesis", "ExpectingRightParanthesis", "Default", "Error"};

ParseTree* create_parse_tree () {
    ParseTree* parse_tree = malloc(sizeof(ParseTree));
    parse_tree->left = NULL;
    parse_tree->right = NULL;
    parse_tree->data = -1;
    parse_tree->parent = NULL;
    parse_tree->type = None;
    return parse_tree;
}

void set_state (State* state, State* prev_state, State new_state) {
    *prev_state = *state;
    *state = new_state;
}

bool state_is (State* state, State expected_state) {
    return *state == expected_state;
}

ParseTree *parse_expr (char* expr) {

    State s = ExpectingLeftParenthesis;
    State prev_s = Default;
    State* state = &s;
    State* prev_state = &prev_s;

    size_t length = strlen(expr);
    short start_index = 0;
    char* expression = expr;
    if (expr[0] != '(') {
        length++;
        start_index = 1;
    }
    if (expr[length - 1] != ')') {
        length++;
    }

    expression = (char*)malloc(sizeof(char) * (length + 1));

    if (expr[0] != '(') expression[0] = '(';
    if (expr[length - 1] != ')') expression[length - 1] = ')';
    for (size_t i = 0; i < strlen(expr); i++) {
        expression[start_index + i] = expr[i];
    }
    expression[length] = '\0';
    printf("%s", expression);


    ParseTree* temp = NULL;
    ParseTree* current = create_parse_tree();


    for (size_t i = 0; i < length; i++) {

        char c = expression[i];

        if (c == ' ') {
            continue;
        }
        else if (c == '(') {
            current->left = create_parse_tree();
            temp = current;
            current = current->left;
            current->parent = temp;
            set_state(state, prev_state, ExpectingOperand);
        }

        else if (c == ')') {
            if (current->parent != NULL) {
                current = current->parent;
            }
        }

        else if (is_operator(c)) {
            if (state_is(state, ExpectingRightParenthesis) && state_is(prev_state, ExpectingOperand)) {
                // handle consecutive operators case
                temp = current;
                current->right->left = create_parse_tree();
                current = current->right->left;
                current->data = temp->right->data;
                current->parent = temp->right;
                current = temp->right;
                temp = NULL;
                printf("\n\n%c", current->left->data);
            }
            set_state(state, prev_state, ExpectingOperand);
            current->data = c;
            current->type = Operator;
            current->right = create_parse_tree();
            temp = current;
            current = current->right;
            current->parent = temp;
        }

        // else if (is_function())

        else {
            current->data = c;
            current->type = Number;
            current = current->parent;
            if (state_is(state, ExpectingOperand) && state_is(prev_state, ExpectingOperator)) {
                set_state(state, prev_state, ExpectingRightParenthesis);
            }
            else {
                set_state(state, prev_state, ExpectingOperator);
            }
        }
        printf("\n%s, %s", states[*state], states[*prev_state]);
    }


    return current;
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
        case '^':
            return pow(a, b);
            break;
        case '%':
            return (int)a % (int)b;
            break;
        default:
            printf("Invalid operator: %c", operator);
            return 0;
    }
}

double evaluate_expr (ParseTree* parse_tree) {
    if (parse_tree->left == NULL && parse_tree->right == NULL) return strtod(&parse_tree->data, NULL);
    double val1 = evaluate_expr(parse_tree->left);
    double val2 = evaluate_expr(parse_tree->right);
    return calculate(val1, parse_tree->data, val2);
}