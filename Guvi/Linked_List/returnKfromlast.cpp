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
         
         int length(){
            Node *curr;
            curr = head;
            int count= 1;
            while(curr->next!=NULL){
                curr = curr->next;
                count++;
            }
            return count;
        }
 
    int returnfromlast(int k){
        int l = length();
        int del = l - k;
        Node *curr;
        curr = head;
        for(int i=0;i<del;i++){
            curr = curr->next;
        }
        return curr->data;
    }
    

 
    
    void display(){
        if(head == NULL){
            cout<<"No Node Present"<<endl;
        }
        else{
            Node *curr;
            curr = head;
            while(curr->next!=NULL){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<curr->data<<endl;
        }
    }
};
 
 
int main(){
    llist newlist;
    int a,k,last;
    cin>>a;
    while(a!=-1){
        newlist.insert(a);
        cin>>a;
    }
    cout<<"\nLlist"<<endl;
    newlist.display();
    cout<<"Enter k ";
    cin>>k;
    last = newlist.returnfromlast(k);
    cout<<"Element "<<k<<" from last : "<<last<<endl;
    return 0;
}
