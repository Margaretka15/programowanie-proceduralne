#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void *my_strcat(char*, char*);
char * find_char(char *, char);
void reverse_string(char *);
void remove_spaces(char*);
void get_word();
void print_three (char *);


int main()
{

/////zadanie 1
//    char word1[] = "Babeczka ";
//    char word2[]= "z kremem ";
//    char word3[] = "czekoladowym";
//    my_strcat(word1, word2); /////przyklejamy word2 do word1
//    my_strcat(word1, word3); /////przyklejamy word3 do word1 (wiec sa juz sklejone wszystkie trzy)
//    printf("%s", word1);
/////zadanie 2

//    char word[] = "jablko";
//    char *a = find_char(word, 'l');
//    if(a == NULL)
//        printf("Nie znaleziono znaku!");
//    else
//        printf("%c", *a);

/////zadanie 3
//    char word[] = "jablko";
//    reverse_string(word);
//    printf("%s", word);

//////zadanie 4
//    char word[] = "ala ma kota i pieska";
//    remove_spaces(word);
//    printf("%s", word);

/////zadanie 5
//    get_word();

////zadanie 6
    print_three("kotek");
    return 0;
}
void print_three (char* str)
{
    for (int i = 0; i < 3; ++i)
    {
        if(str[i] == '\0')
            break;
        printf("%c", str[i]);
    }
}
void get_word() /////zadanie 5
{
    char word[100];
    printf("Podaj slowa: \n");
//    scanf("%s", word);   ///////////scanf tak dziala - wczytuje do bialego znaku :)
    gets(word);
    for (int i = 0; word[i]!='\0'; ++i)
    {
        if(word[i] == ' ')
        {
         word[i] = '\0';
         break;
        }
    }

    printf("\n\n%s", word);
}
void remove_spaces(char* string) /////zadanie 4
{
    int count = 0;
    for (int i = 0; string[i]!='\0'; ++i)
    {
        if(string[i] != ' ')
        {
            string[count++]=string[i];
        }
    }
    string[count] = '\0';
}
void reverse_string(char *string) /// zadanie 3 (w praktyce zwykle odwracanie tablicy)
{
    char temp;
    int size = strlen(string);
    for (int i = 0; i < size/2; ++i)
    {
        temp = string[i];
        string[i] = string[size - i - 1];
        string[size - i - 1] = temp;
    }
    printf("%d ", size);
}
char* find_char(char* string, char a) ///zadanie 2
{
    char *p = string;
    while (*p != '\0')
    {
        if (*p==a)
        return p;
        p++;
    }
    return NULL;
}
void *my_strcat(char* destination, char* word) //////zadanie 1
{
    char *start = destination;
    char *w = word; ////
    while (*start != '\0') ////znajduję koniec łancucha, do ktorego bede dolaczac drugi
    {
        start++;
    }
    while (*w != '\0')
    {
        *start++ = *w++;
    }
    *start = '\0';
}