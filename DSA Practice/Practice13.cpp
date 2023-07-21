#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

vector<int> rightview(Node *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int level = q.size();

        for (int i = 0; i < level; i++)
        {
            Node *node = q.front();

            q.pop();

            if (i == 0)
            {
                result.push_back(node->data);
            }

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
    }

    return result;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> rightSide = rightview(root);
    cout << "Right side view: ";
    for (int val : rightSide)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}