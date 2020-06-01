#include<iostream>
#include<stdlib.h>
using namespace std;

class SingleArrayDoubleStack
{
public:
int choice,value,ltop,rtop,size,rElement,count;
int arr[100];

SingleArrayDoubleStack()
{
    ltop=-1;
    cout<<"Enter Size of Array (Less than 100) : ";
    cin>>size;
    cout<<endl;

    for(int i=0;i<size;i++)
    {
        arr[i]=0;
    }

    rtop=size;
}

void get()
{
    do
			{
				cout<<"0.Exit\n01.Push an Element ( Left Side )\n02.Pop an Element ( Left Side )\n03.Push an Element ( Right Side )\n04.Pop an Element ( Right Side )\n05.Display\n";
				cout<<"Enter Your Choice : "<<" ";
                cin>>choice;
				switch(choice)
				{
                    case 0:
                    break;

					case 1:
						lpush();
						break;

                    case 2:
						lpop();
						break;

                    case 3:
						rpush();
						break;

                    case 4:
						rpop();
						break;

					case 5:
						display();
						break;

					default:
					    cout<<"invalid input"<<endl<<endl;
				}
			}while(choice!=0);

}

bool isEmptyr()
{
    if(rtop==size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFullr()
{
    if(arr[rtop-1] != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyl()
{
    if(ltop==-1)
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
    if(arr[ltop+1] != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void lpush()
{

    cout<<"Enter value : ";
    cin>>value;
    cout<<endl;
    if(isFulll())
    {
        cout<<ltop<<" ";
        cout<<"Sorry OverFlowwwww "<<endl;
    }
    else
    {
    cout<<ltop<<" ";
    ltop=ltop+1;
    arr[ltop]=value;
    // ltop=ltop+1;
    }
    display();
    cout<<endl;
}

void lpop()
{
    cout<<endl;
    if(isEmptyl())
    {
        cout<<"Sorry UnderFlow "<<endl;
    }
    else
    {
        rElement=arr[ltop];
        arr[ltop]=0;
        cout<<"The removed Element : "<<rElement<<" from Position : "<<ltop<<endl;
        ltop=ltop-1;
    }
    display();
    cout<<endl;
}

void rpush()
{

    cout<<"Enter value : ";
    cin>>value;
    cout<<endl;
    if(isFullr())
    {   
        cout<<rtop<<" ";
        cout<<"Sorry OverFlow "<<endl;
    }
    else
    {
    rtop=rtop-1;
    arr[rtop]=value;
    }
    display();
    cout<<endl;
}

void rpop()
{
    cout<<endl;
    if(isEmptyr())
    {
        cout<<"Sorry UnderFlow "<<endl;
    }
    else
    {
        rElement=arr[rtop];
        arr[rtop]=0;
        cout<<"The removed Element : "<<rElement<<" from Position : "<<rtop<<endl;
        rtop=rtop+1;
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
    SingleArrayDoubleStack d;
    d.get();
    return 0;
}
