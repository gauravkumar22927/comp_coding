#include<iostream>
#include<string>

using namespace std;
//template<typename T>
class Node{
public:
  string key;
  int val;
  Node* next;

  Node(string key,int val){
    this->key = key;
    this->val = val;
    next = NULL;
  }

  ~Node(){
    if(next != NULL){
      delete next;
    }
  }
};

//template<typename T>
class HashTable{
  Node **table;
  int cs;
  int ts;

  int hash_func(string s){
    int idx = 0;
    int power = 1;
    for(char x: s){
      idx = (idx + x*power) % ts;
      power = (power * 29)%ts;
    }
    return idx;
  }
  void rehash(){
    Node **old_table = table;
    int old_ts = ts;

    cs = 0;
    ts = 2*ts +1;
    table = new Node*[ts];
    // important to initialize new table with NULL
    for(int i =0;i<ts;i++){
      table[i] = NULL;
    }
    for(int i =0;i<old_ts;i++){
      Node* temp = old_table[i];
      while(temp != NULL){
        insert(temp->key,temp->val);
        temp=temp->next;
      }
      //destroy each table entry after inserting in new table;
      if(old_table[i] != NULL){
      delete old_table[i];
      }
    }
    delete [] old_table;
  }
public:
  HashTable(int default_size = 7){
  cs = 0;
  ts = default_size;

  table = new Node*[ts];
  for(int i =0;i<ts;i++){
      table[i] = NULL;
    }
  }

  void insert(string key,int val){
    int idx = hash_func(key);
    Node* n = new Node(key,val);
    // insert at head of each hash table
    n->next = table[idx];
    table[idx] = n;
    cs++;
    // check load factor
    float load_factor = cs/float(ts);
    if(load_factor > 0.7){
      rehash();
    }
  }

  void print(){
    for(int i = 0;i<ts;i++){
      if(table[i] == NULL){
        cout << "Table " << i << "->";
      }
      else{
        Node* temp = table[i];
        cout << "Table " << i << "->";
        while(temp != NULL){
          cout << temp ->key << ":" << temp->val << "->";
          temp = temp-> next;
        }
      }
      cout << endl;
    }
  }
};
int main(){
  HashTable h;
  h.insert("Mango" ,100);
  h.insert("Apple" ,110);
  h.insert("Banana" ,120);
  h.insert("Guava" ,130);
  h.insert("Orange" ,140);
  h.insert("Pinapple" ,150);

  h.print();
}