#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;//::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  int b = 0,c = 0;

  for (size_t i = 0; i < a.size(); i++)
  {
    /* code */
    if(a[i]==a[b]){
      c++;
    }
    else c--;
    if(c==0){
      c++;
      b=i;
    }
  }
  c=0;
  for (size_t i = 0; i < a.size(); i++)
  {
    /* code */
    if(a[i]==a[b]){
      c++;
    }
    if(c>a.size()/2)return a[b];
  }
  // if (left == right) return -1;
  // if (left + 1 == right) { return a[left]; }
  // if(right - left > 1){
  //   b = get_majority_element( a , left , left + (right - left)/2 );
  //   c = get_majority_element( a , left + (right - left)/2 + 1 , right );
  // }
  // if(b==-1){ return c; }
  // else if(c==-1){ return b; }
  // else if(left==0||right==a.size()-1){
  //   for (size_t i = left; i <= right; i++)
  //   {
  //     if(a[i]==b)b_c++;
  //     else if(a[i]==c)c_c++;
  //   }
  //   if(b > c){ return b; }
  //   else if(b < c)return c;
  //   else return -1;
  // }
  // for (size_t i = left; i <= right; i++)
  //   {
  //     if(a[i]==b)b_c++;
  //     else if(a[i]==c)c_c++;
  //   }
  //   if(b > c && b_c>a.size()/2){ return b; }
  //   else if(b < c && c_c>a.size()/2)return c;
  //write your code here
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
