
#include <iostream>

using namespace std;

struct Interval
{
    double left;
    double right;
} rada[5];
double eps = 1e-9;

double f(double x)
{
    return x * x * x + 6 * x * x - 7 * x - 42;
}


int Separation(double A, double B, double h);
double Bisection(double a, double b, int& k);

int main()
{
    int i, n;
    double A = -7;
    double B = 3;
    double h = 0.05;
    double x;
    printf("Proiect nr. 1 la Analiza numerica\nElaborata de Smoleac Mihai\n\n");
    n = Separation(A, B, h);
    for (i = 0; i < n; i++)
    {
        printf("O solutie separata se afla pe [%2f; %2f]\n", rada[i].left, rada[i].right);
    }
    printf("\n\n\n");
    return 0;
}

int Separation(double A, double B, double h)
{
    int n = 0;
    double x0 = A, x;
    do {
        x = x0 + h;
        //if(f(x)==0)...
        if (f(x0) * f(x) < 0) {
            rada[n].left = x0;
            rada[n].right = x;
            n++;
        }
        x0 = x;

    } while (x < B);
    return n;
}