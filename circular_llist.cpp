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
                temp->next = head;
            }
            else{
                curr=head;
                while(curr->next!=head){
                    curr=curr->next;
                }
                curr->next=temp;
                temp->next = head;
            }
        
        }
        
        // void reverse(){
        //     Node *curr, *next, *prev;
        //     next = NULL;
        //     curr = head;
        //     while(curr->next!=head){
        //         curr=curr->next;
        //     }
        //     prev = curr->next;
 
        //     while(curr->next!=head){
        //         next = curr->next;
        //         curr->next = prev;
        //         prev = curr;
        //         curr = next;
        //     }
        //     head = prev;
        // }
 
         int length(){
            Node *curr;
            curr = head;
            int count= 1;
            while(curr->next!=head){
                curr = curr->next;
                count++;
            }
            return count;
        }
 
    void deletefromlast(int k){
        int l = length();
        int del = l - k;
        Node *curr, *prev;
        curr = head;
        for(int i=0;i<del;i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next=curr->next;
        curr= NULL;
    }
    
    void reverse(){
      Node *curr, *next, *prev;
      curr = head;
      prev = head;
      next = NULL;
      while(prev->next!= head){
        prev = prev -> next; 
      }
      while(next!=head){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }
      head=prev;
      
    }
    
    void display(){
        if(head == NULL){
            cout<<"No Node Present"<<endl;
        }
        else{
            Node *curr;
            curr = head;
            while(curr->next!=head){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<curr->data<<"--->"<<curr->next->data<<endl;
        }
    }
};
 
 
int main(){
    llist newlist;
    int a,k;
    cin>>a;
    while(a!=-1){
        newlist.insert(a);
        cin>>a;
    }
    cout<<"\nLlist"<<endl;
    newlist.display();
    cout<<"Enter k ";
    cin>>k;
    newlist.deletefromlast(k);
    newlist.display();
    newlist.reverse();
    cout<<"Reversed : "<<endl;
    newlist.display();
    return 0;
}
