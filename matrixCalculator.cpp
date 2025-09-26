#include <iostream> 
#include <vector>
using namespace std;

int main()
{
	int mAH, mAW, mBH, mBW;
	int i, j, m, n;
	string matrixOperator;

	cout << "Enter heigh of A matrix: " << endl;
	cin >> mAH;
	cout << "Enter width of A matrix: " << endl;		//getting matrix A options
	cin >> mAW;

	cout << "Enter heigh of B matrix: " << endl;
	cin >> mBH;
	cout << "Enter width of B matrix: " << endl;		//getting matrix B options
	cin >> mBW;

	vector<vector<int>> matrixA(mAH, vector<int>(mAW)); //matrixA
	vector<vector<int>> matrixB(mBH, vector<int>(mBW)); //matrixB
	vector<vector<int>> matrixPoM(mAH, vector<int>(mAW)); //matrixPoM (Plus or Minus)
	vector<vector<int>> matrixMult(mAH, vector<int>(mBW)); //matriMult (multiply)

	for (i = 0; i < mAH; i++)
	{
		for (j = 0; j < mAW; j++)
		{
			cout << "Enter value of the " << i + 1 << j + 1 << "elemet" << endl;	//insert elements in A matrix
			cin >> matrixA[i][j];
		}
	}

	for (m = 0; m < mBH; m++)
	{
		for (n = 0; n < mBW; n++)
		{
			cout << "Enter value of the " << m + 1 << n + 1 << "elemet" << endl;	//insert elements in B matrix
			cin >> matrixB[m][n];
		}
	}

	cout << "Enter operator (+, -, *)" << endl;		//operator + - * 
	cin >> matrixOperator;


	if (matrixOperator == "+") {						// calculator func
		if (mAH != mBH || mAW != mBW)
		{
			cout << "It could not be calculated(" << endl;
		}
		else
		{
			for (int f = 0; f < mAH; f++)					// f x g
			{
				for (int g = 0; g < mAW; g++)
				{
					matrixPoM[f][g] = matrixA[f][g] + matrixB[f][g];
				}
			}

			cout << "Result matrix (A + B):" << endl;
			for (int f = 0; f < mAH; f++) {
				for (int g = 0; g < mAW; g++) {
					cout << matrixPoM[f][g] << " ";
				}
				cout << endl;
			}
		}
	}
	else if (matrixOperator == "-") {
		if (mAH != mBH || mAW != mBW)
		{
			cout << "It could not be calculated(" << endl;
		}
		else
		{
			for (int f = 0; f < mAH; f++)					// f x g
			{
				for (int g = 0; g < mAW; g++)
				{
					matrixPoM[f][g] = matrixA[f][g] - matrixB[f][g];
				}
			}

			cout << "Result matrix (A - B):" << endl;
			for (int f = 0; f < mAH; f++) {
				for (int g = 0; g < mAW; g++) {
					cout << matrixPoM[f][g] << " ";
				}
				cout << endl;
			}
		}
	}
	else if (matrixOperator == "*") {
		if (mAW != mBH)
		{
			cout << "It could not be calculated(" << endl;
		}
		else
		{
			for (int f = 0; f < mAH; f++)					// f x g
			{
				for (int g = 0; g < mBW; g++)
				{
					matrixMult[f][g] = 0;
					for (int k = 0; k < mAW; k++)
					{
						matrixMult[f][g] += matrixA[f][k] * matrixB[k][g];
					}
				}
			}

			cout << "Result matrix (A * B):" << endl;
			for (int f = 0; f < mAH; f++) {
				for (int g = 0; g < mBW; g++) {
					cout << matrixMult[f][g] << " ";
				}
				cout << endl;
			}
		}
	}
	else {
		cout << "This is not the operator" << endl;
	}
}