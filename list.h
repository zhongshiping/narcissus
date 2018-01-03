#pragma once

namespace mylib
{
	template<typename T>
	struct  ListStruct
	{
		T value;
		ListStruct* next_node;
		ListStruct* previous_node;
	};

	template<typename T>
	class List
	{
	public:
		explicit List<T>() {};
		explicit List<T>(const List<T>& other)
		{
			for (int i = 0; i < other.count(); ++i)
			{
				append(other.at(i));
			}
		};
		~List() {};

		void append(const T &value)
		{
			ListStruct<T>* list_struct = new ListStruct<T>;
			list_struct->value = value;
			list_struct->next_node = nullptr;

			if (list_struct_ == nullptr)
			{
				list_struct_ = list_struct;
			}
			else
			{
				ListStruct<T>* temp = list_struct_;
				while (temp->next_node != nullptr)
				{
					temp = temp->next_node;
				}
				temp->next_node = list_struct;
				temp->next_node->previous_node = temp;
			}
			++count_;
		};
		const T& at(int i) const
		{
			ListStruct<T>* list_struct = list_struct_;
			while (i--)
			{
				list_struct = list_struct->next_node;
			}
			return list_struct->value;
		};
		T& back()
		{
			static_assert(empty());
			ListStruct<T>* list_struct = list_struct_;
			while (list_struct->next_node != nullptr)
			{
				list_struct = list_struct->next_node;
			}
			return list_struct->value;

		};
		void clear()
		{
			delete list_struct_;
			list_struct_ = nullptr;
		};
		int count() const
		{
			return count_;
		};
		bool empty() const
		{
			return count_ <= 0;
		};
		T& first()
		{
			static_assert(empty());
			return list_struct_->value;
		};
		void insert(int i, const T& value)
		{
			if (empty() || i > count())
			{
				append(value);
			}
			else
			{
				ListStruct<T>* temp = list_struct_;
				while (--i)
				{
					temp = temp->next_node;
				}
				ListStruct<T>* node = new ListStruct<T>;
				node->value = value;
				node->next_node = temp->next_node;
				node->previous_node = temp->previous_node;
				temp->next_node = node;
			}
			++count_;
		};
		int indexOf(const T& value, int from = 0) const
		{
			int index = -1, idx = -1;
			ListStruct<T>* temp = list_struct_;
			if (from == 0)
			{
				while (temp != nullptr)
				{
					++index;
					if (temp->value == value)
					{
						idx = index;
					}
					temp = temp->next_node;
				}
			}
			else
			{
				while (temp != nullptr && from--)
				{
					++index;
					if (temp->value == value)
					{
						idx = index;
					}
					temp = temp->next_node;
				}
			}
			return idx;
		};
		T value(int i) const
		{
			if (empty()) return -1;
			ListStruct<T>* temp = list_struct_;
			while (i--)
			{
				temp = temp->next_node;
			}
			return temp->value;
		};
		void removeAt(int i)
		{
			if (empty()) return;
			if (i > count()) return;
			ListStruct<T>* temp = list_struct_;
			while (--i)
			{
				temp = temp->next_node;
			}
			temp->next_node = temp->next_node->next_node;
			--count_;
		};
		int removeAll(const T& value)
		{
			int count = 0;
			if (empty()) return count;
			ListStruct<T>* temp = list_struct_;
			while (temp != nullptr)
			{
				if (temp->value == value)
				{
					temp->previous_node->next_node = temp->next_node;
					++count;
					--count_;
				}
				temp = temp->next_node;
			}
			return count;
		};
		List<T>& operator=(const List<T>& other)
		{
			list_struct_ = other.list_struct_;
			count_ = other.count_;
			return	*this;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    other;
		};
	private:
		ListStruct<T> * list_struct_ = nullptr;
		size_t count_ = { 0 };
	};

}
