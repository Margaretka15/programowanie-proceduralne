#include <stdio.h>
double power(double , int );
int gcd(int, int);
int main()
{
///zadanie 1
//    double x = 5;
//    int y = 4;
//    double result = power(x,y);
//    printf("%.2f do potegi %d = %.2f\n", x, y, result);

////zadanie 2
//    int x = 20;
//    int y = 40;
//    printf("Najwiekszy wspolny dzielnik liczb %d i %d to %d", x, y, gcd(x,y));

////zadanie 4
/// jak wywołamy maina tak po prostu bez warunku granicznego, to mamy nieskończoną rekurencję
//    static int a = 0;
//    a++;
//    printf("%d\n", a);
//    if(a != 10)
//        main();
//    return 0;

////zadanie 5 i 6 - trzeba stwierdzić co robi kod podany w treści zadania
////zad 5 - w sumie nwm
///zad 6 - realizuje mnożenie liczb a i b - funkcja wywoływana jest b razy

    return 0;
}
double power(double base, int exponent) /// zadanie 1
{
   if(exponent!=1)
   {
       return base * power(base, exponent-1);
   }
   else
       return base;
}
int gcd(int x, int y) /////zadanie 2
{
   if(x==0)
   {
       return y;
   }
   else
       return gcd(y%x, x);
}
