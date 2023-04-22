#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;
class Node{
public:
  string name;
  list<string> nbrs;

  Node(string name){
    this-> name = name;
  }
};
class graph{
  unordered_map<string,Node*> m;

public:
  graph(vector<string> cities){
    for(auto city:cities){
      m[city] = new Node(city);
    }
  }
  void addEdge(string x,string y,bool direction = false){
    m[x] -> nbrs.push_back(y);
    if(direction){
      m[y] -> nbrs.push_back(x);
    }
  }

  void print(){
    for(auto x:m){
      cout << x.first << "->";
      Node* n = x.second;
      for(auto y: n->nbrs){
        cout << y << " ";
      }
      cout << endl;
    }
  }

};

int main(){
  vector<string> cities = {"Delhi","Landon","NewYork","Paris"};
  graph g(cities);

  g.addEdge("Delhi","Landon");
  g.addEdge("Delhi","Paris");
  g.addEdge("Paris","NewYork");
  g.addEdge("NewYork","Landon");

  g.print();
}