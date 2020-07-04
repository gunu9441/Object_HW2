#include <iostream>
#include"Matrix.h"

using namespace std;

int main()
{
	int rw, cl;
	Matrix mat1, mat2, mat3, mat4, mat5;

	cout << "Input 3*3 matrix" << endl;
	cout << ":";
	mat1.set_matrix();

	cout << "Input 3*3 matrix" << endl;
	cout << ":";
	mat2.set_matrix();

	cout << "+ operation" << endl;//Addition.
	mat3 = mat1 + mat2;
	mat3.print_matrix();
	cout << "- operation" << endl;//Minus.
	mat3 = mat1 - mat2;
	mat3.print_matrix();
	cout << "* operation" << endl;//Multiplication.
	mat3 = mat1 * mat2;
	mat3.print_matrix();
	
	cout << "L rotation" << endl;//Left rotation.
	mat4 = mat1.rotation_Left();
	mat4.print_matrix();
	cout << "R rotaion" << endl;//Right rotation.
	mat4 = mat4.rotation_Right();
	mat4.print_matrix();
	cout << "inverse" << endl;//inverse fuction.
	mat5 = mat4.inverse();
	mat5.print_matrix();

	return 0;
}