//traverst he linked list from the head node ehile treversing compsre each node with its next node
//if thr data of the next node is the same as the current node then delete the next node
//before we delete aa node we need to store the next pointer of the node

#include<bits/stdc++.h>
using namespace std;

//linke dlsit node
class Node
{
    public:
        int data;
        Node* next;
};

//the finction removes duplicates from thr linked list
void removeDuplicates(Node* head)
{
    //pointer to traverse the linked lsit
    Node* current=head;
    //pointer to store the next pointer of the node to be deleted
    Node* next_next;
    //do nothing if the list ids empty
    if(current==NULL)
    {
        return;
    }
    //traverse the list till laast node
    while (current->next!=NULL)
    {
        //compare current node with next node
        if( current->data == current->next->data )
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}

//function  to insert  a node at the at the beginning of the linked lsit
void push(Node** head_ref,int new_data)
{
    //alloccate node
    Node* new_node=new Node();
    //put in the data
    new_node->data=new_data;
    //link the old list ro the new node
    new_node->next=(*head_ref);
    //move the head to the point of the new node
    (*head_ref)=new_node;
}

//function to print node
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
    //start with an empty node
    Node* head=NULL;
    push(&head,20);
    push(&head,13);
    push(&head,13);
    push(&head,11);
    push(&head,11);
    push(&head,11);

    cout<<"linked list before dulicaed rmeoval"<<endl;
    printList(head);

    removeDuplicates(head);
    cout<<"linke lsit after duplicate removal"<<endl;
    printList(head);
    return 0;
    
}