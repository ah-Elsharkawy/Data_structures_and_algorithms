#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class linkedList
{
    int length = 0;
    Node *head = nullptr;

public:
    linkedList()
    {
        this->head = nullptr;
    }
    void add(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->length++;
    }

    void print()
    {
        Node *temp = this->head;
        cout << "[ ";
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << ", ";
            temp = temp->next;
        }
        cout << " ]\n";
    }

    void removeNode(Node *pre, Node *curr)
    {
        pre->next = curr->next;
        delete curr;
        this->length--;
    }

    void removeHead()
    {
        this->head = this->head->next;
        this->length--;
    }

    void removalMessage(Node *node)
    {
        cout << "Element: " << node->data << " is removed\n";
    }

    void removeByIndex(int index)
    {
        int i = 0;
        Node *pre = this->head;
        Node *curr = pre->next;
        if (index >= this->length || index < 0)
        {
            cout << "out of range please enter a valid index\n";
            return;
        }

        if (index == 0)
        {
            removalMessage(this->head);
            removeHead();
            delete pre;
            return;
        }

        while (i < index)
        {
            if (i == index - 1)
            {
                removalMessage(curr);
                removeNode(pre, curr);
                return;
            }
            i++;
            pre = pre->next;
            curr = pre->next;
        }
    }

    void removeByValue(int value)
    {
        Node *pre = this->head;
        Node *curr = this->head->next;
        if (pre->data == value)
        {
            removeHead();
            pre = this->head;
            curr = pre->next;
        }

        while (curr != nullptr)
        {
            if (curr->data == value)
            {
                removalMessage(curr);
                removeNode(pre, curr);
                curr = pre->next;
            }
            else{
                pre = curr;
                curr = curr->next;
            }
            
        }
    }
    // returns the first index of the value
    int findValue(int value)
    {
        Node* tmp = this->head;
        int index = 0;
        while(tmp != nullptr)
        {
        if(tmp->data == value){
            return index;
        }
        else{
            index++;
            tmp = tmp->next;
        }
        }
        return -1;
    }

    int size()
    {
        return this->length;
    }
};

int main()
{
    int x;
    cout << "enter the value you want to remove: ";
    cin >> x;
    linkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(1);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(1);

    cout << "the size of the linked list is " << list.size() << endl;
    list.print();
    cout << "the value is at index: " << list.findValue(x) << endl;
    cout << "the new size of the list " << list.size() << endl;
    list.print();
    return 0;
}