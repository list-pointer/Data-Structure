#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class HeapSort
{
public:
int min[100],sort[100];

void minHeap(int min[],int n,int i)
{
    // for(int z=1;z<n;z++)
    // {
    //     min[z]=arr[z];
    // }

    int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && min[l] > min[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && min[r] > min[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(min[i], min[largest]); 

		// Recursively heapify the affected sub-tree 
		minHeap(min, n, largest); 
	}

    for(int p=1;p<n;p++)
    {
        cout<<min[p]<<"    ";
    }
    cout<<endl;
}

void minSort(int arr[],int n)
{
// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) 
		minHeap(arr, n, i); 

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--) { 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap 
		minHeap(arr, i, 0); 
	}
}

void sorted(int arr[],int s)
{
cout<<"Sorted Array: ";
for(int i=1;i<s;i++)
{
cout<<arr[i]<<" ";
}
}

void display()
{
    
}

void maxHeap(int arr[],int n,int i)
{

}

void maxSort(int arr[],int n)
{

}

};

int main()
{
    HeapSort s;
    int choice,size;
    cout<<"Enter the size of array : ";
    cin>>size;
    size=size+1;
    int arr[size];
    for(int i=1;i<size;i++)
    {
        cout<<"Enter Value "<<i<<" : ";
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
						s.maxSort(arr,size);
						break;

                    case 2:     
						s.minSort(arr,size);
						break;

                    case 3:     
						s.sorted(arr,size);
						break;
					
					default:
					    cout<<"invalid input"<<endl<<endl;
                        cout<<endl<<endl;
                }
			}while(choice!=0); 

         
    return 0;
}