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


template <typename T>
void matrix_transpose(Matrix<T>& m1, Matrix<T>& m2) {
	// alocar a matriz e armazenar a transposta
	// realizar a transposição de m1 em m2
	int i, j;
	
	matrix_creator(m2, m1.colunas, m1.linhas);

	for(i = 0; i < m1.linhas; i++) {
		for(j = 0;  j< m1.colunas; j++) {
			m2.elemento[j][i] = m1.elemento[i][j];
		}
	}
}

int main(int argc, char* argv[]) {

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
	cout << "Informar elementos da matriz M" << endl;
	matrix_read(m1);

	// escrever matriz m1 informada
	cout << "Matriz informada: " << endl;
	matrix_write(m1);

	// traspor e escrever a transposta m2
	cout << "Matriz transposta: " << endl;
	matrix_transpose(m1, m2);
	matrix_write(m2);

	// desalocar o espaco utilizado por m1 e m2
	matrix_destructor(m1);
	matrix_destructor(m2);

	return EXIT_SUCCESS;
}