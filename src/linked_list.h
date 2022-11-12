#pragma once

namespace btl {
	template <typename _type>
	struct singly_link {
	public:
		_type value;
		singly_link* next;

	public:
		singly_link() = delete;
		singly_link(_type value) : value(value) ,next(nullptr) {}

		singly_link* get_next() { if (next) { return next; } return nullptr; }
	};


	template <typename _type>
	struct singly_linked_list {
		
	public:
		singly_link<_type>* head;
		int size;

	public:
		singly_linked_list():head(nullptr), size(0) {}
		~singly_linked_list() { clear(); }
		void add(_type item);
		void clear(void);
		
	};

	
	
	template<typename _type>
	inline void singly_linked_list<_type>::add(_type item)
	{
		if (!head) {
			head = new singly_link<_type>(item);
			size++;
		}
		else {
			auto current = head;
			while (1) {
				if (current->next) {
					current = current->next;
				}
				else {
					current->next = new singly_link<_type>(item);
					size++;
					return;
				}
			}
		}
		
	}

	template<typename _type>
	inline void singly_linked_list<_type>::clear(void)
	{
		singly_link<_type>* current = head;
		singly_link<_type>* temp_ptr = current;
		size = 0;
		while (1) {
			current = temp_ptr;
			if (temp_ptr) {
				temp_ptr = current->get_next();
				//delete current;
				
				free(current);
			}
			else {
				return;
			}
		}
	}

}

