#include "list.h"
#include <iostream>

int main()
{
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
	return 0;
}
