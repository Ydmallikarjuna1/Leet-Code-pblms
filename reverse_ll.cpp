#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};


Node* createNode(int value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Core logic to reverse the linked list
Node* reverseList(Node* head) 
{
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) 
    {
        nextNode = current->next; 
        current->next = prev;     
        prev = current;          
        current = nextNode;     
    }

    return prev; 
}

void display(Node* head)
{
    Node* temp = head;
    while (temp != NULL) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> value;
        Node* newNode = createNode(value);

        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original Linked List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    display(head);

    return 0;
}