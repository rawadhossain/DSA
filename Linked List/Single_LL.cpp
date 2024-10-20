// From Strivers Linked List Playlist

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val, Node *nextAdd)
    {
        data = val;
        next = nextAdd;
    }
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr) // returns head which is a user defined func Node and it has address so pointer* used
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printLL(Node *head) // By traversing
{
    Node *temp = head; // traverse temp
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// printing LL without using *temp
void print(Node *head) // By traversing
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int LengthofLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int SearchElement(Node *head, int k)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == k)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node *removeHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;

    /*Alternative: //without delete or free command
    if (head == NULL) return head;
    head = head->next;
    return head;
    */
}
/* Node *head = convertArr2LL(arr);
head = removeHead(head);
printLL(head);*/

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}
/* Node *head = convertArr2LL(arr);
head = removeTail(head);
printLL(head);*/

Node *removeKelement(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        head = head->next;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removeElement(Node *head, int el)
{
    if (head == NULL)
        return head;
    if (head->data == el)
    {
        head = head->next;
        return head;
    }
    // no need count, coz we can linear search using the value of element
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertHead(Node *head, int value)
{
    Node *temp = new Node(value, head);
    return temp;
    //    in 1 line:
    //     return new Node(value, head);
}

Node *insertTail(Node *head, int value)
{
    if (head == NULL || head->next == NULL)
        return new Node(value, head);

    Node *tail = new Node(value);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = tail;
    return head;
}

Node *insertPosition(Node *head, int value, int k) // insterting a value at position k
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(value);
        else
            return head; // or return NULL
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count + 1 == k)
        {
            Node *element = new Node(value);
            element->next = temp->next;
            temp->next = element;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// inserting an element before the value in a LL
Node *insertElement_before_value(Node *head, int el, int value) // members of LL: value, newly added element: el
{
    if (head == NULL)
    {
        if (head->data == value)
            return new Node(value);
        else
            return head; // or return NULL
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == value)
        {
            Node *element = new Node(el);
            element->next = temp->next;
            temp->next = element;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 6, 10};
    Node *head = convertArr2LL(arr); // VVI to handle, convert to array for using head
    head = insertElement_before_value(head, 99, 6);
    printLL(head);
    cout << endl;

    return 0;

    // Node *x = new Node(arr[2], nullptr);
    // cout << x->data << " " << x->next << endl;
    // Node *y = new Node(10);
    // cout << y->data << " " << y->next;
}
