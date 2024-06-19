#include <bits/stdc++.h>
using namespace std;

// creating a linked list node.
class Node {
public:
    int data;
    Node *next;
};

/*
insertNode function will create a new node and insert the newly created node at the last.
*/
void insertNode(Node **head, int newData) {
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = (*head);
    (*head) = newNode;
}

// a function that will check if the linked list is a palindrome linked list or not.
bool checkPalindrome(Node *head) {
    // defining an array that will store the elements of the linked list.
    vector<int> a;

    // traversing the list and storing the elements.
    while (head != NULL) {
        a.push_back(head->data);
        head = head->next;
    }

    // checking whether the array is palindrome or not.
    for (int i = 0; i < a.size() / 2; i++)
        if (a[i] != a[a.size() - i - 1])
            return false;
    return true;
}

int main() {
    // an empty linked list
    Node *l = NULL;

    insertNode(&l, 1);
    insertNode(&l, 2);
    insertNode(&l, 3);
    insertNode(&l, 4);
    insertNode(&l, 1);

    if (checkPalindrome(l) == 1)
        cout << "The linked list is a palindrome linked list.";
    else
        cout << "The linked list is not a palindrome linked list.";

    return 0;
}
