#include <iostream>
#include <stack>
using namespace std;

class Queuestack{
  
    stack<int> stack1;
    stack<int> stack2;
    
public:
    void enqueue(int data){
        stack1.push(data);
        
    }
    
    void display(){
        static stack<int> temp = stack1;
        while(!temp.empty()){
            int tempdata = temp.top();
            temp.pop();
            display();
            cout<<tempdata<<" ";
        }
    }

    void dequeue(){
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(!stack2.empty()){
            cout <<"Dequeue : "<<stack2.top()<<endl;
            stack2.pop();
        }
    }
    
    bool empty(){
        return stack1.empty() && stack2.empty();
    }
    
    void clear(){
        while(!empty())
            dequeue();
    }
    
};

int main(){
        
    Queuestack stqueue = Queuestack();
    int n,a;
    cout<<"\nEnter the Number of Elements : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        stqueue.enqueue(a);   
    }
    cout<<"\nQueue : ";
    stqueue.display();
    cout<<"\nDequeuing..." <<endl;
    stqueue.clear();
    return 0;
}