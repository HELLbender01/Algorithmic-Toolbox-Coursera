#include <iostream>
#include <vector>

using namespace std;   //::vector;
// int count=0,count2=0;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  // cout<<".. ";

  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  for(int i=left;i<ave;i++){
    for(int j=ave;j<right;j++){
      if(a[i]>a[j])number_of_inversions++;
    }
  }
  // for(int i=0; i < a.size(); i++){
  //   cout<<a[i]<<" ";}cout<<endl;
  
  int m=left,n=ave;
  for(int i=left;i<right;i++){
    if(m < ave && n < right){
      if(a[m] < a[n]){
        b[i] = a[m];
        m++;
      }
      else { b[i] = a[n]; n++; }
    }
    else if(m >= ave){
      b[i] = a[n];
      n++;
    }
    else { b[i] = a[m]; m++; }
  }
  for(int i=left; i < right; i++){
    a[i]=b[i];
  }
  // for(int i=0; i < a.size(); i++){
  //   cout<<a[i]<<" ";
  // }cout<<"  "<<left<<"  "<<ave<<"  "<<right<<"  --"<<number_of_inversions<<"\n\n";

  return number_of_inversions;
}
// void bla(vector<int> &a, size_t left, size_t right){
//   if(left==right){ return; }
//   if(right-left==1){ if(a[]) }
// }
// void abc(vector <int> a){
//   vector<int> b;
//   int m = rand()%20;
//   for (size_t i = 0; i < m; i++) {
//     // cin >> a[i];
//     a.push_back(rand()%20);
//   }
//   count=0;count2=0;
//   for(int i=0;i<a.size()-1;i++){
//     if(a[i+1]<a[i]){
//       b.push_back(i+1);
//     }
//   }
//   for(int i=0;i<b.size();i++){
//     for(int j= 0;j<b[i];j++){
//       if(a[j]>a[b[i]])count++;
//     }
//   }
//    for(int i=0;i<a.size();i++){
//     for(int j=i;j<a.size()-1;j++){
//       if(a[j]<a[i])count2++;
//     }
//   }

// }

int main() {
  int n;
  cin >> n;
  // vector<int> a(n),c(n);
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b(a.size());
  cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  
  // for(int i=0;i<n-1;i++){
  //   if(a[i+1]<a[i]){
  //     b.push_back(i+1);
  //   }
  // }
  // for(int i=0;i<b.size();i++){
  //   for(int j= 0;j<b[i];j++){
  //     if(a[j]>a[b[i]])count++;
  //   }
  // }
  // cout<<count;
  
  // for(int i=0;i<m;i++){
  //   for(int j=i;j<m-1;j++){
  //     if(a[j]<a[i])count2++;
  //   }
  // }
  
  // while(count==count2){
  // abc(a);
  // for(int i=0;i<a.size();i++){
  //   cout<<a[i]<<"-";
  // }  
  // cout<<count<<" "<<count2<<endl;
  // a.empty();
  // }


}

