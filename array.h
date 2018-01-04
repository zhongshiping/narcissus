#pragma once

namespace mylib
{
	template<typename  _T, int size>
	class Array
	{
	public:
		explicit  Array() {};
		explicit  Array(const Array& other) {};
		~Array() {};

		template<typename _T1>
		static void _fill(_T1 t1, _T1 t2, _T value)
		{
			for (; t1 != t2; ++t1)
			{
				*t1 = value;
			}
		}

		void fill(const _T& value)
		{
			_fill(array_, array_ + size_, value);
		}

		template<typename _T1, typename _T2, typename _T3>
		void _swap(_T1 t1, _T2 t2, _T3 t3)
		{
			for (; t1 != t2; ++t1, ++t3)
			{
				_T t = *t1;
				*t1 = *t3;
				*t3 = t;
			}
		}

		void swap(Array& other) noexcept
		{
			if (size_ <= other.size_)
				static_assert(true);
			_swap(array_, array_ + size_, other.array_);

		}

		const _T& at(const size_t index)
		{
			if (index < 0 || index >= size_)
				static_assert(true);
			return array_[index];
		}

		_T& operator[](const size_t index)
		{
			if (index < 0 || index >= size_)
				static_assert(true);
			return array_[index];
		}

		constexpr const _T& front()
		{
			return array_[0];
		}

		constexpr const _T& back()
		{
			return array_[size_ - 1];
		}

		constexpr size_t length() const
		{
			return size_;
		}

	private:
		_T * array_ = new _T[size];
		size_t size_ = size;
	};

}
