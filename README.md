# Basic Template Library (BTL)

## Introduction
Welcome to the Basic Template Library (BLT), a powerful C++ library designed to enhance your development experience by providing efficient and optimized implementations of fundamental data structures. Whether you're a seasoned developer or just starting your coding journey, BLT aims to simplify your projects with its easy-to-use components.

## Features
BLT currently includes the following features:
- **Array:** A flexible and optimized array implementation.
- **Singly Linked List:** A memory-efficient singly linked list.
- **Flag:** A space-efficient flag management system.
- **Doubly Linked List:** A versatile doubly linked list.

## Getting Started
To get started with BLT, simply include the relevant header files in your project:
```cpp
#include "btl.h"
```

## Optimized Code
BLT is crafted with performance in mind. The code is optimized to ensure efficiency without compromising functionality. The library provides a seamless experience for developers who demand both speed and reliability in their applications.

## Usage

### Array
```cpp
btl::array<int, 5> myArray;
myArray.fill(42);
```

### Singly Linked List
```cpp
btl::singlyLinkedList<int> myList;
myList.push_front(10);
myList.push_back(20);
```

### Flag
```cpp
btl::flag myFlag(~0);
myFlag.clearFlag(1);
bool isSet = myFlag.getFlag(1);
```

### Doubly Linked List
```cpp
btl::doublyLinkedList<int> myDoublyList;
myDoublyList.push_back(30);
myDoublyList.push_front(40);
```

## Contribution
We welcome contributions from the community to make BLT even better. If you have ideas for improvements, bug fixes, or additional features, feel free to open an issue or submit a pull request. 

## License
BLT is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For any questions, feedback, or collaboration opportunities, reach out to the project maintainer:

**Sujal**
- GitHub: [Sujal](https://github.com/SujalChoudhari)
- Email: [btl@sujal.xyz](mailto:btl@sujal.xyz)

Let's build something amazing together with BLT! 
Happy coding!