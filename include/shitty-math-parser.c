#include <shitty-math-parser.h>

bool is_operator (char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}


ParseTree* create_parse_tree () {
    ParseTree* parse_tree = malloc(sizeof(ParseTree));
    parse_tree->left = NULL;
    parse_tree->right = NULL;
    parse_tree->data = -1;
    parse_tree->parent = NULL;
    parse_tree->type = None;
    return parse_tree;
}

ParseTree *parse_expr (char* expr) {
    printf("Parsing expression: %s", expr);
    char* expression = expr;
    if (expr[0] != '(') {
        // add left parenthesis is not present later
        printf("Expression must start with a left parenthesis");
        return NULL;
    }
    size_t length = strlen(expression);

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

        }

        else if (c == ')') {
            if (current->parent != NULL) {
                current = current->parent;
            }
        }

        else if (is_operator(c)) {
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
        }
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