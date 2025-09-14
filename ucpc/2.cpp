#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

int adjList[1000][1000];
//vector<int> result;

int main(void) {
  int n,m;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> adjList[i][j];
    }
  }

  
  // for(int i=0; i<n; i++) {
  //   for(int j=0; j<n; j++) {
  //     cout << adjList[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}