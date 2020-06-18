// #include <iostream>
// #include <string>
#include<bits/stdc++.h>

using namespace std;//::string;

int a[101][101];

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m=str1.size(),l=str2.size();
  for(int i=0;i<=max(m,l);i++){
    if(i<=m)a[0][i]=i;
    if(i<=l)a[i][0]=i;
  }
  for(int i=1;i<=l;i++){
    for(int j=1;j<=m;j++){
      int b=a[i-1][j-1],c=a[i][j-1]+1,d=a[i-1][j]+1;
      if(str2[i-1]==str1[j-1]){ a[i][j]=min(b,min(c,d)); }
      else a[i][j]=min(b+1,min(c,d));
    }
  }
  return a[l][m];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
