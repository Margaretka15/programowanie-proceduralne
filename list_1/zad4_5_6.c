#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 15
int count_numbers(FILE*);
int * create_array(int size);
void complete_array(int *, FILE*, int);
void print_array(int *, int);
int count_numbers2(char *name);

int main()
{
////    zadanie 4
//    FILE * plik = fopen("plik.txt", "w");
//    if(plik == NULL)
//    {
//        printf("Nie udalo sie zaladowac pliku");
//        return 1;
//    }
//    fprintf(plik, "Programowanie Proceduralne 2021");
//    fclose(plik);

////  zadanie 5
//    FILE * plik = fopen("numbers.txt", "w");
//    srand(time(NULL));
//    if(plik == NULL)
//    {
//        printf("Nie udalo sie zaladowac pliku");
//        return 1;
//    }
//    for (int i = 0; i < 500; ++i)
//    {
//        fprintf(plik, "%d \n", rand()%1000+1);
//    }
//    fclose(plik);

////    zadanie 6
//    FILE * plik1 = fopen("numbers.txt", "r");
//    FILE * plik2 = fopen("numbers2.txt", "w");
//    if(plik1 == NULL || plik2 == NULL)
//    {
//        printf("Nie udalo sie zaladowac pliku");
//        return 1;
//    }
//    int number;
//
//    while (fscanf(plik1, "%d", &number)== 1)
//    {
//        printf("%d ", number);
//        if(number%3 == 0)
//        {
//            fprintf(plik2, "%d \n", number);
//        }
//    }
//    fclose(plik1);
//    fclose(plik2);

//////  zadanie 7
//    FILE * plik = fopen("numbers2.txt", "r");
//    if(plik == NULL)
//    {
//        printf("Nie udalo sie zaladowac pliku");
//        return 1;
//    }
//    int number_of_elements = count_numbers(plik);
//    int* array = create_array(number_of_elements);
//    plik = fopen("numbers2.txt", "r");
//    complete_array(array, plik, number_of_elements);
//    print_array(array, number_of_elements);

    printf("liczba: %d", count_numbers2("numbers2.txt"));

    return 0;
}
int count_numbers2(char *name)
{
    int x;
    int counter = 0;
    FILE *plik = fopen(name, "r");
    while (fscanf(plik, "%d", &x)== 1)
    {
        counter++;
    }
    fclose(plik);
    return counter;
}
int count_numbers(FILE* plik)
{
    int x;
    int counter = 0;
    while (fscanf(plik, "%d", &x)== 1)
    {
        counter++;
    }
    fclose(plik);
    return counter;
}
int * create_array(int size)
{
    return (int*)malloc(size*sizeof(int));
}
void complete_array(int *array, FILE*plik, int size)
{
    for (int i = 0; i < size; ++i)
    {
        fscanf(plik, "%d ", array+i);
    }
    fclose(plik);
}
void print_array(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%5d ", *(array+i));
    }
}
