# include<iostream>
using namespace std;

class QuickSort
{
    private:
    int arr[100];
    int noe,pivot,temp,s,e,i,j;

    public:
    void GetData()
    {
        cout<<"Enter size of array : "<<endl;
        cin>>noe;

        for(int i=0;i<noe;i++)
        {
            cout<<"Enter element : ";
            cin>>arr[i];
        }
    }

    void ShowData()
    {
        for(int i=0;i<noe;i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

    void Sorted()
    {
        Quick(0,noe-1);
    }

    void Quick(int s,int e)
    {

        pivot=s;
        i=pivot+1;
        j=e;
        if(j<i)
        {
            return;
        }

        while(arr[pivot]>arr[i])
        {
            i++;
            if(j<i)
            {
                swap(arr[pivot],arr[j]);
                pivot=j;
                Quick(s,pivot-1);
                Quick(pivot+1,e);
                return;
            }
        }
        while(arr[pivot]<arr[j])
        {
            j--;
            if(j<i)
            {
                swap(arr[pivot],arr[j]);
                pivot=j;
                Quick(s,pivot-1);
                Quick(pivot+1,e);
                return;
            }
        }
        swap(arr[i],arr[j]);
        ShowData();
        Quick(s,e);
        return;
    }

    void swap(int &a,int &b)
    {
        temp=a;
        a=b;
        b=temp;
    }
};

int main()
{
    QuickSort d;
    d.GetData();
    d.ShowData();
    d.Sorted();
    d.ShowData();
}