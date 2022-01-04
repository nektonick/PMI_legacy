#include <iostream>
#include <vector>
#include "fstream"
using namespace std;
long long int convert(long long int a, unsigned long long int p)
{
    while(a < 0)
        a += p;
    a %= p;
    return a;
}
long long int division(long long int a, long long int b, unsigned long long int p)
{
    int i = 1;
    while((b * i) % p != 1)
    {
        i++;
        cout << i << endl;
    }
    return (a * i) % p;
}
long long int lagrange(long long int a, long long int* x, long long int* y, int n, unsigned long long int p)
{
    long long int result = 0;
    long long int basicsPol;
    for (int i = 0; i < n; i++)
    {
        basicsPol = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                basicsPol *= division(convert(a-x[j], p), convert(x[i]-x[j], p), p);
                basicsPol= convert(basicsPol, p);
            }
        }
        result += (convert(y[i], p) * convert(basicsPol, p));
        result = convert(result, p);
    }
    return result;
}
int main()
{
    unsigned long long int p; // простой модуль p
    ifstream file("D:\\lagrange_tests\\test4.in");
    if (!file.is_open())
    {
        return 0;
    }
    file >> p;
    long long int a; // текущая точка
    file >> a;
    int N; // количество точек
    file >> N;
    auto* x = new long long int[N];
    auto* y = new long long int[N];
    for (int i = 0; i < N; i++)
    {
        file >> x[i] >> y[i];
    }
    cout << lagrange(a, x, y, N, p);
}