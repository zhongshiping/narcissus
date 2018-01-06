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

#define PRINT(SIZE, T) for(size_t i = 0; i < SIZE; ++i) { std::cout<< T[i] << " ";} std::cout << std::endl;

int main()
{
	//list
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
	for (int i = 0; i < list.count(); ++i)
	{
		std::cout << list.at(i) << std::endl;
	}
	std::cout << list.indexOf('c', 4) << list.value(4) << std::endl;
	mylib::List<char> llist;
	llist = list;
	for (int i = 0; i < llist.count(); ++i)
	{
		std::cout << llist.at(i) << std::endl;
	}
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
	std::cout << std::endl << aarry[0] << aarry.front() << aarry.back();

	//deque
	mylib::Queue<int> queue;
	queue.push_back(1);
	queue.push_back(2);
	queue.push_back(3);
	queue.push_back(4);
	queue.push_back(5);
	queue.push_back(6);
  int a = queue.front();
  int b = queue.back();
	queue.pop_back();
	queue.pop_back();
	queue.pop_back();
	queue.pop_back();
  a = queue.front();
  b = queue.back();

	mylib::Pair<int, std::string> p(1, "4");
	mylib::Pair<int, std::string> p1(p);
	int d = p1.first_;
	std::string c = p1.second_;
	mylib::Pair<int, std::string> p2(3, "6");
	p2.swap(p);

	std::map<int, double> mk;
	mk[3] = 3.3;
  mk[1] = 22;

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
	//mmap.clear();
  mylib::List<int> ll = mmap.keys();
	return 0;
}
