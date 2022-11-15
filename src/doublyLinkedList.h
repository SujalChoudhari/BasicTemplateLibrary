#pragma once

namespace btl {
	namespace internals {
		/// <summary>
		/// Node used in Doubly Linked List
		/// </summary>
		/// <typeparam name="t_Type"></typeparam>
		template <typename t_Type>
		struct doublyLink {
		public:
			/// <summary>
			/// Value of the node
			/// </summary>
			t_Type value;

			/// <summary>
			/// Poinert to next node of the list
			/// </summary>
			doublyLink* next;

			/// <summary>
			/// Pointer to previous node if the list
			/// </summary>
			doublyLink* prev;

		public:
			doublyLink() = delete;

			/// <summary>
			/// Create a node of doubly linked list
			/// </summary>
			/// <param name="value">- data to be stored</param>
			doublyLink(t_Type value) : value(value), next(nullptr), prev(nullptr) {}
		};

	}

	using namespace internals;


	/// <summary>
	/// Doubly Link list has both head and tail, 
	/// it is possible to iterate through the list
	/// in reverse order
	/// </summary>
	/// <typeparam name="t_Type">type of data</typeparam>
	template <typename t_Type>
	struct doublyLinkedList {

	public:
		/// <summary>
		/// Head of the list, iter using next value.
		/// </summary>
		doublyLink<t_Type>* head;

		/// <summary>
		/// Tail of the list, iterate using prev value.
		/// </summary>
		doublyLink<t_Type>* tail;

		/// <summary>
		/// No of elements of in the list
		/// </summary>
		int size;

	public:
		/// <summary>
		/// Create a new doubly linked list. Head and Tail are to be created rightaway
		/// </summary>
		/// <param name="head">- Value of the element at head position</param>
		/// <param name="tail">- Value of the element at tail position</param>
		doublyLinkedList(t_Type head, t_Type tail) : size(0) {
			this->head = new doublyLink<t_Type>(head);
			this->tail = new doublyLink<t_Type>(tail);

			this->head->next = this->tail;
			this->tail->prev = this->head;

			size = 2;
		}

		~doublyLinkedList() {
			clear();
		}

		/// <summary>
		/// Add a new node inside a list
		/// </summary>
		/// <param name="index">- Position at which to add an new node</param>
		/// <param name="item">- Value of the new Node</param>
		void add(int index, t_Type item);

		/// <summary>
		/// Add a Node at the end of the list. This will be the new tail node.
		/// </summary>
		/// <param name="item">- Value of node</param>
		void pushBack(t_Type item);

		/// <summary>
		/// Add a Node at the beginning of the list. This will be the new head node.
		/// </summary>
		/// <param name="item">- Value of the node</param>
		void pushFront(t_Type item);

		/// <summary>
		/// Get the value of a node with its index from beginning.
		/// </summary>
		/// <param name="index"> - Index of the Node</param>
		/// <returns>Pointer to the value</returns>
		t_Type* get(int index);

		/// <summary>
		/// Clears the list
		/// </summary>
		void clear();
	};

	template<typename t_Type>
	inline void doublyLinkedList<t_Type>::add(int index, t_Type item)
	{
		doublyLink<t_Type>* result = head;
		for (int i = 0;i < index - 1;i++) {
			if (result) result = result->next;
		}

		doublyLink<t_Type>* temp = result->next;
		result->next = new doublyLink<t_Type>(item);
		result->next->prev = result;
		result->next->next = temp;
		size++;
	}

	template<typename t_Type>
	inline void doublyLinkedList<t_Type>::pushBack(t_Type item)
	{
		doublyLink<t_Type>* newItem = new doublyLink<t_Type>(item);
		newItem->prev = tail;
		tail->next = newItem;
		tail = newItem;
		size++;
	}

	template<typename t_Type>
	inline void doublyLinkedList<t_Type>::pushFront(t_Type item)
	{
		doublyLink<t_Type>* newItem = new doublyLink<t_Type>(item);
		newItem->next = head;
		head->prev = newItem;
		head = newItem;
		size++;
	}

	template<typename t_Type>
	inline t_Type* doublyLinkedList<t_Type>::get(int index)
	{
		doublyLink<t_Type>* result = head;
		for (int i = 0;i < index;i++) {
			if (result) result = result->next;
		}

		return &result->value;
	}


	template<typename t_Type>
	inline void doublyLinkedList<t_Type>::clear()
	{
		doublyLink<t_Type>* current = head;
		doublyLink<t_Type>* temp_ptr = current;
		size = 0;
		while (1) {
			current = temp_ptr;
			if (temp_ptr) {
				temp_ptr = current->next;
				free(current);
			}
			else {
				return;
			}
		}
	}

}