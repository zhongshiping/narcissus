#pragma once

namespace mylib
{
	template<typename _T, int _S = 10>
	class Deque
	{
	public:
		explicit Deque() {};
		explicit Deque(const _T& other) { };

		void push_back(const _T& v)
		{
			if (size_ >= max_size_)
			{
				_T* temp = new _T[size_ * 2];
				_T* tt = deque_ + size_;
				for (; deque_ != tt; ++deque_)
					*temp++ = *deque_;
				deque_ = temp;
				max_size_ = size_ * 2;
			}
			deque_[size_++] = v;
		}

		void pop_back()
		{
			_T* temp = ++deque_;
			deque_ = temp;
			--size_;
		}

		size_t size() const
		{
			return size_;
		}

		_T& operator[](const size_t pos)
		{
			if (pos<0 || pos>max_size_)
				static_assert(true);
			return deque_[pos];
		}
	private:
		_T * deque_ = new _T[_S];
		size_t size_ = 0;
		size_t max_size_ = _S;
	};
}
