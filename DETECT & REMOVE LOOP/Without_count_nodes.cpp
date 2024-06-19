//after deteccting the loop if we start the slow pointer from the head and move both slow and fast 
//fast pointers at the same speed until fast doesnt mmet ,they would meet at the beginning of the loop

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node* next;
};

Node* newNode(int key)
{
    Node* temp=new Node;
    temp->key=key;
    temp->next=NULL;
    return temp;

}

void printList(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->key<<" ";
        head=head->next;
    }
}

//function to detect and remove loop
void detectAndRemoveLoop(Node* head)
{
    //if list empty or has only one node without loop
    if(head==NULL || head->next==NULL)
        return ;
    
    Node *slow=head,*fast=head;
    //move slow and fast 1 and 2 steps ahead respectively
    slow=slow->next;
    fast=fast->next->next;

    //search for loop using slow and fast pointers
    while(fast && fast->next)
    {
        if(slow==fast)
            break;
        slow=slow->next;
        fast=fast->next->next;
    }

    //if loop exists
    if(slow==fast)
    {
        slow=head;

        //this check is needed when slow and fast both meet
        //at the head of the LL

        if(slow==fast)
            while(fast->next!=slow)
                fast=fast->next;
        else
        {
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        //since fast->next is the looping point
        fast->next=NULL; //remove loop
    }
}

int main()
{
    Node* head=newNode(50);
    head->next=head;
    head->next=newNode(20);
    head->next->next=newNode(15);
    head->next->next->next=newNode(4);
    head->next->next->next->next=newNode(10);

    //create a loop for testing
    head->next->next->next->next->next=head;
    detectAndRemoveLoop(head);

    printf("linked list after removing loop\n");
    printList(head);

    return 0;
}