//we have to search if element is present in binary tree or not
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
int searchElement(BinaryTree *root_node,int target)
{
    int temp;
    if(root_node==NULL)
    {
        return 0;
    }
    else
    {
        if(root_node->data==target)
        {
            return 1;
        }
        else
        {   
            temp=searchElement(root_node->left,target);
            if(temp!=0)
            {
                return 1;
            }
            else
                return searchElement(root_node->right,target);
        }
    }
    return 0;
}
int main()
{
    BinaryTree *root_node=new BinaryTree(45);
    root_node->left=new BinaryTree(36);
    root_node->right=new BinaryTree(89);
    root_node->left->left=new BinaryTree(90);
    root_node->right->left=new BinaryTree(55);
    int max=INT_MIN;
    if(searchElement(root_node,56))
    {
        cout<<"element is present in tree";
    }
    else
    {
        cout<<"not present";
    }
    cout<<endl;
    if(searchElement(root_node,36))
    {
        cout<<"element is present in tree";
    }
    else
    {
        cout<<"not present";
    }
    

    /*
         45
       /   \
      36   89
      / \   /
    90  47  55

    our binary tree!!
    */
}