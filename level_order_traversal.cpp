//finding maximum element in binary tree
#include <bits/stdc++.h>
using namespace std;
class BinaryTree{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
void level_order_traversal(BinaryTree *root_node)
{
    queue<BinaryTree*> q;
    BinaryTree *temp;
    q.push(root_node);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    BinaryTree *root_node=new BinaryTree(45);
    root_node->left=new BinaryTree(36);
    root_node->right=new BinaryTree(89);
    root_node->left->left=new BinaryTree(90);
    root_node->right->left=new BinaryTree(55);
    root_node->left->right=new BinaryTree(47);
    root_node->right->right=new BinaryTree(77);
    level_order_traversal(root_node);
    

    /*
         45
       /   \
      36    89
      / \   / \
    90  47 55 77

    our binary tree!!

        8
       /   \
      2    37
      / \   / \
    3  99  44 50
    */
}