#pragma once

namespace mylib {

template<typename _T, int _SIZE = 10>
class Deque {
public:
  Deque() : deque_(new _T[_SIZE]) {}
  ~Deque() {}

  void push_back(const _T& value) {
    if (isfull()) {
      ///
      std::cout << "queue is full!" << std::endl;
    }
    else {
      deque_[tail_%maxsize()] = value;
      ++tail_;
      ++size_;
    }
  }

  void push_front(const _T& value) {
    if (isfull()) {
      ///    
      std::out_of_range("deque is full!");
    }
    else if (header_ == 0) {
      header_ = maxsize();
      deque_[--header_] = value;
      ++size_;
    }
    else if (header_ > 0) {
      deque_[--header_] = value;
      ++size_;
    }
  }

  _T& pop_back() {
    if (empty()) {
      return *(new _T(-1));
    }
    if (tail_ > header_) {
      _T v = deque_[--tail_];
      --size_;
      return v;
    }
    if (tail_ == header_ && size_ > 0) {
      tail_ = maxsize() - 1;
      --size_;
      return deque_[tail_];
    }
    _T v = deque_[--tail_];
    if (tail_ == 0) {
      tail_ = maxsize();
    }
    --size_;
    return v;
  }

  _T& pop_front() {
    if (empty()) {
      return *(new _T(-1));
    }
    header_ = header_ % maxsize();
    _T v = deque_[header_];
    ++header_;
    --size_;
    return v;
  }

  int maxsize() const { return max_size_; }

  bool isfull() const {
    if (tail_ >= header_)
      return tail_ - header_ == maxsize();
    return header_ + tail_ == maxsize();
  }

  bool empty() const {
    return size_ > 0 ? false : true;
  }

  _T& front() {
    if (!empty())
      return deque_[header_];
    return *(new _T(-1));
  }
  _T& back() {
    if (!empty())
      return deque_[tail_ - 1];
    return *(new _T(-1));
  }
private:
  _T * deque_;
  int header_ = 0;
  int tail_ = 0;
  int max_size_ = _SIZE;
  int size_ = 0;
};
}