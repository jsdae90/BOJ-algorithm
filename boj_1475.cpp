#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int cnt[10] = {0};

  while (true) {
    cnt[n % 10]++;
    if (n / 10 == 0) {
      break;
    }
    n /= 10;
  }

  int num = 0;
  for (int i = 0; i < 10; i++) {
    if (i != 9 && i != 6) {
      num = max(num, cnt[i]);
    }
  }

  printf("%d", max(num, (cnt[6] + cnt[9] + 1) / 2));
}