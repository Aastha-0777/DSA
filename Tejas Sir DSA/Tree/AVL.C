#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *left;
    struct Node *right;
    int height;

} *root = NULL;

int calculateBF(struct Node* root){

    int rh = 0;
    int lh = 0;

    if(root->left != NULL){

        lh = root->left->height;

    }else if(root->right != NULL){

        rh = root->right->height;

    }

    return lh - rh;

}

int calculateHeight(struct Node* root){

    int rh = 0;
    int lh = 0;

    if(root->left != NULL){

        lh = root->left->height;

    }else if(root->right != NULL){

        rh = root->right->height;

    }

    return (rh > lh) ? rh : lh;

}

struct Node *addNode(struct Node *tempRoot, int value)
{

    if (tempRoot == NULL)
    {

        tempRoot = (struct Node *)malloc(sizeof(struct Node));
        tempRoot->data = value;
        tempRoot->left = NULL;
        tempRoot->right = NULL;
        tempRoot->height = 1;
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

    tempRoot->height = 1 + calculateHeight(tempRoot);

    int bf = calculateBF(root);

    if(bf > 1){
        printf("Imbalance LEFT %d", tempRoot->data);
    }else if(bf < -1){
        printf("Imbalance RIGHT %d", tempRoot->data);
    }

    return tempRoot;

} // end of addNode

void inOrder(struct Node *root)
{

    if (root != NULL)
    {

        inOrder(root->left);
        printf(" %d(%d) ", root->data, root->height);
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

struct Node* inOrderSuccessor(struct Node* root){

    if(root != NULL){
        inOrderSuccessor(root->left);
    }

    return root;

}

struct Node* inOrderPredecssor(struct Node* root){

    if(root != NULL){
        inOrderSuccessor(root->right);
    }

    return root;

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
            free(root);
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            printf("1 Child -> Left\n");
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            printf("1 Child -> Right\n");
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            printf("2 Child\n");

            struct Node* smallest = inOrderSuccessor(root->right);
            root->data = smallest->data;
            root->right = deleteNode(root->right, smallest->data);
            return root; 
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

    root = addNode(root, 50);
    addNode(root, 60);
    addNode(root, 40);
    addNode(root, 30);
    // addNode(root, 45);
    // addNode(root, 70);
    
    inOrder(root);
    printf("\n");

    return 0;

} // end of main