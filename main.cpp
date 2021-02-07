#include <iostream>
#include "ELEC2110CAA.h"
//importing header files and libraries which are not already imported in the header file


int main() {
	//MAIN CONTROL FLOW STRUCTURE  WHICH ALSO GOVERNS THE USER INTERFACE/PROGRAM INTERACTION  
	//switches through the user's choice picked through getOperation()
	switch (getOperation()){
		case 1:{
			printf("\n___________________________________\n\nYou chose matrix addition (A + B)\n___________________________________\n");

			int m, n;//dimensions for both matrices
			getDimensions(m, n, "both matrix A and B");
			
			//dynamically generating the matrices below (read matrix variable names to identify each matrix)
			double** matA = dynamicMatrixGenerator(m, n, matA);
			double** matB = dynamicMatrixGenerator(m, n, matB);
			double** matSum = dynamicMatrixGenerator(m, n, matSum);

			//populating matrix a and b w/ user input
			populateMatrix(m, n, matA, "matrix A");
			populateMatrix(m, n, matB, "matrix B");
			
			//Printing the solution after receiving the returned calculated solution matrix from the sum()
			printMatrix(m, n, sum(m, n, matA, matB, matSum), "THE SUMMATION OF THE TWO MATRICES IS: ");

		break;
		}case 2:{
			printf("\n___________________________________\n\nYou chose matrix subtraction (A - B)\n___________________________________\n");

			int m, n;//dimensions for both matrices
			getDimensions(m, n, "both matrix A and B");
			
			//dynamically generating the matrices below (read matrix variable names to identify each matrix)
			double** matA = dynamicMatrixGenerator(m, n, matA);
			double** matB = dynamicMatrixGenerator(m, n, matB);
			double** matDiff = dynamicMatrixGenerator(m, n, matDiff);

			//populating matrix a and b w/ user input
			populateMatrix(m, n, matA, "matrix A");
			populateMatrix(m, n, matB, "matrix B");

			//Printing the solution after receiving the returned calculated solution matrix from the difference()
			printMatrix(m, n, difference(m, n, matA, matB, matDiff), "THE DIFFERENCE BETWEEN THE TWO MATRICES IS: ");

		break;
		}case 3:{
			printf("\n___________________________________\n\nYou chose matrix multiplication (A*B)\n___________________________________\n");

			int m, n;//dimensions for matrix A
			int p, q;//dimensions for matrix B
			
			do{//getting valid matrix dimensions for matrix multiplication from the user
				(n != p) ? cout << "\n\nERROR: The # of columns of matA and the # of rows of matB are not equal!\nTRY AGAIN...\n\n": cout << "";
				getDimensions(m, n, "Matrix A");
				getDimensions(p, q, "Matrix B");
			}while(n != p);
			
			//dynamically generating the matrices below (read matrix variable names to identify each matrix)
			double** matA = dynamicMatrixGenerator(m, n, matA);
			double** matB = dynamicMatrixGenerator(p, q, matB);
			double** matProd = dynamicMatrixGenerator(m, q, matProd);

			//populating matrix a and b w/ user input
			populateMatrix(m, n, matA, "matrix A");
			populateMatrix(p, q, matB, "matrix B");

			//Printing the solution after receiving the returned calculated solution matrix from the multiply()
			printMatrix(m, q, multiply(m, q, p, matA, matB, matProd), "THE PRODUCT OF THE TWO MATRICES IS: ");
			
		break;
		}case 4:{
			printf("\n___________________________________\n\nYou chose to find the solution to Ax=b (find vector x)\n___________________________________\n");
			
			int m, n;//dimensions for both matrices
			getDimensions(m, n,"", true);
			
			//dynamically generating the matrices below (read matrix variable names to identify each matrix)
			double** matA = dynamicMatrixGenerator(m, n, matA);
			double** vectorB = dynamicMatrixGenerator(m, 1, vectorB);
			// dynamically create the custom augumented matrix with one extra column for vector B [matA | vectorB]
			double** augumented = new double*[m];
			for(int i = 0; i < m+1; i++)
				augumented[i] = new double [m+1];
			
			//populating matrix a and vector b w/ user input
			populateMatrix(m, n, matA, "Matrix A");
			populateMatrix(m, 1, vectorB, "Vector B");

			//Doing gaussian elimination and then printing out the solution vector x  
			solution(m, matA, vectorB, augumented);
		break;
		}case 5:{
			printf("\n___________________________________\n\nYou chose to find the inverse of a matrix (A^-1)\n___________________________________\n");

			int m, n;//dimensions for both matrices 
			getDimensions(m, n, "Matrix A", true);// (m == n) therefore true
			
			//dynamically generating the matrices below (read matrix variable names to identify each matrix)
			double** matA = dynamicMatrixGenerator(m, n, matA);
			double** matL = dynamicMatrixGenerator(m, m, matL);
			double** matU = dynamicMatrixGenerator(m, m, matU);
			double** matInverse = dynamicMatrixGenerator(m, m, matInverse);

			//populating matrix a w/ user input
			populateMatrix(m, n, matA, "Matrix A");

			//Printing the solution after receiving the returned calculated inverse matrix from getMatrixInverse()
			printMatrix(m, m, getMatrixInverse(m, matA, matL, matU, matInverse), "SOLUTION : THE MATRIX INVERSE IS: ");
		break;
		}
	}//end switch
}//end main