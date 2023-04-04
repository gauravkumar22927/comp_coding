#include<iostream>
#include<string>
#include<climits>

using namespace std;
string smallest_str_wnd(string s ,string p){
  int FS[256] = {0};
  int FP[256] = {0};
  for(int i =0;i<p.length();i++){
    FP[p[i]] += 1;
  }
  int count =0;
  int start = 0;
  int start_idx = -1;
  int max_len_so_far = INT_MAX;
  int window_size = 0;
  
  for(int i =0;i<s.length();i++){
    // expansion window till all char are included
    char ch = s[i];
    FS[ch]++;
    // count of char matched so far
    if(FS[ch] <= FP[ch] && FP[ch] != 0){
      count++;
    }
    //contracting from left to minimise window
    if(count == p.length()){
      while(FP[s[start]] == 0 || FS[s[start]] > FP[s[start]]){
        FS[s[start]]--;
        start++;
      }

      //updating max window len
      window_size = i-start +1;
      if(window_size < max_len_so_far){
        max_len_so_far = window_size;
        start_idx = start;
      }
    }

  }
  if(start_idx == -1){
    return "no window found";
  }
  return s.substr(start_idx,max_len_so_far);

}
int main(){
  string input;
  string pattern;
  cout << "Enter string : " <<endl;
  cin >> input;
  cout << "Enter pattern : " <<endl;
  cin >> pattern;
  cout << endl;
  cout << smallest_str_wnd(input , pattern);
}