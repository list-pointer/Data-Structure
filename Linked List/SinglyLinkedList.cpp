#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
}
*list=NULL,*p,*s,*q,*r=NULL;  //*p is used for new node

class SingleLinkList
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
                    p->next=NULL;
                    list=p;
                    display();
            }
            else
            {
                p->next=list;
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
                    p=p->next;
                    count++;
                }
                if(count ==0)
                {
                    q->next=p;
                    list=q;
                }
                else
                {
                    r->next=q;
                q->next=p;
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

                    p=p->next;
                }
                r=p->next;
                p->next=q;
                q->next=r;
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
        else
        {
            p=list;
            list=list->next;
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
        else if (list->next == NULL)
        {
            list=NULL;
        }
        else
        {
            while (p->next->next != NULL) 
            p = p->next; 
            delete (p->next); 
            p->next = NULL;   
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
        else if (list->data == del)
        {
            q=list;
            list=list->next;
            delete q;
        }
        else
        {
            while(p != NULL)
            {
                if(p->data == del)
                break;

                r=p;
                p=p->next;
            }
            q=p;
            p=p->next;
            r->next=p;
            delete q;
        }
        display();
}

void count_ele()
{
    int c=0;
    p=list;
    while(p != NULL)
    {
        p=p->next;
        c++;
    }
    cout<<"The Number of Elements is : "<<c<<endl<<endl;
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
                r=q->next;
                while(r!= NULL)
                {
                    if(r->data < q->data)
                    swap(r->data,q->data);

                    r=r->next;
                }
                q=q->next;
            } 
            display();    
        }
        
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
//             while (p != NULL) { 
//             // Store next 
//             next = p->next; 
  
//             // Reverse current node's pointer 
//             p->next = prev; 
  
//             // Move pointers one position ahead. 
//             prev = p; 
//             p = next; 
//         } 
//         p = prev; 
//         }
//         display();    
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
                    q=q->next;                
                }
                cout<<endl<<endl;
	        }
}


};

int main()
{
    SingleLinkList s;
    s.get();
    return 0;
}