#include<bits/stdc++.h>

using namespace std;

bool areBracketsBalanced(string expression)
{
    stack<char> stack;

    for (char ch : expression)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            stack.push(ch);
        }
         else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (stack.empty())
            {
                return false; // Unmatched closing bracket
            }

            char top = stack.top();
            stack.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
            {
                return false; // Mismatched closing bracket
            }
        }
    }

    return stack.empty(); // Stack should be empty if all brackets are balanced
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
