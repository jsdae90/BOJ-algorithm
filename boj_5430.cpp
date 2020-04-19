#include <iostream>

#define endl "\n"
#define MAX 100001
using namespace std;

int N, Start_Idx, End_Idx, Cur_Idx;
int Arr[MAX];
bool Order;
char P_Arr[MAX];
char Inp_Arr[MAX * 3 + 99999 + 2];

template <typename T>
int My_Strlen(T *A) {
  int i = 0;
  while (A[i] != 0) i++;

  return i;
}

void Initialize() {
  for (int i = 0; i < MAX; i++) {
    P_Arr[i] = '\0';
    Arr[i] = 0;
  }
  for (int i = 0; i < MAX + 99999 + 2; i++) {
    Inp_Arr[i] = '\0';
  }
  Start_Idx = 0;
  Cur_Idx = 0;
  Order = true;
}

void Input() {
  cin >> P_Arr;
  cin >> N;
  cin >> Inp_Arr;
  int Len = My_Strlen(Inp_Arr);
  int Idx = 0;
  for (int i = 0; i < Len; i++) {
    if (Inp_Arr[i] != '[' && Inp_Arr[i] != ']' && Inp_Arr[i] != ',') {
      int j = i;
      int x = 0;
      while (Inp_Arr[j] != '[' && Inp_Arr[j] != ']' && Inp_Arr[j] != ',') {
        x = x + (Inp_Arr[j] - '0');
        x = x * 10;
        j++;
        i++;
      }
      x = x / 10;
      Arr[Idx++] = x;
    }
  }
  End_Idx = Idx - 1;
}

void Solution() {
  bool Flag = true;
  int Len = My_Strlen(P_Arr);
  int Size = My_Strlen(Arr);

  for (int i = 0; i < Len; i++) {
    if (P_Arr[i] == 'R') {
      if (Order == true) {
        Order = false;
        Cur_Idx = End_Idx;
      } else {
        Order = true;
        Cur_Idx = Start_Idx;
      }
    } else {
      if (Size == 0) {
        Flag = false;
        cout << "error" << endl;
      }

      if (Order == true) {
        Start_Idx++;
        Cur_Idx = Start_Idx;
        Size--;
      } else {
        End_Idx--;
        Cur_Idx = End_Idx;
        Size--;
      }
    }
  }
  if (Flag == true) {
    cout << "[";
    if (Order == true) {
      for (int i = Start_Idx; i <= End_Idx; i++) {
        if (i != End_Idx)
          cout << Arr[i] << ",";
        else
          cout << Arr[i];
      }
    } else {
      for (int i = End_Idx; i >= Start_Idx; i--) {
        if (i != Start_Idx)
          cout << Arr[i] << ",";
        else
          cout << Arr[i];
      }
    }
    cout << "]" << endl;
  }
}

void Solve() {
  int Tc;
  cin >> Tc;
  for (int T = 1; T <= Tc; T++) {
    Initialize();
    Input();
    Solution();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
  return 0;
}