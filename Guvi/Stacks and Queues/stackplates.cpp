#include <iostream>
#define SIZE 10
using namespace std;

struct STACK{
    
};

class Stack{
    int stack[SIZE];
    int top = -1;
    public:
       
        

        void push(int data){
            if(top<=9){
                stack[++top] = data;
            }else{

            }
        }
};