#include<iostream>
using namespace std;

class Mid
{
    private:
    int arr[100];
    int choice,size,noe;
    public:
    void get()
    {
        cout<<"Enter the Size of Location Array : "<<" ";
        cin>>size;

        for(int i=0;i<size;i++)
        {
            arr[i]=-1;
        }

        cout<<"How many numbers do you want to hash? : "<<" ";
        cin>>noe;

        for(int i=0;i<noe;i++)
        {
            cout<<"Enter Element no "<<i<<" : ";
            cin>>choice;
            operations(choice);
        }    
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == -1)
            {
                
            }
            else
            {
                cout << i<<" : "<<arr[i] << "\t";
            }
        }
        cout << endl;
    }

    void operations(int choice)
    {
        int key,location;
        key=choice*choice;
        location=count(key);
        cout<<location<<endl;

        if(arr[location] == -1)
        {
            arr[location]=choice;
        }
        else
        {
            while(1)
            {
                location++;
                if(arr[location]==-1)
                {
                    arr[location]=choice;
                    break;
                }
                if(location>=size)
                {
                    location=0;
                }
            }
        }
    }

    int count(int key)
    {
        int loc,temp,count=0;
        temp=key;

        while(temp>0)
        {
            temp=temp/10;
            count++;
        }

        if(count%2==0)
        {
            for(int i=1;i<((count+1)/2);i++)
            {
                key=key/10;
            }
            loc=key%100;
            loc=loc%size;
        }

        else if(count%2!=0)
        {
            for(int i=1;i<((count+1)/2);i++)
            {
                key=key/10;
            }
            loc=key%10;
        }
        return loc;
    }
};

int main()
{
    Mid m;
    m.get();
    m.display();
    return 0;
}