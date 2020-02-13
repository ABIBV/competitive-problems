#include <iostream>
using namespace std;

class MergeSort{
    public:
    void merge(int arr[], int left, int mid, int right) 
    { 
        int i, j, k; 
        int llen = mid - left + 1; 
        int rlen =  right - mid; 
        int Left[llen], Right[rlen]; 

        for (i = 0; i < llen; i++) 
            Left[i] = arr[left + i]; 
        for (j = 0; j < rlen; j++) 
            Right[j] = arr[mid + 1+ j]; 
    
        i = 0;
        j = 0;
        k = left;
        while (i < llen && j < rlen) 
        { 
            if (Left[i] <= Right[j]) 
            { 
                arr[k++] = Left[i++]; 
            } 
            else
            { 
                arr[k++] = Right[j++]; 
            } 
        } 

        while (i < llen) 
        { 
            arr[k++] = Left[i++]; 
        } 

        while (j < rlen) 
        { 
            arr[k++] = Right[j++]; 
        } 
    } 

    void mergeSort(int arr[], int left, int right) 
    { 
        if (left < right) 
        { 
            int mid = left+(right-left)/2; 
            mergeSort(arr, left, mid); 
            mergeSort(arr, mid+1, right); 
            merge(arr, left, mid, right); 
        } 
    } 

    void display(int arr[], int size) 
    { 
        int i; 
        for (i=0; i < size; i++) 
            cout<<arr[i]<<" "; 
        cout<<"\n"; 
    } 
    
};

int main() 
{ 
    int arr[20],arr_size;
    cin>>arr_size;
    for(int i=0;i<arr_size;i++){
        cin>>arr[i];
    } 
    MergeSort msort;
    cout<<"Array before Sorting\n"; 
    msort.display(arr, arr_size); 
    msort.mergeSort(arr, 0, arr_size - 1); 
    cout<<"\nArray after Sorting\n"; 
    msort.display(arr, arr_size); 
    return 0; 
} 