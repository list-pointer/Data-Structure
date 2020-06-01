#include <iostream>
using namespace std;

class StackOperations
{
    int stack_arr[10];
    int size, top;

public:
    StackOperations (int s)
    {
        size = s;
        top = -1;
    }

    void push()
    {
        int n;

        if (top < size - 1)
        {
            cout << "Enter element : ";
            cin >> n;
            top++;
            stack_arr[top] = n;

            cout<< n << " entered at index " <<top;
        }
        else
            cout<<"Stack overflow";
    }

    void pop()
    {
        if (top >= 0)
        {
            cout << stack_arr[top--] << " removed from stack ";
        }
        else
            cout <<"Stack underflow";
    }

    void display()
    {
        int a = top;
        if (a < 0)
            cout << "Stack is empty";
        else
        {
            for (int i = a; a >= 0; a--)
            {
                cout << a << "  :  " << stack_arr[a] << endl;
            }
        }
    }
};

int main()
{
    int size, choice;
    cout << "Enter size of stack : ";
    cin >> size;

    StackOperations s(size);

    cout << "\nEnter your choice :\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
    cout <<endl;
    cout << "Enter choice : ";
    cin >> choice;
    cout << endl;

    while ( choice !=4 )
    {
        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        }
        cout << "\nEnter your choice :\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << endl;
        cout << "Enter choice : ";
        cin >> choice;
        cout << endl;
    }

    return 0;
}