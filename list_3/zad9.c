#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    char *article[] = {"ten", "pewien", "jakis"};
    char *noun[] = {"kot", "pies", "chlopak", "czlowiek", "oszust"};
    char *verb[]= {"ukradl", "pozyczyl", "kupil", "uciekl"};
    char *preposition[] = {"za", "pod", "nad"};

    int a = rand()%sizeof(article)/sizeof(article[0]);
    int n = rand()%sizeof(noun)/sizeof(noun[0]);
    int v = rand()%sizeof(verb)/sizeof(verb[0]);
    int p = rand()%sizeof(preposition)/sizeof(preposition[0]);
//    printf("%d %d %d %d", a, n, v, p);

    char result[150]="";
    strcat(result, article[a]);
    strcat(result, " ");
    strcat(result, noun[n]);
    strcat(result, " ");
    strcat(result, verb[v]);
    strcat(result, " ");
    strcat(result, preposition[p]);

    puts(result);
    return 0;
}


