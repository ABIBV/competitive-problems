#include <iostream>
using namespace std;
#define size 4

void rotatematrix(int a[][size]){
    int temp;
    for(int i=0;i<size/2;i++){
        for(int j=i;j<=size-i-1;j++){
            temp = a[i][j];
            a[i][j] = a[j][size-1-i];
            a[j][size-1-i] = a[size-i-1][size-j-1];
            a[size-i-1][size-j-1] = a[size-j-1][i];
            a[size-j-1][i] = temp;
        }
    }
}

void printmatrix(int a[][size]){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int a[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<"\nEnter the value for a["<<i+1<<"]["<<j+1<<"] :";
            cin>>a[i][j];
        }
    }
    printmatrix(a);
    rotatematrix(a);
    cout<<"\nMatrix rotated :\n";
    printmatrix(a);
}
