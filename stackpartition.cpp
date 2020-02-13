#include <iostream>
#include <map>

#define STCK1 0
#define STCK2 10
#define STCK3 20
int arr[30] = {0};
using namespace std;

int popelement(int pos,int cnt){
    int position = pos-1 + cnt;
    int del = arr[position];
    arr[position] = 0;
    return del;

}

int main(){
    
    int cnt[3] = {0};
    int stck, value,pos;
    map<int,int> mymap = {make_pair(1,STCK1), make_pair(2,STCK2),make_pair(3,STCK3)};
    cin>>stck>>value;
    while(stck!=0){
        arr[mymap[stck]+cnt[stck-1]] = value;
        cnt[stck-1]++;
        cin>>stck>>value;
    }
    // for(int i=0;i<30;i++)
    //    cout<<i<<" "<<arr[i]<<endl;
    cout<<"Enter stack to pop: ";
    cin>>pos;
    cout<<popelement(mymap[pos],cnt[pos-1]);
    return 0;
}