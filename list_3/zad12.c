#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    printf("Podaj tekst: \n");
    char string[100];
    gets(string);
    char str[100];
    strcpy(str, string);
    char korektor[] = " ";

    char *temp = strtok(string, korektor);

    int n = 0;
    while(temp != NULL)
    {
        n++;
        temp = strtok(NULL, korektor);
    }
    char **array = malloc(sizeof(char*)*n);
    temp = strtok(str, korektor);

    for (int i = 0; i < n; ++i)
    {
        array[i] = temp;
        temp = strtok(NULL, korektor);
    }


    for (int i = n-1; i >= 0; --i) /// wypisanie tablicy
    {
      puts(array[i]);
    }

    for (int i = 0; i < n; ++i) //zwalnianie pamieci
    {
        free(array[i]);
    }
    free(array);
    return 0;
}
