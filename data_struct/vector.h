#pragma once

#include "deque.h"

namespace mylib {
template<typename _T, int _SIZE = 10>
class Vector {
public:
  Vector() {}
  Vector(const Vector& other) {}
  Vector(Vector&& other) noexcept {}
  ~Vector() {}

  void push_back(const _T& value) {
    deque_.push_back(value);
  }

  void push_front(const _T& value) {
    deque_.push_front(value);
  }

  _T& pop_back() {
    return deque_.pop_back();
  }

  _T& pop_front() {
    return deque_.pop_front();
  }

  int maxsize() const { return deque_.maxsize(); }

  bool isfull() const {
    return deque_.isfull();
  }

  bool empty() const {
    return deque_.empty();
  }

  _T& front() {
    return deque_.front();
  }

  _T& back() {
    return deque_.back();
  }
private:
  Deque<_T, _SIZE> deque_;
};

}