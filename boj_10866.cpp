#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n = 0;
  cin >> n;
  cin.ignore();

  deque<int> dq;

  for (int i = 0; i < n; ++i) {
    string order;
    getline(cin, order);

    if (order == "front") {
      if (dq.empty()) {
        cout << -1 << "\n";
      } else {
        cout << dq.front() << "\n";
      }
    }

    else if (order == "back") {
      if (dq.empty()) {
        cout << -1 << "\n";
      } else {
        cout << dq.back() << "\n";
      }
    } else if (order[1] ==
               'u') {  // check abt order == push
                       // order[1] is char type data, so only can compare using
                       // ' ' if you use " " for compare order[1], there will be
                       // warnings with red line
      string backup = order;
      if (order[5] == 'f') {                // check push_'f'ront
        int x = stoi(backup.erase(0, 10));  // stoi mean "string to integer"
        dq.push_front(x);
      } else {  // push_back
        int x = stoi(backup.erase(0, 9));
        dq.push_back(x);
      }
    }

    else if (order[1] == 'o') {  // check abt order == pop
      if (order[4] == 'f') {     // check pop_'f'ront
        if (dq.empty()) {
          cout << -1 << "\n";
        } else {
          cout << dq.front() << "\n";
          dq.pop_front();
        }
      } else {  // check pop_back
        if (dq.empty()) {
          cout << -1 << "\n";
        } else {
          cout << dq.back() << "\n";
          dq.pop_back();
        }
      }
    } else if (order == "size") {
      cout << dq.size() << "\n";
    } else if (order == "empty") {
      if (dq.empty()) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
  }
}