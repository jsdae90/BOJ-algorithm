#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  int a[10];
  for (int tc = 1; tc <= T; tc++) {
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
    int min = 10000;
    int max = 0;
    int sum = 0;
    for (int i = 0; i < 10; i++) {
      if (a[i] < min) min = a[i];
      if (a[i] > max) max = a[i];
      sum += a[i];
    }
    int res = round((sum - min - max) / 8.0F);
    printf("#%d %d\n", tc, res);
  }
}