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
class Queue
{
    int length;

    public:
    Node<T>* first;
    Node<T>* last;

    Queue()
    {
        this->length = 0;
        this->first = nullptr;
        this->last = nullptr;
    }

    void enqueue(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        
        if(this->first == nullptr)
        {
            this->first = newNode;
            this->last = newNode;
        }
        else
        {
            this->last->next = newNode;
            this->last = newNode;
        }
        this->length++;
    }

    void dequeue()
    {
        Node<T>* tmp = this->first;
        this->first = this->first->next;
        cout << "dequeued: " << tmp->data << endl;
        delete tmp;
    }

    void print()
    {
        Node<T>* curr = this->first;
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
        return (this->length ? false : true);
    }

    int size()
    {
        return this->length;
    }

    T peek()
    {
        if(this->isEmpty())
        {
            cout << "the Queue is empty, no peek\n";
            return T();
        }

        else
        {
            return this->first->data;
        }

    }
};

int main()
{
    Queue<int> Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);

    cout << "the Queue:\n";
    Q.print();
    cout << "the Queue size: " << Q.size() << endl;
    Q.dequeue();
    Q.dequeue();
    cout << "the Queue after using dequeue:\n";
    Q.print();
    cout << "the Queue size: " << Q.size() << endl;
    cout << "the Queue peek: " << Q.peek() << endl;

}