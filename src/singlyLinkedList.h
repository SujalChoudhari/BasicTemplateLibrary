#pragma once

namespace btl {

	template <typename t_Type>
	struct singlyLink {
	public:

		t_Type m_Value;
		singlyLink* next;

	public:
		singlyLink() = delete;
		singlyLink(t_Type m_Value) : m_Value(m_Value), next(nullptr) {}

	};

	template <typename t_Type>
	struct singlyLinkedList {

	public:
		singlyLink<t_Type>* head;
		int size;

	public:
		singlyLinkedList() :head(nullptr), size(0) {}
		~singlyLinkedList() { clear(); }

		void add(t_Type item);
		void add(int index, t_Type item);
		t_Type* get(int index);
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

		return &result->m_Value;
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

