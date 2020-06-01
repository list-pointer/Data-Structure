#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
}
*list=NULL,*p,*s,*q,*r;  //*p is used for new node

class LinkPal 
{
public:
int choice,value;

void get()
{
    do
			{
				cout<<"0.Exit\n1.Add Elemnet \n2.Check if Pallindrome \n3.Display \n";
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
						check();
						break;
                    
					case 3:
						display();
						break;
					
					default:
					    cout<<"invalid input"<<endl<<endl;
				}
			}while(choice!=0);  

}

void insert()
{
            cout<<"Enter the value : ";
			cin>>value;
            p=(struct node*)malloc(sizeof(node));
            p->data=value;
            if(list == NULL)
            {
                p->next=NULL;
                list=p;
                display();
            }
            else
            {
                q=list;
                while(q->next != NULL)
                {
                    q=q->next;
                }
                q->next=p;
                p->next=NULL;
                display();
            }
}

int count_ele()
{
    int c=0;
    p=list;
    while(p != NULL)
    {
        p=p->next;
        c++;
    }
    return c;
    // cout<<"The Number of Elements is : "<<c<<endl<<endl;
}


void check()
{
            if(list == NULL)
            {
                cout<<endl<<"List is Empty "<<endl<<endl;
            }
        else
        {
            int flag = count_ele()/2;
            p=list;
            q=NULL;
            while(flag > 0)
            {
                r=list;
                while(r->next != q)
                {
                    r=r->next;
                }
                if(p->data == r->data)
                {
                    p = p->next;
                    q=r;
                    flag--;
                }
                else
                    flag = -1;
            }
            if(flag == -1)
                cout<<"The List is a Pallindrome";
            else
                cout<<"The List is not a Pallindrome";
        }
        cout<<endl<<endl;
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
    LinkPal s;
    s.get();
    return 0;
}