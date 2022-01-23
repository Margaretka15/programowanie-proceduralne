#include <stdio.h>
#include <string.h>
void print_latin_word(char*);
int main()
{
    char string[] = "brace yourself  winter is coming";

    print_latin_word(string);
    return 0;
}
void print_latin_word(char* string)
{
    char korektor[] = " ";
    char * temp;
    char first_letter[2];
    first_letter[1] = '\0'; ///////////////robię osobny lancuch na pierwsza litere
    temp = strtok(string, korektor);
    char result[150] = "";
    while( temp != NULL )
    {
        first_letter[0] = temp[0];
        for (int i = 0; i < strlen(temp); ++i)
        {
            temp[i] = temp[i+1];
        }
        strcat(result, temp);
        strcat(result, first_letter);
        strcat(result, "ay ");

        temp = strtok( NULL, korektor );
    }
    printf( "%s\n", result );  //// troche inaczej niz w poleceniu, bo trzeba bylo wypisywac slowa osobno - ja polaczylam w jeden lancuch
}