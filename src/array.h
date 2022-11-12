#pragma once

namespace btl {
	template <typename _type, int _size = 1>
	struct array {

	public:
		typedef _type* iterator;
		typedef const _type* constIterator;

		_type value[_size ? _size : 1];

	public:
		int size();
		void fill(_type value);
		_type& operator[](int index);

		_type* begin();
		const _type* begin() const;
		_type* end();
		const _type* end() const;
	};


	template<typename _type, int _size>
	inline int array<_type, _size>::size()
	{
		return _size;
	}


	template<typename _type, int _size>
	inline void array<_type, _size>::fill(_type value)
	{
		for (int i = 0;i < _size;i++)
			this->value[i] = value;
	}


	template<typename _type, int _size>
	inline _type& array<_type, _size>::operator[](int index)
	{
		return value[index];
	}



	template<typename _type, int _size>
	inline _type* array<_type, _size>::begin()
	{
		return &value[0];
	}

	template<typename _type, int _size>
	inline const _type* array<_type, _size>::begin() const
	{
		return &value[0];
	}

	template<typename _type, int _size>
	inline _type* array<_type, _size>::end()
	{
		return &value[_size];
	}

	template<typename _type, int _size>
	inline const _type* array<_type, _size>::end() const
	{
		return &value[_size];
	}

}
