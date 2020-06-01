#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class HeapSort
{
public:
//int *arr;
int no_ele;
//int abc[100];
HeapSort(int n)
{
	no_ele=n;
	//arr=new int[no_ele];
}

// void getdata()
// {
//     for(int i=0;i<no_ele;i++)
//     {
//         cout<<"Enter element : ";
//         cin>>arr[i];
//     }

//     for(int k=0;k<no_ele;k++)
//     {
//         abc[k]=arr[k];
//     }
// }

void minHeap(int *abc,int i,int n)
{
	int j,temp;
    temp=abc[i];
    j=2*i;
    while(j<=n)
    {
        if(j<n && abc[j+1]<abc[j])
            j=j+1;
        if(temp<abc[j])
            break;
        else if (temp>=abc[j])
        {
            abc[j/2]=abc[j];
            j=2*j;
        }
    }
    abc[j/2]=temp;
    return;
}

void minSort(int abc[],int n)
{
    int i;
    for(i=n;i>=1;i--)
    {
        minHeap(abc,i,n);
    }
    printmin(abc);
}

void printmin(int abc)
{
    for(int z=0;z<=no_ele;z++)
    {
        cout<<abc[z]<<" ";
    }
    cout<<endl<<endl;
}

void maxHeap()
{

}

void maxSort()
{

}

    void make_heap(int *arr)
    {
        for (int i = no_ele / 2 - 1; i >= 0; i--)
        min_heap(arr,no_ele, i);
        
        for (int i=no_ele-1; i>=0; i--)
        {
            swap(arr[0], arr[i]);
            min_heap(arr,i, 0);
        }
        cout<<"\nMin - Heap ";
        showdata();

        for (int i = no_ele / 2 - 1; i >= 0; i--)
        max_heap(arr,no_ele, i);
        
        for (int i=no_ele-1; i>=0; i--)
        {
            swap(arr[0], arr[i]);
            max_heap(arr,i, 0);
        }
        cout<<"\nMax - Heap ";
        showdata();
    }

    void min_heap(int *arr,int n, int root)
    {
        int largest = root;
        int l = 2*root + 1;
        int r = 2*root + 2;
        
        if (l < n && arr[l] > arr[largest])
        largest = l;
        
        if (r < n && arr[r] > arr[largest])
        largest = r;
        
        if (largest != root)
        {
        swap(arr[root], arr[largest]);
        min_heap(arr,n, largest);
        }
    }

    void max_heap(int *arr,int n, int root)
    {
        int largest = root;
        int l = 2*root + 1;
        int r = 2*root + 2;
        
        if (l < n && arr[l] < arr[largest])
        largest = l;
        
        if (r < n && arr[r] < arr[largest])
        largest = r;
        
        if (largest != root)
        {
        swap(arr[root], arr[largest]);
        max_heap(arr,n, largest);
        }
    }

		void showdata()
    {
        cout<<"Sorted Data : \n-------\n";
    	for (int i=0; i<no_ele; ++i)
        cout << arr[i] << " ";
        cout << "\n";
    }

};

int main()
{
    int choice,size;
    cout<<"Enter the size of array : ";
    cin>>size;
	HeapSort s(size);
	//s.getdata();
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element : ";
        cin>>arr[i];
    }
    do
			{
                cout<<endl<<endl;
				cout<<"0.Exit\n1.Max Heap\n2.Min Heap\n3.Heap Sort\n";
				cout<<"Enter Your Choice : "<<" ";
                cin>>choice;
				switch(choice)
				{
                    case 0:
                    break;

					case 1:     
						s.maxSort();
						break;

                    case 2:     
						s.minSort(arr,size);
						break;

                    case 3:     
						s.make_heap(arr);
						break;
					
					default:
					    cout<<"invalid input"<<endl<<endl;
                        cout<<endl<<endl;
                }
			}while(choice!=0); 

         
    return 0;
}