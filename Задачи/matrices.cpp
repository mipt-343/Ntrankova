#include <iostream>
#include <cstdlib>

using namespace std;

class Matrix
{
protected:

	unsigned size_x, size_y;

public:
	double *matrix;

	Matrix(unsigned sz_x, unsigned sz_y)
	{
		matrix = new double[sz_x * sz_y];
		size_x = sz_x; size_y = sz_y;
	}


	void print(){ // вывод матрицы
		for (unsigned i = 0; i < this->size_x*this->size_y; i++){
			if (i%size_x == 0) cout << "\n";
			cout << this->matrix[i];
			int count = 0; 
			int a = this->matrix[i];
			if (a < 0) count++;
			do {
				count++;
				a /= 10;
			} 
			while (a != 0);
			for (a = 0; a < (8 - count); a++) cout << " "; // учет количества пробелов между столбцами
		}
	}

	Matrix& operator+(Matrix b)
	{
		if ((this->size_x != b.size_x) || (this->size_y != b.size_y))
		{
			cout << ("Matrices have different sizes!!! ") << endl;
			system("pause"); 
			exit(1);
		}
		Matrix c = Matrix(this->size_x, this->size_y);
		for (int i = 0; i < this->size_x*this->size_y; i++) c.matrix[i] = this->matrix[i] + b.matrix[i];
		return c;
	}

	Matrix operator-(Matrix b)
	{
		if ((this->size_x != b.size_x) || (this->size_y != b.size_y)) 
		{
			cout << ("Matrices have different sizes!!! ") << endl;
			system("pause"); 
			exit(1);
		}
		Matrix c = Matrix(this->size_x, this->size_y);
		for (int i = 0; i < this->size_x*this->size_y; i++) c.matrix[i] = this->matrix[i] - b.matrix[i];
		return c;
	}

	Matrix operator*(Matrix b)
	{
		if (this->size_x != b.size_y) {
			cout << ("Matrices have unsuitable sizes!!! ") << endl;
			system("pause"); 
			exit(1);
		}
		Matrix c = Matrix(b.size_x, this->size_y);
		for (int i = 0; i < b.size_x*this->size_y; i++) {
			c.matrix[i] = 0;
			for (int k = 0; k < this->size_x; k++){
				c.matrix[i] += this->matrix[(i / b.size_x)*this->size_x + k] * b.matrix[k*b.size_x + i - (i / b.size_x)*b.size_x];
			}
		}
		c.size_x = b.size_x;
		return c;
	}
};

