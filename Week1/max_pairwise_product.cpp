
#include<bits/stdc++.h>

using namespace std;

vector< vector<int>> a;
;
void rec(int b,vector<int> n,vector<int> d[]){
    if(a[b].size()==1){ return; }
    for(int j=0;j<1;j++){
        vector<int> c;
        for(int i=0;i<a[b].size()-1;i=i+2){
            d[a[b][i]].push_back(a[b][i+1]);
            d[a[b][i+1]].push_back(a[b][i]);
            if(n[a[b][i]]>n[a[b][i+1]]){ c.push_back(a[b][i]); }
            else c.push_back(a[b][i+1]);
        }
        if(a[b].size()%2!=0){ c.push_back(a[b][a[b].size()-1]); }
        a.push_back(c);
    }
    // for(int i=0;i<a[b].size();i++){ cout<<a[b][i]<<" ";}
    // cout<<endl;
    rec(b+1,n,d);
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n),d[n];
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    vector <int> tmp;
    for(int i=0;i<numbers.size();i++){ tmp.push_back(i); }
    a.push_back(tmp);
    // d.resize(n);
    rec(0,numbers,d);
    cout<<a[a.size()-1][0]<<endl;
    for(int i=0;i<d[a[a.size()-1][0]].size();i++){
        cout<<d[a[a.size()-1][0]][i];
    }

    return 0;
}
