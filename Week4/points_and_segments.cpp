#include<bits/stdc++.h>

using namespace std;//::vector;
// void rec(vector<int> starts,vector<int> ends,int left, int right){
//   if(right<=left)return;
//   int k = left + rand()%(right-left+1);
//   swap(starts[left],starts[k]);
//   swap(ends[left],ends[k]);
//   int j=0;
//   for(int i=left+1;i<=right;i++){
//     if(starts[i]<=starts[left]){ swap(starts[j+1],starts[i]); swap(ends[j+1],ends[i]); j++; }
//   }
//   swap(starts[left],starts[j]); swap(ends[left],ends[j]); 
//   rec(starts,ends,left,j-1);
//   rec(starts,ends,j+1,right);

// }
// vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//   vector<int> cnt(points.size());
//   rec(starts,ends,0,starts.size()-1);
//   for(int j=0;j<points.size();j++){
//   int count=0;
//   for(int i=0;i<starts.size();i++){
//     if(starts[i]>points[j]){break;}//cout<<"("<<starts[9]<<" "<<points[j]<<") bla "; break;}
//     if(ends[i]>points[j]){ ++count;}//<<"("<<starts[i]<<" "<<points[j]<<").. ";}
//   }
//   cnt[j]=count;
//   }
//   // int max=INT_MIN,min=INT_MAX;
//   // for(int i=0;i<ends.size();i++)
//   // {if(ends[i]>max)max=ends[i];}
//   // for(int i=0;i<points.size();i++)
//   // {if(points[i]>max)max=points[i];}
//   // // if(points[points.size()-1]>max)max=points[points.size()-1];
  
//   // for(int i=0;i<ends.size();i++)
//   // {if(starts[i]<min)min=starts[i];}
//   // for(int i=0;i<points.size();i++)
//   // {if(points[i]<min)min=points[i];}
//   // // if(points[0]>min)min=points[0];
  
//   // for(int i=0;i<starts.size();i++){
//   //   starts[i]-=min;
//   //   ends[i]-=min;
//   // }
//   // for(int i=0;i<points.size();i++){ points[i]-=min; }//cout<<points[i]<<" "; } //cout<<"..";
//   // vector<char> a(max-min+10);
//   // for(int i=0;i<starts.size();i++){
//   //   for(int j=starts[i];j<ends[i];j++){
//   //     a[j]++;
//   //   }
//   // }
//   // // cout<<"--"<<max<<" "<<min<<"--";
//   // for(int i=0;i<cnt.size();i++){
//   //   cnt[i]=(int)a[points[i]];
//   // }

//   return cnt;
// }

// vector<char> c;
// void rec2(vector<int> &b,int left, int right){
//   if(right<=left)return;
//   int k = left + rand()%(right-left+1);
//   // if(c[left]=='p'){ points[left]}
//   swap(b[left],b[k]);
//   swap(c[left],c[k]);
  
//   int j=left;
//   for(int i=left+1;i<=right;i++){
//     if(b[i]<=b[left]){ swap(b[j+1],b[i]); swap(c[j+1],c[i]); j++; }
//   }
//   swap(b[left],b[j]); swap(c[left],c[j]); 
//   rec2(b,left,j-1);
//   rec2(b,j+1,right);

// }
// vector<int> bla(vector<int> b, vector<int> points){

//   // for(int i=0;i<b.size();i++){
//   //   cout<<b[i]<<" "<<(char)c[i]<<", ";}
//   rec2(b,0,b.size()-1);

//   vector <int> cnt;
//   for(int j=0;j<points.size();j++){
//   int count =0;
//   for(int i=0;i<b.size();i++){
//     if(b[i]>points[j]){break;}
//     if(c[i]=='l'){ count++; }
//     // else if(c[i]=='p'){
//     //   // for(int j=0;j<points.size();j++){ if(points[j]==b[i]){ cnt[j]=count; break; } }
//     //   cnt.push_back(count); break;    
//     // }
//     else count--;
//   }cnt.push_back(count);
//   }
//   return cnt;

// }

// vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//   vector<int> cnt(points.size());
//   for (size_t i = 0; i < points.size(); i++) {
//     for (size_t j = 0; j < starts.size(); j++) {
//       cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
//     }
//   }
//   return cnt;
// }
bool start(pair<int,int> &b,pair<int,int> &c){ return (b.first<c.first);}
bool end1(pair<int,int> &b,pair<int,int> &c){ return (b.second<c.second);}

vector<int> bla2(vector<pair<int,int>> b,vector<int> points){
  vector<int> cnt;
  sort(b.begin(),b.end(),start);
  vector<pair<int,int>> d=b;
  // for(int i=0;i<b.size();i++){ cout<<"("<<d[i].first<<" "<<d[i].second<<") ";} cout<<endl;
  
  sort(b.begin(),b.end(),end1);
  vector<pair<int,int>> e=b;
  // for(int i=0;i<b.size();i++){ cout<<"("<<e[i].first<<" "<<e[i].second<<") ";} cout<<endl;
  // int left=0,right=b.size()-1;
  // for(int i=0;i<points.size();i++){ cout<<"("<<points[i]<<") ";} cout<<endl;

  int mid;
  for(int i=0;i<points.size();i++){
    int x=-1,y=-1,left=0,right=b.size()-1;
  while(right>=left){
    mid=(right+left)/2;
    if(right==left){
       if(d[left].first>points[i])break;
       else {
         int j;
         for(j=left;j<d.size();j++){
           if(d[j].first>points[i])break;
         }
         x=j-1; break;
       }
       }
    if(d[mid].first<=points[i]){ x=mid; left=mid+1;}
    else {right=mid-1;}
  } 
  // cout<<" "<<points[i]<<" _"<<x<<"_";
  if(x==-1){ cnt.push_back(0); }
  else {
    right=b.size()-1; left=0;
    while(right>=left){
    mid=(right+left)/2;
    if(right==left){ 
      if(e[left].second>points[i])break;
       else {
         int j;
         for(j=left;j<e.size();j++){
           if(e[j].second>=points[i])break;
         }
         y=j-1; break;
       }
      }
    if(e[mid].second<points[i]){ y=mid; left=mid+1;}
    else {right=mid-1;}
  }
  // cout<<"."<<y<<".  ";
  cnt.push_back(x-y);
  }
  }
  return cnt;
}

int main() {
  int n, m,x,y;
  cin >> n >> m;
  vector<pair<int,int>> b;
  // c.resize(2*n+m);//, ends(n);
  for (size_t i = 0; i < n; i++) {
    cin >> x >>y;
    b.push_back(make_pair(x,y));
    // if(i%2==0){c.push_back('l');}
    // else c.push_back('r');
  }
  vector<int> points(m);
  // points[0].resize(m);   points[1].resize(m);
  for (size_t i = 0; i < m; i++) {
    cin >> points[i];
    // b[2*n+i]=points[i];
    // c[2*n+i]='p';
    // points[i]=2*n+1;
  }
   vector<int> cnt = bla2(b,points);//bla(b , points);
  for (size_t i = 0; i < cnt.size(); i++) {
    cout << cnt[i] << ' ';
  }
}
