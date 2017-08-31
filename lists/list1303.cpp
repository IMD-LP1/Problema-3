/** @file list1303.cpp	*/
/** @@question 9		*/
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
	else {
		std::string line ;
		std::fstream out ("list1301.out") ;
		if (not out) {
			std::perror("list1301.out") ;
		}

		else {

			while (!in.eof()) {
				getline(in, line) ;
				out << line << '\n' ;
				
			}
			
			
			out.close() ; 
		}
		in.close() ;
	}
}

