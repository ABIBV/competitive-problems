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


       void dellast(Node *node,int k){
           if(node == NULL){
               return;
           }else{
               dellast(node->next,k);
               
               if(node->data == k){
                   if(node->next!=NULL){ 
                        node->data = node->next->data;
                        node->next = node->next->next;
                        display();
                        exit(0);
                    }
               }
              

               
           }
       }

        void delnode(int k){
            if(head == NULL){
                return;
            }else{
                Node *node = head;
                dellast(node,k);
            }
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
    int a,k,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        newlist.insert(a);
    }
    cin>>k;
    newlist.delnode(k);
    return 0;
}
