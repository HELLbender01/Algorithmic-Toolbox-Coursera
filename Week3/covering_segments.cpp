#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end,done=0;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  // write your code here
  // for (size_t i = 0; i < segments.size(); ++i)
  int n=segments.size();
  while(n>0) {
  // vector<Segment> a=segments;
  //   cout<<endl;
  //    for(size_t i = 0; i < segments.size(); ++i) {
  //   if(segments[i].done==1)cout << segments[i].start <<"--" << segments[i].end<<"  ";
  // } cout<<endl<<"n->"<<n;

    int min=0,dist=INT_MAX;
    for(size_t j = 0; j < segments.size();j++){
      if(segments[j].done ==0 && segments[j].end < dist){ min=j; dist=segments[j].end; }
    }
    points.push_back(segments[min].end);
    // cout<<" .."<<min<<".. "<<"("<<segments[min].start<<" "<<segments[min].end<<") ";

    for(size_t j = 0; j < segments.size();j++){
      if(segments[j].done!=1&&segments[j].start <= segments[min].end){
        // segments.erase(segments.begin()+j);
        n--;
        segments[j].done=1;
        // cout<<" {"<<segments[j].start<<" "<<segments[j].end<<"} ";//<<"("<<j<<") ";
      }
    }
    // segments.erase(segments.begin()+min);
    // cout<<endl;
    // points.push_back(segments[i].start);
    // points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
