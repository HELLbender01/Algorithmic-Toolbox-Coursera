#include <iostream>

int get_change(int m) {
  //write your code here
  // int a,b,c;
  return m/10 + (m - (m/10)*10)/5 + ( (m - (m/10)*10) - ((m-(m/10)*10)/5)*5 );
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
