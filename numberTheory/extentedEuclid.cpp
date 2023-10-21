#include <bits/stdc++.h>
using namespace std;

int x,y,d;

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

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        extendedEuclid(a,b);
        printf("X= %d Y=%d D=%d\n",x,y,d);
    }
}

//  https://onlinejudge.org/external/101/10104.pdf
