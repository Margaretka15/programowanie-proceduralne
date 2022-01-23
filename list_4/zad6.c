#include <stdio.h>

#include <stdlib.h>
struct node {
    int data ;
    struct node * left , * right ;
};
struct node* new_node(int data);
void print_tree(struct node *);
struct node* find_element(int x);
struct node* insert_element(int x);
struct node *root;

int main()
{
/// w ten prymitywny sposob buduje takie drzewo jak w poleceniu
    root = new_node(9);
    root->left = new_node(6);
    root ->right = new_node(11);
    root->left ->left = new_node(4);
    root->left ->right = new_node(7);
    root->left ->left ->left = new_node(2);
    root ->right ->right = new_node(15);
    root ->right ->right ->right = new_node(25);
    root ->right ->right ->left = new_node(12);

////ogarnac jak to ladnie dodawac do drzewa ta funkcja insert

    print_tree(root);
    struct node *result = malloc(sizeof(struct node));
    result = find_element(25);
    if (result == NULL)
    {
        printf("\nNie znaleziono elementu!\n");
    }
    else
        printf("\nZnaleziono element  %d!\n", result->data);


   result = insert_element(10);
    if (result == NULL)
    {
        printf("Nie udalo sie dodac elementu!\n");
    }
    else
        printf("Wstawiono   %d do  drzewa!\n", result->data);
     print_tree(root);
    return 0;
}
struct node* insert_element(int x)
{
    if (root == NULL)
        return new_node(x);

    struct node *q = root;    ///ten co przesuwamy
    struct node *previous;
    while (q != NULL)
    {
        if(x == q->data)
            return NULL;
        previous = q;

        if(x < q ->data)
            q = q->left;
        else
            q = q->right;
    }
    if (previous == NULL) //tzn ze nic nie ma
        previous  = new_node(x);
    else if(x < previous -> data)
    {
        previous->left = new_node(x);
        previous = previous->left;
    }

    else
    {
        previous->right = new_node(x);
        previous = previous->right;
    }

    return previous;

}
struct node* find_element(int x)
{
    struct node* q;
    q = root;
    while(q!= NULL)
    {
        if (x == q->data)
            return q;
        if(x < q -> data)
        {
            q = q->left;
        }
        else ////czyli idziemy w prawo, bo jest wiekszy niz aktualne q->data
        {
            q = q ->right;
        }
    }
    return q; ///to sie wykona jesli nie znajdziemy

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