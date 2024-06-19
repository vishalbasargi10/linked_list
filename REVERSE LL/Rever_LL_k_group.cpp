//Question-Given a linked list, write a function to reverse every k nodes (where k is an input to the function). 
//reverse the first sub_list of size k, while reversing keep track of the next node and previous node .let the pointer to the next node be next and pointer to the previous node be prev
//head->next=reverse(next,k)
//return prev(prev becomes head of the of thr list)

//recursive
#include<bits/stdc++.h>
using namespace std;

//link list node
class Node
{
    public:
        int data;
        Node* next;

};

//reveerse the linked list in groups of size k and reurn the pointer to the new head node
Node* reverse(Node* head,int k)
{
    //base case
    if(!head)
        return NULL;
    
    Node* current=head;
    Node* next=NULL;
    Node* prev=NULL;
    int count=0;

    //reverse first k nodes of the linked list
    while(current!=NULL && count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current =next;
        count++;
    
    }
    if(next!=NULL)
        head->next=reverse(next,k);

    return prev;


}

//  UTULITY FUNCTIONS
//function to push the node
void push(Node** head_ref,int new_data)
{
    //allocate node
    Node* new_node=new Node();

    //put in the data
    new_node->data=new_data;

    //link the old list of the new node
    new_node->next=(*head_ref);

    //move the head to pont to the new node
    (*head_ref)=new_node;

}

void printList(Node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;

    }
}

int main()
{
    //start with empty list
    Node* head=NULL;

    //created a linked list
    push(&head, 9); 
    push(&head, 8); 
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 

    cout<<"given linked list";
    printList(head);
    head=reverse(head,3);

    cout<<"\n reversed linked list";
    printList(head);

    return 0;


}