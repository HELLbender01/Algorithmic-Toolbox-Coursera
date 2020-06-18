#include <iostream>
#include <vector>
using namespace std;
// using std::vector;

int b[]={2,4,7, 2, 0, 3, 4, 8, 3, 2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1, 4, 6 ,1, 8, 0, 9, 0, 0, 1};

vector <int> a;
int get_fibonacci_partial_sum_naive(long long from, long long to) {
    int sum = 0;
    int current = 0;
    int next  = 1;

    if(to<60){    
    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum = (sum+current)%10;
            // a.push_back(sum);
            // cout<<sum<<" ";
        }

        long long new_current = next;
        next = (next + current)%10;
        current = new_current;
    }
    return sum;
    }

    // sum = 0;
    // current = 0;
    // next  = 1;
    // for (long long i = 0; i <= to; ++i) {
    //     if (i >= from) {
    //         sum = (sum+current)%10;
    //         // cout<<sum<<" ";
    //     }

    //     long long new_current = next;
    //     next = (next + current)%10;
    //     current = new_current;
    // }
    // cout<<" -- "<<sum<<" -- ";
    // cout<<"---";
    return b[(to-2)%60]-b[(from-3)%60];
}

int main() {
    long long from, to;
    cin >> from >> to;
    // get_fibonacci_partial_sum_naive(from, to);
    // cout <<a[(to-from)%60]  << '\n';
    // for(int i=0; i<60;i++){ cout<<a[i]<<" "; }
    int x=get_fibonacci_partial_sum_naive(from, to);
    if(x>=0)cout<<x;
    else cout<<x+10;
}
