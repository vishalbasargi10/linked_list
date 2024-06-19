//Here in this approach, we use O(n) extra space for vector to store the linked list values and we simply return middle value of vector.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class NodeOperation
{
    public:
        void pushNode( class Node** head_ref,int data_val)
        {

            //allocate node
            class Node *new_node=new Node();

            //put in the data
            new_node->data=data_val;

            //link the old list of the new node
            new_node->next=*head_ref;

            //move the head to point to tthe new nod
            *head_ref=new_node;
        }
    
};

int main()
{
    class Node *head=NULL;
        class NodeOperation *temp=new NodeOperation();
        for(int i=5;i>0;i--)
        {
            temp->pushNode(&head,i);

        }
        vector<int>v;
        while(head!=NULL)
        {
            v.push_back(head->data);
            head=head->next;
        }
        cout<<"middle value of the linked list is";
        cout<<v[v.size()/2]<<endl;
        return 0;
}

