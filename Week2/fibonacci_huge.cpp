#include<bits/stdc++.h>

using namespace std;

vector <long long> a;
int x=0;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    int l=0;
    long long previous = 0;
    long long current  = 1;
    a.push_back(0);
    a.push_back(1);

    // cout<< a[0]<<" "<<a[1]<<" ";
    if(n<m){
        for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }
    return current%m;
    }
    else {
        for (long long i = 0; ; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
        
        a.push_back(current%m);
        
        if(l==1){
            if(i==x+5){ break; }
            if(a[i-x]!=a[i+2]){
                // cout<<"~~"<<a[i-x]<<","<<a[i+2]<<"~~ ";
                l=0;
                x=0;
            }
        }

        if((l!=1)&&current%m==0){
            x=i;
            l=1;

            // cout<<endl<<"--"<<x<<"-- "<<endl;
        }
        // cout<<a[i+2]<<" ";//("<<l<<") ";
    }
    }

    return a[n%(x+2)];
    // return current % m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    // get_fibonacci_huge_naive(n, m);
    // for(int i=0;i<x;i++){ cout<<a[i]<<" "; }
    cout << get_fibonacci_huge_naive(n, m) << '\n';
}
