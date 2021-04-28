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

    if (end != 0) {
      for (int i = end - 1; i >= 0; i--) {
        if (item.prior > arr[i].prior) {
          arr[i + 1] = arr[i];
        } else {
          arr[i + 1] = item;
          break;
        }
        if (i == 0) {
          arr[0] = item;
        }
      }
    } else {
      arr[end] = item;
    }
    end++;
    count++;
  }
  T pop() {
    assert(count > 0);

    T item = arr[begin++];
    count--;

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
