#pragma once

namespace mylib {
template<typename _T, int _S = 10>
class Queue {
public:
  explicit Queue() {}
  explicit Queue(const _T& other) {
    queue_ = other;
  }
  ~Queue() {}

  void push_back(const _T& v) {
    if (isfull()) {
      ///
      if (isexpand()) {
        expand(_S);
        queue_[tail_%maxsize()] = v;
        ++tail_;
      }
      else
        std::out_of_range("queue is full!");

    }
    else {
      queue_[tail_%maxsize()] = v;
      ++tail_;
    }
  }

  _T& pop_front() {
    if (empty()) {
      return *(new _T(-1));
    }
    int t = header_ % maxsize();
    ++header_;
    return queue_[t];
  }

  _T& front() {
    if (!empty())
      return queue_[header_];
    return *(new _T(-1));
  }

  _T& back() {
    if (!empty())
      return queue_[tail_ - 1];
    return *(new _T(-1));
  }

  int size() const {
    return tail_ < header_ ? header_ + tail_ + 1 : tail_ - header_ + 1;
  }
  int maxsize() const { return max_size_; }

  void reserver(const int alloc) {
    queue_ = alloc <= max_size_ ? queue_ : expand(alloc);
  }

  bool isexpand() const { return can_expand_; }
  void set_expand(const bool can_expand) { can_expand_ = can_expand; };

  bool isfull() const {
    if (tail_ >= header_)
      return tail_ - header_ == maxsize();
    return header_ + tail_ == maxsize();
  }

  bool empty() const {
    return tail_ == header_;
  }
private:
  void expand(const int alloc = _S) {
    _T* temp = queue_;
    queue_ = new _T[max_size_ += alloc];
    if (tail_ < header_) {
      int i;
      static int j = 0;
      for (i = header_; i < maxsize() - alloc; ++i, ++j) {
        queue_[j] = temp[i];
      }
      for (; i < tail_; ++i, ++j) {
        queue_[i] = temp[j];
      }
    }
    else {
      int j = 0;
      for (int i = header_; i < maxsize() - alloc; ++i, ++j) {
        queue_[j] = temp[i];
      }
    }
    delete temp;
    temp = nullptr;
    tail_ = max_size_ - alloc;
    header_ = 0;
  }

  _T * queue_ = new _T[_S];
  int header_ = 0, tail_ = 0;
  int max_size_ = _S;
  bool can_expand_ = false;
};
}
