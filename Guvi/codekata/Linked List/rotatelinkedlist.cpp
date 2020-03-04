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
         
    
    void rotate(int k){
        Node *slow, *fast, *slowback;
        slow = head;
        fast = head;
        for(int i=1;i<k;i++){
            fast = fast->next;
        }
        while(fast->next!=NULL){
            slowback = slow;
            fast = fast->next;
            slow = slow->next;
        }
        slowback->next = NULL;
        fast->next = head;
        head = slow;
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
    int n,a,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        newlist.insert(a);
    }
    cin>>k;
    newlist.rotate(k);
    newlist.display();
    return 0;
}
