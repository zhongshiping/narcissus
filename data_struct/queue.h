#pragma once

namespace mylib {
template<typename _T, int _S = 10>
class Queue {
public:
  explicit Queue() {}
  explicit Queue(const _T& other) {}
  ~Queue() {
    delete queue_;
    queue_ = nullptr;
  }

  void push_back(const _T& v) {
    if (tail_ < max_size_)
      queue_[tail_++] = v;
    else
      tail_ = 0;
  }

  void pop_back() {
    if (header_ < max_size_)
      ++header_;
    else
      header_ = 0;
  }

  _T& front() {
    if (header_ != tail_)
      return queue_[header_];
    _T* t = new _T(-1);
    return *t;
  }

  _T& back() {
    if (header_ != tail_)
      return queue_[tail_ - 1];
    _T* t = new _T(-1);
    return *t;
  }

  size_t size() const { return tail_ - header_; }

private:
  _T * queue_ = new _T[_S];
  int header_ = 0, tail_ = 0;
  size_t max_size_ = _S;
};
}
