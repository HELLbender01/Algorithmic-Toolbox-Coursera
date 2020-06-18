#include <iostream>
#include <vector>

using namespace std;

// using std::cin;
// using std::cout;
// using std::vector;
// using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int a=0,b=0;
    while(dist-a>=tank){
        if(dist-a<=tank){ return b; }
        int i=0;
        while(i<stops.size()&&stops[i]-a<=tank){
            i++;
        }
        a=stops[i-1];
        b++;
        // cout<<a<<"--"<<b<<"--"<<stops.size()<<"--"<<i<<" "<<endl;
        if(i==0){ return -1; }
        stops.erase(stops.begin(),stops.begin()+i);

    }
    if(dist-a<=tank){ return b; }

    return -1;
}


int main() {
    int d = 0,m=0,n=0;
    cin >> d;
    // int m = 0;
    cin >> m;
    // int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
