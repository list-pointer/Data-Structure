#include<iostream>
using namespace std;

class BubbleSort
{
    private:
    int noe,i,j,temp;
    int arr[100];
    public:
    void GetData()
    {
        cout<<"Enter The Number Of Elements Required To be Sorted : ";
        cin>>noe;
        for(i=0;i<noe;i++)
        {
            cout<<"Enter Data : ";
            cin>>arr[i];
        }
    }

     void ShowData()
    {
        for(int i=0;i<noe;i++)
        {   
            cout<<arr[i]<<"	";      
        }
		cout<<"\n\n";
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
             cout<<"Pass "<<i<<":  ";
            ShowData();
        }
    }   
};


int main()
{
    BubbleSort b=BubbleSort();
    b.GetData();
    cout<<endl<<"Before Sorting :"<<endl;
    b.ShowData();
    cout<<endl<<"After Sorting :"<<endl;
    b.ShowData();
    b.Sort();
    return 0;
}