#include <bits/stdc++.h>
using namespace std;
/*      10
       /  \
      20  30
     /    /
    40   50
our binary tree
*/
class BinaryTree{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
};
void inorder_traversal(BinaryTree *root_node)
{
    if(root_node!=NULL)
    {
        inorder_traversal(root_node->left);
        cout<<root_node->data<<" ";
        inorder_traversal(root_node->right);
    }
}
void preorder_traversal(BinaryTree *root_node)
{
    if(root_node!=NULL)
    {
        cout<<root_node->data<<" ";
        preorder_traversal(root_node->left);
        preorder_traversal(root_node->right);
    }
}
void postorder_traversal(BinaryTree *root_node)
{
    if(root_node!=NULL)
    {
        postorder_traversal(root_node->left);
        postorder_traversal(root_node->right);
        cout<<root_node->data<<" ";
    }
}
int main()
{
    BinaryTree *root_node=new BinaryTree();
    BinaryTree *node1=new BinaryTree();
    BinaryTree *node2=new BinaryTree();
    BinaryTree *node3=new BinaryTree();
    BinaryTree *node4=new BinaryTree();
    root_node->data=10;
    root_node->left=node1;
    root_node->right=node2;
    node1->data=20;
    node1->left=node3;
    node1->right=NULL;
    node2->data=30;
    node2->left=node4;
    node2->right=NULL;
    node3->data=40;
    node4->data=50;
    inorder_traversal(root_node);
    cout<<"<-"<<"inorder traversal"<<endl;
    preorder_traversal(root_node);
    cout<<"<-"<<"preorder traversal"<<endl;
    postorder_traversal(root_node);
    cout<<"<-"<<"postorder traversal";
}