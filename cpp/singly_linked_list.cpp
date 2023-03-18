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

    // time complexity: O(n) where n is the length of the list
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
   
    // time complexity: O(n) where n is the length of the list
    void removeByValue(int value)
    {
        Node* pre = nullptr;
        Node* curr = this->head;
        if(this->length == 0)
        {
            cout << "the list is empty\n";
            return;
        }
        while(curr != nullptr)
        {
            if(curr->data == value)
            {   Node* tmp = this->head;
                if(pre == nullptr)
                {
                    this->head = this->head->next;
                    delete tmp;
                    curr = this->head;
                }
                else
                {
                    tmp = curr;
                    pre->next = curr->next;
                    curr = curr->next;
                    delete tmp;
                }
                this->length--;
            }
            else
            {
                pre = curr;
                curr = curr->next;
            }
        }
    }
    // reverse the list by reversing the addresses of the nodes
    // complexity time: O(n) where n is the list size
    void reverse()
    {
        if(this->length == 0 || this->length == 1)
        return;
        Node* pre = nullptr;
        Node* curr = this->head;
        Node* next = curr->next;
        while(curr != nullptr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        this->head = pre;
    }

    // returns the first index of the value
    // time complexity: O(n) where n is the length of the list
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
    // insert a given value at the given index
    // time complexity: O(n) where n is the length of the listS
    void insertAt(int value, int index)
    {
        if(index < 0)
        {
            cout << "please enter a valid index\n";
            return;
        }
    
        if(index == 0)
        {
        add(value);
        return;
        }

        Node* pre = nullptr;
        Node* curr = this->head;
        Node* newNode = new Node(value);
        while(index--)
        {   
            pre = curr;
            curr = curr->next;
        }
        pre->next = newNode;
        newNode->next = curr;
        this->length++;
    }

    // returns the length of the list
    int size()
    {
        return this->length;
    }
};

int main()
{
    /* int x;
    cout << "enter the value you want to remove: ";
    cin >> x; */
    linkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);


    cout << "the size of the linked list is " << list.size() << endl;
    list.print();
    /* cout << "the value is at index: " << list.findValue(x) << endl;
    list.removeByValue(x); */
    cout << "the list after reversing \n";
    list.reverse();
    list.print();
    cout << "enter the value and the index to be inserted at respectively: \n";
    int index,value;
    cin >> value >> index;
    list.insertAt(value, index);
    cout << "the size of the linked list is " << list.size() << endl;
    list.print();
    
    return 0;
}