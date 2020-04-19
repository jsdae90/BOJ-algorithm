#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool vps(string ps) {
  stack<char> s;
  bool sw = true;
  for (int i = 0; i < ps.size(); ++i) {
    if (ps[i] == '(') {  // '(' 는 스택에 push
      s.push(ps[i]);
    } else if (!s.empty() &&
               ps[i] == ')') {  // 스택에 '('가 있으면서 ')'일 경우 ')'를 pop
      s.pop();
    } else if (s.empty() && ps[i] == ')') {  // ')'가 있는데, stack이 비어있다면
                                             // 쌍이 없는 잘못된 것
      sw = false;
      break;
    }
  }
  if (s.empty() && sw) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int num;
  string ps;
  cin >> num;
  for (int i = 0; i < num; ++i) {
    cin >> ps;
    if (vps(ps)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}