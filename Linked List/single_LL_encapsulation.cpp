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

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {} // Constructor initializing head to nullptr

    void convertArr2LL(vector<int> &arr)
    {
        if (arr.empty())
            return;
        head = new Node(arr[0]);
        Node *mover = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
    }

    void printLL()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int LengthofLL()
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

    bool SearchElement(int k)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == k)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void removeHead()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void removeTail()
    {
        if (head == NULL || head->next == NULL)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void removeKelement(int k)
    {
        if (head == NULL || k < 1)
            return;

        if (k == 1)
        {
            removeHead();
            return;
        }

        int count = 1;
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL && count != k)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
            return; // k is larger than the length of the list

        prev->next = temp->next;
        delete temp;
    }

    void removeElement(int el)
    {
        if (head == NULL)
            return;

        if (head->data == el)
        {
            removeHead();
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL && temp->data != el)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return; // Element not found

        prev->next = temp->next;
        delete temp;
    }

    void insertHead(int value)
    {
        head = new Node(value, head);
    }

    void insertTail(int value)
    {
        if (head == NULL)
        {
            insertHead(value);
            return;
        }

        Node *tail = new Node(value);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = tail;
    }

    void insertPosition(int value, int k)
    {
        if (k == 1)
        {
            insertHead(value);
            return;
        }

        Node *temp = head;
        int count = 1;
        while (temp != NULL && count < k - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
            return; // Position is out of range

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertElement_before_value(int el, int value)
    {
        if (head == NULL)
            return;

        if (head->data == value)
        {
            insertHead(el);
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == value)
            {
                Node *newNode = new Node(el);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList ll;
    vector<int> arr = {1, 2, 3, 4, 5};

    ll.convertArr2LL(arr);
    ll.printLL();

    ll.insertHead(0);
    ll.printLL();

    ll.insertTail(6);
    ll.printLL();

    ll.removeHead();
    ll.printLL();

    ll.removeTail();
    ll.printLL();

    ll.removeKelement(3);
    ll.printLL();

    ll.insertPosition(10, 3);
    ll.printLL();

    return 0;
}
