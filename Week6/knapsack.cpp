// #include <iostream>
// #include <vector>
#include<bits/stdc++.h>

using namespace std;//::vector;

int min1,v=0;
vector<int> w;

// void optimal_weight(int W, int k) {
//   // int current_weight = 0;
//   if(v==1){ return; }
//   // if(W==0){ min1=0; v=1; return; }
//   if(k<0){ if( min1 > W ){ min1=W; } return; }
//   // for (size_t i = 0; i < w.size(); ++i) {
//   //   if (current_weight + w[i] <= W) {
//   //     current_weight += w[i];
//   //   }
//   // }
//   // cout<<"("<<W<<" "<<k<<") ";
//   if(W-w[k]==0){ min1=0; v=1; return; }
//   if(W-w[k]>0){ optimal_weight(W-w[k],k-1); }
//   optimal_weight(W,k-1);
//   // return current_weight;
// }

vector<vector<int>> a;

void rec(int W,int k){
  if(k<0){ if(k<-1){ return; } else { a[W][0]=W; if(W==0){ v=1; } return;}  }
  if(v==1){ return; }
  if(a[W][k+1]!=0){ return; }
  if(W-w[k]>=0){ rec(W-w[k],k-1); }
  rec(W,k-1);
  if(W-w[k]>=0){ a[W][k+1]=min(a[W][k],a[W-w[k]][k]); }
  else a[W][k+1]=a[W][k];
}

int main() {
  int n, W;
  cin >> W >> n;
  w.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    // cout<<w[i];
  }
  a.resize(W+1);
  for(int i=0;i<W+1;i++){
    a[i].resize(n+1);
  }
  min1 = W;
  // optimal_weight(W,n-1);
  rec(W,n-1);
  if(v==1)cout<< W <<endl;
  else cout << W-a[W][n] << '\n';
}
