#include<iostream>
using namespace std;

struct Node
{
   int data;
   struct Node* next;
};

struct Node* createNode(int num){

    struct Node* temp=new Node;
    temp->data=num;
    temp->next=NULL;
    return temp;
}

// Linklist- all possible insertion operation
struct Node* insertAtBegin(struct Node* head,int num)
{
    struct Node* temp=createNode(num);
    temp->next=head;
    head=temp;
    return head;
};

struct Node* insertAtEnd(struct Node* head,int num)
{
    struct Node* temp=head;
    while (temp->next)
    {
        temp=temp->next;
    }
    temp->next=createNode(num);

    return head;
};

struct Node* insertAtPosition(struct Node* head,int num,int pos)
{
    int k=0;
    struct Node* temp=head;

    // finding the size of the list
    int list_size=0;
    struct Node* itr=head;
    while (itr)
    {
        itr=itr->next;
        list_size++;
    }
    
    if (pos<=0){
        head=insertAtBegin(head,num);
    }
    else if(pos>=list_size){
        head=insertAtEnd(head,num);
    }

    else{
        while (k<pos-1)
        {
            temp=temp->next;
            k++;
        }
        struct Node* node=createNode(num);
        node->next=temp->next;
        temp->next=node;
    }
    return head;
};

// Linklist- all possible deletion operation
struct Node* deleteFromFront(struct Node* head){
    struct Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head){

    struct Node* temp=head;
    //             +(temp)
    // -2 -1 0 9 1 2 3(next=NULL)
    while (temp->next->next)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}

struct Node* deleteFromPosition(struct Node* head,int pos){

    int k=0;
    struct Node* temp=head;

    // finding the size of the list
    int list_size=0;
    struct Node* itr=head;
    while (itr)
    {
        itr=itr->next;
        list_size++;
    }
    
    if (pos<=0){
        head=deleteFromFront(head);
    }
    else if(pos>=list_size){
        head=deleteFromEnd(head);
    }

    else{
        while (k<pos-1)
        {
            temp=temp->next;
            k++;
        }
        struct Node* n;
        n=temp->next;
        temp->next=temp->next->next;
        free(n);
    }
    return head;
}

void PrintList(struct Node* head){

    if (!head) cout<<"Linked List is empty !"<<endl;
    struct Node* temp=head;
    while (temp)
    { 
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void Peek(struct Node* head,int pos){
        int k=0;
    struct Node* temp=head;

    // finding the size of the list
    int list_size=0;
    struct Node* itr=head;
    while (itr)
    {
        itr=itr->next;
        list_size++;
    }
    
    if (pos==0){
        cout<<"The element at position "<<pos<<" is "<<head->data<<endl;
    }
    else if(pos>=list_size or pos<0){
        cout<<"Invalid position! "<<"Position ranges from: 0 -> "<<list_size-1<<endl;
    }

    else{
        while (k<pos-1)
        {
            temp=temp->next;
            k++;
        }
    cout<<"The element at position "<<pos<<" is "<<temp->next->data<<endl;
    }
}

int main(){

    struct Node* head;
    head=createNode(0);
    head=insertAtBegin(head,-1);
    head=insertAtBegin(head,-2);
    head=insertAtBegin(head,-3);
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,3);
    PrintList(head);
    head=insertAtPosition(head,9,4);
    cout<<endl;
    PrintList(head);
    head=deleteFromFront(head);
    cout<<endl;
    PrintList(head);
    head=deleteFromEnd(head);
    cout<<endl;
    PrintList(head);
    head=deleteFromPosition(head,3);
    cout<<endl;
    PrintList(head);
    cout<<endl;
    Peek(head,3);
    return 0;
}