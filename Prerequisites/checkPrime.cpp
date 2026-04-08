#include <bits/stdc++.h>
using namespace std;
void checkPrime(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (i != n / i && (n % (n / i) == 0))
            {
                cnt++;
            }
        }
    }
    if (cnt == 2)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}
int main()
{
    checkPrime(13);
    checkPrime(12);
    checkPrime(16);
    checkPrime(37);
    checkPrime(243);
    checkPrime(2);
    checkPrime(1);
    return 0;
}