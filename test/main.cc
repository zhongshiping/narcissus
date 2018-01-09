#include "list.h"
#include "array.h"
#include <iostream>
#include "deque.h"
#include "pair.h"
#include "map.h"
#include <map>
#include "queue.h"
#include <queue>
#include <stack>
#include "stack.h"
#include "vector.h"

#define PRINT(SIZE, T) for(size_t i = 0; i < SIZE; ++i) { std::cout<< T[i] << " ";} std::cout << std::endl;

int main() {
  ////list
  mylib::List<char> list;
  list.append('a');
  list.append('b');
  list.append('c');
  list.append('d');
  list.append('e');
  list.append('f');
  list.append('g');
  list.append('h');
  list.append('c');
  list.insert(2, 'k');
  list.removeAt(2);
  list.removeAll('c');
  for (int i = 0; i < list.count(); ++i) {
    std::cout << list.at(i) << std::endl;
  }
  std::cout << list.indexOf('c', 4) << list.value(4) << std::endl;
  mylib::List<char> llist;
  llist = list;
  for (int i = 0; i < llist.count(); ++i) {
    std::cout << llist.at(i) << std::endl;
  }
  llist.clear();
  //array
  mylib::Array<int, 6> arry;
  arry[0] = 1;
  arry[1] = 2;
  arry[2] = 3;
  arry[3] = 4;
  arry[4] = 5;
  arry[5] = 6;
  mylib::Array<int, 6> aarry;
  aarry.fill(9);
  arry.swap(aarry);
  PRINT(arry.length(), arry);
  PRINT(aarry.length(), aarry);
  std::cout << std::endl << aarry[0] << aarry.front() << aarry.back() << std::endl;
  //deque
  mylib::Queue<int> queue;
  queue.set_expand(true);
  queue.push_back(1);
  queue.push_back(2);
  queue.push_back(3);
  queue.push_back(4);
  queue.push_back(5);
  queue.push_back(6);
  queue.push_back(7);
  queue.push_back(8);
  queue.push_back(9);
  queue.push_back(10);
  queue.push_back(11);
  queue.push_back(12);
  queue.push_back(13);
  for (; !queue.empty();) {
    std::cout << queue.front() << " ";
    queue.pop_front();
  }
  std::cout << std::endl;

  mylib::Pair<int, std::string> p(1, "4");
  mylib::Pair<int, std::string> p1(p);
  int d = p1.first_;
  std::string c = p1.second_;
  mylib::Pair<int, std::string> p2(3, "6");
  p2.swap(p);

  mylib::Map<int, std::string> mmap;
  mmap.insert(1, "r");
  mmap.insert(2, "rr");
  mmap.insert(4, "rrr");
  mmap.insert(5, "rrr");
  mmap.insert(7, "rrr");
  mmap.insert(8, "rrr");
  mmap.insert(11, "rrr");
  mmap.insert(14, "rrr");
  mmap.insert(15, "rrr");

  std::string rr = mmap[5];
  mmap[3] = "this";
  mmap.remove(8);
  mmap.clear();
  mylib::List<int> ll = mmap.keys();
  mmap.clear();
  ll.clear();


  mylib::Deque<int> deque;
  //deque.push_front(1);
  //deque.push_front(2);
  //deque.push_front(3);
  //deque.push_front(4);
  //deque.push_front(5);
  //deque.push_front(6);
  //deque.push_front(7);
  //deque.push_front(8);
  //deque.push_front(9);
  //deque.push_front(0);
  deque.push_back(0);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  deque.push_back(6);
  deque.push_back(7);
  deque.push_back(8);
  deque.push_back(9);
  for (; !deque.empty();) {
    std::cout << deque.pop_back() << " ";
  }
  std::cout << std::endl;

  mylib::Stack<int> stack;
  stack.push_back(0);
  stack.push_back(1);
  stack.push_back(2);
  stack.push_back(3);
  stack.push_back(4);
  stack.push_back(5);
  stack.push_back(6);
  for (; stack.empty();) {
    std::cout << stack.pop_back() << " ";
  }
  std::cout << std::endl;


  mylib::Vector<int> vector_;
  vector_.push_back(1);
  vector_.push_back(2);
  vector_.push_back(3);
  vector_.push_back(4);
  vector_.push_back(5);
  vector_.push_back(6);
  vector_.push_back(7);
  vector_.push_back(8);

  //for (; !vector_.empty();) {
  //  std::cout << vector_.pop_back() << " ";
  //}
  std::cout << vector_.back() << " " << vector_.front() << std::endl;
  return 0;
}
