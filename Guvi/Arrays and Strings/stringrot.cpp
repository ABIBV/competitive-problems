#include <iostream>
using namespace std;

int rotated(string s1, string s2){
    if(s1.length()!=s2.length()){
        return 0;
    }else{
        s1 = s1+s1;
        if(s1.find(s2)!=string::npos);
            return 1;
        return 0;    
    }
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    if(rotated(s1,s2)){
        cout<<"Rotated"<<endl;
    }else{
        cout<<"Not Rotated"<<endl;
    }
    return 0;
}