#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

void bst_insert(Node* &head,int data){
  if(head == NULL){
    Node* n = new Node(data);
    head = n;
    return;
  }
  if(data < head -> data){
    bst_insert(head->left,data);
  }
  else{
    bst_insert(head->right,data);
  }
}

void print_preorder(Node* head){
  if(head == NULL){
    return;
  }
  cout << head->data << " ";
  print_preorder(head->left);
  print_preorder(head->right);
}
Node* build_tree(){
  int d;
  cin >> d;
  // 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
  if(d == -1){
    return NULL;
  }
  Node* n = new Node(d);
  cout << "Enter data to left of: " << n->data << endl;
  n->left = build_tree();
  cout << "Enter data to right of: " << n->data << endl;
  n->right = build_tree();
  return n;
}
Node* build_levelorder(){
  int d;
  cout << "Enter root node data :" <<endl;
  cin >> d;
  if(d==-1){
    return NULL;
  }
  Node* root = new Node(d);
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* curr = q.front();
    q.pop();

    int c1,c2;
    cout << "Enter 2 numbers :" <<endl;
    cin >> c1 >> c2;
    if(c1 != -1){
      curr->left = new Node(c1);
      q.push(curr->left);
    }
    if(c2 != -1){
      curr -> right = new Node(c2);
      q.push(curr->right);
    }
  }
  return root;
}
void print_level_order(Node* root){
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* temp = q.front();
    if(temp == NULL){
      cout << endl;
      q.pop();
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      q.pop();
      cout << temp ->data << " ";
      if(temp -> left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }
    }
  }
}

int height(Node* root){
  if(root == NULL){
    return 0;
  }
  int h1 = height(root->left);
  int h2 = height(root->right);
  int max = h1 > h2 ? h1:h2;
  return 1 + max;
}

class HDpair{
public:
  int height;
  int diameter;
};
HDpair optimised_diameter(Node* root){
  HDpair p;
  if(root == NULL){
    p.height = p.diameter = 0;
    return p;
  }

  HDpair left = optimised_diameter(root->left);
  HDpair right = optimised_diameter(root->right);

  p.height = max(left.height,right.height) + 1;

  int D1 = left.height + right.height;
  int D2 = left.diameter;
  int D3 = right.diameter;

  p.diameter = max(D1,max(D2,D3));

  return p;
}
int main(){
  /*
  Node* head = NULL;
  bst_insert(head,8);
  bst_insert(head,5);
  bst_insert(head,3);
  bst_insert(head,1);
  bst_insert(head,2);
  bst_insert(head,4);
  bst_insert(head,6);
  */
  
  cout << "Enter data for root:";
  Node * head = build_tree(); // 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
  print_level_order(head);
  cout << endl;
  //optimised_diameter(head);
  cout << "Height : " << optimised_diameter(head).height << " Diameter : " << optimised_diameter(head).diameter << endl;
  //cout << height(head);

  /*
  Node* head = build_levelorder(); //1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1,-1
  print_preorder(head);
  */

}