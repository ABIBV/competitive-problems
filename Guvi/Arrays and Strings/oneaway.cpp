#include <iostream>
#include <algorithm>
using namespace std;

int oneaway(string one, string two){
    int count = 0;
    int maxlen = one.length() > two.length() ? one.length() : two.length();
    int minlen = one.length() < two.length() ? one.length() : two.length();
    int diff = maxlen - minlen;
    if(diff<=1 && diff>=0){
        if(diff == 0){
            for(int i=0;i<maxlen;i++){
                if(one[i]!=two[i]){
                    count++;
                }
            }
            return count==1 ? count : 0;
        }else{
            for(int i=0;i<minlen;i++){
                if(one[i]==two[i]){
                    count++;
                }
            }
            return count == 1 ?count:0;
        }
    }else{
        return 0;
    }
}

int main(){
    string one,two;
    cin>>one>>two;
    if(oneaway(one,two)){
        cout<<"It is one away"<<endl;
    }else{
        cout<<"It is not one away"<<endl;
    }
    return 0;
}