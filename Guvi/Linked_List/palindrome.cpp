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

        int checkPalindrome(Node* list2){
            Node* list1 = head;
            while(list1!=NULL){
                if(list1->data != list2->data){
                    return 0;
                }
                list1 = list1->next;
                list2 = list2->next;
            }
            return 1;
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
    llist list1,list2;
    int a,check;
    cin>>a;
    while(a!=-1){
        list1.insert((int)a);
        cin>>a;
    }
    cout<<"\nLlist"<<endl;
    list1.display();
    list2=list1;
    list2.reverse();
    
    check = list1.checkPalindrome(list2.head);
    if(check == 0){
        cout<<"List is not a Palindrome..."<<endl;
    }else{
        cout<<"List is a Palindrome..."<<endl;
    }
    return 0;
}
