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

        if (value > tempRoot->data)
        {

            // add at right
            tempRoot->right = addNode(tempRoot->right, value);
        }
        else
        {

            // add at left
            tempRoot->left = addNode(tempRoot->left, value);

        } // end of inner if-else

    } // end of if-else

    return tempRoot;

} // end of addNode

void inOrder(struct Node *root)
{

    if (root != NULL)
    {

        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node *root)
{

    if (root != NULL)
    {

        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root)
{

    if (root != NULL)
    {

        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}

void searchNode(struct Node *root, int value)
{

    if (root == NULL)
    {

        printf("Not Found\n");
    }
    else if (root->data == value)
    {

        printf("Found\n");
    }
    else if (value < root->data)
    {
        // left
        searchNode(root->left, value);
    }
    else
    {
        // right
        searchNode(root->right, value);
    }
}

struct Node *deleteNode(struct Node *root, int key)
{

    if (root == NULL)
    {

        printf("Not Found\n");
    }
    else if (root->data == key)
    {

        printf("Found\n");

        // delete logic

        if (root->left == NULL && root->right == NULL)
        {
            printf("0 Child\n");
        }
        else if (root->left != NULL && root->right == NULL)
        {
            printf("1 Child -> Left\n");
        }
        else if (root->left == NULL && root->right != NULL)
        {
            printf("1 Child -> Right\n");
        }
        else
        {
            printf("2 Child\n");
        }
    }
    else if (key < root->data)
    {

        // left
        root->left = deleteNode(root->left, key);
    }
    else
    {

        // right
        root->right = deleteNode(root->right, key);
    }

    return root;
}

int main()
{

    root = addNode(root, 67);
    addNode(root, 70);
    addNode(root, 80);
    addNode(root, 50);
    addNode(root, 40);

    // printf("%d\n", root->left->left->data);
    // printf("%d\n", root->left->data);
    // printf("%d\n", root->data);
    // printf("%d\n", root->right->data);
    // printf("%d\n", root->right->right->data);

    inOrder(root);
    printf("\n");
    // preOrder(root);
    // postOrder(root);

    // searchNode(root, 67);
    // searchNode(root, 6);

    root = deleteNode(root, 67);

    return 0;

} // end of main