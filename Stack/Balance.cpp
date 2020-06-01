#include <iostream>
#include <string>
using namespace std;

class StackOperations
{
    char stack_arr[25];
    string equation;
    int top, x;

public:
    StackOperations()
    {
        top = -1;
    }

    void operation()
    {
        cout << "Enter the Equation : "
             << " ";
        getline(cin, equation);
        x = equation.length();

        cout << "The Given Equation is :" << endl;
        for (int i = 0; i < x; i++)
        {
            cout << equation[i] << "  ";
        }

        for (int i = 0; i < x; i++)
        {
            if (equation[i] == '(')
            {
                push(equation[i]);
            }

            if (equation[i] == ')')
            {
                if (top == -1)
                {
                    cout << "Equation  is not Balanced";
                    goto xyz;
                }
                else
                {
                    pop();
                }
            }
        }

        compare();
    xyz:
        cout << endl;
    }

    void push(char c)
    {
        top = top + 1;
        stack_arr[top] = c;
    }

    void pop()
    {
        if (top > -1)
        {
            stack_arr[top];
            top = top - 1;
        }
    }

    void compare()
    {
        if (top == -1)
        {
            cout << "Equation is balanced";
        }

        else
        {
            cout << "Equation is not balanced";
        }
    }
};

int main()
{
    StackOperations s;
    s.operation();
    return 0;
}