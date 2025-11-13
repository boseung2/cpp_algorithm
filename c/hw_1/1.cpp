#include <iostream>

using namespace std;

int main(void) {
  int result;
  int num1, num2;
  cout << "정수 one: ";
  cin >> num1;

  cout << "정수 two: ";
  cin >> num2;

  result = num1 + num2;
  cout << num1 << " + " << num2 << " = " << result << "\n";
}