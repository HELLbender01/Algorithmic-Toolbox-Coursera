#include <iostream>

int get_fibonacci_last_digit_naive(long n) {
    if (n <= 1)
        return n;

    // int previous = 0;
    // int current  = 1;//,sum=1;

    int a[]={2,4,7, 2, 0, 3, 4, 8, 3, 2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1, 4, 6 ,1, 8, 0, 9, 0, 0, 1};

    // for (int i = 0; i < n - 1 ; ++i) {
    //     int tmp_previous = previous;
    //     previous = current;
    //     current = (tmp_previous + current+1)%10;
    //     // sum=(sum+current)%10;
    //     // std::cout<<current<<" ";
    // }
    // sum=(sum+current)%10;
    // std::cout<<current<<"---";
    return a[(n-2)%60];
    // return current;
}

int main() {
    long n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
