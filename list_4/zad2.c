#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int capacity;
    int *array;

};
struct stack create_stack();
void push(struct stack *s, int x);
void pop(struct stack* s);
void print_stack(struct stack* s);
int main()
{
    struct stack s = create_stack();
    push(&s, 5);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    push(&s, 4);
    push(&s, 7);
    print_stack(&s);
    pop(&s);
    pop(&s);
    print_stack(&s);

    return 0;

}
void pop(struct stack* s)
{
    s->size--;
    if(s->size <= s->capacity/4)
    {
        s->capacity /= 2;
        s->array = realloc(s->array, s->capacity * sizeof(int));
    }
}
void push(struct stack *s, int x)
{
    if(s->size == s->capacity)
    {
        s->capacity *= 2;
        s->array = realloc(s->array, s->capacity * sizeof(int));
    }
    s->array[s->size] = x;
    s->size++;
}
struct stack create_stack()
{
    struct stack s;
    s.size = 0;
    s.capacity = 1;
    s.array = malloc(sizeof (int) * 1);
    return s;
}
void print_stack(struct stack* s)
{
    for (int i = 0; i < s->size; ++i)
    {
        printf("%5d", s->array[i]);
    }
    printf("\n\n");
}