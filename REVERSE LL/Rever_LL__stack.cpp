//store the novdes (values and address) i n the stack until all the values are entered
//once all entries are done,update the head pointer to thr alst location
//start pooping the nodes and store them in the same order until the stack is empty
//update the next pointer of last nide in the stack by NULL

#include<iostream>
#include<bits/stdc++.h>
#include<stack>

using namespace std;

//create a class node to enter values and adress in the list

class Node
{
    public:
        int data;
        Node* next;

};

//function to reverse a linked list

void reverseLL(Node** head)
{
    //create a stack "s" of Node type
    stack< Node* > s;
    Node* temp=*head;
    while(temp->next!=NULL)
    {
        s.push(temp);
        temp=temp->next;

    }
    *head =temp;
    while(!s.empty())
    {
        //store th top value of stack in the list
        temp->next=s.top();
        //pop the value from the stack
        s.pop();
        //update thr next pointer int he list
        temp=temp->next;

    }
    temp->next=NULL;


}

//function to display the elements in list
void printList(Node* temp)
{
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//program to insert back of the linked list
void insert_back(Node** head,int value)
{
    //we have used insertion to enter values in thr list
    Node*temp=new Node();
    temp->data=value;
    temp->next=NULL;

    //if 8head equals to NULL
    if (*head==NULL)
    {

        *head=temp;
        return;
    }

    else
    {
        Node* last_node= *head;
        while(last_node->next!=NULL)
            last_node=last_node->next;
        last_node->next=temp;
        return;


    }

}
// Driver Code
int main()
{
    Node* head = NULL;
    insert_back(&head, 1);
    insert_back(&head, 2);
    insert_back(&head, 3);
    insert_back(&head, 4);
    cout << "Given linked list\n";
    printList(head);
    reverseLL(&head);
    cout << "\nReversed linked list\n";
    printList(head);
    return 0;
}