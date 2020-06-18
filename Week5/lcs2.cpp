// #include <iostream>
// #include <vector>
#include<bits/stdc++.h>

using namespace std;//::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  // return min(min(a.size(), b.size()), c.size());
}

int main() {
  int a[101][101];
  size_t n;
  cin >> n;
  vector<int> g(n);
  for (size_t i = 0; i < n; i++) {
    cin >> g[i];
  }

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    cin >> b[i];
  }
  // sort(a.begin(),a.end());
  // sort(b.begin(),b.end());
  int c=0,d=0,e=0;
  
  // for(int i=0;i<a.size();i++){
  //   for(int j=d;j<b.size();j++){
  //     if(a[i]==b[j]){ c++; d=j+1; break; }
  //   }
  //   if(d>=b.size()){ e=max(e,c); c=0; d=0; cout<<e<<" "; }
  // }
  int k=g.size(),l=b.size();
  for(int i=0;i<=max(k,l);i++){
    if(i<=k)a[0][i]=0;
    if(i<=l)a[i][0]=0;
  }
  for(int i=1;i<=l;i++){
    for(int j=1;j<=k;j++){
      int e=a[i-1][j-1],c=a[i][j-1],d=a[i-1][j];
      if(b[i-1]==g[j-1]){ a[i][j]=max(e+1,max(c,d)); }
      else a[i][j]=max(e,max(c,d));
    }
  }
  cout<<a[l][k];
  // cout<<e;
  // cout << lcs2(a, b) << endl;
}
