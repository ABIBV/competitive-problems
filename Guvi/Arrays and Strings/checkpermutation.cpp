#include <iostream>
#include <algorithm>
using namespace std;

int checkpermutation(string s1, string s2){
    if(s1.length() != s2.length()){
        return 0;
    }else{
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int len = s1.length();
        for(int i=0;i<len;i++){
            if(s1[i]!=s2[i]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    string st1,st2;
    cin>>st1>>st2;
    if(checkpermutation(st1,st2)){
        cout<<"The Given Strings are permutations of each other"<<endl;
    }else{
        cout<<"The Given Strings are not permutations of each other"<<endl;
    }
    return 0;
}