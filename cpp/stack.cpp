#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node<T>* next;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class Stack
{
    int length;

    public:
    Node<T>* head;

    Stack()
    {
        this->length = 0;
        this->head = nullptr;
    }

    void push(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = this->head;
        this->head = newNode;
        this->length++;
    }

    void print()
    {
        Node<T>* curr = this->head;
        cout << "[ ";
        while (curr != nullptr)
        {
            cout << curr->data << (curr->next != nullptr ? ", ": " ");  
            curr = curr->next;      
        }
        cout << "]\n";
    }

    bool isEmpty()
    {
        return (this->length ? true : false);
    }

    int size()
    {
        return this->length;
    }

    T peek()
    {
        if(this->length > 0)
            return this->head->data;

        else
        {
            cout << "the stack is empty, no peek\n";
            return T();
        }

    }

    T pop()
    {
        if(this->length > 0)
        {
            Node<T>* tmp = this->head;
            T data = tmp->data;
            this->head = tmp->next;
            delete tmp;
            this->length--;
            return data;
        }
        else
        {
            cout << "cannot pop empty stack\n";
            return T();
        }
        
    }
};


int main()
{
    Stack<string> s;
    s.push("i");
    s.push("will");
    s.push("pop");
    s.push("this");    
    s.print();
    cout << "stack peek: " << s.peek() << endl;
    cout << "stack size: " << s.size() << endl;
    cout << "stack pop: " << s.pop() << endl;
    cout << "stack size: " << s.size() << endl;
    s.print();

}