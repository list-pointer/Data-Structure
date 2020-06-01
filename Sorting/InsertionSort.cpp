#include<iostream>
using namespace std;

class InsertionSort
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

     void ShowData(int num)
    {
        for(int i=0;i<num;i++)
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
         temp=arr[i];
         j=i;
         
         while(j>0 && temp<arr[j-1])
          {
             arr[j]=arr[j-1];
             j=j-1;
          }
         arr[j]=temp;
          cout<<"Pass "<<i<<" :  ";
         ShowData(i+1);
     }
     
    }   
};


int main()
{
    InsertionSort b=InsertionSort();
    b.GetData();
    //cout<<endl<<"Before Sorting :"<<endl;
    //b.ShowData();
    cout<<endl<<"After Sorting :"<<endl;
    //b.ShowData();
    b.Sort();
   
    return 0;
}