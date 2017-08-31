/** @file questao07.cpp	*/
/** @question 7		*/
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T> // elemento do tipo T
struct Matrix {
	int linhas;		// numero de linhas da matriz
	int colunas;	// numero de colunas da matriz
	T** elemento;	// elementos da matriz
};

template <typename T>
void matrix_creator(Matrix<T>& m, int linhas, int colunas) {
	
	int i;
	// inicializar as dimensoes (linhas e colinas)
	m.linhas = linhas;
	m.colunas = colunas;

	// alocar as linhas da matriz
	m.elemento = new T*[linhas];
	
	// alocar as colinas da matriz
	for(i = 0; i < m.linhas; i++) {
		m.elemento[i] = new T[colunas];
	}
}

template <typename T>
void matrix_destructor(Matrix<T>& m) {

	int i;
	// desaloca a coluna de cada linha da matriz
	for(i = 0; i < m.linhas; i++) {
		delete[] m.elemento[i];
	}
	// desaloca as linhas da matriz
	delete[] m.elemento;
}

template <typename T>
void matrix_read(Matrix<T>& m) {
	int i, j;
	// ler o elemento de cada linha i e coluna j da matriz
	for (i = 0; i < m.linhas; i++) {
		for(j = 0; j < m.colunas; j++) {
			cout << "M[" << i << ", " << j << "]: ";
			cin >> m.elemento[i][j]; 
		}
	}
}


template <typename T>
void matrix_write(Matrix<T>& m) {
	// escrever elemento de cada linha i e coluna j da matriz
	int i, j;

	for (i = 0; i < m.linhas; i++) {
		for(j = 0; j < m.colunas; j++) {
			cout << m.elemento[i][j] << " ";
		}
		cout << endl;
	}
}

template<typename T>
void verifica (Matrix<T>& m1 ,Matrix<T>& m2 ) {
	if (m1.linhas != m2.colunas) {
		cout << "Não é possível fazer a multiplicação." << endl ;
		exit(1) ;
	}
	else {
		cout << "Matriz 1: " << endl;
		matrix_write(m1);
		cout << "Matriz 2: " << endl;
		matrix_write(m2);
		cout << "Matriz 3: " << endl ;
		multiplica(m1,m2) ;
	}
}

template<typename T>
void multiplica (Matrix<T>& m1 ,Matrix<T>& m2 ) {
	int ii;
	int jj;
	for (ii = 0 ; ii < m1.linhas ; ii++) {
		for (jj = 0 ; jj < m1.colunas ; jj++) {
			cout << m1.elemento[ii][jj] * m2.elemento[jj][ii] << " "  ;
		}
		cout << '\n' ;
	}
}

int main(int argc, char* argv[]) {

	Matrix<int> m1, m2;
	int linhas, colunas;

	// solicitar numero de linhas da matriz m1
	cout << "Informe o numero de linhas da matriz M1: ";
	cin >> linhas;
	// solicitar numero de colunas da matriz m1
	cout << "Informe o numero de colunas da matriz M1: ";
	cin >> colunas;
	// alocar matriz m1
	matrix_creator(m1, linhas, colunas);

	// solicitar e ler valores da matriz m1
	cout << "Informar elementos da matriz M1" << endl;
	matrix_read(m1);


	// solicitar numero de linhas da matriz m2
	cout << "Informe o numero de linhas da matriz M2: ";
	cin >> linhas;
	// solicitar numero de colunas da matriz m2
	cout << "Informe o numero de colunas da matriz M2: ";
	cin >> colunas;
	// alocar matriz m1
	matrix_creator(m2, linhas, colunas);

	// solicitar e ler valores da matriz m2
	cout << "Informar elementos da matriz M2" << endl;
	matrix_read(m2);
	
	// Verifica se a multiplicação entre as matrizes m1 e m2 é possivel
	verifica(m1,m2) ;


	// desalocar o espaco utilizado por m1 e m2
	matrix_destructor(m1);
	matrix_destructor(m2);

	return EXIT_SUCCESS;
}
