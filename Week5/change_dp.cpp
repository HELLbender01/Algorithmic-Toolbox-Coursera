// #include <iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> change;

int get_change(int m) {
  //write your code here
  if(m==0) return 0;
  int a;
  if(change[m]!=0 && change[m]>10000){
  if(m-1>0){
    a=get_change(m-1)+1;
    // cout<<get_change(m-1)+1<<" "<<m;
    if(change[m]>a)change[m]=a; 
  }
  if(m-3>0){
    a=get_change(m-3)+1;
    if(change[m]>a)change[m]=a; 
  }if(m-4>0){
    a=get_change(m-4)+1;
    if(change[m]>a)change[m]=a; 
  }
  
  // cout<<" ("<<change[m]<<"  --"<<m<<") ";
  } 
  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  change.resize(m+5);
  change[0]=0;
  change[1]=1;
  for(int i=2;i<m+5;i++){
    change[i]=INT_MAX;
  }
  change[4]=1;
  change[3]=1;

  std::cout << get_change(m) << '\n';
}
