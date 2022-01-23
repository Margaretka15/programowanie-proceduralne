#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    //////tu wlasciwie nie jestem pewna czy tak trzeba bylo to zrobic, jakos jest :/
    char number[14] = "(530)156-9876";
   //// scanf("%s", number);
    puts(number);
    char korektor[] = "()-";
    char* kierunkowy = strtok(number, korektor);
    char* poczatek = strtok(NULL, korektor);
    char* koncowka = strtok(NULL, korektor);

    char *n = strcat(poczatek, koncowka);
//    puts(n);
//    puts(kierunkowy);

    int k = atoi(kierunkowy);
    printf("%d", k);

    long int x= atoi(n);
    printf(" %d", x);
    printf("\n\n");

    return 0;
}
