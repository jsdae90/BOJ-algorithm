#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  queue<int> q;
  int n = 0;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; ++i) {
    string order;
    getline(cin, order);  // read string

    if (order == "pop") {
      if (q.empty()) {
        cout << -1 << endl;
      } else {
        cout << q.front() << endl;
        q.pop();
      }
    }

    else if (order == "size") {
      cout << q.size() << endl;
    }

    else if (order == "empty") {
      if (q.empty()) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }

    else if (order == "front") {
      if (q.empty()) {
        cout << -1 << endl;
      } else {
        cout << q.front() << endl;
      }
    }

    else if (order == "back") {
      if (q.empty()) {
        cout << -1 << endl;
      } else {
        cout << q.back() << endl;
      }
    }

    else {
      order = order.erase(0, 5);  // erase order's 0 to 5
      int x = stoi(order);        // string to int
      q.push(x);
    }
  }
}