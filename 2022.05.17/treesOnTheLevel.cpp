#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(NULL), right(NULL) {}
};

bool isAllNodesHasValue(Node* root){
    if(root == NULL) return true;
    if(root->value == -1) return false;

    bool hasValue = isAllNodesHasValue(root->left) && isAllNodesHasValue(root->right);
    return hasValue;
}

void destroyTree(Node* root){
    if(root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);

    free(root);
}

void printTree(Node* root){
    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    bool isPrint = false;
    while(!nodeQueue.empty()){
        if(isPrint) printf(" ");

        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        printf("%d", currentNode->value);
        if(currentNode->left != NULL) nodeQueue.push(currentNode->left);
        if(currentNode->right != NULL) nodeQueue.push(currentNode->right);
        isPrint = true;
    }

    printf("\n");
}

int main(){
    string node;
    Node* tree = NULL;
    bool isValid = true;
  
    int datas;
    cin >> datas;

    while(datas--){
        while(cin >> node){
            if(node == "()"){
                if(isValid && isAllNodesHasValue(tree)){
                    printTree(tree);
                }
                else{
                    printf("not complete\n");
                }
                destroyTree(tree);
                tree = NULL;
                isValid = true;
                break;
            }

            if(!isValid) continue;

            int value = 0;
            int index;
            for(index = 1 ; node[index] != ',' ; ++index){
                value = value * 10 + node[index] - '0'; // get the value of each input node
            }

            if(tree == NULL) tree = new Node(-1);   // -1 is to mark the node we traverse through but haven't give a value
            Node* currentNode = tree;
            for(++index ; node[index] != ')' ; ++index){
                if(node[index] == 'L'){
                    if(currentNode->left == NULL) currentNode->left = new Node(-1);
                    currentNode = currentNode->left;
                }
                else if(node[index] == 'R'){
                    if(currentNode->right == NULL) currentNode->right = new Node(-1);
                    currentNode = currentNode->right;
                }
            }
            if(currentNode->value != -1){
                isValid = false;
                continue;
            }

            currentNode->value = value;
        }
    }
  

    return 0;
}