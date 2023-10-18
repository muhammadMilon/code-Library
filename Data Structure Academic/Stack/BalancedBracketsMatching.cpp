#include<bits/stdc++.h>

using namespace std;

bool areBracketsBalanced(string expression)
{
    stack<char> st;

    for (char ch : expression)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
        else if (ch == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                return false;
            }
            st.pop();
        }
        else if (ch == '}')
        {
            if (st.empty() || st.top() != '{')
            {
                return false;
            }
            st.pop();
        }
    }

    return st.empty(); // Stack should be empty if all brackets are balanced
}

int main() 
{
    string expression;
    cout << "Enter an expression with brackets: ";
    cin >> expression;

    if (areBracketsBalanced(expression))
    {
        cout << "Brackets are balanced." << endl;
    }
    else
    {
        cout << "Brackets are not balanced." << endl;
    }

    return 0;
}
