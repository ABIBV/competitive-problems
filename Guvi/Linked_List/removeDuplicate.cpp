#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class Linkedlist{
    Node* head;
    public:
        Linkedlist(){
            head = NULL;
        }

        void insert(int data){
            Node *temp, *curr;
            temp = new Node(data);
            if(head == NULL){
                head = temp; 
            }else{
                curr = head;
                while(curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = temp;
            }
        }

        void removeDuplicate(){
            Node *temp, *curr, *prev;
            temp = head;
            while(temp->next != NULL){
                curr = temp->next;
                prev = temp;
                while(curr!= NULL){
                    if(curr->data == temp->data){
                         prev ->next = curr->next;
                         curr = prev->next;
             
                    }
                    else{
                        prev = curr;
                        curr = curr->next;
                    }
                 
                }
                temp = temp->next;
            }
            
        }

        void display(){
            cout<<"print started"<<endl;
            Node *curr;
            curr = head;
            while(curr){
                cout<<curr->data<<" -> ";
                curr = curr->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    Linkedlist ll;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        ll.insert(a);
    }
    ll.display();
    ll.removeDuplicate();
    ll.display();
    return 0;
}
