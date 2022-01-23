#include <stdio.h>
int how_many(int [], int, int); //zadanie 1
double *max(double [], int); //zadanie 2
int sum(int array[], int size);
int main()
{
    //zadanie 1
//    int array[5] = {1,2,7,8,5};
//    int k = 5;
//    printf("Liczba elementow wiekszych od %d wynosi %d.", k, how_many(array, 5, k));
//    printf("Suma elementow tablicy %d",  sum(array, 5));

   // zadanie 2
    double array[5] = {0,15,0,9,2};
    printf("Wartosc maksymalna w tablicy wynosi %f.", *(max(array, 5)));


    return 0;
}

int how_many(int array[], int size, int k) //zadanie 1
{
    int count = 0;
    while(size > 0)
    {
        count += (*(array++) > k);
        size--;
    }
    return count;
}
int sum(int array[], int size)
{
    int suma = 0;
    while(size > 0)
    {
        suma += *(array++);

        size--;
    }
    return suma;
}
double *max(double array[], int size) // zadanie 2
{
    double *max = array;
    while(size>0)
    {
        if(*(max) < *(array))
            max = array;
        array++;
        size--;
    }
    return max;
}

