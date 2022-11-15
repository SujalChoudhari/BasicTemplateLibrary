#pragma once

namespace btl {

	template <typename t_Type>
	struct doublyLink {
	public:
		t_Type value;

		doublyLink* next;
		doublyLink* prev;

	public:
		doublyLink() = delete;
		doublyLink(t_Type value) : value(value), next(nullptr), prev(nullptr) {}
	};




	template <typename t_Type>
	struct doublyLinkedList {

	public:

		doublyLink<t_Type>* head;
		doublyLink<t_Type>* tail;
		int size;

	public:
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

		void add(int index, t_Type item);
		void pushBack(t_Type item);
		void pushFront(t_Type item);
		t_Type* get(int index);
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