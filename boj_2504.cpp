#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  stack<string> st;
  string strings;
  string temp;
  int tempSum;
  int result = 1;
  cin >> strings;
  for (int i = 0; i < strings.size(); i++) {
    temp = strings.at(i);
    if (temp == "(" || temp == "[")
      st.push(temp);
    else {
      tempSum = 1;
      // (1)
      while (!st.empty() && st.top() != "(" && st.top() != "[") {
        //(2)
        tempSum *= stoi(st.top());
        st.pop();
      }
      // (3)
      if (st.empty() || (temp == ")" && st.top() != "(") ||
          (temp == "]" && st.top() != "[")) {
        result = 0;
        break;
      }
      // (4)
      if (temp == ")")
        tempSum *= 2;
      else
        tempSum *= 3;
      st.pop();
      // (5)
      while (!st.empty() && st.top() != "(" && st.top() != "[") {
        tempSum += stoi(st.top());
        st.pop();
      }
      st.push(to_string(tempSum));
    }
  }
  if (result == 0 || st.size() != 1 || st.top() == "[" || st.top() == "(")
    cout << 0;
  else
    cout << st.top();

  return 0;
}