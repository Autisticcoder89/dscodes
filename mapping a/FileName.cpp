//241398
//hania shahzad
#include<iostream>
using namespace std;
//row mapping and it's reverse
int* rowmapping(int arr[][3], int n, int m) {
	static int a[9];
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[k] = arr[i][j];
			k++;
		}

	}
	return a;
}
//column major mapping
int* columnmapping(int arr[3][3], int n, int m) {
	static int b[9];
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[k] = arr[j][i];
			k++;
		}
	}
	return b;
}

int* diagonalmapping(int arr[3][3], int n, int m) {
	static int c[3];
	int k = 0;
	for (int j = 0; j < 3; j++) {
		c[k] = arr[j][j];
		k++;
	}
	return c;
}
// Diagonal reverse mapping 
int* dreversemapping(int diagonal[], int n) {
	static int matrix[3][3] = { 0 };
	for (int i = 0; i < n; i++) {
		matrix[i][i] = diagonal[i];
	}
	return (int*)matrix;
}
int* tridiagonalmap(int arr[][4],int x,int y) {
	static int tridiag[10];
	//this matrix will have 3n-2 elements
	for (int j = 0; j < x; j++) {
		tridiag[j]=arr[j][j];
	}
	for (int j = 0; j < x - 1; j++) {
		tridiag[y + j] = arr[j][j + 1];
	}
	for (int j = 0; j < x - 1; j++) {
		tridiag[(2 * y) - 1 + j] = arr[j + 1][j];
	}
	return tridiag;
}
int tridiagonalreversemap(int arr[],int i,int j,int columns) {//why didnt we use * in this query
	if (i == j) {
		return arr[i];
	}
	if (i == j -1) {
		return arr[columns + j - 1];

	}
	if (i == j + 1) {
		return arr[2 * columns + j - 1];
	}
	else {
		return 0;
	}


}

int* lowertriangularmapping(int arr[][4], int n, int m)
{
	static int a[(4 * (4 + 1)) / 2];  
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i >= j)  
			{
				a[c] = arr[i][j];
				c++;
			}
		}
	}
	return a;
}
int reverselowertriangularmapping(int arr[], int i, int j)
{
	if (j > i)
	{
		return 0;
	}
	else
	{
		return arr[(i * (i + 1)) / 2 + j];  
	}
	
	
}
int* uppertriangularmapping(int matrix[4][4], int n) {
	int size = (n * (n + 1)) / 2;
	int* compressed = new int[size];
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			compressed[index++] = matrix[i][j];
		}
	}
	return compressed;
}
int reverseuppertriangularmapping(int arr[], int i, int j, int n) {
	if (j < i) {
		return 0;  
	}
	else {
		
		int index = (i * (2 * n - i + 1)) / 2 + (j - i);
		return arr[index];
	}
}
int* symmetricMapping(int matrix[4][4], int n) {
	int size = (n * (n + 1)) / 2;  
	int* compressed = new int[size];
	int index = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {  
			compressed[index++] = matrix[i][j];
		}
	}
	return compressed;
}
int reverseSymmetricMapping(int arr[], int i, int j) {
	if (i >= j) {
		
		return arr[(i * (i + 1)) / 2 + j];
	}
	else {
		
		return arr[(j * (j + 1)) / 2 + i];
	}
}









