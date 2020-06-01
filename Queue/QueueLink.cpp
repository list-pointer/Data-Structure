#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
}
*list=NULL,*p,*s,*q,*r,*front=NULL,*rear=NULL;  //*p is used for new node

class QueueLink
{
public:
int choice,value;

void get()
{
    do
			{
				cout<<"0.Exit\n1.Push\n2.Pop\n3.display\n";
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

					case 11:
						display();
						break;
					
					default:
					    cout<<"invalid input"<<endl<<endl;
				}
			}while(choice!=0);  
}

void push()
{
    		cout<<"Enter the value : ";
			cin>>value;
            p=(struct node*)malloc(sizeof(node));
            p->data=value;
            if(list == NULL)
            {
                    p->next=NULL;
                    list=p;
                    rear=p;
                    front=p;
            }
            else
            {
                rear->next=p;
                p->next=NULL;
                rear=rear->next;
                
            }
            display();
}

void pop()
{
		cout<<"Delete Fisrt element "<<endl;
        if(front == NULL && rear == NULL)
        {
            cout<<"Empty List"<<endl<<endl;
        }
        else if (rear == front)
        {
            p=front;
            list=list->next;
            front=front->next;
            delete p; 
        }
        else
        {
            p=front;
            list=list->next;
            front=front->next;
            delete p;
        }
        display();		
}

void display()
{
    if(list==NULL)
		    {
		        cout<<endl<<"List is Empty "<<endl<<endl;
		    }
		    else
		    {
                cout<<"The List is : ";
		        q=list;
		        while(q	!=NULL)
                {   
                    cout<<q->data<<"|----->";
                    q=q->next;                
                }
                cout<<endl<<endl;
	        }
}
};

int main()
{
    QueueLink s;
    s.get();
    return 0;
}