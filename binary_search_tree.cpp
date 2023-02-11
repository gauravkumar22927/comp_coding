#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int d){
    data = d;
    left = right = NULL;
  }
};

Node* insert(Node* root,int key){
  if(root == NULL){
    return new Node(key);
  }
  if(key < (root->data)){
    root->left = insert(root->left,key);
  }
  else{
    root->right = insert(root->right,key);
  }

  return root;
}
void printInOrder(Node *root){
  if(root == NULL){
    return;
  }
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}
Node* findmin(Node* root){
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}
Node* delete_key(Node* root,int key){
  if(root == NULL){
    return NULL;
  }
  else if(key < root->data){
    root->left = delete_key(root->left,key);
  }
  else if(key < root->data){
    root->right = delete_key(root->right,key);
  }
  else{
    if(root->left == NULL & root->right == NULL){
      delete root;
      root=NULL;
    }
    else if(root ->left == NULL){
      Node* temp = root;
      root = root->right;
      delete temp;
    }
    else if(root ->right == NULL){
      Node* temp = root;
      root = root->left;
      delete temp;
    }
    else{
      Node* temp = findmin(root->right);
      root->data = temp->data;
      root->right = delete_key(root->right,temp->data);
    }
  }
  return root;
}
int main(){
  Node* root = NULL;
  int arr[] = {8,3,10,1,6,14,4,7,13};

  for(int x: arr){
    root = insert(root,x);
  }
  printInOrder(root);
  cout << endl;
  int key;
  cin >> key;
  root = delete_key(root,key);

  printInOrder(root);
}