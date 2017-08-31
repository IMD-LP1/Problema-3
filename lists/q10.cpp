#include <iostream>
using std::cout ;
using std::cin ;
using std::endl ;
#include <cstdio>
#include <fstream>



int main (int argc, char *argv[]) {
	
	int quantidade, i;
	std::string output, palavra, ponto; 
	
	if (argc < 2) {
		cout << "Informe o arquivo de entrada" << endl;
		return EXIT_FAILURE;
	}
	else if(argc == 2) { 
		output = "output.txt";	
	} else {
		output = argv[2];
	}	

	std::ifstream in(argv[1]);
	
	if (not in) {
		std::perror("Falha na abertura do arquivo!");
		exit(1);
	}

	std::string line ;
	std::ofstream out(output);
	
	if (not out) {
		std::perror("Falha na criação do arquivo");
		exit(1);
	}
	
	while (!in.eof()) {
		in >> palavra;
		in >> ponto;
		in >> quantidade;
		for (i = 0 ;i < quantidade; i++) {
			out << palavra << " ";				
		}
	}
		
	out.close();
	in.close();
		
}
