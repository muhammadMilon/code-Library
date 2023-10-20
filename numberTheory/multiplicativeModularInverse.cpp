#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const int sz = 1e5 + 5, mod = 1e9 + 7;

// Function to calculate the greatest common divisor (GCD) using the extended Euclidean algorithm
int gcdExtended(int a, int m, int &x, int &y) // In the function int gcdExtended(int a, int m, int &x, int &y), the & symbol is used to pass x and y by reference, rather than by value
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return m;
    }

    int x1, y1;
    int gcd = gcdExtended(m % a, a, x1, y1);

    x = y1 - (m / a) * x1;
    y = x1;

    return gcd;
}

// Function to find the multiplicative modulo inverse of 'a' modulo 'm'
int modInverse(int a, int m)
{
    int x, y;
    int gcd = gcdExtended(a, m, x, y);

    if (gcd != 1)
    {
        // Modular inverse does not exist if a and m are not coprime
        cout << "Multiplicative Modulo Inverse does not exist." << endl;
        return -1; // Invalid
    }
    else
    {
        // Ensure the result is positive
        int result = (x % m + m) % m;
        return result;
    }
}

int main()
{
    int a, m;
    cout << "Enter the values for 'a' and 'm' to find the multiplicative modulo inverse (a^-1 mod m): ";
    cin >> a >> m;

    int inverse = modInverse(a, m);
    if (inverse != -1)
    {
        cout << "The multiplicative modulo inverse of " << a << " modulo " << m << " is: " << inverse << endl;
    }

    return 0;
}
