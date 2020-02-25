#include <iostream>
#define size 4
using namespace std;

void zeromat(int a[][size]){
    int row[size] = {0};
    int col[size] = {0};
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(a[i][j] == 0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(row[i] || col[j]){
                a[i][j]=0;
            }
        }
    }
}

void printmatrix(int a[][size]){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int a[size][size];
    for(int i=0;i<size;i++){
        cout<<"\nEnter 4 values :";
        for(int j=0;j<size;j++){
            cin>>a[i][j];
        }
    }
    printmatrix(a);
    cout<<endl<<"zero matrix...\n";
    zeromat(a);
    printmatrix(a);
    
}
