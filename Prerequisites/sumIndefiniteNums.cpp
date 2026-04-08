#include <bits/stdc++.h>
using namespace std;
int printSum(int sum, int x)
{
    sum += x;
    int z;
    cout << "Enter next integer : ";
    cin >> z;
    if (z != 0)
    {
        printSum(sum, z);
    }
    else if (z == 0)
    {
        return sum;
    }
}
int main()
{
    int y;
    cout << "Enter integer : ";
    cin >> y;
    int a = printSum(0, y);
    cout << "The sum is : " << a << endl;
    return 0;
}