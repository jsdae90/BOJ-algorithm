#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
  int N = 0;
  scanf("%d", &N);

  stack<char> result;
  stack<char> temp;

  for (int t = 0; t < N; t++) {
    string tmp;
    scanf("%s", &tmp);

    stack<char> result;
    stack<char> temp;

    for (int i = 0; i < tmp.length(); i++) {
      if (tmp[i] == '<') {
        if (!result.empty()) {
          temp.push(result.top());
          result.pop();
        }
      }

      else if (tmp[i] == '>') {
        if (!temp.empty()) {
          result.push(temp.top());
          temp.pop();
        }
      }

      else if (tmp[i] == '-') {
        if (!result.empty()) {
          result.pop();
        }
      }

      else {
        result.push(tmp[i]);
      }
    }

    while (!temp.empty()) {
      result.push(temp.top());
      temp.pop();
    }

    string answer;

    while (!result.empty()) {
      answer += result.top();
      result.pop();
    }

    reverse(answer.begin(), answer.end());
    printf("%s\n", answer.c_str());
  }
  return 0;
}