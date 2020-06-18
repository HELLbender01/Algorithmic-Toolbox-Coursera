#include <iostream>

long gcd_naive(long long a, long long b) {
  // int current_gcd = 1;
  if(a==0){ return b; }
  else if(b==0){ return a; }

  if(a<b){ gcd_naive(a,b%a); }
  else { gcd_naive(a%b,b); }

  // return current_gcd;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  if(a!=b){ std::cout << (a * b)/gcd_naive(a, b) << std::endl; }
  else std::cout << a;
  return 0;
}
