#include <iostream>
using namespace std;



int main(){
    string st1, compstr = "";

    int top=-1,count=0;
    cin>>st1;
    char stack[100];
    stack[++top]=st1[0];
    count++;
    for(int i=1;i<st1.length();i++){
        if(top==-1){
            stack[++top]=st1[i];
        }
        if(st1[i]!=stack[top] && top!=-1){
            compstr+=stack[top];
            compstr+=(char)('0'+count);
            count=0;
            while(top!=-1){
                stack[top--]='\0';
            }
            stack[++top]=st1[i];
            count++;
        }else{
            stack[++top]=st1[i];
            count++;
        }   
    }
      compstr+=stack[top];
    compstr+=(char)('0'+count);

    cout<<compstr<<endl;
    return 0;
}