#include<iostream>
using namespace std;

class BSearch
{
    private:
    int noe,key,low,high,mid,i,j,temp;
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
    }

      int Sorted()
    {
	for(int i=0;i<noe-1;i++)
    	{
    		if(arr[i]>arr[i+1])
    			return 0;
		}
		return 1;
    }

    void Sort()
    {
        for(i=0;i<noe;i++)
        {   
            if(Sorted())
			break;

            for(j=0;j<noe-1;j++)
            {  
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    } 

     void ShowData()
    {
        cout<<"Sorted Array :";
        for(int i=0;i<noe;i++)
        {   
            cout<<arr[i]<<"	";      
        }
		cout<<"\n\n";

        cout<<endl<<"Enter Number to be Searched : ";
        cin>>key;
    }

    void Search() 
    { 
        int flag=0;
        low=0;
       high=noe-1;
       
   while(low <= high)
   {
       mid=(low+high)/2;
       
       cout<<mid;
       if(arr[mid] == key)
       {
           flag=1;
           cout<<"The Number is Found At : "<<mid<<"th Index and "<<mid+1<<"th position"<<endl;
           break;
       }

       else if(arr[mid] > key)
       {
           high=mid-1;
       }

       else
       {
           low=mid+1;
       }
       
   }
   if (flag == 0)
   {
       cout<<"Number Not Present";
   }
}   
};


int main()
{
    BSearch b=BSearch();
    b.GetData();
    b.Sort();
    b.ShowData();
    b.Search();
    return 0;
}