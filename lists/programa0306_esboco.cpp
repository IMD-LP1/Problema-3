/** @file programa0306_esboco.cpp	*/
/** @@question 6		*/
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
void matrix_creator(Matrix<T>& m, int linhas, int colinas) {
	
	int i, j;
	// inicializar as dimensoes (linhas e colinas)
	m.elemento = new T[linhas];
	// alocar as linhas da matriz
	// alocar as colinas da matriz
	for(i == 0; i < linhas; i++) {
		m.elemento = new T*[colinas];
		for(j == 0; j < colunas; j++){

		}	
	}
}

template <typename T>
void matrix_destructor(Matrix<T>& m) {
	// desaloca a coluna de cada linha da matriz
	// desaloca as linhas da matriz
}

template <typename T>
void matrix_read(Matrix<T>& m) {
	int i, j;
	// ler o elemento de cada linha i e coluna j da matriz
	cout << "Informar elementos da matriz M" << endl;

}


template <typename T>
void matrix_write(Matrix<T>& m) {
	// escrever elemento de cada linha i e coluna j da matriz
	cout << "Matriz informada: " << endl;
}


template <typename T>
void matrix_transpose(Matrix<T>& m1, Matrix<T>& m2) {
	// alocar a matriz e armazenar a transposta
	// realizar a transposição de m1 em m2
}

int main(int argv, char * argv []) {

	Matrix<int> m1, m2;
	int linhas, colunas;

	// solicitar numero de linhas da matriz m1
	cout << "Informe o numero de linhas da matriz M: ";
	cin >> linhas;
	// solicitar numero de colunas da matriz m1
	cout << "Informe o numero de colunas da matriz M: ";
	cin >> colunas;
	// alocar matriz m1
	matrix_creator(m1, linhas, colunas);
	// solicitar e ler valores da matriz m1
	matrix_read(m1);
	// escrever matriz m1 informada
	matrix_write(m1);
	// traspor e escrever a transposta m2
	matrix_transpose(m2);
	// desalocar o espaco utilizado por m1 e m2
	matrix_destructor(m2, linhas, colunas);

	return EXIT_SUCCESS;
}