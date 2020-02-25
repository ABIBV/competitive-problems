#include <iostream>
#include <algorithm>
using namespace std;

int unique(string st){
    sort(st.begin(), st.end());
    for(int i=0;i<st.length()-1; i++){
        if(st[i]==st[i+1]){
            return 1;
        }
    }
    return 0;
}

int main()
{
    string st;
    cin>>st;
    if(!unique(st)){
        cout<<"String contains unique characters"<<endl;
    }else{
        cout<<"String contains repeated characters"<<endl;
    }
    return 0;
}
