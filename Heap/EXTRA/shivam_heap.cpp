#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
class heap{
private:
int size, *maxheap, *minheap, *sorted;
public:
heap(int len){
size=len;
maxheap = new int(size);
minheap = new int(size);
sorted = new int(size);
}
// void maxHeap(int arr[]){
// for(int i=1;i<size;i++)
// maxheap[i]=arr[i];
// for(int i=2;i<size;i++){
// if(maxheap[i/2]<maxheap[i]){
// int k=i;
// while(k>1){
// if(maxheap[k/2]<maxheap[k]){
// swap(maxheap[k/2],maxheap[k]);
// k=k/2;
// }
// }
// }
// }
// cout<<"Max Heap: ";
// for(int i=1;i<size;i++){
// cout<<maxheap[i]<<" ";
// }
// }
void maxHeap(int arr[]){
for(int i=1;i<size;i++)
maxheap[i]=arr[i];
for(int i=2;i<size;i++){
if(maxheap[i/2]<maxheap[i]){
int k=i;
if(maxheap[k/2]<maxheap[k]){
swap(maxheap[k/2],maxheap[k]);
k=k/2;
}
}
}
cout<<"Max Heap: ";
for(int i=1;i<size;i++){
cout<<maxheap[i]<<" ";
}
}
void maxHeapSort(int arr[]){
maxHeap(arr);
// for(int i=1;i<size;i++){
// if(maxheap[i]!=0){
// sorted[i]=maxheap[1];
// maxheap[i]=0;
// maxHeap(maxheap);
// }
// }
// maxheap[1]=maxheap[size-1];
int j=1;
for(int i=size-1;i>0;i--){
// if(maxheap[])
sorted[j]=maxheap[1];
j++;
// maxheap[1]=maxheap[i];
swap(maxheap[1],maxheap[i]);
// delete(maxheap[i]);
maxheap[i]=-987654321;
maxHeap(maxheap);
}
// cout<<"Max Heap Sorted: ";
// for(int i=1;i<size;i++){
// cout<<sorted[i]<<" ";
// }
}
};

int main(){
int size,*array;
cout<<"Enter the size of the array: ";
cin>>size;
size = size+1;
array = new int[size];
for(int i=1;i<size;i++){
cout<<"Enter "<<i<<" element: ";
cin>>array[i];
}
cout<<endl<<"Entered Elements: ";
for(int i=1;i<size;i++){
cout<<array[i]<<" ";
}
heap obj(size);
cout<<"1. Apply Max Heap/n2. Apply Min Heap/";
obj.maxHeapSort(array);
return 0;
}