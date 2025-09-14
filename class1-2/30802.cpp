#include<iostream>

using namespace std;

int count(int num, int t) {
  if(num == 0) return 0;
  return ((num - 1) / t) + 1;
}

int main(void) {
  // 티셔츠 한 장 , 펜 한 자루
  // 티셔츠 :S, M, L, XL, XXL, XXXL 
  // -> 6가지 같은 사이즈 T장만 가능
  // 펜 : 한 종류 -> P자루씩 묶음, 한 자루씩
  // 티셔츠 - 남아도됨 부족하면 안됨
  // 펜 - 정확히 수 맞아야함
  int n;
  int s, m, l, xl, xxl, xxxl;
  int t, p;

  cin >> n;
  cin >> s >> m >> l >> xl >> xxl >> xxxl;
  cin >> t >> p;

  // 티셔츠
  // 각각 (몫-1 / t) 다 더함
  // 펜
  // n / p -> 몫, 나머지
  
  int sum = count(s, t)
            + count(m, t)
            + count(l, t)
            + count(xl, t)
            + count(xxl, t)
            + count(xxxl, t);
  cout << sum << endl;
  cout << n / p << " " << n % p;
}