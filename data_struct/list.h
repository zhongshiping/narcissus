#pragma once

namespace mylib {
template<typename T>
struct  DoubleLinkedList {
  T value;
  DoubleLinkedList* next_node;
  DoubleLinkedList* previous_node;
};

template<typename T>
class List {
public:
  explicit List<T>() {};

  explicit List<T>(const List<T>& other) {
    list_struct_ = other.list_struct_;
    count_ = other.count_;
  };
  List<T>(List<T>&& other) noexcept {
    list_struct_ = other.list_struct_;
    count_ = other.count_;
  }
  ~List() {};

  void append(const T& value) {
    DoubleLinkedList<T>* list_struct = new DoubleLinkedList<T>;
    list_struct->value = value;
    list_struct->next_node = nullptr;

    if (list_struct_ == nullptr) {
      list_struct_ = list_struct;
      list_struct_->previous_node = nullptr;
    }
    else {
      DoubleLinkedList<T>* temp = list_struct_;
      while (temp->next_node != nullptr) {
        temp = temp->next_node;
      }
      temp->next_node = list_struct;
      temp->next_node->previous_node = temp;
    }
    ++count_;
  }

  const T& at(int i) const {
    DoubleLinkedList<T>* list_struct = list_struct_;
    while (i--) {
      list_struct = list_struct->next_node;
    }
    return list_struct->value;
  }

  T& back() {
    static_assert(empty());
    DoubleLinkedList<T>* list_struct = list_struct_;
    while (list_struct->next_node != nullptr) {
      list_struct = list_struct->next_node;
    }
    return list_struct->value;

  }

  void clear() {
    DoubleLinkedList<T>* list = nullptr;
    while (list_struct_) {
      list = list_struct_->next_node;
      delete list_struct_;
      list_struct_ = nullptr;
      if (list && list->previous_node)
        list->previous_node = nullptr;
      list_struct_ = list;
    }
  }

  int count() const { return count_; }

  bool empty() const { return count_ <= 0; }

  T& first() {
    if (empty())
      static_assert(true);
    return list_struct_->value;
  }

  void insert(int i, const T& value) {
    if (empty() || i > count()) {
      append(value);
    }
    else {
      DoubleLinkedList<T>* temp = list_struct_;
      while (--i) {
        temp = temp->next_node;
      }
      DoubleLinkedList<T>* node = new DoubleLinkedList<T>;
      node->value = value;
      node->next_node = temp->next_node;
      node->previous_node = temp->previous_node;
      temp->next_node = node;
    }
    ++count_;
  }

  int indexOf(const T& value, int from = 0) const {
    int index = -1, idx = -1;
    DoubleLinkedList<T>* temp = list_struct_;
    if (from == 0) {
      while (temp != nullptr) {
        ++index;
        if (temp->value == value) {
          idx = index;
        }
        temp = temp->next_node;
      }
    }
    else {
      while (temp != nullptr && from--) {
        ++index;
        if (temp->value == value) {
          idx = index;
        }
        temp = temp->next_node;
      }
    }
    return idx;
  }

  T value(int i) const {
    if (empty()) return -1;
    DoubleLinkedList<T>* temp = list_struct_;
    while (i--) {
      temp = temp->next_node;
    }
    return temp->value;
  }

  void removeAt(int i) {
    if (empty()) return;
    if (i > count()) return;
    DoubleLinkedList<T>* temp = list_struct_;
    while (--i) {
      temp = temp->next_node;
    }
    temp->next_node = temp->next_node->next_node;
    --count_;
  }

  int removeAll(const T& value) {
    int count = 0;
    if (empty()) return count;
    DoubleLinkedList<T>* temp = list_struct_;
    while (temp != nullptr) {
      if (temp->value == value) {
        temp->previous_node->next_node = temp->next_node;
        ++count;
        --count_;
      }
      temp = temp->next_node;
    }
    return count;
  }

  List<T>& operator=(const List<T>& other) {
    list_struct_ = other.list_struct_;
    count_ = other.count_;
    return	*this;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    other;
  }

private:
  DoubleLinkedList<T>* list_struct_ = {nullptr};
  int count_ = {0};
};

}
