#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//link list node
struct Node
{
    public:
        int data;
        struct Node* next;
};

void removeLoop(struct Node*,struct Node*);

int detectAndRemoveLoop(struct Node* list)
{
    struct  Node *slow=list,*fast=list;

    //iterate and find if loop exists or not
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        //if slow and fast point meet at some point then loop is present
        if(slow==fast)
        {
            removeLoop(slow,list);

            //return 1 to indicate loop is found

            return 1;
        }
    }
    return 0;
}

    //function to remove loop
    //loop--->pointer to one of thr loop nodes
    //head--->pointer to start node of the liked list
void removeLoop(struct Node* loop_node,struct Node* head)
{
    struct Node* ptr1 =loop_node;
    struct Node* ptr2=loop_node;

    //count number of nodes in loop
    unsigned int k=1,i;
    while(ptr1->next!=ptr2)
    {
        ptr1=ptr1->next;
        k++;
    }



    //fix one pointer to head
    ptr1=head;
    //and the other pointer to k nodes after head
    ptr2=head;

    for(i=0;i<k;i++)
        ptr2=ptr2->next; 
    //move the pointers at the same pace they will meet at loop starting point
    while(ptr2!=ptr1)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;

    }

    //get pointer to the last  node
    while(ptr2->next!=ptr1)
        ptr2=ptr2->next;
    //set the next node of the the loop ending node to fix the loop
    ptr2->next=NULL;

}

//functoion to print the linekd list
void printList(struct Node* node)
{
    //print the list after loop removal
    while(node !=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;

    }

}

struct Node* newNode(int key)
{
    struct Node* temp=new Node();
    temp->data=key;                     //did not underatsnd???????????????//
    temp->next=NULL;
    return temp;
}

int main()
{
    struct Node* head=newNode(50);
    head->next=newNode(20);
    head->next->next=newNode(15);
    head->next->next->next=newNode(4);
    head->next->next->next->next=newNode(10);

    //create a loop for testing
    head->next->next->next->next->next=head->next->next;
    
    detectAndRemoveLoop(head);

    cout<<"linked lsit after removing loop\n";

    printList(head);

}

