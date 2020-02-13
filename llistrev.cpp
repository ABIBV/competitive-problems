#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }    
};

struct llist{
    Node *head;
    llist(){
        head = NULL;
    }

    void insert(int data){
        Node *temp = new Node(data);
        if(head == NULL){
            head = temp;
        }
        else{
            Node *curr;
            curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next = temp;
        }
        
        
    }

    void reverse(){
        Node *curr, *next, *prev;
        next = NULL;
        prev = NULL;
        curr = head;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void recursion(){
        recrev(head,NULL,NULL);
    }

    void recrev(Node *curr, Node *next, Node *prev){

        if(curr==NULL){
            head=prev;
            return;
        }
        else{
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            head = prev;
            recrev(curr, next, prev);
        }
    
        }

    int length(){
        Node *curr;
        curr = head;
        int count= 0;
        while(curr!=NULL){
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

    void deletefromlast2ptr(int k){
        Node *one, *two, *prev;
        one = head;
        two = head;
        for(int i=0;i<k;i++){
            two = two->next;
        }
        if()
        while(two!=NULL){
            two = two->next;
            prev = one;
            one = one->next;
        }
        prev->next = one->next;
        one=NULL;

    }
        

    void display(){
        if(head == NULL){
            cout<<"No Node Present"<<endl;
        }
        else{
            Node *curr;
            curr = head;
            while(curr -> next !=NULL){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<curr->data<<"->NULL"<<endl;
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
    newlist.deletefromlast2ptr(k);
    newlist.display();

    // newlist.reverse();
    // cout<<"\nLlist after reversed"<<endl;
    // newlist.display();
    // newlist.recursion();
    // cout<<"\nLlist after reversed using recursion"<<endl;
    // newlist.display();
    cout<<newlist.length();
    return 0;
}