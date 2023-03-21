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

    bool search(int value, TNode *newNode)
    {
        if(newNode == nullptr)
            return false;
        cout << newNode->data << " "; // this line to print every element in the path of the value
        if(newNode->data == value)
            return true;

        if(newNode->data < value)
        {
            search(value, newNode->right);
        }
        else
        {
            search(value, newNode->left);
        }
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

    // return the tree as a string where nodes are seperated by '-' and levels are seperated by '|'
    string printTree()
    {
        queue<TNode*> p; // primary queue
        queue<TNode*> s; // secondary queue
        string res = ""; // the result

        p.push(this->root);
        res += to_string(this->root->data);
        res += " | ";    // this sign '|' is used to seperate between levels it means the end of this level and the start of the next

        while(!p.empty())
        {   
            // push all the children of the current level nodes to the secondery queue (s) from left to right
            while (!p.empty())
            {
                s.push(p.front()->left);
                s.push(p.front()->right);
                p.pop();
            }

            // then add the data of every node to the result string whether it is null or not 
            // and push the non-empty nodes to the primary queue
            while (!s.empty())
            {
                if(s.front() == nullptr)
                {
                    res += "n";
                    
                    s.pop();
                }

                else
                {
                    res += to_string(s.front()->data);
                    p.push(s.front());
                    s.pop();
                }

                if(s.empty())
                    res += " | ";
                else
                {
                    res += "-";
                }
            }
        }
        return res;
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
    /* int n; cin >> n;
    cout << (t.search(n, t.root) ? "found" : "not found") << endl; */
    cout << "the string representation of the tree:\n" << t.printTree() << endl; 

}
