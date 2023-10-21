#include <bits/stdc++.h>
using namespace std;

int x, y, d;

void extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int modInverse(int a, int m)
{
    extendedEuclid(a, m);
    if (d != 1)
    {
        return -1;
    }
    x = (x % m + m) % m;
    return x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, m;
        cin >> a >> m;
        int inverse = modInverse(a, m);
        if (inverse == -1)
        {
            cout << "Not Exist" << endl;
        }
        else
        {
            cout << inverse << endl;
        }
    }

    return 0;
}
