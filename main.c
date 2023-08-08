#include <stdio.h>
#include <shitty-math-parser.h>

void traverse_inorder (ParseTree* parse_tree) {
    if (parse_tree == NULL) {
        printf("parse tree is NULL");
        return;
    }
    if (parse_tree->left != NULL) traverse_inorder(parse_tree->left);
    if (parse_tree != NULL) printf("%c", parse_tree->data);
    if (parse_tree->right != NULL) traverse_inorder(parse_tree->right);
}

int main() {
    ParseTree* parse_tree = parse_expr("(1 + 2 + 3)");
    printf("\n");
    traverse_inorder(parse_tree);
    printf("\n%lf", evaluate_expr(parse_tree));
    return 0;
}
