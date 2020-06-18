// #include <iostream>
// #include <vector>
#include<bits/stdc++.h>

using namespace std;//::vector;

int sum=0,v=0;
vector<short int> B;
int partition3(vector<short int> A, int m, int pos,vector<short int> c) {
  //write your code here

  // cout<<" ("<<m<<" "<<A.size()<<" "<<A[pos]<<") ";
  if(v==1){ return 1; }
  if(m > sum/3){ return 0; }
  if(m==sum/3){
    B=c;
    v=1; return 1; 
    } 
  if(pos>=A.size()){ return 0; }

  int d1=partition3(A,m,pos+1,c);
  // m+=A[pos];
  // A.erase(A.begin()+pos);
  c.push_back(pos);
  int d2=partition3(A,m+A[pos],pos+1,c);
  return d1||d2;
}

int partition2(vector<short int> A, int m, int pos) {
  //write your code here

  // cout<<" ("<<m<<" "<<A.size()<<" "<<A[pos]<<") ";
  if(v==1){ return 1; }
  if(m > sum/3){ return 0; }
  if(m==sum/3){
    // B=c;
    v=1; return 1; 
    } 
  if(pos>=A.size()){ return 0; }

  int d1=partition2(A,m,pos+1);
  int d2=partition2(A,m+A[pos],pos+1);
  return d1||d2;
}

int main() {
  int n;
  cin >> n;
  vector<short int> A(n),c;
  for (size_t i = 0; i < A.size(); ++i) {
    cin >> A[i];
    sum+=A[i];
  }

  // cout<<endl<<sum/3<<" ";
  // partition3(A,0,0,c);
  // for(int i=0;i<B.size();i++){
  //   cout<<A[B[i]]<<" ";
  // }
  if( n<3 || sum%3!=0 ){ cout<<"0"<<endl; }
  else {
  // cout << partition3(A,0,0,c) << '\n';
  if(partition3(A,0,0,c)==0){ cout<<"0"<<endl; }
  else {
    vector<short int> d;
    for(int i=0,j=0;i<A.size();i++){
      if(i==B[j]){ j++; }
      else { d.push_back(A[i]); }
    }
    v=0;
    cout<< partition2(d,0,0) << endl;
  }
  
  }
}
