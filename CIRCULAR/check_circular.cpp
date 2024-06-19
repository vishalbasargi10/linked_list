//Given a singly linked list, find if the linked list is circular or not. 
//A linked list is called circular if it is not NULL-terminated and all nodes are connected in the form of a cycle

//node
//An empty linked list is considered circular.

//Declare a Node pointer node and initialize it to the head’s next
//Move node pointer to the next node, while the node is not equal to nullptr and node is not equal to the head//
//After coming out of the loop, check if the node is equal to head then return true, else return false
#include<bits/stdc++.h>
using namespace std;

//link list node
struct Node
{
    public:
        int data;
        struct Node* next;
};

//functions return true if given linked list is circular or not
bool isCircular(struct Node *head)
{
    //an empty linked list is circular
    if(head==NULL)
        return true;
    
    //next of head
    struct Node *node=head->next;

    //this loop would stop in both cases if circular and not circular
    while(node!=NULL && node!=head)
        node=node->next;
    
    //if loop stopped because of circular condition
    return (node==head);
}

//utility function create new node
Node *newNode(int data)
{
    struct Node *temp=new Node;
    temp->data=data;                    //not understood??????????????????????????????????????????????????
    temp->next=NULL;
    return temp;
}

int main()
{
    //start with an empty list
    struct Node* head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);

    isCircular(head)?cout<<"yes\n":cout<<"no\n";

    //making linked list circular
    head->next->next->next->next=head;

    isCircular(head)?cout<<"yes\n":cout<<"no";

    return 0;
}



