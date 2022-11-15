#pragma once

namespace btl {
	template <typename t_Type, int t_Size = 1>
	struct array {

	public:
		t_Type value[t_Size ? t_Size : 1];

	public:
		int size();
		void fill(t_Type value);

		t_Type& operator[](int index);

		t_Type* begin();
		const t_Type* begin() const;
		t_Type* end();
		const t_Type* end() const;
	};


	template<typename t_Type, int t_Size>
	inline int array<t_Type, t_Size>::size()
	{
		return t_Size;
	}


	template<typename t_Type, int t_Size>
	inline void array<t_Type, t_Size>::fill(t_Type value)
	{
		for (int i = 0;i < t_Size;i++)
			this->value[i] = value;
	}


	template<typename t_Type, int t_Size>
	inline t_Type& array<t_Type, t_Size>::operator[](int index)
	{
		return value[index];
	}



	template<typename t_Type, int t_Size>
	inline t_Type* array<t_Type, t_Size>::begin()
	{
		return &value[0];
	}

	template<typename t_Type, int t_Size>
	inline const t_Type* array<t_Type, t_Size>::begin() const
	{
		return &value[0];
	}

	template<typename t_Type, int t_Size>
	inline t_Type* array<t_Type, t_Size>::end()
	{
		return &value[t_Size];
	}

	template<typename t_Type, int t_Size>
	inline const t_Type* array<t_Type, t_Size>::end() const
	{
		return &value[t_Size];
	}

}
