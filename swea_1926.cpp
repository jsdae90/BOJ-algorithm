#include <iostream>
#include <string>
using namespace std;

void calc(int n) {
  string strnum = to_string(n);
  int cnt = 0;
  for (int i = 0; i < strnum.length(); i++) {
    int x = strnum[i] - '0';
    if (x == 3 || x == 6 || x == 9) {
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << n << " ";
  } else {
    for (int i = 0; i < cnt; i++) {
      cout << "-";
    }
    cout << " ";
  }
}

int main(int argc, char** argv) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    calc(i);
  }
  return 0;
}