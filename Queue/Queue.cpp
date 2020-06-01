#include<iostream>
#include<stdlib.h>
using namespace std;

class Queue
{
public:
int choice,value,fr,rear,size,rElement;
int arr[100];

Queue()
{
    rear=fr=-1;
    for(int i=0;i<100;i++)
    {
        arr[i]=0;
    }

    cout<<"Enter Size of Queue (Less than 100) : ";
    cin>>size;
    cout<<endl;
}

void get()
{
    do
			{
				cout<<"0.Exit\n01.Push an Element\n02.Pop an Element\n03.Display\n";
				cout<<"Enter Your Choice : "<<" ";
                cin>>choice;
				switch(choice)
				{
                    case 0:
                    break;

					case 1:
						push();
						break;

                    case 2:
						pop();
						break;

					case 3:
						display();
						break;

					default:
					    cout<<"invalid input"<<endl<<endl;
				}
			}while(choice!=0);

}

bool isEmpty()
{
    if(rear == -1 && fr == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if(rear >= size-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push()
{

    cout<<"Enter value : ";
    cin>>value;
    cout<<endl;
    if(isFull())
    {
        cout<<"Sorry OverFlow "<<endl;
    }
    else if (rear == -1 and fr == -1)
    {
        rear=0;
        fr=0;
        arr[rear]=value;
    }
    else
    {
    rear=rear+1;
    arr[rear]=value;
    }
    display();
    cout<<endl;
}

void pop()
{
    cout<<endl;
    if(isEmpty())
    {
        cout<<"Sorry UnderFlow "<<endl;
    }
    else if (fr == rear)
    {
        rElement=arr[fr];
        arr[fr]=0;
        cout<<"The removed Element : "<<rElement<<" from Position : "<<fr<<endl;
        fr=-1;
        rear=-1;
       // cout<"The Queue is is Empty";
    }
    else
    {
        rElement=arr[fr];
        arr[fr]=0;
        cout<<"The removed Element : "<<rElement<<" from Position : "<<fr<<endl;
        fr=fr+1;
    }
    display();
    cout<<endl;
}

void display()
{
    cout<<"The Elements in Queue are :"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Position : "<<i<<" value : "<<arr[i]<<endl;
    }
}

};

int main()
{
    Queue d;
    d.get();
    return 0;
}
