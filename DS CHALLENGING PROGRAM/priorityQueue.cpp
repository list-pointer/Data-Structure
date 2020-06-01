#include<iostream>
#include<stdlib.h>
using namespace std;

class PriorityQueue
{
public:
int choice,value,rear,front,rElement,count,size;
int arr[100],priority[100];

PriorityQueue()
{
    front=0;
    rear=-1;
    cout<<"Enter Size of Array (Less than 100) : ";
    cin>>size;
    cout<<endl;

    for(int i=0;i<size;i++)
    {
        arr[i]=0;
    }

    for(int i=0;i<size;i++)
    {
        priority[i]=111;
    }
}

void get()
{
    do
			{
				cout<<"0.Exit\n01.Enter an Element\n02 Delete an Element\n03.Display\n";
				cout<<"Enter Your Choice : "<<" ";
                cin>>choice;
				switch(choice)
				{
                    case 0:
                    break;

					case 1:
						insert();
						break;

                    case 2:
						delete_ele();
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
    if(front>rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFulll()
{
    if(rear>=size-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void insert()
{
    cout<<"Enter value : ";
    cin>>value;
    cout<<endl;
    if(isFulll())
    {
        cout<<rear<<" ";
        cout<<"Sorry OverFlowwwww "<<endl;
    }
    else
    {
    cout<<rear<<" ";
    rear=rear+1;
    arr[rear]=value;
    cout<<"Enter priority : ";
    cin>>priority[rear];
    cout<<endl;
    }
    display();
    cout<<endl;
}

void delete_ele()
{
    int lowest_priority,index_lowest_priority;
    cout<<endl;
    if(isEmpty())
    {
        cout<<"Sorry UnderFlow "<<endl;
    }
    else
    { 
        lowest_priority=priority[0];
        for(int z=0;z<size;z++)
        {
            if(lowest_priority >= priority[z])
            {

                    lowest_priority=priority[z];
                    index_lowest_priority=z;
            }  
        }
        rElement=arr[index_lowest_priority];
        arr[index_lowest_priority]=0;
        priority[index_lowest_priority]=111;
        cout<<"The removed Element : "<<rElement<<" from Position : "<<index_lowest_priority<<endl;
        front=front+1;
    }
    display();
    cout<<endl;
}

void display()
{
    cout<<"The Elements in Queue are :"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Position : "<<i<<"    value : "<<arr[i]<<"    priority : "<<priority[i]<<endl;
    }
}

};

int main()
{
    PriorityQueue d;
    d.get();
    return 0;
}
