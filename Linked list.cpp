#include<iostream>
using namespace std;
class node {
    int data;
    node* next;
    public:
    node(int data){
        this->data=data;
        this->next=NULL;
    }

};
node* takeinputLL(){
    int data;
    cin>>data;
    node* head=NULL;
    node* tail= NULL;
    while(data!=-1){
        node * newnode=new node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        tail->next=newnode;
        tail=tail->next;     
        cin>>data;
    }
    return head;
}
//Function to print linked list
void printLL(node * head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->"<<" ";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<"\n";
    return;
} 



int main(){
    node* head;
    head=takeinputLL();
    printLL(head);
    return 0;
}

