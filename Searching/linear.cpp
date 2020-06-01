#include<iostream>
using namespace std;

class LSearch
{
    private:
    int noe,key,i;
    int arr[100];
    public:
    void GetData()
    {
        cout<<"Enter The Size of List(Maximum 100) : ";
        cin>>noe;
        for(i=0;i<noe;i++)
        {
            cout<<"Enter Data : ";
            cin>>arr[i];
        }
        cout<<endl<<"Enter Number to be Searched : ";
        cin>>key;
    }

    void add()
{
    noe+=1;
    arr[noe-1]=key;
}

    void ShowData()
    {
        for(int i=0;i<noe;i++)
        {   
            cout<<arr[i]<<"	";      
        }
    }

int Search()
{
    int flag=0;
    for(i=0;i<noe;i++)
    {
         if(key==arr[i])
            {
                flag=1;
                cout<<"The Number is Found At : "<<i<<"th Index and "<<i+1<<"th position"<<endl;
                break;
            }
    }
    return flag;
}     
};


int main()
{
    LSearch b=LSearch();
    b.GetData();
    if(b.Search() == 0)
    {   
        b.add();
        b.ShowData();
    }
    return 0;
}