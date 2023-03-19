#include <bits/stdc++.h>
using namespace std;

class TNode
{
public:
    int data;
    TNode *left;
    TNode *right;

    TNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BTree
{
public:
    TNode *root;
    int size;

    BTree()
    {
        this->root = nullptr;
        this->size = 0;
    }

    void insert_left(TNode *&curr, TNode *newNode, int value)
    {
        if (curr->left == nullptr)
        {
            curr->left = newNode;
            return;
        }
        if (value <= curr->left->data)
        {
            insert_left(curr->left, newNode, value);
        }
        else
        {
            insert_right(curr->left, newNode, value);
        }
    }

    void insert_right(TNode *&curr, TNode *newNode, int value)
    {
        if (curr->right == nullptr)
        {
            curr->right = newNode;
            return;
        }
        if (value > curr->right->data)
        {
            
            insert_right(curr->right, newNode, value);
        }
        else
        {
            insert_left(curr->right, newNode, value);
        }
    }

    void insert(int value)
    {
        TNode *newNode = new TNode(value);
        if (this->root == nullptr)
        {
            this->root = newNode;
        }
        else
        {
            TNode *curr = this->root;
            if (value <= curr->data)
            {
                insert_left(curr, newNode, value);
            }
            else
            {
                insert_right(curr, newNode, value);
            }
        }
        this->size++;
    }

    void pre_order(TNode *start)
    {
        TNode* node = start;
        if(node != nullptr)
        {
            cout << node->data << " ";
            pre_order(node->left);
            pre_order(node->right);  
        }
    }

    void in_order(TNode *start)
    {
        TNode* node = start;
        if(node != nullptr)
        {
            in_order(node->left);
            cout << node->data << " ";
            in_order(node->right);  
        }
    }

    void post_order(TNode *start)
    {
        TNode* node = start;
        if(node != nullptr)
        {
            post_order(node->left);
            post_order(node->right);  
            cout << node->data << " ";
        }
    }

    void level_order()
    {
        if(this->root == nullptr)
            return;
        
        queue <TNode*> q;
        q.push(this->root);
        while(q.size() > 0)
        {
            TNode* curr = q.front();
            cout << curr->data << " ";

            if(curr->left != nullptr)
            {
                q.push(curr->left);
            }

            if(curr->right != nullptr)
            {
                q.push(curr->right);
            }

            q.pop();
        }
    }

    
/*     void insert(int val) {
        TNode* newNode = new TNode(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        TNode* curr = root;
        while (true) {
            if (val < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            }
        }
    } */

    void printTree(TNode *root, int space = 0, int height = 10)
    {
        if (root == nullptr)
        {
            return;
        }
        space += height;
        printTree(root->right, space, height);

        cout << endl;
        for (int i = height; i < space; i++)
        {
            cout << " ";
        }
        cout << root->data << "\n";

        printTree(root->left, space, height);
    }

    int count()
    {
        return this->size;
    }
};
int main()
{
    BTree t;
    t.insert(6);
    t.insert(11);
    t.insert(1);
    t.insert(4);
    t.insert(5);
    t.insert(13);
    t.insert(27);
    t.insert(3);
    t.insert(4);
    t.insert(6);
    cout << "the number of tree nodes: " << t.count() << endl;
    cout << "the pre_order:\n";
    t.pre_order(t.root);
    cout << endl;
    cout << "the in_order:\n";
    t.in_order(t.root);
    cout << endl;
    cout << "the post_order:\n";
    t.post_order(t.root);
    cout << endl;
    cout << "the level order:\n";
    t.level_order();
    cout << endl;
}
