#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
  int n, m;
  int a[100000];
  int b[100000];

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  cin >> m;
  for(int i=0; i<m; i++) {
    cin >> b[i];
  }

  // a 배열 정렬
  // b 처음부터 돌면서 binary_search
  // b에서 자기보다 작은 값 확인하면서 a에 존재하면 1, 아니면 0 출력
  sort(a, a+n);
  for(int i=0; i<m; i++) {
    if(binary_search(a, a+n, b[i])) {
      cout << 1 << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}