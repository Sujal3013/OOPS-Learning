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

bool search(node*  head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
            temp=temp->next;
        }
    }
    return false;

}

void deletion(node* head,int val){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteathead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}

void deleteathead(node* &head){
    node* todelete= head;
    head=head->next;

    delete todelete;
}

//REVERSING A LINKED LIST [ITERATIVE METHOD]
node* reverse(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

//REVERSING LIST[RECURRSIVE METHOD]
node* Reversebyrecurrsion(node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead=Reversebyrecurrsion(head->next);
    head->next->next=head;
    head->next=NULL;
}

node* reversek(node* &k,int k){
    node* prev=NULL;
    node* curr=head;
    node* next;

    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
    head->next=reversek(next,k);
    }

    return prev;
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
