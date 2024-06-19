#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void push(Node** head_ref,int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

Node* sortTwoList(Node *head1, Node *head2)
{
    if(head1==NULL)
        return head2;

    if(head2==NULL)
        return head2;

    if(head1->data<=head2->data)
        return solve(head1,head2);
    else
        return solve(head2,head1);
}

Node* solve(Node* head1, Node* head2)
{
    Node* curr1=head1;
    Node* next1=curr1->next;
    Node* curr2=head2;
    Node* next2=curr2->next;

    while (next1!=NULL && curr2!=NULL )
    {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
        }

        else
        {
            curr1=next1;
            next1=next1->next;

            if(next1 ==NULL)
            {
                curr1->next=curr2;
                return head1;
            }
        }

    }
    

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
    Node* head1= new Node();
    push(&head1,1);
    push(&head1,3);
    push(&head1,5);
    // push(&head,);
    // push(&head,);
    // push(&head,);
    // push(&head,);

    Node* head2= new Node();
    push(&head2,2);
    push(&head2,4);
    push(&head2,5);
    // push(&head,);
    // push(&head,);
    // push(&head,);
    // push(&head,);
    
    sortTwoList(head1,head2);

    return 0;
}