#include <stdio.h>
int A (int, int); /// w sumie moglby  byc typ long do tego
int main()
{
    int x, y;
    x = 3;
    y = 3;
    int result = A (x,y);
    printf("%d ", result);
    return 0;
}
int A (int m, int n)
{
    if(m==0)
        return n+1;
    else if (m > 0 && n == 0)
        return A(m-1,1);
   else if (m > 0  && n > 0)
        return A(m-1, A(m, n-1));
}
