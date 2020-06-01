#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *lptr;
    struct node *rptr;
}
*list=NULL,*p,*s,*q,*r;  //*p is used for new node

class DoubleLinkList
{
public:
int choice,value;

void get()
{
    do
			{
				cout<<"0.Exit\n1.Insert at Starting\n2.Insert at Ending\n3.Add before the element\n4.Add after the element\n5.Delete the First element\n6.Delete the Last element\n7.Delete the particular element\n8.Count\n9.Sort\n10.Reverse\n11.Display\n";
				cout<<"Enter Your Choice : "<<" ";
                cin>>choice;
				switch(choice)
				{
                    case 0:
                    break;

					case 1:     
						insert_start();
						break;

                    case 2:     
						insert_end();
						break;

                    case 3:     
						before_add();
						break;

                    case 4:     
						after_add();
						break;

                    case 5:     
						delete_start();
						break;

                    case 6:     
						delete_end();
						break;

                    case 7:     
						delete_ele();
						break;

                    case 8:     
						count_ele();
						break;

                    case 9:     
						sort_ele();
						break;
                    
                    // case 10:
					// 	reverse_ele();
					// 	break;

					case 11:
						display();
						break;
					
					default:
					    cout<<"invalid input"<<endl<<endl;
				}
			}while(choice!=0);  

}

void insert_start()
{
    		cout<<"Enter the value : ";
			cin>>value;
            p=(struct node*)malloc(sizeof(node));
            p->data=value;
            if(list == NULL)
            {
                    p->lptr=NULL;
                    p->rptr=NULL;
                    list=p;
                    display();
            }
            else
            {
                q=list;
                p->lptr=NULL;
                p->rptr=list;
                q->lptr=p;
                list=p;
                display();
            }
}

void insert_end()
{
            cout<<"Enter the value : ";
			cin>>value;
            p=(struct node*)malloc(sizeof(node));
            p->data=value;
            if(list == NULL)
            {
                    p->lptr=NULL;
                    p->lptr=NULL;
                    list=p;
                    display();
            }
            else
            {
                q=list;
                while(q->rptr != NULL)
                {
                    q=q->rptr;
                }
                q->rptr=p;
                p->lptr=q;
                p->rptr=NULL;
                display();
            }
}

void before_add()
{
            int before,count=0;
			cout<<"Enter Before Value : ";
            cin>>before;
            if(list==NULL)
            {
                cout<<"The Number is Not Present";
            }
            else
            {
                q=(struct node*)malloc(sizeof(node));
                cout<<"Enter Value : ";
                cin>>value;
                q->data=value;
                p=list;
                while(p != NULL)
                {
                    if(p->data == before)
                    break;

                    r=p;
                    p=p->rptr;

                    count++;
                }
                if(count ==0)
                {
                    q->lptr=NULL;
                    q->rptr=list;
                    list=q;
                }
                else
                {
                q->lptr=r;
                r->rptr=q;
                q->rptr=p;
                p->lptr=q;
                }
                display();
            }
}

void after_add()
{
            int after;
			cout<<"Enter After Value : ";
            cin>>after;
            if(list==NULL)
            {
                cout<<"The Number is Not Present";
            }
            else
            {
               q=(struct node*)malloc(sizeof(node));
                cout<<"Enter Value : ";
                cin>>value;
                q->data=value;
                p=list;
                while(p != NULL)
                {
                    if(p->data == after)
                    break;
                    p=p->rptr;
                }
                if(p->rptr == NULL)
                {
                    p->rptr=q;
                    q->lptr=p;
                    q->rptr=NULL;
                }
                else
                {
                   s=p->rptr;
                   p->rptr=q;
                   q->rptr=s;
                   q->lptr=p;
                   s->lptr=q; 
                }
                display();    
            }
            
}

void delete_start()
{
		cout<<"Delete Fisrt element "<<endl;
        if(list == NULL)
        {
            cout<<"Empty List"<<endl<<endl;
        }
        else if (list->rptr == NULL)
        {
            list=NULL;
        }
        else
        {
            p=list;
            list=list->rptr;
            list->lptr=NULL;
            delete p;
        }
        display();		
}

void delete_end()
{
        cout<<"Delete Last element "<<endl;
        p=list;
        if(list == NULL)
        {
            cout<<"Empty List"<<endl<<endl;
        }
        else if (list->lptr == NULL && list->rptr == NULL)
        {
            list=NULL;
        }
        else
        {
        while(p->rptr != NULL)
        {
            r=p;
            p=p->rptr;
        }
        delete(r->rptr);
        r->rptr=NULL;
        }
        display();
}

void delete_ele()
{   
        int del;
        cout<<"Enter Element to be deleted : ";
        cin>>del;
        p=list;
        if(list == NULL)
        {
            cout<<"Empty List";
        }
        else if (p->data == del)
        {
            q=list;
            list=list->rptr;
            list->lptr=NULL;
            delete q;
        }
        else
        {
            while(p->data !=del)
            {
                q=p;
                p=p->rptr;
            }
            if(p->rptr == NULL)
            {
                delete p;
                q->rptr=NULL;
            }
            else
            {
                s=p->rptr;
                q->rptr=s;
                s->lptr=q;
            }
        }
            display();
}

int count_ele()
{
    int c=0;
    p=list;
    while(p != NULL)
    {
        p=p->rptr;
        c++;
    }
    cout<<"The Number of Elements is : "<<c<<endl<<endl;
    return c;
}

void sort_ele()
{
        cout<<"Sorted List "<<endl;
        q=list;
        if(list == NULL)
        {
            cout<<"Empty List"<<endl<<endl;
        }
        else
        {
            while(q!= NULL)
            {
                r=q->rptr;
                while(r!= NULL)
                {
                    if(r->data < q->data)
                    swap(r->data,q->data);

                    r=r->rptr;
                }
                q=q->rptr;
            } 
                
        }
        display();
}

// void reverse_ele()
// {
//         cout<<"Reversed List "<<endl;
//         if(list == NULL)
//         {
//             cout<<"Empty List"<<endl<<endl;
//         }
//         else
//         {
//             p=list;
//         q=list;
//             while (q != NULL)
//             {
//                 q=q->rptr;
//             }
            
            
//         }
        
// }

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
                    q=q->rptr;                
                }
                cout<<endl<<endl;
	        }
}


};

int main()
{
    DoubleLinkList d;
    d.get();
    return 0;
}