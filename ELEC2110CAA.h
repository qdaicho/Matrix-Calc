#ifndef ELEC2110CAA
#define ELEC2110CAA
#include <vector>
#include <string>
//importing required libraries

using namespace std;

/**
 * retrieves a calculation choice from the user
 * 
 * @return returns user’s operation of choice
 */
int getOperation(){
	printf("PLEASE TYPE DOWN WHAT MATRIX OPERATION YOU WOULD LIKE TO PERFORM.\n\nOPTIONS (type an number below):\n");
	printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Solve Ax=b\n5. Find Inverse of Matrix\n\nYour chosen operation: ");

	int operation;//the user's operation of choice
	while(true){
		cin >> operation;

		if (operation > 0 && operation < 6){
			break;
		}else{
			printf("\ninput not valid...try again\n");
			cin.clear();//corrects the stream
			cin.ignore();//skips the remaining stream data
		}
	}
	return operation;
}

/**
 * utility function that sets the values of variables inputted into the parameter
 * 
 * @param 
 * int &rowA – memory address of variable holding the row size of matrix
 * int &colA – memory address of variable holding the columns size of matrix
 * string message – prints out a custom prompt based on the name of the matrix in question
 * bool oneParam – optional flag variable which is triggered when row size = column size
 * 
 * @return void
 */
void getDimensions(int &rowA, int &colA, string name, bool oneParam = false){
	if (!oneParam){
		cout << "\nPlease type the dimensions for " << name << " sequentially (rows then columns):   ";
		scanf("%d %d", &rowA, &colA);
	}else{
		cout << "\nPlease type the # of equations in this system of equations\ni.e. The dimensions for the square matrix (type one number):   ";
		scanf("%d", &rowA);
		colA = rowA;
	}
}

/**
 * utility function that generates a dynamic 2d double pointer array/matrix  
 * 
 * @param
 * int row – variable holding the row size of matrix
 * int col – variable holding the columns size of matrix
 * double ** matrix – holds an uninitialized double pointer matrix variable
 *
 * @return returns a double pointer to newly generated dynamic matrix
 */
double **dynamicMatrixGenerator(int row, int column, double **matrix){
	matrix = new double *[row];
	for(int x = 0; x < row; x++){
		matrix[x] = new double[column]; 
	}
	return matrix;
}

/**
 * utility function which cleanly prints any matrix in a formatted fashion
 * 
 * @param
 * int row – variable holding the row size of matrix
 * int col – variable holding the columns size of matrix
 * double ** matrix – holds a double pointer to a matrix
 * string message – any custom message that the user wants to show during the print
 *
 * @return void
 */
void printMatrix(int row, int col, double **matrix, string message = ""){
	cout << endl << message << endl;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("%10.4f", matrix[i][j]);
		}
		cout << endl;
	}
}

/**
 * populates all the elements within any matrix with user input
 * 
 * @param
 * int row – variable holding the row size of matrix
 * int col – variable holding the columns size of matrix
 * double ** matrix – holds a double pointer to a matrix
 * string message – any custom prompt message that is shown before retrieving values from user
 * 
 * @return void
 */
void populateMatrix(int row, int col, double **matrix, string message = "MATRIX"){
	cout << "\n\nPlease type down each element in [" << message << "] (enter the numbers sequentially row by row)\n";
	cout << "-----> i.e Every [" << col << "] number(s), PRESS ENTER since you start a new row (with a total of " << row << " rows)\n";
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			cin >> matrix[i][j];
		}
	}
}

/**
 * computes the sum of two matrices A and B
 * 
 * @param
 * int row – variable holding the row size of both matrices
 * int col – variable holding the columns size of both matrices
 * double ** matA – holds a double pointer to a populated matrix A
 * double ** matB – holds a double pointer to a populated matrix B
 * double ** summedMatrix– holds a double pointer to a blank summation matrix
 *
 * @return returns double pointer to the summation matrix
 */
double** sum (int row, int col, double **matA, double **matB, double** summedMatrix){

	// sum the two input matrices
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			summedMatrix[i][j] = matA[i][j] + matB[i][j]; 
		}
	}

	return summedMatrix;
}

/**
 * computes the difference of two matrices A and B
 * 
 * @param
 * int row – variable holding the row size of both matrices
 * int col – variable holding the columns size of both matrices
 * double ** matA – holds a double pointer to a populated matrix A
 * double ** matB – holds a double pointer to a populated matrix B
 * double ** matDifference – holds a double pointer to a blank difference matrix
 *
 * @return returns double pointer to the difference matrix
 */
double** difference (int row, int col, double **matA, double **matB, double** matDifference){

	// find the difference between the two input matrices
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			matDifference[i][j] = matA[i][j] - matB[i][j]; 
		}
	}

	return matDifference;
}

