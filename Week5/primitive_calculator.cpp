// #include <iostream>
// #include <vector>
// #include <algorithm>

#include<bits/stdc++.h>

using namespace std;//::vector;

int zz,v;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
// vector<vector<int>> a;

// int fn(int n,int o){
//   // if(v==1){return a[a.size()-1].size(); }
//   if(n==1 && o<=zz){ v=1; return 0; }
//   if(o==zz && n!=1){ return INT_MAX; }
//   if(a[n].empty()==1){
//     int b=INT_MAX,c=INT_MAX,d=INT_MAX;
//     if(n%2==0){ b = fn(n/2,o+1);  }
//     if(b!=0){ if(n%3==0){ c = fn(n/3,o+1); } }
//     if(c!=0 && b!=0){ if(n-1>0){ d = fn(n-1,o+1); } }
//     if(b<c && b<d){
//       a[n]=a[n/2]; a[n].push_back(n);  
//     }
//     else if(c<b && c<d){ a[n]=a[n/3]; a[n].push_back(n); }
//     else { a[n]=a[n-1]; a[n].push_back(n); }
//     // cout<<" ("<<a[n].size()-1<<" , "<<n<<") ";
//   }
//   return a[n].size();
//   // return a[n];
// }

vector<int> c;

void rec(stack<int> b , int m ){
  // if(v==1){ return; }
  // cout<<"("<<m<<" "<<b.size()+1<<" {"<<zz<<"}) ";
  if(b.size()+1>=zz){ return; }
  // b.push(m);
  if(m==1 && b.size()+1<zz){
    c.clear();
    // v=1;
    zz = b.size()+1; 
    b.push(1);
    while(b.empty()!=1){
      // cout<<b.top()<<" ";
      c.push_back(b.top());
      b.pop();
    }
    // cout<<"  .."<<c.size()<<"..  ";
    // cout << b.size() - 1 << endl;
    // while(b.empty()!=1){
    //   cout<<b.top()<<" ";
    //   b.pop();
    // }
    return; 
  }
  b.push(m);
  if(m%3==0){ rec(b,m/3); }
  if(m%2==0){ rec(b,m/2); }
  if(m-1>0){ rec(b,m-1); }
  return; 

}


int main() {
  int n;
  cin >> n;
  v=0;
  // a.resize(n+1);  a[1].push_back(1);
  vector<int> sequence2 = optimal_sequence(n);
  zz= sequence2.size();
  stack<int> b;
  // b.push(n);
  rec(b,n);
  // vector<int> sequence = fn(n,1);
  // if(fn(n,1)<zz){
  // cout << a[n].size() - 1 << endl;
  // for (size_t i = 0; i < a[n].size(); ++i) {
  //   cout << a[n][i] << " ";
  // }}
  // else{ 
    // cout << sequence2.size() - 1 << endl;
    // for (size_t i = 0; i < sequence2.size(); ++i) {
    // cout << sequence2[i] << " ";
  // }
  // }
  if(sequence2.size()>c.size() && c.empty()==0){
    cout << c.size() - 1 << endl;
    for (size_t i = 0; i < c.size(); ++i) {
      cout << c[i] << " ";
    }
  }
  else {
    cout << sequence2.size() - 1 << endl;
    for (size_t i = 0; i < sequence2.size(); ++i) {
      cout << sequence2[i] << " ";
    }
  }
  // cout<<endl<<sequence2.size();
}
