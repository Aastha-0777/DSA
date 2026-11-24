#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *build(int *preorder, int preorderSize, int *index, int bound)
{
    
    if (*index >= preorderSize || preorder[*index] > bound)
    {
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[(*index)++];

    root->left = build(preorder, preorderSize, index, root->val);

    root->right = build(preorder, preorderSize, index, bound);

    return root;
}

struct TreeNode *bstFromPreorder(int *preorder, int preorderSize)
{

    int index = 0; 
    return build(preorder, preorderSize, &index, INT_MAX);
    
}