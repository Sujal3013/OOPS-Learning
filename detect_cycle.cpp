//FLOYD'S ALGORITHM
// HARE & TORTOISE ALGORITHM

#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node &head,int val){
    node* n=new node(val);
    n->next=head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n= new node(val);
    node* temp=head;

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//MAKING A CYCLE

void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

//DETECTING A CYCLE

bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }else{
            return false;
        }
    }
}

void removecycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    
    fast=head;
    while(slow->next=fast->next){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=NULL;
    
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    // insertAtHead(head,4);
    display(head);
    deletion(head,3);
    deleteathead(head);
    node* newhead=reverse(head);
    display(newhead);

    return 0;
}