/**
 * computes the product of two matrices A and B
 * 
 * @param 
 * int row – variable holding the row size of both matrices
 * int col – variable holding the columns size of both matrices
 * double ** matA – holds a double pointer to a populated matrix A
 * double ** matB – holds a double pointer to a populated matrix B
 * double ** matProd – holds a double pointer to a blank product matrix
 *
 * @return returns double pointer to the product matrix
 */
double** multiply (int row, int col, int common, double **matA, double **matB, double** matProd){

	// find the product between the two input matrices
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			for(int k = 0; k < common; k++){
				matProd[i][j] += matA[i][k] * matB[k][j]; 
			}
		}
	}

	return matProd;
}

/**
 * performs gaussian elimination on an augmented matrix and prints the solution to Ax=b.
 * 
 * @param
 * int dimensions – variable holding the dimensions of square matrix A
 * double ** matA – holds a double pointer to a populated matrix A
 * double ** vectorB – holds a double pointer to a populated vector B
 * double ** matAugumented – holds a double pointer to a blank augumented matrix
 *
 * @return returns double pointer to the augmented matrix
 */
double** solution(int dimensions, double **matA, double **vectorB, double **matAugumented){
	//transforming matrix A and vector B into an augmented matrix then printing it [matrix A | vector B]
	for(int i = 0; i < dimensions; i++){
	   for(int j = 0; j < dimensions+1; j++){
			if (j == dimensions){
				matAugumented[i][j] = vectorB[i][0];
			}else{
				matAugumented[i][j]=matA[i][j];
			}
		}
	}
	printMatrix(dimensions, dimensions+1, matAugumented, "--> Augumented Matrix:");

	//partial pivoting
	double apple;//temporary variable used to hold values when pivoting
	for(int i = dimensions-1; i > 0; i--){
		if(matAugumented[i-1][0] < matAugumented[i][0]){
			for(int j = 0; j <= dimensions; j++){
				apple = matAugumented[i][j];
				matAugumented[i][j] = matAugumented[i-1][j];
				matAugumented[i-1][j] = apple;
			}
		}
	}
	printMatrix(dimensions, dimensions+1, matAugumented, "--> Partially Pivoted Augumented Matrix:"); 

	double temp;//temp variable used in calculations to hold values temporarily
	double* x = new double[dimensions];// solution vector 

	//gaussian elimination algorithm implementation aka generating upper triangular matrix from augmented matrix
	for(int i = 0; i < dimensions-1; i++){
		for(int j = i+1; j < dimensions; j++){
			temp = matAugumented[j][i]/matAugumented[i][i];
			for(int k = 0; k <= dimensions; k++){
				matAugumented[j][k] -= temp * matAugumented[i][k];
			}
			temp = 0;
		}
	}//afterwards print the upper triangular matrix
	printMatrix(dimensions, dimensions+1, matAugumented, "--> Matrix after gaussian elimination:");

	//back substitution algorithm implementation
	for(int i = dimensions-1; i >= 0; i--){
		x[i] = matAugumented[i][dimensions];
		for(int j = i+1; j < dimensions; j++){
			if (j!=i) {x[i] -= matAugumented[i][j] * x[j];} 
		}
		x[i] /= matAugumented[i][i];
	}

	//print the computed solution vector x in Ax=b onto the terminal
	cout << endl << "SOLUTION OF LINEAR SYSTEM OF EQUATIONS:";
	for(int i = 0; i < dimensions; i++){
		printf("\nx [%d] = %.10f", i, x[i]);
	}

	return matAugumented;//return augmented matrix
}

/**
 * performs L U Decomposition on matrix A using the doolittle decomposition algorithm from the textbook.
 * 
 * @param
 * int dimensions – variable holding the dimensions of square matrix A
 * double ** matA – holds a double pointer to a populated matrix A
 * double ** matL – holds a double pointer to a blank lower matrix
 * double ** matU – holds a double pointer to a blank upper matrix
 *
 * @return void
 */
