 #include <stdio.h>

#include <stdlib.h>
 struct node {
     int data ;
     struct node * left , * right ;
 };
 struct node* new_node(int data);
void print_tree(struct node *);
int main()
{
    struct node *root;

    root = new_node(9);
    root->left = new_node(6);
    root ->right = new_node(11);
    root->left ->left = new_node(4);
    root->left ->right = new_node(7);
    root->left ->left ->left = new_node(2);
    root ->right ->right = new_node(15);
    root ->right ->right ->right = new_node(25);
    root ->right ->right ->left = new_node(12);

        print_tree(root);

    return 0;
}
 void print_tree(struct node *t)
 {
    if(t  == NULL)
    {
        return;
    }
    print_tree(t->left);
    printf("%5d", t->data);
    print_tree(t->right);

 }
 struct node* new_node(int data)
 {

     struct node* temp  = (struct node*)malloc(sizeof(struct node));
     temp->data = data;

     temp->left = NULL;
     temp->right = NULL;
     return (temp);
 }