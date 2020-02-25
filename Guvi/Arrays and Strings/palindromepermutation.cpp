#include <iostream>
#include <algorithm>
using namespace std;

void palindperm(string s){
    int len = s.length();
    int count[len],sum=0;
    count[len] = {0};
    for(int i=0;i<len;i++){
        if(s[i]==s[i+1]){
            sum+=4;
            i++;
        }else{
            sum++;
        }
    }
    if(len%2==0 && sum==len*2){
        cout<<"It is a palindrome"<<endl;
    }else if(len%2!=0 && sum == (len*2)-1){
        cout<<"It is a palindrome"<<endl;
    }else{
        cout<<"It is not a palindrome"<<endl;
    }
}

int main(){
    string st;
    cin>>st;
    sort(st.begin(),st.end());
    palindperm(st);
    return 0;
}