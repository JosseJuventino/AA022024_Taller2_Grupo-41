#include <iostream>


void Heapify(int arr[], int i, int n){
    int left = 2*i + 1; // left child
    int right = 2*i + 2; //right child
    int max = i;

    if(left < n && arr[left] > arr[max]){
        max = left;
    } else{
        max = i;
    }

    if(right < n && arr[right] > arr[max]){
        max = right;
    }

    if(max != i){
        // Make a swap between arr[i] and arr[max]
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        Heapify(arr, max, n);
    }
    

}

void BuildMaxHeap(int arr[], int n){

    for(int i = n / 2 - 1; i >= 0; i--){  // n/2 to 0
        Heapify(arr, i, n);
    }
}



void HeapSort(int arr[], int n){
    BuildMaxHeap(arr, n);

    for (int i = n - 1; i >= 1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr, 0, i);
    }
}


int main(){
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr, n);

    std::cout << "Sorted array is \n";
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    
    return 0;
}