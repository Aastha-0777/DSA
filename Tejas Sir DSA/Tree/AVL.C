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

struct Node* leftRotate(struct Node* rootTemp) {

    struct Node* rootRight = rootTemp->right;
    rootTemp->right = rootRight->left;
    rootRight->left = rootTemp;

    rootTemp->height = 1 + calculateHeight(rootTemp);
    rootRight->height = 1 + calculateHeight(rootRight);

    return rootRight;

}//end of leftRotate

struct Node* rightRotate(struct Node* rootTemp) {

    struct Node* rootLeft = rootTemp->left;
    rootTemp->left = rootLeft->right;
    rootLeft->right = rootTemp;

    rootTemp->height = 1 + calculateHeight(rootTemp);
    rootLeft->height = 1 + calculateHeight(rootLeft);

    return rootLeft;

}//end of rightRotate

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

        if(tempRoot->left->data < value){
            printf("- RIGHT %d", tempRoot->data);
            tempRoot->left = leftRotate(tempRoot->left);
            return rightRotate(tempRoot);
        }
        else
        {
            printf(" - LEFT %d", tempRoot->data);
            return rightRotate(tempRoot);
        }

    }else if(bf < -1){
        printf("\nImbalance RIGHT - ");
        if (tempRoot->right->data < value)
        {
            printf(" RIGHT : %d", tempRoot->data);
            return leftRotate(tempRoot);
        }
        else
        {

            printf(" LEFT : %d", tempRoot->data);
        }
    }

    return tempRoot;

} // end of addNode

void inOrder(struct Node *rootTemp)
{
    if (rootTemp != NULL)
    {
        inOrder(rootTemp->left);
        printf(" %d(%d) ", rootTemp->data, rootTemp->height);
        inOrder(rootTemp->right);
    }
}

void preOrder(struct Node *rootTemp)
{
    if (rootTemp != NULL)
    {
        printf(" %d ", rootTemp->data);
        preOrder(rootTemp->left);
        preOrder(rootTemp->right);
    }
}

void postOrder(struct Node *rootTemp)
{
    if (rootTemp != NULL)
    {
        postOrder(rootTemp->left);
        postOrder(rootTemp->right);
        printf(" %d ", rootTemp->data);
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
        while(root->left != NULL){
            root = root->left;
        }
    }

    return root;

}

struct Node* inOrderPredecessor(struct Node* root){

    if(root != NULL){
        while(root->right != NULL){
            root = root->right;
        }
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

      // // RR
    // root = addNode(root, 50); // NULL,50
    // root = addNode(root, 60); // 50 , 60
    // root = addNode(root, 70);

    // RL
    //  root = addNode(root, 50); // NULL,50
    //  addNode(root, 70);        // 50 , 60
    //  addNode(root, 60);

    //  LL
    // root = addNode(root, 50); // NULL,50
    // addNode(root, 40);        // 50 , 60
    // addNode(root, 30);

    // LR
    root = addNode(root, 100); // NULL,50
    root = addNode(root, 50);  // 50 , 60
    root = addNode(root, 70);

    // rotation -->

    printf("\nAll data => ");
    inOrder(root);
    printf("\n");

    return 0;

} // end of main