int main() {
	int r = 3; int c = 3;
	static int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int* array;
	array = rowmapping(a, 3, 3);
	cout << endl << "row major mapping" << endl;
	for (int j = 0; j < 9; j++) {
		cout << array[j] << " ";
	}

	//reverse mapping
	cout << endl << "reverse mapping:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	//index based mapping
	cout << "index based row major mapping:" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << " " << "is mapped on" << " " << (i * c) + j << endl;
		}
	}
	//column major mapping
	cout << endl << "column major mapping" << endl;
	int* array1 = columnmapping(a, r, c);
	for (int i = 0; i < (r * c); i++) {
		cout << array1[i] << " ";
	}
	//revsere mapping
	cout << endl << "reverse mapping" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[j][i] << " ";
		}
		cout << endl;
	}
	cout << "index based mapping" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << " " << "is mapped on" << " " << i + (r * j) << endl;
		}
	}


	//diagonal  mapping
	cout << "diagonal mapping" << endl;
	static int d[3][3] = { {1,0,0},{0,2,0 },{0,0,3} };
	int* array2 = diagonalmapping(d, r, c);
	for (int i = 0; i < r; i++) {
		cout << array2[i];

	}
	cout << endl;
	int diagonal[] = { 1,2,3 };
	int* array3 = dreversemapping(diagonal, r);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << array3[i * 3 + j] << " ";
		}
		cout << endl;
	}
	//tri-diagonal matrix
	int x = 4, y = 4, columns = 4;
	static int tridiagonal[][4] = { {1, 5, 0, 0}, {8, 2, 6, 0}, {0, 9, 3, 7}, {0, 0, 10, 4} };
	int* array4;
	array4 = tridiagonalmap(tridiagonal, x, y);
	cout << "tri-diagonal mapping" << endl;
	for (int i = 0; i < 10; i++) {
		cout << array4[i] << " ";
	}
	int compressedArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << endl << endl;


	cout << "Reconstructed 4x4 Matrix:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << tridiagonalreversemap(compressedArray, i, j, columns) << "\t";
		}
		cout << endl;
	}
	// lower-triangular matrix
	static int lowerTriangular[4][4] = {
	{4, 0, 0, 0},
	{3, 7, 0, 0},
	{2, 5, 8, 0},
	{1, 4, 6, 9} };
	
   int* compressedArray2;
   compressedArray2 = lowertriangularmapping(lowerTriangular, 4, 4);

   
   cout << "Lower Triangular 1D array: ";
   for (int i = 0; i < 10; i++) {  
	   cout << compressedArray[i] << " ";
   }
   cout << endl << endl;

   
   cout << "Lower Triangular reverse mapping:" << endl;
   for (int i = 0; i < 4; i++) {
	   for (int j = 0; j < 4; j++) {
		   cout << reverselowertriangularmapping(compressedArray, i, j) << "\t";
	   }
	   cout << endl;
   }
   int upperTriangular[4][4] = {
		{1, 2, 3, 4},
		{0, 5, 6, 7},
		{0, 0, 8, 9},
		{0, 0, 0, 10}
   };

   // Mapping
   int* compressedArray4= uppertriangularmapping(upperTriangular, 4);

   cout << "Upper Triangular 1D array: ";
   int size = (4 * (4 + 1)) / 2; 
   for (int i = 0; i < size; i++) {
	   cout << compressedArray4[i] << " ";
   }
   cout << endl << endl;

   // Reverse mapping
   cout << "Upper Triangular reverse mapping:" << endl;
   for (int i = 0; i < 4; i++) {
	   for (int j = 0; j < 4; j++) {
		   cout << reverseuppertriangularmapping(compressedArray, i, j, 4) << "\t";
	   }
	   cout << endl;
   }
   int symmetricMatrix[4][4] = {
		{1, 2, 3, 4},
		{2, 5, 6, 7},
		{3, 6, 8, 9},
		{4, 7, 9, 10}
   };

  
   int* compressedArray5 = symmetricMapping(symmetricMatrix, 4);

   cout << "Symmetric 1D array: ";
   int size1 = (4 * (4 + 1)) / 2; 
   for (int i = 0; i < size; i++) {
	   cout << compressedArray5[i] << " ";
   }
   cout << endl << endl;

   
   cout << "Symmetric reverse mapping:" << endl;
   for (int i = 0; i < 4; i++) {
	   for (int j = 0; j < 4; j++) {
		   cout << reverseSymmetricMapping(compressedArray, i, j) << "\t";
	   }
	   cout << endl;
   }

   
}