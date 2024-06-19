//using dummy nodes
//O(n)+O(1)
//sc=o(1)
#include<bits/stdc++.h>
using  namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void insertAttail(Node* &tail,Node* curr)
{
    tail->next=curr;
    tail=curr;
}

Node* sorta(Node* head)
{   
    Node* zerohead=new Node();
    Node* zerotail=zerohead;
    Node* onehead=new Node();
    Node* onetail=onehead;
    Node* twohead=new Node();
    Node* twotail=twohead;

    Node* curr=head;
    //created lists for 0 1 2 
    while (curr!=NULL)
    {
        int value=curr->data;
        //created funtion to copy elements
        if(value==0)
        {
            insertAttail(zerotail,curr);
        }
        else if(value==1)
        {
            insertAttail(onetail,curr);
        }
        else if(value==2)
        {
            insertAttail(twotail,curr);
        }
        curr=curr->next;
    }

    //now merge

    if(onehead->next!=NULL) //1 ka list is not empty
    {
        zerotail->next=onehead->next;
    } 
    // 1 ka list empty
    else
    {
        zerotail->next=twohead->next;
    }   

    onetail->next=twohead->next;
    twotail->next=NULL;
    //setip head
    head=zerohead->next;
    //delte dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}



void push(Node** head_ref,int new_data)
{
    Node* new_Node=new Node();
    new_Node->data=new_data;
    new_Node->next=*head_ref;
    *head_ref=new_Node;
}

void printList(Node* node)
{
    while(node!=NULL)
    {
        cout<<" "<<node->data;
        node=node->next;
    }
}

int main()
{
    Node* head=NULL;
    push(&head,0);
    push(&head,2);
    push(&head,1);
    push(&head,2);
    push(&head,1);
    push(&head,0);

    sorta(head);
    printList(head);
}
