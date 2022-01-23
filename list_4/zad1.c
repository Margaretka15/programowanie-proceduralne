#include <stdio.h>
#include <stdlib.h>
struct node{
    int dane;
    struct node *next;
};
void push(struct node**, int);
void print_stack(struct node*);
void pop(struct node** top);
int main()
{
    struct node* top = malloc(sizeof(struct node));
    top = NULL;
    push(&top, 5);

    push(&top, 4);

    push(&top, 3);

    pop(&top);

    print_stack(top);


    return 0;
}
void push(struct node** top, int x)
{
    struct node *temp = malloc(sizeof(struct node));

    temp->dane = x;

    temp->next = *top;

    *top = temp;
}
void pop(struct node** top)
{
    if(top!= NULL)
    {
        struct node* temp;
        temp = (*top)->next;
        free(*top);
        *top = temp;
    }
    else
        printf("Stack is empty");
}
void print_stack(struct node* head)
{
    struct node* ptr;
    ptr = head;
    while(ptr!= NULL)
    {
        printf("%d", ptr->dane);
        ptr= ptr->next;
    }
}
