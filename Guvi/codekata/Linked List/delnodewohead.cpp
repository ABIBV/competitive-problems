#include <iostream>
#include <map> 
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
    map<int,Node*> mapping;

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
                mapping[head->data] = head;
            }
            else{
                curr=head;
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                curr->next=temp;
                mapping[curr->data] = curr;
            }
        }
         
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

        void delnode(int k){
            Node *del = mapping[k];
            del->data = del->next->data;
            del->next = del->next->next;
        }
    
        void display(){
            if(head == NULL){
                cout<<"No Node Present"<<endl;
            }
            else{
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
    int n,k,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        newlist.insert(a);
    }
    cin>>k;
    newlist.delnode(k);
    newlist.display();
    return 0;
}