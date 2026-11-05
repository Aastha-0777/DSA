#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode* root, int low, int high) {

    // 1. Base case: what if root is NULL?
    
    if(root == NULL)
        return 0;

    // 2. What if root->val < low? 
    
    if(root->val < low)
        return rangeSumBST(root->right, low, high);
    
    // 3. What if root->val > high? 

    if(root->val > high)
        return rangeSumBST(root->left, low, high);

    // 4. What if root->val is inside [low, high]?
    
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);

}

int main()
{

    return 0;
}