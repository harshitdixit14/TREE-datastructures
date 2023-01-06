#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 13
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
class stack_array{
public:
    int capacity;
    BinaryTree *top;
    BinaryTree *array;
    BinaryTree *help;
};
int isEmpty(stack_array *s1)
{
    if(s1->top==s1->help)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(stack_array *s1)
{
    if(s1->array==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
stack_array* create_stack()
{
    stack_array* S=new stack_array();
    S->capacity=MAXSIZE;
    S->array=(BinaryTree*)malloc(S->capacity*sizeof(BinaryTree));
    //S->top=S->array;
    S->help=S->array;
    return S;
}
void push(stack_array *s1,BinaryTree *data)
{
    
    s1->array++;
    s1->top=s1->array;
    (s1->top)->data=data->data;
    (s1->top)->left=data->left;
    (s1->top)->right=data->right;
}
BinaryTree* pop(stack_array *s1)
{
    BinaryTree *ans=s1->top;
    --s1->top;
    --s1->array;
    return ans;
}
void traverse(stack_array *s1)
{
    while((s1->array)!=NULL)
    {
        cout<<s1->top<<" ";
        --(s1->top);
    }
}
void delete_stack(stack_array *s1)
{
    delete s1->top;
}
void preorder_nonrecursive(BinaryTree*root_node)
{
    stack_array *s=create_stack();
    while(1)
    {
        while(root_node!=NULL)
        {
            cout<<root_node->data<<" ";
            push(s,root_node);
            root_node=root_node->left;
        }
        if(isEmpty(s))
        {
            break;
        }
        root_node=pop(s);
        root_node=root_node->right;
    }
}
int main()
{
    BinaryTree *root_node=new BinaryTree();
    BinaryTree *node1=new BinaryTree();
    BinaryTree *node2=new BinaryTree();
    BinaryTree *node3=new BinaryTree();
    BinaryTree *node4=new BinaryTree();
    BinaryTree *node5=new BinaryTree();
    root_node->data=10;
    root_node->left=node1;
    root_node->right=node2;
    node1->data=20;
    node1->left=node3;
    node1->right=node5;
    node5->data=60;
    node5->left=NULL;
    node5->right=NULL;
    node2->data=30;
    node2->left=node4;
    node2->right=NULL;
    node3->data=40;
    node3->left=NULL;
    node3->right=NULL;
    node4->data=50;
    node4->left=NULL;
    node4->right=NULL;
    preorder_nonrecursive(root_node);
}