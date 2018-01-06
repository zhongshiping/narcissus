#pragma once

namespace mylib {
template<typename _T1, typename _T2>
class Pair {
public:
  explicit Pair() {}
  Pair(const Pair& other) {
    first_ = other.first_;
    second_ = other.second_;
  }

  explicit Pair(Pair&& other) noexcept {
    first_ = other.first_;
    second_ = other.second_;
  }

  explicit Pair(const _T1 t1, const _T2 t2) {
    first_ = t1;
    second_ = t2;
  }

  void swap(Pair& other) noexcept {
    Pair<_T1, _T2> temp = *this;
    first_ = other.first_;
    second_ = other.second_;
    other.first_ = temp.first_;
    other.second_ = temp.second_;
  }

  Pair& operator=(const Pair& other) {
    first_ = other.first_;
    second_ = other.second_;
    return *this;
  }

  Pair& operator=(Pair&& other) noexcept {
    first_ = other.first_;
    second_ = other.second_;
    return *this;
  }

  _T1 first_;
  _T2 second_;
};

}
