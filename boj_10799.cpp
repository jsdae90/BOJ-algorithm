#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string s;
  stack<char> stk;
  int cnt = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      stk.push(s[i]);
    } else {
      stk.pop();
      if (s[i - 1] == '(') {
        cnt += stk.size();
      } else {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}