#include <stdio.h>
#include <stdlib.h>
////struct i tablica niepotrzebne - ale moga sie przydac jesli chcielibysmy rysowac kolejne etapy ukladania
struct tower
{
    char name;
    int* array;
};


void move_tower(struct tower* A, struct tower* B, struct tower* C, int n)
{
    if(n == 1)
    {
        printf("%c->%c\n", A->name, C->name);
        A->array[0] = 0;
        C->array[0] = 1;
    }
    else
    {
        move_tower(A, C, B, n-1);
        printf("%c->%c\n", A->name, C->name);
        A->array[n-1] = 0;
        C->array[n-1] = 1;
        move_tower(B, A, C, n-1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int* A = (int*)malloc(n*sizeof(int));
    int* B = (int*)calloc(n, sizeof(int));
    int* C = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        A[i] = 1;
    }

    struct tower tower_a = {'A', A};
    struct tower tower_b = {'B', B};
    struct tower tower_c = {'C', C};

    move_tower(&tower_a, &tower_b, &tower_c, n);
    free(A);
    free(B);
    free(C);
    return 0;
}