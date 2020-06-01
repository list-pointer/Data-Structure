#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class PostFixEval
{   
    private:
    int stack[100];
    string eq;
    int top,len,value,a,b,ans;
    public:
    PostFixEval()
    {
        top=-1;
    }

    void get()
    {
        cout<<"Enter String (Equation) : "<<" ";
        getline(cin,eq);
        len=eq.length();

        for(int i=0;i<len;i++)
        {
            if(eq[i] == '+')
            {
                a=pop();
                b=pop();
                ans=b+a;
                cout<<"Addition is : "<<ans<<endl;
                push(ans);
            }
            else if(eq[i] == '-')
            {
                a=pop();
                b=pop();
                ans=b-a;
                cout<<"Subraction is : "<<ans<<endl;
                push(ans);
            }
            else if(eq[i] == '/')
            {
                a=pop();
                b=pop();
                ans=b/a;
                cout<<"Division is : "<<ans<<endl;
                push(ans);
            }
            else if(eq[i] == '*')
            {
                a=pop();
                b=pop();
                ans=b*a;
                cout<<"Multiplication is : "<<ans<<endl;
                push(ans);
            }
            else
            {
                value=eq[i]-48;
                push(value);
            }
            
        }
    }

    void push(int value)
    {
        top++;
        stack[top]=value;
        cout<<value<<" Pushed ";
    }

    int pop()
    {
        int val=stack[top];
        top--;
        return val;
    }

    void display()
    {
        cout<<endl;
        cout<<"The Answer of given Equation is : "<<stack[top];
    }
};

int main()
{
    PostFixEval p;
    p.get();
    p.display();
    return 0;
}