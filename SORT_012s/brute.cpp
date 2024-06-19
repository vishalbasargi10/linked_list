//counting number of 0 1 2 by traversing and then replacing each elemt by number of 0 1 2 
//o(n)+o(n)
//O(1)
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* sorta(Node  *head)
{
    int zero=0;
    int one=0;
    int two=0;

    //traverse ll
    Node* temp=head;
    while (temp!=NULL)
    {
        if(temp->data==0)
            zero++;
        else if(temp->data==1)
            one++;
        else if(temp->data==2)
            two++;
        temp=temp->next;
    }

    temp=head;
    while (temp!=NULL)
    {
        if(zero!=0)
        {
            temp->data=0;
            zero--;
        }

        else if(one!=0)
        {
            temp->data=1;
            one--;
        }

        else if(two!=0)
        {
            temp->data=2;
            two--;
        }

        temp=temp->next;
    }
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
    push(&head,1);
    push(&head,2);
    push(&head,2);
    push(&head,0);
    push(&head,1);

    sorta(head);
    printList(head);

    return 0;
}




