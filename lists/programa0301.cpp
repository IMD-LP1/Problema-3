#include <iostream>

int main(int argc, char *argv[])
{
	int* pointer{new int {42}};
	std::cout << *pointer << std::endl;

	*pointer = 10;
	std::cout << *pointer << std::endl;

	delete pointer;
	//pointer = nullptr;

	std::cout << *pointer << std::endl;

	long* good{new long{}};
	std::cout << *good << std::endl;
	delete good;

	//delete good

	good = nullptr;

	//delete good;

	long* bad{new long};
	std::cout << *bad << std::endl;
	delete bad;
	bad = nullptr;

	return EXIT_SUCCESS;
}
