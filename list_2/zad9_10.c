#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void create_file();
int **create_array();
void print_array(int*, int);
int main()
{
    srand(time(NULL));
    create_file();
    int **array = create_array();
    return 0;
}
void create_file() ////zadanie 9
{
    FILE* plik = fopen("plik.txt", "w");
    int n = rand()%15+1;
    fprintf(plik, "%d\n", n);

    int m;
    int number;
    for (int i = 0; i < n; ++i)
    {
        m = rand()%10+1;
        fprintf(plik, "%d\n", m);
        for (int j = 0; j < m; ++j)
        {
            number = rand()%1001-500;
            fprintf(plik, "%d ", number);
        }
        fprintf(plik, "\n");
    }
    fclose(plik);
}
int **create_array() ////zadanie 10
{
    FILE* plik = fopen("plik.txt", "r");
    int **array;
    int n, m;
    fscanf(plik, "%d", &n);
    array = (int**)malloc(n * sizeof (int*));
    for (int i = 0; i < n; ++i)
    {
        fscanf(plik, "%d", &m);
        *(array+i) = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; ++j)
        {
            fscanf(plik, "%d", (*(array+i)+j));
        }
        print_array(array[i], m);
        printf("\n");
    }

    fclose(plik);
    return array;
}
void print_array(int*array, int  size)
{
    for (int i = 0; i < size; ++i)
    {
       printf("%5d", array[i]);
    }
}