void LU_Decomposition(int dimensions, double **matA, double **matL, double **matU){
	// partial pivoting
	double apple;//temporary variable used to hold values when pivoting
	for(int i = dimensions-1; i > 0; i--){
		if(matA[i-1][0] < matA[i][0]){
			for(int j = 0; j <= dimensions; j++){
				apple = matA[i][j];
				matA[i][j] = matA[i-1][j];
				matA[i-1][j] = apple;
			}
		}
	}
	printMatrix(dimensions, dimensions, matA, "PARTIALLY PIVOTED MATRIX:");

	//making the diagonal of matU equal to the diagonal of matA
	for(int i = 0; i < dimensions; i++){
		for(int j = 0; j < dimensions; j++){
			matU[i][j] = matA[i][j];
		}
	}

	//gaussian elimination to generate matU from matA
	for(int i = 0; i < dimensions-1; i++){//iterating through matrix rows
		for(int j = i+1; j < dimensions; j++){//iterating through rows but it is one lower than the row at i
			//dividing the element below diagonal with element at diagonal to get coefficient
			double coefficient = matU[j][i] /matU[i][i];

			for(int k = 0; k < dimensions; k++){
				//subtracting all the elements in a row the calculated coefficient times the row before it ex. R2 = R2 - C*R1
				matU[j][k] -= coefficient*matU[i][k];
			}

			//storing each calculated coefficient of every iteration into matL (below the diagonal)
			matL[j][i] = coefficient;
		}
	}

	for(int i = 0; i < dimensions; i++){
		for(int j = 0; j < dimensions; j++){
			if(j>i){
				//make elements above diagonal of matrix L equal to 0
				matL[i][j] = 0;
			}else if (i == j){
				//make elements at diagonal of matL equal to 1
				matL[i][j] = 1;
			}
		}
	}

	//printing out each of the three matrices
    printMatrix(dimensions, dimensions, matA, "INPUT : MATRIX A:");
    printMatrix(dimensions, dimensions, matL, "STEP 1 : LOWER TRIANGULAR MATRIX: ");
    printMatrix(dimensions, dimensions, matU, "STEP 2 : UPPER TRIANGULAR MATRIX: ");
}

/**
 * computes each column of A inverse
 * 
 * @param
 * int dimensions – variable holding the dimensions of square matrices A,L,U, and A^-1
 * int i- variable holding the current column number being computed in the inverse matrix
 * double ** matA – holds a double pointer to a populated matrix A
 * double ** matL – holds a double pointer to a populated lower matrix
 * double ** matU – holds a double pointer to a populated upper matrix
 * double ** matIdentity – double pointer to a blank identity matrix
 * double * vectorX – double pointer to a blank vector X which will later be populated with column elements of A^-1
 * 
 * @return double floating point - pointer to column vector X
 */
double * substitution(int dimensions, int i, double **matA, double **matL, double **matU, double **matIdentity, double* vectorX){
	//retrieves the current column of the identity matrix and transforms it into a 1d array which is later used within the algorithm. ex. [1, 0, 0] or [0, 0, 1]
	double **matRowIdentity = dynamicMatrixGenerator(dimensions, 1, matRowIdentity);
	for (int col = 0; col < dimensions; col++){
		matRowIdentity[col][0] = matIdentity[i][col];
	}

	//uses forward substitution to solve for Ld=B and it then populates vector d
	double vectorD[dimensions];// ex. d0, d1, d2

	for(int j = 0; j < dimensions; j++){
		double summation = matRowIdentity[j][0];
		for(int k = j-1; k >= 0; k--){
			summation -= matL[j][k] * vectorD[k];
		}
		vectorD[j] = summation/matL[j][j];//populating elements of vector D
	}

	//uses back substitution to solve Ux=D which consequently populates the column vector x
	for(int j = dimensions-1; j >= 0; j--){
		double summation = vectorD[j];
		for(int k = j+1; k < dimensions; k++){
			summation -= matU[j][k] * vectorX[k];
		}
		vectorX[j] = summation/matU[j][j];//populating elements of vector X
	}

	return vectorX;//returns column vector X (holds a computed column of A inverse)
}

/**
 * computes matrix inverse of matrix A. It does this by calling LU Decomposition function once and then it repeatedly calls the substitution function above
 * 
 * @param
 * int dimensions – variable holding the dimensions of square matrices A,L,U, and A^-1
 * double ** matA – holds a double pointer to a populated matrix A
 * double ** matL – holds a double pointer to a populated lower matrix
 * double ** matU – holds a double pointer to a populated upper matrix
 * double ** matInverse – holds a double pointer to a blank inverse matrix
 * 
 * @return returns a double pointer to the fully populated inverse matrix.
 */
double** getMatrixInverse(int dimensions, double **matA, double **matL, double **matU, double **matInverse){
	//first, LU decompose matrix A
	LU_Decomposition(dimensions, matA, matL, matU);

	//next, generate and print a local dynamic identity matrix that corresponds to the same dimensions of matrix A
	double **matIdentity = dynamicMatrixGenerator(dimensions, dimensions, matIdentity);
	for(int i = 0; i < dimensions; i++){
		matIdentity[i][i] = 1;
	}
	printMatrix(dimensions, dimensions, matIdentity, "STEP 3 : IDENTITY MATRIX:");

	//after, create pointer to a black array which will later hold the column elements of A^-1
	double* vectorX = new double [dimensions];

	// inverse matrix gets its blank elements populated column by column using nested for loops and by calling the substitution function above
	for(int i = 0; i < dimensions; i++){
		for(int a = 0; a < dimensions; a++){
			matInverse [a][i] = substitution(dimensions, i, matA, matL, matU, matIdentity, vectorX)[a];
		}
		cout << endl;
	}
	return matInverse;//returns a fully computed inverse matrix to matrix A
}
#endif