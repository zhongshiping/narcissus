#pragma once

namespace mylib {

template<typename _T, int _SIZE = 10>
class Stack {
public:
  Stack() {}
  Stack(const Stack& other) {};
  Stack(Stack&& other) noexcept {};
  ~Stack() {};

  void push_back(const _T& v) {
    if (top_ < _SIZE)
      stack_[top_++] = v;
    else if (top_ == _SIZE) {
      expend();
      stack_[top_++] = v;
    }
  }

  _T& pop_back() {
    if (top_ >= 0)
      return stack_[--top_];
    return *(new _T(-1));
  }

  _T& top() {
    if (top_ >= 0)
      return stack_[top_];
    _T* t = new _T(-1);
    return t;
  }

  bool empty() const {
    return top_;
  }
private:
  void expend(const int alloc = _SIZE) {
    _T* temp = stack_;
    stack_ = new _T[size_ += alloc];
    for (int i = 0; i < top_; ++i) {
      stack_[i] = temp[i];
    }
    delete[] temp;
  }
  _T * stack_ = new _T[_SIZE];
  int top_ = 0;
  int size_ = _SIZE;
};

}