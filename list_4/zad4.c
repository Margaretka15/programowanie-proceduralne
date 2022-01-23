#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct queue{
    struct node* head;
    int size;
};
struct queue create_queue();
void enqueue(struct queue *, int);
int dequeue(struct queue *);
void print_queue(struct queue *);
int main()
{

    struct queue q = create_queue();
    enqueue(&q, 5);
    enqueue(&q, 8);

    enqueue(&q, 7);

    print_queue(&q);

    dequeue(&q);
    dequeue(&q);
    print_queue(&q);


    return 0;
}
struct queue create_queue()
{
    struct queue q;
    q.head = NULL;
    q.size = 0;
    return q;
}
void enqueue(struct queue *q, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = q->head;
    q->head = temp;
    q->size++;
}
int dequeue(struct queue *q)
{
    struct node* temp = q->head;
    for (int i = 0; i < q->size - 2; ++i)
    {
        temp = temp -> next;
    }
    int a = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    q->size--;
    return a;


}
void print_queue(struct queue *q)
{
    struct node* temp = q->head;
    for (int i = 0; i < q->size ; ++i)
    {
        printf("%d ", temp->data);
        temp = temp -> next;
    }
    printf("\n\n");
}