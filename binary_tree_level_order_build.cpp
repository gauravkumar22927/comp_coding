#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
      this->data = d;
      this->left = NULL;
      this->right = NULL;
    }
};
void level_order_print(Node* root){
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
      cout << temp->data << " ";
      if(temp -> left){
        q.push(temp->left);
      }
      if(temp -> right){
        q.push(temp->right);
      }
    }
  }
  return;
}
Node* build_level_order(){
  int d;
  cout << "Enter root Data :" << endl;
  cin >> d;
  Node* root = new Node(d);
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* current = q.front();
    q.pop();

    int c1,c2;
    cout << "Enter Data to insert left of :"<< current->data << endl;
    cin >> c1;
    cout << "Enter Data to insert right of :"<< current->data << endl;
    cin >> c2;
    if(c1 != -1){
      current->left=new Node(c1);
      q.push(current->left);
    }
    if(c2 != -1){
      current->right=new Node(c2);
      q.push(current->right);
    }
  }
  return root;
}
int height(Node* root){
  if(root==NULL){
    return 0;
  }
  int h1 = height(root->left);
  int h2 = height(root->right);

  return 1+max(h1,h2);
}

int diameter(Node* root){
  if(root == NULL){
    return 0;
  }
  int D1 = height(root->left) + height(root->right);
  int D2 = diameter(root->left);
  int D3 = diameter(root->right);

  return max(D1,max(D2,D3));
}
class HDPair{
public:
  int height;
  int diameter;
};
HDPair opt_diameter(Node* root){
  HDPair p;

  if(root == NULL){
    p.diameter = p.height = 0;
    return p;
  }
  HDPair left = opt_diameter(root->left);
  HDPair right = opt_diameter(root->right);

  p.height = 1 + max(left.height , right.height);
  
  int D1 = left.height + right.height;
  int D2 = left.diameter;
  int D3 = right.diameter;

  p.diameter = max(D1,max(D2,D3));
  return p;
}
//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
int main(){
  Node* root = build_level_order();
  level_order_print(root);
  cout << endl;
  cout << diameter(root) << endl;;
  cout << "optimal soln :" << endl;
  HDPair soln = opt_diameter(root);
  cout << "Max Height :" << soln.height << endl;
  cout << "Max Diameter :" << soln.diameter << endl;
}