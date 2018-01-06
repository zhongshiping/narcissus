#pragma once

namespace mylib {

template<typename _T, int SIZE>
class Stack {
  Stack(const Stack& other) {};
  Stack(Stack&& other) noexcept {};
  ~Stack() {};

  void push_back(const _T& v) {
    if (top_ < SIZE)
      stack_[top_++] = v;
  }

  void pop_back() {
    if (top_ >= 0)
      --top_;
  }

  _T& top() {
    if (top_ >= 0)
      return stack_[top_];
    _T* t = new _T(-1);
    return t;
  }

private:
  _T * stack_ = new _T[SIZE];
  int top_ = 0;
};

}