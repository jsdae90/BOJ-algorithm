#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int test_case;
  int T, n;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
      cin >> n;
      if (n % 2 == 1) {
        sum += n;
      }
    }
    cout << "#" << test_case << " " << sum << endl;
  }
  return 0;
}