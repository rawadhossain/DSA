#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int val, Node *nextAdd, Node *backAdd)
    {
        data = val;
        next = nextAdd;
        back = backAdd;
    }

    Node(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *convertArrDoubly(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp; // OR prev = prev->next same thing
    }
    return head;
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr; // disconnecting head from the wholeLL

    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    Node *prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node *delete_Kth_element(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL && prev == NULL) // i.e having single element
        return NULL;
    else if (prev == NULL) // first element
        return deleteHead(head);
    else if (front == NULL) // last element
        return deleteTail(head);

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

void delete_Kth_node(Node *temp) // head node never deleted i.e Exception
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    delete temp;
}
/* Printing the func:
        Node *head = convertArrDoubly(arr);
        delete_Kth_node(head->next->next->next);
        printDLL(head);*/

Node *insert_Before_Head(Node *head, int value)
{
    Node *newHead = new Node(value, head, nullptr);
    head->back = newHead;

    return newHead; // NOT return head
}


Node *insert_Before_Tail(Node *head, int value)
{
    if (head->next == NULL)
        return insert_Before_Head(head, value);

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    Node *prev = temp->back;
    Node *newTail = new Node(value, temp, prev);
    prev->next = newTail;
    temp->back = newTail;
    return head;
}

Node *insert_Before_Kth_Element(Node *head, int value, int k)
{
    if (k == 1)
        return insert_Before_Head(head, value);

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *newNode = new Node(value, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insert_before_node(Node *temp, int value) // Dont want to change head
{
    Node *prev = temp->back;
    Node *newNode = new Node(value, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
}


int main()
{
    vector<int> arr = {2, 5, 6, 10, 45};
    Node *head = convertArrDoubly(arr);
    insert_before_node(head->next->next, 99);
    printDLL(head);
    return 0;
}
