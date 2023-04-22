#include<iostream>
#include<list>

using namespace std;
class graph{
  int v;
  list<int> *l;

  public:
    graph(int n){
      this->v = n;
      this->l = new list<int>[n];
    }

    void addEdge(int a,int b,bool dir = true){
      l[a].push_back(b);
      if(dir){
        l[b].push_back(a);
      }
    }

    void print_adj(){
      for(int i = 0;i<v;i++){
        cout << i << "->";
        for(auto x: l[i]){
          cout << x << " ";
        }
        cout << endl;
      }
    }

};
int main(){
  graph g(6);
  g.addEdge(0,1);
  g.addEdge(0,4);
  g.addEdge(2,1);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.addEdge(2,3);
  g.addEdge(3,5);
  g.print_adj();

}