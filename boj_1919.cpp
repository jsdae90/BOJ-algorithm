#include <iostream>
#include <string>
using namespace std;

int str1[26], str2[26];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string f, s;
  cin >> f >> s;

  for (int i = 0; i < f.length(); i++) {
    str1[f[i] - 'a']++;
  }
  for (int i = 0; i < s.length(); i++) {
    str2[s[i] - 'a']++;
  }
  int cnt = 0;

  for (int i = 0; i < 26; i++) {
    if (str1[i] != str2[i]) {
      cnt += abs(str1[i] - str2[i]);
    }
  }

  cout << cnt << '\n';
  return 0;
}