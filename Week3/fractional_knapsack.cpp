// #include <iostream>
// #include <vector>
#include<bits/stdc++.h>

using namespace std;
// using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  while(capacity>0&&values.empty()!=1){
    int max=0;
    for(int i=0;i<values.size();i++){
      if((((double)values[max])/weights[max]) < (((double)values[i])/weights[i])){ max=i; }
    }
    if(capacity-weights[max]>=0){ 
      // cout<<values[max]<<" ";
      capacity-=weights[max]; value+=values[max]; values.erase(values.begin()+max); weights.erase(weights.begin()+max); }
    else {
      value+=(((double)values[max])/weights[max])*capacity;
      // cout<<".."<<values[max]<<"..";
      break;
    }
  }

  // cout<<" --";
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
