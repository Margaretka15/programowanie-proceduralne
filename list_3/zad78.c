#include <stdio.h>
#include <string.h>
void compare_strings(char*, char*);
void compare_parts_of_strings(char*, char*, int);
int main()
{

//////zadanie 7 i 8
    char word1[50];
    char word2[50];
    int n;
    printf("Podaj pierwszy lancuch: \n");
    gets(word1);
    printf("Podaj drugi lancuch: \n");
    gets(word2);
    compare_strings(word1, word2); ///zad7
    printf("Podaj liczbe znakow, ktore chcesz sprawdzic: \n"); ///zad8
    scanf("%d", &n);
    compare_parts_of_strings(word1, word2, n);

    return 0;
}
void compare_parts_of_strings(char* str1, char* str2, int n)
{
    if( strncmp( str1, str2, n ) == 0 )
        printf( "Badane wycinki lancuchow znakow sa rowne.\n" );
    else if  ( strncmp( str1, str2, n ) < 0 )
        printf( "Wycinek o dlugosci %d pierwszego lancucha jest mniejszy niz wycinek drugiego\n", n );
    else
        printf( "Wycinek o dlugosci %d pierwszego lancucha jest wiekszy  od wycinka drugiego\n", n );
}

void compare_strings(char* str1, char* str2) /////zadanie 7
{
    if (strcmp(str1, str2) == 0)
        printf("Lancuchy s1 i s2 sa takie same");
    else if (strcmp(str1, str2) < 0)
        printf("Lancuch pierwszy jest mniejszy niz drugi");
    else
        printf("Lancuch drugi jest mniejszy niz pierwszy ");
}