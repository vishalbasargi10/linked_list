#include<bits/stdc++.h>
using namespace std;
#include<vector>

//linkedlist node
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

int main()
{
    Node* a=newNode(5);
    a->next=newNode(10);
    a->next->next=newNode(15);
    a->next->next->next=newNode(40);

    Node* b=newNode(2);
    b->next=newNode(3);
    b->next->next=newNode(20);

    vector<int>v;
    while(a!=NULL)
    {
        v.push_back(a->key);
        a=a->next;
      
    }

    while (b!=NULL)
    {
        v.push_back(b->key);
        b=b->next;
    }
    
    sort(v.begin(),v.end());

    /*Node* result =newNode(-1);
    Node* temp=result;

    for(int i=0;i<v.size();i++)
    {
        result->next=newNode(v[i]);
        result=result->next;
    }

    temp=temp->next;
    cout<<"resultsnt merge linke lsit"<<" ";
    while(temp!=NULL)
    {
        cout<<temp->key<<" ";
        temp=temp->next;
    }*/

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}

