#include <iostream>
using namespace std;

class Matrix{
private:
	double matrix[3][3];

public:
	Matrix(void);
	~Matrix(void);

	void set_matrix(void);
	void print_matrix(void);

	Matrix rotation_Left();
	Matrix rotation_Right();
	Matrix inverse();

	Matrix operator + (const Matrix& mat);
	Matrix operator - (const Matrix& mat);
	Matrix operator = (const Matrix& mat);
	Matrix operator * (const Matrix& mat);
};