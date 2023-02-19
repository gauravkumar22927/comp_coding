#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
  string word1 = "aabcdda";
  string word2 = "";
  map<int,int> w1;
  map<int,int> w2;
  for(int i=0;i<word1.size();i++){
      int temp = ((int)word1[i]) - 97;
      w1[temp]++;
  }
  for(int i=0;i<word2.size();i++){
      int temp = ((int)word2[i]) - 97;
      w2[temp]++;
  }
  for(auto x:w1){
    cout<< x.first << " " << x.second << endl;
  }

}