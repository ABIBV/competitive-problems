#include <iostream>
#include <stack>
using namespace std;

void displaystack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void sortstack(stack<int> s){
    stack<int> tmp;
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        while(!tmp.empty() && tmp.top()<temp){
                s.push(tmp.top());
                tmp.pop();
        }
        tmp.push(temp);
    }
    cout<<"Arranged : ";
    displaystack(tmp);
}

int main(){
    stack<int> s,tmp;
    int n,a;
    cout<<"\nEnter the Number of Elements : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        s.push(a);
    }
    cout<<"Stack : ";
    displaystack(s);
    sortstack(s);
    return 0;
}