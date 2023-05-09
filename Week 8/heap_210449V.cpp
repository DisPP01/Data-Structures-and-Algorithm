#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    
    if(arr[left] > arr[largest] && left < n){   //checking the largest value with the left node
        largest = left;
    }
    if(arr[right] > arr[largest] && right < n){ //checking the largest value with the right node
        largest = right;
    }
    if(largest != root){
        swap(arr[root],arr[largest]);   //swapping the current largest value with the root value
        heapify(arr ,n ,largest);   //calling the heapify again to heapify the heap
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for(int i = n/2 -1; i>=0; i--){
        heapify(arr,n,i);
    }

    // extracting elements from heap one by one 
    for(int i = n-1; i>=0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);   //to heapify the heap again after the changes
    }

}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
    cout << arr[i] << " ";
    cout << "\n";
}
  
// main program
int main()
{
    int array_size;
    cout << "Enter the array size: ";   //getting the user input for the array size for the heap
    cin >> array_size;
    
    int heap_arr[array_size];   //initializing the array to the given size

    cout << "Enter the elements of the array: ";    //getting the elements of the array from the user
    for(int i=0; i<array_size; i++){
        cin >> heap_arr[i]; //inserting the elements one by one to the array
    } 
    
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
    
    heapSort(heap_arr, n);
    
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}