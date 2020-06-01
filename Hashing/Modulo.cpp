#include<iostream>
using namespace std;

class Modulo
{
    public:
    void Hash(int *arr,int *key_arr,int n,int noe)
    {
        for(int i=0;i<n;i++)
        {
            if(i>=noe)
            {
                cout<<"Out of Bounds"<<endl;
                break;
            }
            int loc=key_arr[i]%noe;
            if(arr[loc] == 0)
            {    
                arr[loc]=key_arr[i];
            }
            else
            {
                while(1)
                {
                    loc++;
                    if(loc >= noe)
                    {
                        loc=loc%noe;
                    }
                    if(arr[loc] == 0)
                    {
                        arr[loc]=key_arr[i];
                        break;
                    }    
                }
            }
            
        }
    }

    void Display(int *arr,int noe)
    {
        for(int i=0;i<noe;i++)
        {
            cout<<i<<" "<<arr[i];
            cout<<endl;
        }

    }
};

int main()
{
    int n,noe;
    cout<<"Enter The Size of Array (Location Array) :";
    cin>>noe;
    int arr[noe] ={0};
    cout<<"Enter The Number of Elements to be Hashed :";
    cin>>n;
    int key_arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter Data "<<i<<" : ";
        cin>>key_arr[i];
    }
    
    Modulo m=Modulo();
    m.Hash(arr,key_arr,n,noe);
    m.Display(arr,noe);
    return 0;
}