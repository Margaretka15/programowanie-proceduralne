#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack{
    int size;
    int capacity;
    struct position* array;
};
struct position{
    int x;
    int y;
};
enum direction{
    EAST,
    WEST,
    NORTH,
    SOUTH
};
struct stack create_stack();
void push(struct stack *s, struct position x);
void pop(struct stack* s);
void print_stack(struct stack* s);
bool traverse_labyrinth(int labyrinth[10][18], struct stack* s, enum direction);
int main()
{
    struct stack s = create_stack();
    FILE *file = fopen("labirynt.txt", "r");

    int labyrinth[10][18];
    char *t = malloc(sizeof(char) * 19);
    size_t t_size = 18;
    for (int i = 0; i < 10; ++i)
    {

        getline(&t, &t_size, file);
        for (int j = 0; j < 18; ++j)
        {
            labyrinth[i][j] = t[j];
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 18; ++j)
        {
            printf("%c", labyrinth[i][j]);
        }
        printf("\n");
    }

    struct position p;
    for (int i = 0; i < 10; ++i)
    {
        if(labyrinth[i][0] == '@')
        {
            p.x = 0;
            p.y = i;
            push(&s,p);
            break;
        }
    }
    traverse_labyrinth(labyrinth, &s, EAST);

    return 0;

}
bool traverse_labyrinth(int labyrinth[10][18], struct stack* s, enum direction d)
{
    print_stack(s);
    struct position p = s->array[s->size - 1];
    if(p.x == 17)
    {
        print_stack(s);
        return true;
    }

    if(labyrinth[p.y][p.x + 1] == '@' && d != WEST)
    {
        p.x+=1;
        push(s, p);
        if(traverse_labyrinth(labyrinth, s, EAST))
        {
            return true;
        }
        p.x-=1;
        pop(s);
    }
    if(labyrinth[p.y + 1][p.x] == '@' && d != NORTH)
    {
        p.y+=1;
        push(s, p);
        if(traverse_labyrinth(labyrinth, s, SOUTH))
        {
            return true;
        }
        p.y-=1;
        pop(s);
    }
    if(labyrinth[p.y][p.x - 1] == '@' && d != EAST)
    {
        p.x-=1;
        push(s, p);
        if(traverse_labyrinth(labyrinth, s, WEST))
        {
            return true;
        }
        p.x+=1;
        pop(s);
    }
    if(labyrinth[p.y - 1][p.x] == '@' && d != SOUTH)
    {
        p.y-=1;
        push(s, p);
        if(traverse_labyrinth(labyrinth, s, NORTH))
        {

            return true;
        }
        p.y+=1;
        pop(s);
    }

    return false;
}
void pop(struct stack* s)
{
    s->size--;
    if(s->size <= s->capacity/4)
    {
        s->capacity /= 2;
        s->array = realloc(s->array, s->capacity * sizeof(struct position));
    }
}
void push(struct stack *s, struct position x)
{
    if(s->size == s->capacity)
    {
        s->capacity *= 2;
        s->array = realloc(s->array, s->capacity * sizeof(struct position));
    }
    s->array[s->size] = x;
    s->size++;
}
struct stack create_stack()
{
    struct stack s;
    s.size = 0;
    s.capacity = 1;
    s.array = malloc(sizeof (struct position) * 1);
    return s;
}
void print_stack(struct stack* s)
{
    for (int i = 0; i < s->size; ++i)
    {
        printf("{%d, %d}", s->array[i].x, s->array[i].y);
    }
    printf("\n\n");
}