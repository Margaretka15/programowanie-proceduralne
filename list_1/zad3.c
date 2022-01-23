#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble_sort(int *, int *);
int* create_array(int);
void print_array(int *, int);
void swap(int *, int *);
int main()
{
//  zadanie 3

    int n = 50;
    srand(time(NULL));
    int *p = create_array(n);
    print_array(p, n);
    bubble_sort(p, p+n-1);
    printf("\n\n Sorted array: \n");
    print_array(p, n);
    free(p);
    return 0;
}
int* create_array(int size)
{
    int* p =  malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        *(p+i) = rand()%201 - 100;
    }
    return p;
}
void print_array(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if(i %10 == 0)
            printf("\n");
        printf("%5d", *(array + i));
    }

}
void bubble_sort(int *first, int *last)
{
    int size = last - first + 1;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if(*(first + j) > *(first + j + 1))
                swap(first+j, (first + j + 1));
        }
    }
}
void swap(int *a, int *b)
{
    int t;
    t = *b;
    *b = *a;
    *a = t;
}