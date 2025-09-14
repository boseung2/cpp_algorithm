#include<iostream>
#include<iomanip> // for hex formatting

using namespace std;

int main(void) {
  int i = 0x1B2B3B4B;
  int *pi = &i;
  char *pc = (char*)pi;
  short *ps = (short*)pi;

  cout << hex << *pi << endl;
  cout << hex << (int)(unsigned char)*pc << endl;
  cout << hex << *ps << endl;

}