// #include <algorithm>
// #include <iostream>
// #include <sstream>
// #include <iomanip>
// #include <vector>
// #include <string>
// #include <cmath>
#include<bits/stdc++.h>

using namespace std;//::vector;
// using std::string;
// using std::pair;
// using std::min;

bool abc(pair<int,int> a,pair<int,int> b){ return (a.first<b.first); }
bool abc2(pair<int,int> a,pair<int,int> b){ return (a.second<b.second); }


double dist(vector<pair<int,int>> x,int i,int j){
  return (sqrt(pow(x[i].first-x[j].first,2) + pow(x[i].second-x[j].second,2)));
}

double minimal_distance(vector<pair<int,int>> x,int l,int r) {
  if(r<=l+1){ 
    if(r!=l)return dist(x,l,r);
    else return INT_MAX;
  }
  // cout<<" ["<<l<<" "<<r<<"] ";
  double d=min( minimal_distance(x,l,l+(r-l)/2) , minimal_distance(x,(r-l)/2+l+1,r) );
  
  vector<pair<int,int>> c;//,f;
  for(int i=l+(r-l)/2;i>=l;i--){
    if(abs(x[i].first-x[(l+(r-l)/2)].first)>d){ break; }
      c.push_back(make_pair(x[i].first,x[i].second));
  }
  for(int i=(r-l)/2+l+1;i<=r;i++){
    if(abs(x[i].first-x[(l+(r-l)/2)].first)>d){ break; }
      c.push_back(make_pair(x[i].first,x[i].second));
  }
  sort(c.begin(),c.end(),abc2);
  for(int i=0;i<c.size()-1;i++){
    int j = i+1;
    while( j<c.size() && c[j].second < c[i].second + d){
    double e = dist(c,i,j);
      if(e<d){ d = e; }
      j++;
  }
  }
  return d;
}

double bleh(vector<pair<int,int>> x,int l,int r){
if(r<=l+1){ 
    if(r!=l)return dist(x,l,r);
    else return INT_MAX;
  }
  double d=min( bleh(x,l,l+(r-l)/2) , bleh(x,(r-l)/2+l+1,r) );
  for(int i=l+(r-l)/2 ; i>=l ;i--){
    if(x[(l+(r-l)/2)].first-x[i].first >= d){ break; }
    for(int j=(r-l)/2+l+1 ; j<=r ; j++){
      if(x[j].first > x[i].first + d){ break; }
      double e = dist(x,i,j);
      if(e<d){ d = e; }
    }
  }

return d;
}

int main() {
  size_t n,aa,bb;
  cin >> n;
  // n=rand()%5+2;
  vector<pair<int,int>> x(n);
  for (size_t i = 0; i < n; i++) {
    cin >> aa >> bb;
    x[i]=make_pair(aa,bb);
    // x[i]=make_pair(rand()%10,rand()%10);
  }
  
  sort(x.begin(),x.end(),abc);
  
  // for (size_t i = 0; i < n; i++) {
  //   cout<<" ("<<x[i].first<<" "<<x[i].second<<") ";
  // }
  // int w=minimal_distance(x,0,x.size()-1),v=bleh(x,0,x.size()-1); 
  // cout<<"  >>"<<v<<" "<<w<<"<<  ";

  // while(v==w){
  //   n=rand()%5+2;
  //   x.empty(); x.resize(n);
  //   for (size_t i = 0; i < n; i++) {
  //   x[i]=make_pair(rand()%10,rand()%10);
  // }
  // sort(x.begin(),x.end(),abc);
  // for (size_t i = 0; i < n; i++) {
  //   cout<<" ("<<x[i].first<<" "<<x[i].second<<") ";
  // }
  // v=bleh(x,0,x.size()-1);
  // w=minimal_distance(x,0,x.size()-1);
  // cout<<"  >>"<<v<<" "<<w<<"<<  ";
  // }

  // for(int i=0;i<x.size();i++){
  //   cout<<" ("<<x[i].first<<" "<<x[i].second<<") ";
  // }

  // aa = x[0].first; bb=x[n-1].first; 
  cout << fixed;
  cout << setprecision(9) << minimal_distance(x,0,x.size()-1) << "\n";
}
