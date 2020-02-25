#include <iostream>
#include <unordered_set>

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

        Node* intersection(Node* list2){
            Node *list1 = head;
            unordered_set<Node*> nodes;
            while(list1!=NULL){
                nodes.insert(list1);
                list1=list1->next;
            }

            while(list2!=NULL){
                if(nodes.find(list2) != nodes.end()){
                    return list2;
                }
                list2 = list2->next;   
            }
            return NULL;
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

        void makeintersection(Node* list2, int pos){
            int len = length();
            if(pos>len){
                cout<<"Position is greater than the length"<<endl;
            }else{
                Node* list1 = head;
                for(int i=0;i<pos-1;i++){
                    list1=list1->next;
                }
                list1->next = list2;
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
    llist list1,list2;
    llist check = llist();
    int a,pos;
    cout<<"\nEnter data for 1st list : ";
    cin>>a;
    while(a!=-1){
        list1.insert(a);
        cin>>a;
    }
    cout<<"\nEnter data for 2nd list : ";
    cin>>a;
    while(a!=-1){
        list2.insert(a);
        cin>>a;
    }
    cout<<"Do you want to make intersection ?(0/1)"<<endl;
    cin>>a;
    if(a==1){
        cout<<"Enter the position you want to make intersection : ";
        cin>>pos;
        list1.makeintersection(list2.head,pos);
    }
    check.head = list1.intersection(list2.head);
    if(check.head == NULL){
        cout<<"No intersection found"<<endl;
    }else{
        cout<<"Intersection found at "<<check.head->data<<endl;
    }
    return 0;
}
