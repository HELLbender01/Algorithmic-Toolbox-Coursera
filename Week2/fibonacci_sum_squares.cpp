#include <iostream>
using namespace std;
int a[]={2, 6, 5, 0, 4, 3, 4, 0, 5, 6, 2, 1, 0, 0, 9, 8, 4, 5, 0, 6, 7, 6, 0, 5 ,4, 8, 9, 0, 0, 1 };
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    // long long previous = 0;
    // long long current  = 1;
    // long long sum      = 1;

    // for (long long i = 0; i < n - 1; ++i) {
    //     long long tmp_previous = previous;
    //     previous = current;
    //     current = (tmp_previous + current)%10;
    //     sum = ((current * current)+sum)%10;
    //     cout<<sum<<" ";
    // }

    return a[(n-2)%30];
}

int main() {
    long long n = 0;
    cin >> n;
    cout <<fibonacci_sum_squares_naive(n);
}
