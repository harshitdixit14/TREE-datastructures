#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
TreeNode* insert_into_level(TreeNode *root,int item)
{
    // we have to insert element into binary tree level orderely
    queue<TreeNode*> qt;
    qt.push(root);
    while(!qt.empty())
    {
        if(qt.front()->left)
        {
            qt.push(qt.front()->left);
        }
        if(qt.front()->right)
        {
            qt.push(qt.front()->right);
        }
        if(!qt.front()->left)
        {
            qt.front()->left=new TreeNode(item);
            break;
        }
        if(!qt.front()->right)
        {
            qt.front()->right=new TreeNode(item);
            break;
        }
        qt.pop();
    }
    return root;
}
void level_traverse(TreeNode *root)
{
    queue<TreeNode*> qt;
    qt.push(root);
    while(!qt.empty())
    {
        cout<<qt.front()->data<<" ";
        if(qt.front()->left)
        {
            qt.push(qt.front()->left);
        }
        if(qt.front()->right)
        {
            qt.push(qt.front()->right);
        }
        qt.pop();
    }
}
int main()
{
    // we have to insert element in binary tree
    //first we will create a binary tree
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(89);
    root->right=new TreeNode(54);
    root->left->left=new TreeNode(77);
    root->left->right=new TreeNode(90);
    root->right->left=new TreeNode(47);
    level_traverse(root);
    root=insert_into_level(root,87);
    cout<<endl;
    level_traverse(root);
}