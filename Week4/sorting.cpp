#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;//::vector;
// using std::swap;
// int c,d;

vector<int> b;
// void partition2(vector<int> &a, int l, int r) {
//   // int x = a[l];
//   int k = l , m = r;
//   for (int i = l + 1; i <= r; i++) {
//     if(a[i]<a[l]){
//       b[k]=a[i];
//       // cout<<b[k]<<" ";
//       k++;
//     }
//     else if(a[i]>a[l]){
//       b[m]=a[i];
//       // cout<<b[m]<<" ";
//       m--;
//     }
    
//     // cout<<endl;
//     // if (a[i] <= x) {
//     //   j++;
//     //   swap(a[i], a[j]);
//     // }
//   }
//   for(int i=k;i<=m;i++){
//     a[i]=a[l];
//   }
//   for(int i=l;i<=r;i++)
//   {
//     if(i<k||i>m){a[i]=b[i];}
//   }
//   // swap(a[l], a[j]);
//   // return j;
//   // ret<<k<<","<<m;
//   // for (size_t i = 0; i < a.size(); ++i) {
//   //   cout << a[i] << ' ';
//   // }cout<<endl;
  
//   c=k;
//   d=m;
// }

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  // int w=c,x=d;
  // partition2(a, l, r);
  int k = l , m = r;
  for (int i = l + 1; i <= r; i++) {
    if(a[i]<a[l]){
      b[k]=a[i];
      k++;
    }
    else if(a[i]>a[l]){
      b[m]=a[i];
      m--;
    }
  }
  for(int i=k;i<=m;i++){
    a[i]=a[l];
  }
  for(int i=l;i<=r;i++)
  {
    if(i<k||i>m){a[i]=b[i];}
  }
  
  // ret>>k>>c>>m;

  randomized_quick_sort(a, l, k - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  b.resize(n);
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
