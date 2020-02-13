#include <iostream>
using namespace std;
class Contigous{
    int sum=0;
    public:
    void subarray(int *arr, int size){
        for(int i=0;i<size;i++){
            sum=0;
            for(int j=i;j<size;j++){
                sum+= arr[j];
                if(sum==0){
                    print(arr,i,j);
                }
            }
        }
    }

    void print(int *arr, int start, int end){
        for(int i=start;i<=end;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Contigous cont;
    cont.subarray(arr,size);
    return 0;
}