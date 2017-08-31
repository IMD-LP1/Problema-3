/** @file list1301.cpp	*/
/** @@question 8		*/
#include <cstdio>
#include <fstream>
#include <iostream>


/**
 *	@brief	Funçao principal
*/
int main () {
	std::fstream in ("list1301.in") ;
	if (not in) {
		std::perror("list1301.in") ;
	}
	else 
	{
		int x(0);
		while(in >> x)
		std::cout << x << '\n';
	}
}

