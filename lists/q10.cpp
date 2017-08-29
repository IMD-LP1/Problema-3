#include <iostream>
using std::cout ;
using std::cin ;
using std::endl ;
#include <cstdio>
#include <fstream>



int main (int argc, char *argv[]) {
	
	int quantidade ;
	std::string  output ; 
	if (argc < 2) {
		cout << "Informe o arquivo de entrada" << endl ;
		return EXIT_FAILURE ;
	}
	else if(argc == 2) { 
		output = "output.txt" ;
		
	}

	else {
		output = argv[2] ;
		
	}	

	std::fstream in (argv[1]) ;
	if (not in) {
		std::perror("input") ;

	}

	std::string line ;
	std::fstream out(output) ;
	if (not out) {
		std::perror("output") ;
	}
	else {
		while (!in.eof()) {
		getline(in, line , ':') ;
		quantidade << in ;
		cout << quantidade ; 
		}
		
	}
	out.close() ;
	in.close() ;
		

}