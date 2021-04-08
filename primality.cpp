// C++ program to perform primality test implementing monte carlo(rabin miller)
#include <bits/stdc++.h>
using namespace std;
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

bool MonteCarlo(int d, int n)
{
    int a = 2 + rand() % (n - 4);
    int x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}

bool isPrime(int n, int k)
{

    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
         if (!MonteCarlo(d, n))
              return false;

    return true;
}

// Driver program
int main()
{
    int k = 4;
    cout<<"SHEEMA ZAINAB MI 19MID0014"<<endl;
    cout << "All prime numbers   smaller than 10: \n";
    for (int n = 1; n < 10; n++)
       if (isPrime(n, k))
          cout << n << " ";

    return 0;
}
