#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int **create_array(int, int);
void complete_array(int **,int, int);
void print_array(int** p, int m, int n);
void  print_sum_rows(int **, int, int);
void  print_sum_columns(int **, int, int);
int main()
{
    int x = 3;
    int y = 5;
    srand(time(NULL));
    int **tab = create_array(x,y);
    complete_array(tab, x, y);
    print_array(tab, x, y);
    print_sum_rows(tab, x, y);
    print_sum_columns(tab, x, y);
    return 0;
}
int **create_array(int m, int n)
{
    int **p;
    p = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i)
    {
        *(p+i) = (int*)malloc(sizeof(int) * n);
    }
    return p;
}
void complete_array(int** p, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            *(*(p+i)+j) = rand()%10 +1;
        }
    }
}
void print_array(int** p, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%5d", *(*(p+i)+j));
        }
        printf("\n");
    }
}
void  print_sum_rows(int **p, int m, int n)
{
    int sum;
    for (int i = 0; i < m; ++i)
    {
        sum = 0;
        for (int j = 0; j < n; ++j)
        {
            sum+= *(*(p+i)+j);
        }
        printf("Suma wiersza nr %d:%d\n", i+1, sum);
    }
}
void  print_sum_columns(int **p, int m, int n)
{
    int sum;
    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        for (int j = 0; j < m; ++j)
        {
            sum+= *(*(p+j)+i);
        }
        printf("Suma kolumny nr %d:%d\n", i+1, sum);
    }
}