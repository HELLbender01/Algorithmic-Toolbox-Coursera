// #include <iostream>
// #include <vector>
#include<bits/stdc++.h>

using namespace std;//::vector;

// int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
//   //write your code here
//   return min(min(a.size(), b.size()), c.size());
// }

int main() {
  size_t an;
  cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    cin >> a[i];
  }
  size_t bn;
  cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    cin >> b[i];
  }
  size_t cn;
  cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    cin >> c[i];
  }
  short int d[max(an,max(bn,cn))+1][max(an,max(bn,cn))+1][max(an,max(bn,cn))+1];
  for(int i=0;i<=max(an,max(bn,cn)); i++){
    for(int j=0;j<=max(an,max(bn,cn)); j++){
      d[0][i][j]=0;
      d[i][0][j]=0;
      d[i][j][0]=0;
    }
  }
  for(int i=1;i<=an;i++){
    for(int j=1;j<=bn;j++){
      for(int k=1;k<=cn;k++){
        short int z1=d[i-1][j-1][k-1],z2=d[i-1][j-1][k],z3=d[i-1][j][k-1],z4=d[i][j-1][k-1],z5=d[i][j][k-1],z6=d[i-1][j][k],z7=d[i][j-1][k];
        short int zz=max(z2,max(z3,max(z4,max(z5,max(z6,z7)))));
        if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){ d[i][j][k] = max((short)(z1+1),zz); }
        else { d[i][j][k]=max(z1,zz); }
      }
    }
  }
  cout << (int)d[an][bn][cn] << endl;
}
