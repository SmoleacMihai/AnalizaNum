#include <iostream>
double eps = 1e-9;

double f(double x, char caz='a') {
    double vf;
    switch (caz)
    {
        case 'a': vf = x + 5; break;
        case 'b': vf = x * x + 5; break;
        case 'c': vf = x * x * x + 5; break;
        case 'd': vf = sin(x) / x; break;
        default:
            break;
    }
    return vf;
    
}

double df4(double x, char caz = 'a') {
    double vf;
    switch (caz)
    {
        case 'a': vf = 0; break;
        case 'b': vf = 2; break;
        case 'c': vf = 3 * 2 * x; break;
        default:
            break;
    }
    return vf;
}

double Trapez(double a, double b, char caz='a') {
    return (b - a) * (f(a, caz) + f(b, caz)) / 2;
}

double TrapezGeneral(double a, double b, char caz) {
    return 1;
}

double Runge(double a, double b, int &n, char caz) {
    int i;
    double S0, S = 0, h, x;
    n = 1; h = b - a;
    S0 = Trapez(a, b, caz);
    do {
        S0 = S;
        h /= 2;
        n *= 2;
        S = 0;
        x = a;
        for (i = 1; i <= n; i++) {
            S = S + Trapez(x, x + h, caz);
            x += h;
        }
    } while (fabs(S - S0) > eps);
    return S;
}

int main()
{
    int k, i, n;
    double a = 1, b = 5, S0, S, I, R;


    printf("Proiect nr. 4!\n");
    
    S = Trapez(a, b);
    printf("\n a) Val aproximativa care coincide cu valoarea exacta %16.12lf", S);
    
    S = Trapez(a, b, 'b');
    R = pow(b - a, 3) * df4(a, 'b') / 12;
    I = S - R;
    printf("\n b) Val aproximativa a intervalei %16.12lf", S);
    printf("\n\t  Val max. a termenului de rest %16.12lf", R);
    printf("\n\t  Val exacta %16.12lf", I);

    S = Runge(a, b, k, 'c');
    R = pow(b - a, 3) * df4(a, 'c') / 12;
    I = S - R;
    printf("\n c) Val aproximativa a intervalei %16.12lf", S);
    printf("\n\t  Val max. a termenului de rest %16.12lf", R);
    printf("\n\t  Val exacta %16.12lf", I);

    return 0;
}
