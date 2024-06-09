#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct TreeNode {
    Date date;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_node(Date date) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->date = date;
    new_node->left = new_node->right = NULL;
    return new_node;
}

TreeNode* insert(TreeNode* root, Date date) {
    if (root == NULL) return create_node(date);
    if (date.year < root->date.year || (date.year == root->date.year && date.month < root->date.month) || (date.year == root->date.year && date.month == root->date.month && date.day < root->date.day))
        root->left = insert(root->left, date);
    else
        root->right = insert(root->right, date);
    return root;
}

void preorder_traversal(TreeNode* root) {
    if (root != NULL) {
        printf("Date: %02d-%02d-%d\n", root->date.day, root->date.month, root->date.year);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return is_leap_year(year) ? 29 : 28;
        default: return 31;
    }
}

void add_days(Date *date, int days) {
    date->day += days;
    while (date->day > days_in_month(date->month, date->year)) {
        date->day -= days_in_month(date->month, date->year);
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

int main() {
    TreeNode* root = NULL;
    Date dates[10];

    for (int i = 0; i < 10; i++) {
        printf("Enter date %d (dd mm yyyy): ", i + 1);
        scanf("%d %d %d", &dates[i].day, &dates[i].month, &dates[i].year);
        add_days(&dates[i], 3);
        root = insert(root, dates[i]);
    }

    printf("\nUpdated Dates (Preorder Traversal):\n");
    preorder_traversal(root);

    return 0;
}
