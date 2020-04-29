#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int tmp = 0;
    float sum = 0;
    int avg = 0;
    for (int i = 0; i < 10; i++) {
      cin >> tmp;
      sum += tmp;
    }
    avg = round(sum / 10);
    cout << "#" << test_case << " " << avg << "\n";
  }
  return 0;
}