#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int a=0,b=0;
  while(n>0){
    a++;
    if(n-a>a){
      n-=a;
      summands.push_back(a);
    }
    else { summands.push_back(n); n=0; }
   }

  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
