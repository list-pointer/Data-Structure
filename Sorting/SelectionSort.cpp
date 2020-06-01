#include<iostream>
using namespace std;

class SelectionSort
{
    private:
    int noe,i,j,temp,index,count;
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
        for(i=0; i<(noe-1); i++)
        {
        if(Sorted())
			break;
        int min = arr[i];
        for(j=(i+1); j<noe; j++)
        {
            if(min>arr[j])
            {
                min = arr[j];
                count++;
                index = j;
            }
        }
        if(count!=0)
        {
            temp = arr[i];
            arr[i] = min;
            arr[index] = temp;
        }
        count=0;
         cout<<"Pass "<<i<<" :  ";
        ShowData();

    }
    }   
};


int main()
{
    SelectionSort b=SelectionSort();
    b.GetData();
    cout<<endl<<"Before Sorting :"<<endl;
    b.ShowData();
    cout<<endl<<"After Sorting :"<<endl;
    b.ShowData();
    b.Sort();
   
    return 0;
}