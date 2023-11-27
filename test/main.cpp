#include <iostream>
#include "../src/btl.h"

int main() {
	btl::flag mFlag = btl::flag(0);

	mFlag.clearAll();
	mFlag.setAll();
	mFlag.setFlag(2);
	mFlag.setFlag(3);
	mFlag.clearFlag(3);

	std::cout << mFlag.getFlag(0) << std::endl;
	std::cout << mFlag.getFlag(1) << std::endl;
	std::cout << mFlag.getFlag(2) << std::endl;
	std::cout << mFlag.getFlag(3) << std::endl;
	std:: cout << mFlag.getFlag(4) << std::endl;

}