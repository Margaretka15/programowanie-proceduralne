#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int how_many_characters(char*, char);
void count_alphabet_characters(char*, int*, char*);
void print_result(char*, int*);
int main()
{

//////zadanie 16

    FILE * plik = fopen("plik.txt", "r");

    int n = 50;
    char *line = malloc(sizeof(char) * n);

    int count [26] = {0};
    char alphabet [27];
    for(int i = 0; i < 26; i++) ///wypelniam tablice alphabet literami
    {
        alphabet[i] = (char)(97 + i);
    }
    alphabet[26] = '\0';
    while(NULL != fgets(line, n, plik))
    {

        count_alphabet_characters(line, count, alphabet);
    }

    char string[] = "bobo i kaszka";

    print_result(alphabet, count);

        fclose(plik);

    return 0;
}
void count_alphabet_characters(char* string, int* count, char* alphabet)
{

    for(int i =0; string[i] != '\0'; i++)
    {
        if(string[i] <= 'z' && string[i] >= 'a')
        {
            count[(int)string[i] -97] ++;
        }
        else if (string[i] <= 'Z' && string[i] >= 'A')
        {
            count[(int) string[i] - 97 + 32]++;
        }
    }
}
void print_result(char*alphabet, int* count)
{
    printf("\nRezultat: \n\n");
    for(int i = 0; i < 26; i++)
    {
        printf("%c ----- %2d\n",alphabet[i], count[i]);
    }
}
