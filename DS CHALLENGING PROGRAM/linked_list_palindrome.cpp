#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *list = NULL, *p, *q, *r, *temp;

class ll
{
public:
    void insert_beg()
    {
        int val;
        cout << "Enter element : ";
        cin >> val;

        p = (struct node *)malloc(sizeof(node));
        p->data = val;
        if (list == NULL)
        {
            p->next = NULL;
            list = p;
            cout <<"\n----- "<<val<<" inserted -----\n";
        }
        else
        {
            p->next = list;
            list = p;
            cout <<"\n----- "<<val<<" inserted -----\n";
        }
    }

    void insert_end()
    {
        int val;
        cout << "Enter element : ";
        cin >> val;

        p = (struct node *)malloc(sizeof(node));
        p->data = val;
        if (list == NULL)
        {
            p->next = NULL;
            list = p;
            cout <<"\n----- "<<val<<" inserted -----\n";
        }
        else
        {
            q = list;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
            p->next = NULL;
            cout <<"\n----- "<<val<<" inserted -----\n";
        }
    }
    void delete_beg()
    {
        if (list == NULL)
            cout << "\n***** List is empty *****\n\n";
        else
        {
            q = list->next;
            list->next = NULL;
            list = q;
            cout << "\n----- First element deleted -----n\n";
        }
    }

    void delete_end()
    {
        if (list == NULL)
            cout << "\n***** List is empty *****\n\n";
        else
        {
            q = list;
            while (q->next != NULL && q->next != NULL)
            {
                r = q;
                q = q->next;
            }
            r->next = NULL;
            free(q);
            cout << "\n----- Last element deleted -----\n\n";
        }
    }

    int count()
    {
        int cnt = 0;
        if (list == NULL)
            cout << "\nNo of elements = " << cnt << "\n\n";
        else
        {
            q = list;
            while (q != NULL)
            {
                cnt++;
                q = q->next;
            }

            cout << "\nNo of elements = " << cnt << "\n\n";
        }
        return cnt;
    }

    void palindrome()
    {
        if(list == NULL)
            cout << "\n***** List is empty *****\n\n";
        else
        {
            int flag = count()/2;
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
                cout<<"NOT PALINDROME\n";
            else
                cout<<"PALINDROME\n";
        }
    }

    void display()
    {
        if (list == NULL)
            cout << "\n***** List is empty *****\n\n";
        else
        {
            q = list;
            while (q != NULL)
            {
                cout << q->data << "-->";
                q = q->next;
            }
            cout << "NULL\n\n";
        }
    }
};

int main()
{
    int flag = 0;
    ll l;
    while (1)
    {
        cout<<"--------------------\n";
        cout << "1. Insert element at beginning\n2. Insert Element at the end\n3. Delete from beginning\n4. Delete from end\n5. "
             << "Count no. of elements\n6. Display\n7. Palindrome\n8. Exit\n\nEnter choice : ";
        cin >> flag;
        cout<<"--------------------\n";

        switch (flag)
        {
        case 1:
            l.insert_beg();
            break;
        case 2:
            l.insert_end();
            break;
        case 3:
            l.delete_beg();
            break;
        case 4:
            l.delete_end();
            break;
        case 5:
            l.count();
            break;
        case 6:
            l.display();
            break;
        case 7:
            l.palindrome();
            break;
        case 8:
            cout<<"\n\n xxx Program Terminated \n\n";
            exit(0);
            break;
        default:
            break;
        }
    }
}