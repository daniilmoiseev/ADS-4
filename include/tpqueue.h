// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
private:
  T *arr;
  int size;
  int begin, end;
  int count;

public:
  TPQueue() :
    size(100),
    begin(0), end(0), count(0) {
    arr = new T[size + 1];
  }
  ~TPQueue() {
    delete[] arr;
  }

  void push(const T &item) {
    assert(count < size);

    T *mas = new T[count];
    bool tr = false;
    if (end != 0) {
      for (int i = 0; i < count; i++) {
        if (item.prior > arr[end - 1].prior) {
          mas[i] = arr[--end];
          tr = true;
        }
      }
      arr[end++] = item;
    } else {
      arr[end++] = item;
    }
    if (tr) {
      for (int i = count - 1; i >= 0; i--)
        arr[end++] = mas[i];
    }
    count++;

    if (end > size)
      end -= size + 1;
  }
  T pop() {
    assert(count > 0);

    T item = arr[begin++];
    count--;

    if (begin > size)
      begin -= size + 1;

    return item;
  }
  T get() const {
    assert(count > 0);
    return arr[begin];
  }
  bool isEmpty() const {
    return count == 0;
  }
  bool isFull() const {
    return count == size;
  }
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
