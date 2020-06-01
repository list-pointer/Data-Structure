// Push “(“onto Stack, and add “)” to the end of X.
// Scan X from left to right and repeat Step 3 to 6 for each element of X until the Stack is empty.
// If an operand is encountered, add it to Y.
// If a left parenthesis is encountered, push it onto Stack.
// If an operator is encountered ,then:
// Repeatedly pop from Stack and add to Y each operator (on the top of Stack) which has the same precedence as or higher precedence than operator.
// Add operator to Stack.
// [End of If]
// If a right parenthesis is encountered ,then:
// Repeatedly pop from Stack and add to Y each operator (on the top of Stack) until a left parenthesis is encountered.
// Remove the left Parenthesis.
// [End of If]
// [End of If]
// END.



#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class InfixToPostfix
{   
    private:
    char stack[100];
    string expression,eq;
    int top,len,value;
    public:
    InfixToPostfix()
    {
        top=-1;
    }

    void get()
    {
        cout<<"Enter String (Equation) : "<<" ";
        getline(cin,eq);
        len=eq.length();
        top++;
        stack[top]='(';
        for(int i=0;i<len;i++)
        {
            opeartion(eq[i]);
        }

    }

    void opeartion(char val)
    {
        char str=val;
        if( str=='*' || str=='+' || str=='-' || str=='/' || str=='^' )
        {
            if( stack[top]=='*' || stack[top]=='+' || stack[top]=='-' || stack[top]=='/' || stack[top]=='^' )
            {
                compare(str);
            }
            else
            {
                push(str);
            }
            
        }
        else if(str == '(')
            {
                push(str);
            }
        else if(str == ')' )
        {
           while(stack[top] != '(')
           {
               pop();
           } 
        }
        else
        {
            expression.append(len+1,str);
        }
    }

    void push(char v)
    +{
        top++;
        stack[top]=v;
     }

    void pop()
    {
        int l=expression.length();
        expression.append(l+1,stack[top]);
        top--;
    }

    int compare(char op)
    {
        char operators=op;
        char operators_arr[5]={'^','/','*','+','-'};
        int index,index2;
        for(int i=0;i<5;i++)
        {
            if(operators == operators_arr[i])
            index=i;
            if(stack[top] == operators_arr[i])
            index2=i;
        }
        // if(index2 < index)
        // {
        //     pop();
        //     stack[top]=operators;
        // }
        // else if(index2 > index)
        // {
        //     stack[top]=operators;
        // }
        if(index == 0)
        {
            pop();
            push(operators);
        }
        else
        {

        }
    }

    void display()
    {
        cout<<expression<<" ";
        for(int i=0;i<len;i++)
        {
            cout<<endl;
            cout<<stack[i]<<" ";
            
        }
    }
};

int main()
{
    InfixToPostfix p;
    p.get();
    p.display();
    // p.compare();
    return 0;
}