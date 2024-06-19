//reversing each pointers backwards
//Node* prev=NULL;
//Node* curr=head;
//if i remove connection between 3 & 5 i will lose remaining LL so use another pointer
//forward=curr->next;
//curr->next=prev;
//then do the same thing till curr becomes equal to NULL in while loop
//in loop
//prev=curr;
//curr=forward;
//return prev;
//TC=O(n)
//SC=O(1)


//initialize three pointers prev as NULL, curr as head, and next as NULL.
//Iterate through the linked list. In a loop, do the following:
//Before changing the next of curr, store the next node 
//next = curr -> next
//Now update the next pointer of curr to the prev 
//curr -> next = prev 
//Update prev as curr and curr as next 
//prev = curr 
//curr = next


//Iterative approach
#include<bits/stdc++.h>
using namespace std;

//link list node
struct Node
{
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

struct LinkedList
{
    Node* head;
    LinkedList()
    {
        head=NULL;

    }

    //function to reverse a LL
    void reverse()
    {
        //initilize current,previous,next pointers
        Node* current =head;
        Node *prev=NULL,*next=NULL;

        while(current !=NULL)
        {
            //store next
            next=current->next;
            //reverse current nodes pointer
            current->next=prev;
            //move pointers one position ahead
            prev=current;
            current=next;

        }
        head =prev;
        
    }


    //funtion to print LL
    void print()
    {
        struct Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;

        }
    }

    void push(int data)
    {
        Node* temp=new Node(data);
        temp->next=head;
        head=temp;
        //head->next=NULL;

    }
};

// Driver code
int main()
{
    //Start with the empty list
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed linked list \n";
    ll.print();
    return 0;
}