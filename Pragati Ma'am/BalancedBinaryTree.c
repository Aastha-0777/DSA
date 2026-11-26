#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkHeight(struct TreeNode* root) { 
    
    if(root == NULL){
        return 0;
    }//end of if
    int leftHeight = checkHeight(root->left);
    if(leftHeight == -1){
        return leftHeight;
    }//end of if
    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1){
        return rightHeight;
    }//end of if
    (abs(leftHeight - rightHeight) > 1) ? -1 : 1 + MAX(leftHeight, rightHeight);
    
}

bool isBalanced(struct TreeNode* root) {
    
    if(checkHeight(root) != -1){
        return true;
    }else{
        return false;
    }
    
}