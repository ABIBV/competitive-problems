#include <iostream>
 
using namespace std;
 
class llist{
    struct Node{
        int data;
        struct Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }    
    };
    public:
        Node *head;
        llist(){
            head = NULL;
        }
 
        void insert(int data){
            Node *temp = new Node(data);
            Node *curr;
            if(head == NULL){
                head = temp;
            }
            else{
                curr=head;
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                curr->next=temp;
            }
        
        }
         
    
    void reverse(){
      Node *curr, *next, *prev;
      curr = head;
      prev = NULL;
      next = NULL;
      while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }
      head=prev;
    }

    
    void display(){
        if(head != NULL){
            Node *curr;
            curr = head;
            while(curr->next!=NULL){
                cout<<curr->data<<" ";
                curr=curr->next;
            }
            cout<<curr->data<<endl;
        }
    }
};
 
 
int main(){
    llist newlist;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        newlist.insert(a);
    }
    newlist.reverse();
    newlist.display();
    return 0;
}
