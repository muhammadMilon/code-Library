#include<bits/stdc++.h>

using namespace std;

bool areBracketsBalanced(string expression)
{
    stack<char> bracketStack;

    for (char ch : expression)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            bracketStack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (bracketStack.empty())
            {
                return false; // Unmatched closing bracket
            }

            char top = bracketStack.top();
            bracketStack.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
            {
                return false; // Mismatched closing bracket
            }
        }
    }

    return bracketStack.empty();  // Stack should be empty if all brackets are balanced
}

int main() {
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
