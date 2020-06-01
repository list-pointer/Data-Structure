# include<iostream>
using namespace std;

class ShellSort
{
    private:
    int arr[100];
    int noe,temp,i,j,increment,p;

    public:
    void GetData()
    {
        cout<<"Enter size of array : "<<endl;
        cin>>noe;
        for(int i=0;i<noe;i++)
        {
            cout<<"Enter Data : ";
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
				
		for(increment = noe/2 ; increment > 0 ; increment=increment/2)
		{	
			if(Sorted())
			{ 
				break;
			}
					
			for(j = increment ; j < noe ; j++)
			{
				for(i = j - increment ; i >= 0 ; i=i-increment)
				{
					if(arr[i+increment] > arr[i])
					{
						break;
					}	
					else
					{
						swap(arr[i+increment],arr[i]);
					}
				}
			}
            ShowData();
					
		}	
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
    ShellSort d;
    d.GetData();
    d.ShowData();
    d.Sort();
}