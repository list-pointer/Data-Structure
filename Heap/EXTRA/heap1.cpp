// // C++ program for implementation of Heap Sort 
// #include <iostream> 
// using namespace std; 

// // To heapify a subtree rooted with node i which is 
// // an index in arr[]. n is size of heap 
// void heapify(int arr[], int n, int i) 
// { 
// 	int largest = i; // Initialize largest as root 
// 	int l = 2 * i + 1; // left = 2*i + 1 
// 	int r = 2 * i + 2; // right = 2*i + 2 

// 	// If left child is larger than root 
// 	if (l < n && arr[l] > arr[largest]) 
// 		largest = l; 

// 	// If right child is larger than largest so far 
// 	if (r < n && arr[r] > arr[largest]) 
// 		largest = r; 

// 	// If largest is not root 
// 	if (largest != i) { 
// 		swap(arr[i], arr[largest]); 

// 		// Recursively heapify the affected sub-tree 
// 		heapify(arr, n, largest); 
// 	} 
// } 

// // main function to do heap sort 
// void heapSort(int arr[], int n) 
// { 
// 	// Build heap (rearrange array) 
// 	for (int i = n / 2 - 1; i >= 0; i--) 
// 		heapify(arr, n, i); 

// 	// One by one extract an element from heap 
// 	for (int i = n - 1; i >= 0; i--) { 
// 		// Move current root to end 
// 		swap(arr[0], arr[i]); 

// 		// call max heapify on the reduced heap 
// 		heapify(arr, i, 0); 
// 	} 
// } 

// /* A utility function to print array of size n */
// void printArray(int arr[], int n) 
// { 
// 	for (int i = 0; i < n; ++i) 
// 		cout << arr[i] << " "; 
// 	cout << "\n"; 
// } 

// // Driver program 
// int main() 
// { 
// 	int arr[] = { 12, 11, 13, 5, 6, 7 }; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 

// 	heapSort(arr, n); 

// 	cout << "Sorted array is \n"; 
// 	printArray(arr, n); 
// } 









#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class HeapSort
{
public:
int choice,size;
int arr[1000];

void get()
{
    cout<<"Enter the size of array : ";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter Value "<<i<<" : ";
        cin>>arr[i];
    }
    do
			{
				cout<<"0.Exit\n1.Max Heap\n2.Min Heap\n3.Heap Sort\n";
				cout<<"Enter Your Choice : "<<" ";
                cin>>choice;
				switch(choice)
				{
                    case 0:
                    break;

					case 1:     
						//maxHeap();
						break;

                    case 2:     
						minHeap();
						break;

                    case 3:     
						sort();
						break;
					
					default:
					    cout<<"invalid input"<<endl<<endl;
				}
			}while(choice!=0);  

}

void maxHeap(int i)
{
    int largest = i; 
	int l = 2 * i + 1;  
	int r = 2 * i + 2; 

	if (l < size && arr[l] > arr[largest]) 
		largest = l; 
 
	if (r < size && arr[r] > arr[largest]) 
		largest = r; 

	if (largest != i) { 
		swap(arr[i], arr[largest]); 
    maxHeap(largest);
}
cout<<"Max Heap : ";
display();
}

void minHeap()
{

}

void sort()
{ 

	for (int i = size / 2 - 1; i >= 0; i--) 
		maxHeap(i); 
	for (int i = size - 1; i >= 0; i--) { 

		swap(arr[0], arr[i]); 
		maxHeap(0); 
	} 
} 

void display()
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

};

int main()
{
    HeapSort s;
    s.get();
    s.sort();
    return 0;
}