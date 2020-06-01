#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
}
*list=NULL,*p,*s,*q,*r,*top=NULL;  

class StackUsingLinkedList
{
public:
int choice,value;

void get()
{
    do
			{
				cout<<"0.Exit\n1.Push Operation\n2.Pop Operation\n3.Display\n";
				cout<<"Enter Your Choice : "<<" ";
                cin>>choice;
				switch(choice)
				{
                    case 0:
                    break;

					case 1:     
						push_op();
						break;

                    case 2:     
						pop_op();
						break;

					case 3:
						display();
						break;
					
					default:
					    cout<<"invalid input"<<endl<<endl;
				}
			}while(choice!=0);  

}

void push_op()
{
    		cout<<"Enter the value : ";
			cin>>value;
            p=(struct node*)malloc(sizeof(node));
            p->data=value;
            if(list == NULL)
            {
                    list=p;
                    p->next=top;
                    top=p;
                    display();
            }
            else if (!p)
            {
                cout<<"Overflow (Memory Full) ";
            }
            else
            {
                top->next=p;
                p->next=NULL;
                top=p;
                display();
            }
}

void pop_op()
{
            if(list == NULL)
            {
                cout<<"Under Flow (No Elements) ";
            }
            else
            {
                q=list;
                    while(q->next != NULL)
                {   
                    r=q;
                    q=q->next;
                }
                top=r;
                top->next=NULL;
                delete q;
                display();
            }
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
    StackUsingLinkedList s;
    s.get();
    return 0;
}