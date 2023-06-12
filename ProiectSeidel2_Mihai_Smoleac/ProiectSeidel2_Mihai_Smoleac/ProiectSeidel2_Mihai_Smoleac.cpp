#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
double eps = 1e-9;
double f(double x, char caz = 'a')
{
    double vf; //valoarea functiei
    switch (caz)
    {
    case 'a': vf = x + 7; break;//polinom de grad 1
    case 'b': vf = x * x + 10; break; //polinom de grad 2
    case 'c': vf = x * x * x + 10; break; //polinom de grad 3, simposon gr 3, 4, 5
    case 'd': vf = sin(x) / x; break; //varianta de la prima lectie
    }

    return vf;
}
double df2(double x, char caz = 'a')
{
    double vf;
    switch (caz)
    {
    case 'a': vf = 0; break;
    case 'b': vf = 2; break;
    case 'c': vf = 3 * 2 * x; break;
    }

    return vf;
}
double Trapez(double a, double b, char caz = 'a')
{
    return (b - a) * (f(a, caz) + f(b, caz)) / 2;
    //return (b-a) * (f(a)+4*(f(a+b)*0.5), caz) + f(b, caz)/6;
}
double TrapezGenerala(double a, double b, char caz)
{
    return 1;
}
double Runge(double a, double b, int& n, char caz)
{
    int i;
    double h, x, S0, S;

    n = 1; h = b - a;
    S = Trapez(a, b, caz);
    do
    {
        S0 = S;
        h /= 2; n *= 2;
        S = 0;
        x = a;
        for (i = 1; i <= n; i++)
        {
            S = S + Trapez(x, x + h, caz);
            x += h;
        }
    } while (fabs(S - S0) > eps);

    return S;
}
int main()
{
    int k, i, n;
    double a = 1, b = 5, S0, S, R, I;
    cout << "Pr Nr 4!" << endl;
    //cazul a
    S = Trapez(a, b);
    printf("\n a). Val. apr. a integralei, care coincide cu val. exacta: %16.12lf", S);
    //cazul b
    S = Trapez(a, b, 'b');
    R = pow(b - a, 3) * df2(a, 'b') / 12;
    I = S - R;
    printf("\n b).\t Val. apr. a integralei: %16.12lf", S);
    printf("\n\t Val. termenului de rest: %16.12lf", R);
    printf("\n\t Val. exacta: %16.12lf", I);

    // caz C
    S = Trapez(a, b, 'c');
    R = pow(b - a, 3) * df2(b, 'c') / 12;
    I = S - R;
    printf("\n c).\t Valoarea aproximativa a integralei: %16.12lf", S);
    printf("\n \t Valoarea maximala a termenului de rest: %16.12lf", R);
    printf("\n \t Valoarea exacta: %16.12lf <= I <= %16.12lf", I, S);

    // caz D
    S = Runge(a, b, n, 'c');
    printf("\n d).\t Valoarea aproximativa a integralei: S%d = %16.12lf", n, S);
    return 0;
}
