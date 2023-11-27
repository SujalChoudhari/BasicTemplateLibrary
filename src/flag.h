#pragma once
#include <stdlib.h>
namespace btl {

	class flag {
	private:
		char m_Memory;

	public:
		flag(char initialState);
		bool getFlag(int index) const;
		void clearAll();
		void setAll();
		void setFlag(int index);
		void clearFlag(int index);
	};

	inline btl::flag::flag(char init)
		:m_Memory(init)
	{}

	inline bool flag::getFlag(int index) const {
		// create a mask with a 1 at the desired index
		// bitwise AND to get the value at the desired position
		return (m_Memory & (1 << index)) != 0;
	}

	inline void flag::setFlag(int index) {
		m_Memory |= 1 << index;
	}

	inline void flag::clearFlag(int index) {
		m_Memory &= ~(1 << index);
	}

	inline void flag::clearAll() {
		// set all bits to 0
		m_Memory = 0;
	}

	inline void flag::setAll() {
		// set all bits to 1
		m_Memory = ~0;
	}
}