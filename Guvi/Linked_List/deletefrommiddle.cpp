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
            while(curr->next!=head){
                curr = curr->next;
                count++;
            }
            return count;
        }


        void deletefrommiddele(Node *delnode){
            delnode->data = delnode->next->data;
            delnode->next = delnode->next->next;
        }

        void delnode(int k){
            if(head == NULL){
                cout<<"No Node is present"<<endl;
            }else{
                Node *curr;
                curr = head;
                for(int i=0;i<k-1;i++){
                    curr = curr->next;
                }
                deletefrommiddele(curr);
            }
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
    int a,k;
    cin>>a;
    while(a!=-1){
        newlist.insert(a);
        cin>>a;
    }
    cout<<"\nLlist"<<endl;
    newlist.display();
    cout<<"\nEnter the Node to be deleted : ";
    cin>>k;
    newlist.delnode(k);
    cout<<"\nAfter deleting middle node :";
    newlist.display();
    return 0;
}
