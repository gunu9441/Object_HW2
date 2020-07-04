#include "Matrix.h"

Matrix::Matrix(void) {

}

Matrix::~Matrix(void) {

}

void Matrix::set_matrix() {
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cin >> matrix[row][col];
		}
	}
	return;
}//Input matrix.

void Matrix::print_matrix() {
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}//Output matrix.

Matrix Matrix::rotation_Left() {
	double temp;
	Matrix mtr;
	
	for (int cnt = 0; cnt < 2; cnt++)//Left rotation.
	{
		temp = matrix[2][2-cnt];
		matrix[2][2 - cnt] = matrix[2 - cnt][0];
		matrix[2-cnt][0] = matrix[0][cnt];
		matrix[0][cnt] = matrix[cnt][2];
		matrix[cnt][2] = temp;
	}
	for (int rw = 0; rw < 3; rw++)//mtr.matrix = matrix.
	{
		for (int cl = 0; cl < 3; cl++)
		{
			mtr.matrix[rw][cl] = matrix[rw][cl];
		}
	}
	return mtr;
}

Matrix Matrix::rotation_Right() {
	double temp;
	Matrix mtr;
	
	for (int cnt = 0; cnt < 2; cnt++)//Right rotation.
	{
		temp = matrix[2 - cnt][0];
		matrix[2 - cnt][0] = matrix[2][2 - cnt];
		matrix[2][2 - cnt] = matrix[cnt][2];
		matrix[cnt][2] = matrix[0][cnt];
		matrix[0][cnt] = temp;
	}
	for (int rw = 0; rw < 3; rw++)//mtr.matrix = matrix
	{
		for (int cl = 0; cl < 3; cl++)
		{
			mtr.matrix[rw][cl] = matrix[rw][cl];
		}
	}
	return mtr;
}

Matrix Matrix::inverse() {//Inverse function.
	double temp_mtr[3][3];
	Matrix mtr;
	double det = ((matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[1][0] * matrix[2][1] * matrix[0][2])) - ((matrix[2][0] * matrix[1][1] * matrix[0][2]) + (matrix[1][0] * matrix[0][1] * matrix[2][2]) + (matrix[0][0] * matrix[2][1] * matrix[1][2]));
	
	if (det != 0)
	{
		temp_mtr[0][0] = (((matrix[2][2] * matrix[1][1]) - (matrix[1][2] * matrix[2][1])) / det);
		temp_mtr[0][1] = (((matrix[0][2] * matrix[2][1]) - (matrix[2][2] * matrix[0][1])) / det);
		temp_mtr[0][2] = (((matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1])) / det);
		temp_mtr[1][0] = (((matrix[1][2] * matrix[2][0]) - (matrix[1][0] * matrix[2][2])) / det);
		temp_mtr[1][1] = (((matrix[2][2] * matrix[0][0]) - (matrix[0][2] * matrix[2][0])) / det);
		temp_mtr[1][2] = (((matrix[0][2] * matrix[1][0]) - (matrix[0][0] * matrix[1][2])) / det);
		temp_mtr[2][0] = (((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])) / det);
		temp_mtr[2][1] = (((matrix[0][1] * matrix[2][0]) - (matrix[0][0] * matrix[2][1])) / det);
		temp_mtr[2][2] = (((matrix[1][1] * matrix[0][0]) - (matrix[0][1] * matrix[1][0])) / det);

		for (int rw = 0; rw < 3; rw++){
			for (int cl = 0; cl < 3; cl++){
				mtr.matrix[rw][cl] = temp_mtr[rw][cl];
			}
		}
		return mtr;
	}

	else//det==0.
	{
		cout << "This matrix's inverse fucntion does not exist." << endl;
		exit(1);
	}


}

Matrix Matrix::operator+(const Matrix& mat) {//addition.
	Matrix result;

	for (int rw = 0; rw < 3; rw++){
		for (int cl = 0; cl < 3; cl++){
			result.matrix[rw][cl] = matrix[rw][cl] + mat.matrix[rw][cl];
		}
	}
	return result;
}
Matrix Matrix::operator - (const Matrix& mat) {//Minus.
	Matrix result;

	for (int rw = 0; rw < 3; rw++){
		for (int cl = 0; cl < 3; cl++){
			result.matrix[rw][cl] = matrix[rw][cl] - mat.matrix[rw][cl];
		}
	}
	return result;
}
Matrix Matrix::operator = (const Matrix& mat) {
	for (int rw = 0; rw < 3; rw++) {
		for (int cl = 0; cl < 3; cl++) {
			matrix[rw][cl] = mat.matrix[rw][cl];
		}
	}
	return *this;
}
Matrix Matrix::operator * (const Matrix& mat)//Multiplication.
{
	Matrix result;

	for (int rw = 0; rw < 3; rw++)
	{
		for (int cl = 0; cl < 3; cl++)
		{
			result.matrix[rw][cl] = matrix[rw][0] * mat.matrix[0][cl] + matrix[rw][1] * mat.matrix[1][cl] + matrix[rw][2] * mat.matrix[2][cl];
		}//Multiplication of matrix.
	}
	return result;
}
