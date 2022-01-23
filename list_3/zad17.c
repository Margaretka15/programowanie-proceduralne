#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int count_word_in_line(char * );

int main()
{
    int n = 100;
    char *string = malloc(sizeof (char) * n);

    int count_words = 0;
    FILE * plik = fopen("plik.txt", "r");

    while(NULL != fgets(string, n, plik))
    {
        count_words+=count_word_in_line(string);
    }
    printf("Liczba slow w podanym tekscie wynosi: %d", count_words );

    return 0;
}
int count_word_in_line(char * string)
{
    char korektor[] = " ";
    int count = 0;
    char *temp = strtok(string, korektor);
    while(temp != NULL)
    {
        count++;
        temp = strtok(NULL, korektor);

    }
    return count;
}