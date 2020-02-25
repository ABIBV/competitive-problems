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

        int findCarry(int sum){
            int carry = 0;
            if(sum > 9){
                carry = 1;
            }else{
                carry = 0;
            }
            return carry;
        }

        llist addLists(Node* list2, llist list3){
           // list3.head = new Node(0);
            Node* add1 = head;
            Node* add2 = list2;
            Node* remain;
            int carry = 0,sum=0;
            while(add1!=NULL && add2!=NULL){
                sum = carry + add1->data + add2->data;
                carry = findCarry(sum);
                list3.insert(sum%10);
                add1 = add1->next;
                add2 = add2->next;
            } 
            if(add1 == NULL){
                remain = add2;
            }else{
                remain = add1;
            }
            while(remain!=NULL){
                sum = carry + remain->data;
                carry = findCarry(sum);
                list3.insert(sum%10);
                remain = remain->next;
            }
            carry = findCarry(sum);
            if(carry>0){
                list3.insert(carry);
            }
            return list3;
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
    llist list1,list2,list3;
    int a,b;
    cout<<"\nEnter two Numbers : ";
    cin>>a>>b;
    if(a==0){
        list1.insert(0);
    }
    while(a>0){
        list1.insert(a%10);
        a/=10;
    }
    if(b==0){
        list2.insert(0);
    }
    while(b>0){
        list2.insert(b%10);
        b/=10;
    }
   
    
    list3 = list1.addLists(list2.head, list3);
    list1.reverse();
    list2.reverse();
    list3.reverse();
    cout<<"\nLists"<<endl;
    list1.display();
    list2.display();
    list3.display();
    return 0;
}
