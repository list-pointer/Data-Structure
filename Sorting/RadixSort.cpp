#include<iostream>
using namespace std;

class Sort{
    int arr[10];
    int noe,size;
    int bucket[10][20], buck_count[10]; 
    int i,j,k,r,no_of_passes,divisor,largest,pass_no;
    public:
    Sort(int n,int s)
    {
        noe=n;
        size=s;
        no_of_passes=0;
        divisor=1;
    }

    void getdata()
    {
        for(int i=0;i<noe;i++)
        {
            cout<<"Enter element : ";
			cin>>arr[i];
			if(arr[i]<0 )
		{
		cout<<"negative number not allowed"<<endl;
		cout<<"Re-Enter The Value :";
		cin>>arr[i];
		}
        }
    }

    void sort()
    {
    	cout<<"In sort\n";
		largest=arr[0]; 
		for(i=1;i<noe;i++)  
		{ 
		if(Sorted())
		{
			cout<<"SORTED";
			break;
		}
		if(arr[i] > largest) 
		largest=arr[i]; 
		} 
		while(largest > 0)  
		{	 
		no_of_passes++; 
		largest /= 10; 
		} 
		for(pass_no=0; pass_no < no_of_passes; pass_no++)
		{ 
		for(k=0; k<10; k++) 
		buck_count[k]=0; 
		for(i=0;i<noe;i++)
		{ 
		r=(arr[i]/divisor) % 10; 
		bucket[r][buck_count[r]++]=arr[i]; 
		} 
		i=0; 		
		for(k=0; k<10; k++)
		{ 
		for(j=0; j<buck_count[k]; j++) 
		arr[i++] = bucket[k][j]; 
		} 
		divisor =divisor * 10; 
		showdata();
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
	
	void showdata()
    {
        for(int i=0;i<noe;i++)
            cout<<" "<<arr[i];
        cout<<endl;
    }
};

int main(){
    int noe, size;
    cout<<"Enter size of array : ";
        cin>>size;
    cout<<"Enter no of elements in array : ";
    cin>>noe;
    if(noe>size)
        cout<<"No of elements exceeds array size";
    else
    {
    Sort s(noe,size);
    s.getdata();
	s.sort();
    }
    finish:
    return 0;
}
