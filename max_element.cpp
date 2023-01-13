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
int findMax(BinaryTree *root_node)
{
    //we will find max in left subtree and right subtree and compare them and chose the largest one
    int lft,rgt,max=INT_MIN,root_val;
    if(root_node)
    {
        root_val=root_node->data;
        lft=findMax(root_node->left);
        rgt=findMax(root_node->right);
        if(lft<rgt)
        {
            max=rgt;
        }
        else
        {
            max=lft;
        }
        if(root_val>max)
        {
            max=root_val;
        }
    }
    return max;
}
int main()
{
    BinaryTree *root_node=new BinaryTree(45);
    root_node->left=new BinaryTree(36);
    root_node->right=new BinaryTree(89);
    root_node->left->left=new BinaryTree(90);
    root_node->right->left=new BinaryTree(55);
    int max=INT_MIN;
    cout<<findMax(root_node);
    

    /*
         45
       /   \
      36   89
      / \   /
    90  47  55

    our binary tree!!
    */
}