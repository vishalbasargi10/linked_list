//program to remove duplicates in an unsorted LL

#include<bits/stdc++.h>
using namespace std;

//linked list node
struct Node
{
    int  data ;
    struct Node* next;
};

//utility function to create a new node
struct Node* newNode(int data)
{
    Node* temp =new Node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

//function to remove duplicates from unsorted linked list
void removeDuplicates(struct Node* start)
{
    struct Node *ptr1,*ptr2,*dup;
    ptr1=start;
 
    //pick elements one by one
    while(ptr1!=NULL && ptr1->next!=NULL)
    {
        ptr2=ptr1;
        //compare the picked elememt with rest of the elements
        while(ptr2->next!=NULL)
        {
            //if duplicate then dealte it
            if(ptr1->data==ptr2->next->data)
            {
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(dup);
            }

            else
                ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}

//function to print nodes in the given linked list
void printList(struct Node* node)
{
    while(node!=NULL)
    {
        cout<<node->data;
        node=node->next;
    }
}

int main()
{
    struct Node* start = newNode(10);
    start->next=newNode(12);
    start->next->next=newNode(11);
    start->next->next->next=newNode(11);
    start->next->next->next->next=newNode(12);
    start->next->next->next->next->next=newNode(11);
    start->next->next->next->next->next->next=newNode(10);
    
    printf("linked list before removing duplictes");
    printList(start);

    removeDuplicates(start);

    printf("\nlinked list after removing duplctes");
    printList(start);
    
    return 0;

}