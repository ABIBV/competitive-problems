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

        void merge(llist l1, llist l2){
            Node *l1_node, *l2_node;
            l1_node = l1.head;
            l2_node = l2.head;
            while(l1_node!=NULL && l2_node!=NULL){
                if(l1_node->data < l2_node->data){
                    insert(l1_node->data);
                    l1_node = l1_node->next;

                }else{
                    insert(l2_node->data);
                    l2_node = l2_node->next;
                }
            }
            while(l1_node!=NULL){
                insert(l1_node->data);
                l1_node = l1_node->next;
            }
            while (l2_node!=NULL){
                insert(l2_node->data);
                l2_node = l2_node->next;
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
    llist list1,list2,list3;
    int m,n,a;
    cin>>m>>n;
    if(m==0){
        list1.insert(0);
    }else{
        for(int i=0;i<m;i++){
            cin>>a;
            list1.insert(a);
        }
    }
    if(n==0){
        list2.insert(0);
    }else{
        for(int i=0;i<n;i++){
            cin>>a;
            list2.insert(a);
        }
    }
    list3.merge(list1, list2);
    list3.display();
    return 0;
}


