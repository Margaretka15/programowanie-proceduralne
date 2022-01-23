#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int how_many_phrases(char*, char*);
int hov_many_characters(char*, char);
int main()
{
///////    zadanie 13
//    char string[50];
//    char word[10];
//    printf("Podaj zdanie:\n");
//    gets(string);
//    printf("Podaj slowo: \n");
//    gets(word);
//
//    char * search_ptr = strstr( string, word );
//  //  printf( "Znaleziono lancuch: %s\n", search_ptr );
//    while (search_ptr != NULL)
//    {
//
//        printf( "Znaleziono lancuch: %s\n", search_ptr);
//        search_ptr = strstr(search_ptr+1, word);
//    }
//////zadanie 14

    FILE * plik = fopen("plik.txt", "r");

    int n = 50;
    char *line = malloc(sizeof(char) * n);
    char word[10];

    printf("Podaj slowo: \n");
    gets(word);
    int sum1 = 0;

    int sum2 = 0;
    char letter = 'e';
    while(NULL != fgets(line, n, plik))
    {
        sum1 += how_many_phrases(line, word); ///14
        sum2 += hov_many_characters(line, letter); ///15
        puts(line);
    }
    printf("Liczba wystapien szukanej frazy: %d \n", sum1);
    printf("Liczba wystapien szukanej litery %d", sum2);

    fclose(plik);

    return 0;
}
int how_many_phrases(char* line, char* word) ///// zadanie 14
{
    int count = 0;
    char * search_ptr = strstr( line, word );
    while (search_ptr != NULL)
    {
        count++;
       // printf( "Znaleziono lancuch: %s\n", search_ptr);
        search_ptr = strstr(search_ptr+1, word);
    }
    return count;
}
int hov_many_characters(char* line, char  character) ////zadanie 15
{
    int count = 0;
    char * search_ptr = strchr( line, character );
    while (search_ptr != NULL)
    {
        count++;
        // printf( "Znaleziono lancuch: %s\n", search_ptr);
        search_ptr = strchr(search_ptr+1, character);
    }

    return count;

}