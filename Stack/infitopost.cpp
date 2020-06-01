
#include <iostream>
#include <string>
using namespace std;
class stack {
    int top1, top2, size;
    char s1[100], s2[100], var;
    string s;

public:
    stack()
    {
        top1 = top2 = -1;
    }
    void geteq()
    {
        cout << "\nEnter equation:- ";
        getline(cin, s);
    }
    void push(char p)
    {
        top1++;
        s1[top1] = p;
    }
    void push2(char p)
    {
        top2++;
        s2[top2] = p;
    }
    char pop()
    {
        var = s1[top1];
        top1--;
        return var;
    }
    int prec(char p)
    {
        if (p == '+')
            return 0;
        if (p == '-')
            return 0;
        if (p == '*')
            return 1;
        if (p == '/')
            return 1;
        if (p == '^')
            return 2;
    }
    void optr(char p)
    {
        char var1, var2;
        var1 = pop();
        if (var1 == '+' || var1 == '-' || var1 == '*' || var1 == '/' || var1 == '^') {
            if (prec(p) > prec(var1)) {
                push(var1);
                push(p);
            }
            else {
                push2(var1);
                push(p);
            }
        }
        else {
            push(var1);
            push(p);
        }
    }
    void close()
    {
        char var;
        var = pop();
        while (var != '(') {
            push2(var);
            var = pop();
        }
    }
    void comp()
    {
        int i = 0;
        push('(');
        while (s[i] != '\0') {
            if (s[i] == '(')
                push(s[i]);
            else if (s[i] >= 'A' && s[i] <= 'Z')
                push2(s[i]);
            else if (s[i] >= 'a' && s[i] <= 'z')
                push2(s[i]);
            else if (s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '/' || s[i] == '^')
                optr(s[i]);
            else if (s[i] == ')')
                close();
            i++;
        }
        cout << "\nExpression:-";
        i = 0;
        while (i <= top2) {
            cout << s2[i];
            i++;
        }
    }
};
int main()
{
    stack s;
    s.geteq();
    s.comp();
}
