#pragma once

namespace btl {

	/// <summary>
	/// btl::array uses basic cpp array to store. 
	/// It provides size.
	/// </summary>
	/// 
	/// <typeparam name="t_Type"> 
	///		The type of the data to store 
	/// </typeparam>
	template <typename t_Type, int t_Size = 1>
	struct array {

	public:

		t_Type value[t_Size ? t_Size : 1];

	public:

		/// <summary>
		/// Get the size of the array
		/// </summary>
		/// <returns> - Size as an Integer</returns>
		int size();

		/// <summary>
		/// Fill all the elements of the array
		/// </summary>
		/// <param name="value"> - Value to fill with</param>
		void fill(t_Type value);
		t_Type& operator[](int index);

		/// <summary>
		/// Get the pointer to the beginning of the array
		/// </summary>
		/// <returns> - pointer of the first element</returns>
		t_Type* begin();

		/// <summary>
		/// Get the pointer to the beginning of the array
		/// </summary>
		/// <returns> - pointer of the first element</returns>
		const t_Type* begin() const;

		/// <summary>
		/// Get the pointer to the end of the array
		/// </summary>
		/// <returns> - pointer of the last element</returns>
		t_Type* end();

		/// <summary>
		/// Get the pointer to the end of the array
		/// </summary>
		/// <returns> - pointer of the last element</returns>
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
