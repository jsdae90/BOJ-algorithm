#include <iostream>
#include <stack>
using namespace std;

int N;
int ans[500001];

stack<pair<int, int>> st;

int main() {
  int height = 0;
  cin >> N;
  cin >> height;
  st.push(make_pair(1, height));

  for (int i = 1; i < N; i++) {
    cin >> height;

    if (height > st.top().second) {  // height가 st.top보다 클 경우
      while (!st.empty() && st.top().second < height) {
        st.pop();
      }

      if (st.empty()) {  // stack에 height보다 큰 값이 없으면
        ans[i] = 0;
      }

      else {  // stack에 height보다 큰 값이 있으면
        ans[i] = st.top().first;
        if (st.top().second == height) {
          st.pop();
        }
      }
    }

    else {  // height가 st.top보다 작거나 같으면
      ans[i] = st.top().first;
    }
    st.push(make_pair(i + 1, height));
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] << ' ';
  }

  return 0;
}