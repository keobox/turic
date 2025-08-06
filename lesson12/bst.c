#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left, *right;
};


/*
 * Add a new node, if root is NULL returns the new root 
 * otherwise it just return the passed root pointer.
 */
struct node *add(struct node* root, int val)
{
    struct node *saved_root = root;
    struct node *new = malloc(sizeof(*new));
    // FIXME do not check for malloc failures, is
    // simple code for learning.
    // malloc can return NULL in case of error.
    new->left = new->right = NULL;
    new->val = val;

    if (root == NULL) return new;
    
    // search position of the new node
    while(1) {
        if (val > root->val) {
            if (root->right == NULL) {
                root->right = new;
                return saved_root;
            }
            // navigate right
            root = root->right;
        } else {
            // val == node.val is here
            if (root->left == NULL) {
                root->left = new;
                return saved_root;
            }
            // navigate left
            root = root->left;
        }
    }
}

/* Implement and Inorder tree walk of the tree to print sorted values */
void print_sorted(struct node *root) {
    // This is an Inorder tree walk
    if (root == NULL) return;

    if (root->left)
        print_sorted(root->left);

    printf("%d\n", root->val);

    if (root->right)
        print_sorted(root->right);
}

int main () {
    struct node *root = NULL;
    root = add(root, 10);
    root = add(root, 5);
    root = add(root, 20);
    root = add(root, 100);
    root = add(root, 40);
    root = add(root, 33);
    print_sorted(root);
    return 0;
}
