
#include <iostream>
using std::cout ;
using std::cin ;
using std::endl ;

#include <new>



struct Vector{
	int tam ;
	double *elementos ;
} ;

void vector_init(Vector& v, int tam) {
	v.tam =tam ;
	v.elementos = new(std::nothrow)double[tam] ;
	if (v.elementos != nullptr) {
		cout << "Alocaçao feita." << endl ;
	}
	else {
		cout << "Alocaçao nao foi feita." << endl ;
	}

}

void vector_free (Vector& v) {
	delete[] v.elementos ;
	v.elementos = nullptr ;
}

void vector_read (Vector& v) {
	for (int ii = 0 ; ii < v.tam ; ii++) {
		cout << "Elemento[" << ii+1 << "]: " ;
		cin >> v.elementos[ii] ;
	}
}

double vector_sum (Vector& v) {
	double soma{0} ;
	for (int ii{0} ; ii < v.tam ; ii++) {
		soma += v.elementos[ii] ;
	}
	return soma ;
}

bool vector_find (Vector& v , int key) {
	for (int ii{0} ; ii < v.tam ; ii++) {
		if (v.elementos[ii] == key) {
			return true ;
		}
	}
	return false ;
}

int main (int argc , char *argv[]) {
	int n{0} , chave{0} ;
	Vector vetor ;
	cout << "Quantos elementos sua lista armazenara ? " ;
	cin >> n ;

	vector_init(vetor, n) ;
	vector_read(vetor) ;
	cout << "Soma dos elementos informados: " << vector_sum(vetor) << endl ;
	cout << "Informe a chave de busca: " ;
	cin >> chave ;
	if (vector_find(vetor, chave)) {
		cout << "Chave localizada!" << endl ;
	}
	else {
		cout <<"Chave nao localizada!" << endl ;
	}



	return EXIT_SUCCESS ;
}