#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *left;
    struct Node *right;

} *root = NULL;

struct Node *addNode(struct Node *tempRoot, int value)
{

    if (tempRoot == NULL)
    {

        tempRoot = (struct Node *)malloc(sizeof(struct Node));
        tempRoot->data = value;
        tempRoot->left = NULL;
        tempRoot->right = NULL;
        return tempRoot;
    }
    else
    {

        if(value > tempRoot->data){

            //add at right
            tempRoot->right = addNode(tempRoot->right, value);

        }else{

            //add at left
            tempRoot->left = addNode(tempRoot->left, value);

        }//end of inner if-else

    } // end of if-else

    return tempRoot;

} // end of addNode

int main()
{

    root = addNode(root, 67);
    addNode(root, 70);
    addNode(root, 80);
    addNode(root, 50);
    addNode(root, 40);

    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->data);
    printf("%d\n", root->right->data);
    printf("%d\n", root->right->right->data);

    return 0;

} // end of main