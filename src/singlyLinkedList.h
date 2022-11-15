#pragma once

namespace btl {
	namespace internals {
		/// <summary>
		/// Singly Link is used by singly linked list as a node.
		/// </summary>
		/// <typeparam name="t_Type"> Type of data to store</typeparam>
		template <typename t_Type>
		struct singlyLink {
		public:
			/// <summary>
			/// Value of the current link
			/// </summary>
			t_Type value;

			/// <summary>
			/// Pointer to the next link, nullptr if none
			/// </summary>
			singlyLink* next;

		public:
			singlyLink() = delete;

			/// <summary>
			/// Create a new link
			/// </summary>
			/// <param name="value"> - value of the current node</param>
			singlyLink(t_Type value) : value(value), next(nullptr) {}

		};

	}

	using namespace internals;


	/// <summary>
	/// SinglyLinkedList
	/// 
	/// 
	/// A linear data structure used to store data on the heap
	/// It is completely resizable, but a lot slower than a  btl::array
	/// </summary>
	/// <typeparam name="t_Type"> Type of data to store</typeparam>
	template <typename t_Type>
	struct singlyLinkedList {

	public:
		/// <summary>
		/// The start of linked list
		/// </summary>
		singlyLink<t_Type>* head;

		/// <summary>
		/// The number of element in the link
		/// </summary>
		int size;

	public:
		singlyLinkedList() :head(nullptr), size(0) {}
		~singlyLinkedList() { clear(); }

		/// <summary>
		/// Add an element at the end of the link
		/// </summary>
		/// <param name="item">- Value of the data</param>
		void add(t_Type item);

		/// <summary>
		/// Add an element at the given position.
		/// The link is appended, no data is deleted.
		/// </summary>
		/// <param name="index">- Index of the location to append</param>
		/// <param name="item"> - Value of the data</param>
		void add(int index, t_Type item);

		/// <summary>
		/// Get an enement from the List
		/// </summary>
		/// <param name="index">- Index of position to read from</param>
		/// <returns>-pointer to the data</returns>
		t_Type* get(int index);

		/// <summary>
		/// Clear the list manually
		/// </summary>
		void clear();

	};


	template<typename t_Type>
	inline void singlyLinkedList<t_Type>::add(t_Type item)
	{
		if (!head) {
			head = new singlyLink<t_Type>(item);
			size++;
		}
		else {
			auto current = head;
			while (1) {
				if (current->next) {
					current = current->next;
				}
				else {
					current->next = new singlyLink<t_Type>(item);
					size++;
					return;
				}
			}
		}

	}

	template<typename t_Type>
	inline void singlyLinkedList<t_Type>::add(int index, t_Type item)
	{
		singlyLink<t_Type>* result = head;
		for (int i = 1;i < index;i++) {
			if (result) result = result->next;
		}

		singlyLink<t_Type>* temp = result->next;
		result->next = new singlyLink<t_Type>(item);

		result->next->next = temp;
		size++;

	}

	template<typename t_Type>
	inline t_Type* singlyLinkedList<t_Type>::get(int index)
	{
		singlyLink<t_Type>* result = head;
		for (int i = 0;i < index;i++) {
			if (result) result = result->next;
		}

		return &result->value;
	}



	template<typename t_Type>
	inline void singlyLinkedList<t_Type>::clear(void)
	{
		singlyLink<t_Type>* current = head;
		singlyLink<t_Type>* temp_ptr = current;
		size = 0;
		while (1) {
			current = temp_ptr;
			if (temp_ptr) {
				temp_ptr = current->next;
				//delete current;

				free(current);
			}
			else {
				return;
			}
		}
	}

}

