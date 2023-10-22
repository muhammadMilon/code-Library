#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int sz = 1e5 + 5, mod = 1e9 + 7;

string longestCommonPrefix(vector<string>& strings)
{
    if (strings.empty())
    {
        return "";
    }

    // Find the shortest string in the vector
    int minLen = strings[0].length();
    for (const string& s : strings)
    {
        minLen = min(minLen, static_cast<int>(s.length()));
    }

    string lcp = "";

    for (int i = 0; i < minLen; i++)
    {
        char currentChar = strings[0][i];

        // Check if the character matches in all strings
        bool allMatch = true;
        for (const string& s : strings)
        {
            if (s[i] != currentChar)
            {
                allMatch = false;
                break;
            }
        }

        if (allMatch)
        {
            lcp += currentChar;
        }
        else
        {
            break;
        }
    }

    return lcp;
}

int main()
{
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strings(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter string " << i + 1 << ": ";
        cin >> strings[i];
    }

    string result = longestCommonPrefix(strings);
    if(longestCommonPrefix(strings).empty())
    {
        cout<< "The LCP is empty." << endl;
    }
    else
    {
         cout << "LCP " << ": " << result << endl;
    }

    return 0;
}
