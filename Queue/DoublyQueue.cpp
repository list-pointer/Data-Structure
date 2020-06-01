#include<iostream>
#include<stdlib.h>
using namespace std;

class DoublyQueue
{
public:
int choice,value,lfront,lrear,rrear,rfront,size,rElement,count;
int arr[100];

DoublyQueue()
{
    lfront=lrear=-1;
    for(int i=0;i<100;i++)
    {
        arr[i]=0;
    }

    cout<<"Enter Size of Queue (Less than 100) : ";
    cin>>size;
    cout<<endl;

    rrear=rfront=size;
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
    if(rrear == size && rfront == size)
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
    if(arr[rrear-1] != 0)
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
    if(lrear == -1 && lfront == -1)
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
    if(arr[rrear-1] != 0)
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
        cout<<lrear<<" ";
        cout<<"Sorry OverFlowwwww "<<endl;
    }
    else if (lrear == -1 and lfront == -1)
    {
        cout<<lrear<<" ";
        lrear=0;
        lfront=0;
        arr[lrear]=value;
    }
    else
    {
        cout<<lrear<<" ";
    lrear=lrear+1;
    arr[lrear]=value;
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
    else if (lfront <= lrear)
    {
        rElement=arr[lfront];
        arr[lfront]=0;
        cout<<"The removed Element : "<<rElement<<" from Position : "<<lfront<<endl;
        lfront=lfront+1;
    }
    else
    {
        cout<<"Sorry UnderFlow "<<endl;
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
        cout<<"Sorry OverFlow "<<endl;
    }
    else if (rrear == size and rfront == size)
    {
        rrear=size-1;
        rfront=size-1;
        arr[rrear]=value;
    }
    else
    {
    rrear=rrear-1;
    arr[rrear]=value;
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
    else if (rrear <= rfront)
    {
        rElement=arr[rfront];
        arr[rfront]=0;
        cout<<"The removed Element : "<<rElement<<" from Position : "<<lfront<<endl;
        rfront=rfront-1;
    }
    else
    {
    cout<<"Sorry UnderFlow "<<endl;
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
    DoublyQueue d;
    d.get();
    return 0;
}
