#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;//::vector;
// using std::string;

string largest_number(vector<string> a) {
  //write your code here
  stringstream ret;
  vector<int> b(a.size());
  vector<int> e[a.size()];
  int g=a.size();

  for(int i=0;i<a.size();i++){
    b[i]=0;
    int d = stoi(a[i]);
    while( d>0 ){
      e[i].push_back(d%10);
      d = d/10;
    }
  }

  while( g > 0 ){
    int c = 0 , f;
    for(int i=0;i<a.size();i++){
      // cout<<b[i]<<" i->"<<i<<" g->"<<g<<" c->"<<c<<endl;
      if(b[i]!=1){
      if(c < e[i][e[i].size()-1]){
        c = e[i][e[i].size()-1];
        f = i;
        // cout<<" ~"<<e[i][e[i].size()-1]<<"~ "<<" ::"<<a[i]<<":: "<<endl;
      }
      else if(c == e[i][e[i].size()-1]){
        if(stoi(a[i]+a[f]) > stoi(a[f]+a[i])){
            c = e[i][e[i].size()-1]; f = i; 
            // cout<<" .."<<a[i]+a[f]<<".. "<<endl;
          }
      }
      }
    }
    b[f]=1;
    ret << a[f];
    // cout<<"{"<<a[f]<<"} ";
    g--;
  }
        // for(int j = 0 ; j < e[i].size() && j < e[f].size() ; j++){
        //   if(e[i][e[i].size()-1-j] > e[f][e[f].size()-1-j]){
        //     c = e[i][e[i].size()-1]; f = i; flag = 1; break;
        //   }
        //   else if(e[i][e[i].size()-1-j] < e[f][e[f].size()-1-j]){
        //     flag = 1; break;
        //   }
        // }
        // if(flag == 0){
        //   if(e[i].size() == e[f].size()){
        //     cout<<" bla ";
        //     flag = 1; 
        //   }
          // else if( e[i].size() > e[f].size() ){
          //   if(e[i][0] > e[i][e[i].size()-1]){
          //     c = e[i][e[i].size()-1]; f = i; flag = 1;
          //   }
          //   else { flag =1; }
          // }
          // else if(e[i].size() < e[f].size() ) {
          //   if( e[f][0] > e[f][e[f].size()-1] ){
          //     flag = 1; 
          //   }
          //   else { 
          //     c = e[i][e[i].size()-1]; f = i; flag = 1; 
          //   }
          // }
          // // stringstream m,n;
          // //m<<a[i]<<a[f];
          // //n<<a[f]<<a[i];
      //     else if(stoi(a[i]+a[f]) < stoi(a[f]+a[i])){
      //       c = e[i][e[i].size()-1]; f = i; flag = 1;
      //       cout<<" .."<<a[i]+a[f]<<".. ";
      //     }
          
      //   }
      // }
      // flag=0;
    // }
      // if( flag==1 ) break;
    // }
  //   b[f]=1;
  //   ret << a[f];
  //   cout<<a[f]<<" ";
  //   g--;
  // }
  
  // for (size_t i = 0; i < a.size(); i++) {
  //   ret << a[i];
  // }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a);
  // cout<<stoi(a[0]+a[1]);
    // stringstream ret;
    // ret<<2<<4<<"a"<<1;
    //   int result;
    //     ret >> result;
    //   cout<<result;

}
