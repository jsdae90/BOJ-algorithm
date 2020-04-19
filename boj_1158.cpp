#include <memory.h>
#include <iostream>

using namespace std;

int N, K;

class Queue {
 private:
  int maxSize;
  int size = 0;
  int arr[5001];
  int front = -1;
  int rear = -1;

 public:
  Queue(int _size) {
    maxSize = _size;
    memset(arr, 0, sizeof(arr));
  }
  bool isEmpty() { return size == 0; }
  bool isFull() { return size == maxSize; }
  void enqueue(int _data) {
    if (!isFull()) {
      rear = (rear + 1) % maxSize;
      arr[rear] = _data;
      size++;
    }
  }
  int dequeue() {
    if (!isEmpty()) {
      front = (front + 1) % maxSize;
      size--;
      return arr[front];
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  Queue people = Queue(N);
  for (int i = 1; i < N + 1; i++) people.enqueue(i);
  cout << '<';
  while (!people.isEmpty()) {
    for (int i = 0; i < K - 1; i++) people.enqueue(people.dequeue());
    cout << people.dequeue();
    if (!people.isEmpty())
      cout << ", ";
    else
      cout << ">\n";
  }
  return 0;
}
