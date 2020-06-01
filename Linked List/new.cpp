#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
    public :
    int data;
    node *next;
};

class Linked_List
{
    public:
    node *list,*p,*q,*r,*temp;
    
    Linked_List()
    {
        list=NULL;
    }
    
    void Insert_start(int val)
    {
        p=(node*)malloc(sizeof(node));
        p->data=val;
        if(list==NULL)
        {
            p->next=p;
            list=p;
        }
        else
        {
            q=list;
            while(q->next!=list)
            {
                q=q->next;
            }
            q->next=p;
            p->next=list;
            list=p;
        }
    }

    void Insert_end(int val)
    {
        p=(node*)malloc(sizeof(node));
        p->data=val;
        if(list==NULL)
        {
            p->next=p;
            list=p;
        }
        else
        {
            q=list;
            while(q->next!=list)
            {
                q=q->next;
            }
            q->next=p;
            p->next=list;
        }
    }

    void after_add(int key,int val)
    {
        p=(node*)malloc(sizeof(node));
        p->data=val;
        if(list==NULL)
        {
            p->next=p;
            list=p;
        }
        else
        {
            bool exhaust=false;
            q=list;
            while(q->data!=key)
            {
                q=q->next;
                if(q==list)
                {
                    exhaust=true;
                    break;
                }
            }
            if(!exhaust)
            {
                r=q->next;
                q->next=p;
                p->next=r;
            }
            else
            {
                cout<<"\nThe element "<<key<<" doesnt exist in the list!"<<endl;            
            }
        }   
    }

    void before_add(int key,int val)
    {
        bool exhaust=false;
        p=(node*)malloc(sizeof(node));
        p->data=val;
        if(list==NULL)
        {
            p->next=p;
            list=p;
        }
        else
        {
            q=list;
            if(q->data==key)
            {
                Insert_start(val);
            }
            else
            {
                while(q->data!=key)
                {
                    r=q;
                    q=q->next;
                    if(q==list)
                    {
                        exhaust=true;
                        break;
                    }
                }
                if(!exhaust)
                {
                    r->next=p;
                    p->next=q;
                }
                else
                {
                    cout<<"\nThe element "<<key<<" doesnt exist in the list!"<<endl;
                }
            }
        }   
    }

    

    void delete_start()
    {
        if(list==NULL)
        {
            cout<<"The list is empty!"<<endl;
        }
        else
        {
            q=list;
            if(q->next==list)
            {
                free(q);
                list=NULL;
                return;
            }
            list=list->next;
            q=list;
            while(q->next!=list)
            {
                r=q;
                q=q->next;
            }
            free(q);
            r->next=list;
        }
    }

    void delete_end()
    {
        if(list==NULL)
        {
            cout<<"The list is empty!"<<endl;
        }
        else
        {
            q=list;
            if(q->next==list)
            {
                free(q);
                list=NULL;
            }
            else
            {
                while(q->next!=list)
                {
                    r=q;
                    q=q->next;
                }
                r->next=list;
                free(q);
            }
        }
    }
    
    void reverse_ele()
    {
        q=p=list;
        temp=NULL;
        do
        {
            q=p->next;
            p->next=temp;
            temp=p;
            p=q;
        }while(q!=list);
        list=temp;
        q->next=list;
    }


    void sort_ele()
    {
        for(int i=0;i<Count();i++)
        {
            q=list;
            while(q->next!=list)
            {
                r=q;
                q=q->next;
                if(r->data>q->data)
                {
                    int temp=r->data;
                    r->data=q->data;
                    q->data=temp;
                }
            }
        }
    }

    void DeleteElement(int val)
    {
        bool exhaust=false;
        if(list==NULL)
        {
            cout<<"The list is empty!"<<endl;
        }
        else
        {
            q=list;
            r=NULL;
            if(list->data==val)
            {
                delete_start();
                return;
            }
            do
            {
                r=q;
                q=q->next;
                if(q==list)
                {
                    exhaust=true;
                    break;
                }
            }while(q->data!=val);
            if(!exhaust)
            {
                temp=q->next;
                free(q);
                r->next=temp;
            }
            else
            {
                cout<<"\nThe element "<<val<<" doesnt exist in the list!"<<endl;
            }
        }
    }

    int Count()
    {
        if(list==NULL)
        {
            return 0;
        }
        else
        {
            int c=0;
            q=list;
            do
            {
                c++;
                q=q->next;
            }while(q!=list);
            return c;
        }
    }

    void display()
    {
        q=list;
        if(list==NULL)
        {
            cout<<"\n List is Empty!"<<endl;
        }
        else
        {
            do
            {
                cout<<q->data<<"  --->  ";
                q=q->next;
            }while(q!=list);
        }
    }
};

int main()
{
    Linked_List l;
    int element,key;
    int choice;
    do
    {
        cout<<"\n 1. Enter at Start \n 2. Enter at End \n 3.Enter before an element \n 4.Enter after an element \n 5. Delete start \n 6. Delete End \n 7. Delete Element \n 8. Get Count \n 9. Display \n 10.reverse_ele \n 11. sort_ele \n 12. Exit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                cout<<"Enter the element : "<<endl;
                cin>>element;
                l.Insert_start(element);
                break;
            }
            
            case 2:
            {
                cout<<"Enter the element : "<<endl;
                cin>>element;
                l.Insert_end(element);
                break;
            }
            
            case 3:
            {
                cout<<"Enter the element to add: "<<endl;
                cin>>element;
                cout<<"Element should be added before :  "<<endl;
                cin>>key;
                l.before_add(key,element);
                break;
            }

            case 4:
            {
                cout<<"Enter the element to add: "<<endl;
                cin>>element;
                cout<<"Element should be added after :  "<<endl;
                cin>>key;
                l.after_add(key,element);
                break;
            }
            
            case 5:
            {
                l.delete_start();
                break;
            }

            case 6:
            {
                l.delete_end();
                break;
            }

            case 7:
            {
                cout<<"Enter the element to delete: "<<endl;
                cin>>element;
                l.DeleteElement(element);
                break;
            }
            
            case 8:
            {
                cout<<"\n The list contains "<<l.Count()<<" elements"<<endl;
                break;
            }

            case 9:
            {
                l.display();
                break;
            }

            case 10:
            {
                l.reverse_ele();
                break;
            }
            
            case 11:
            {
                l.sort_ele();
                break;
            }

            default:
                break;
        }
    }
    while(choice!=12);
}