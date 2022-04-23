#include <iostream>

void reverse_rowsMatrix ( int** matrix , int size ){
	int* tmp = nullptr;
	for ( int i = 0 ; i < size ; i++ ){
		tmp = matrix[i];
		matrix[i] = matrix[size-1-i]; 
		matrix[size-1 -i] = tmp;
	}
}


void print_reverseMatrix ( int** matrix , int size ){
	int temp{};

	for ( int i = 0 ; i < size/2 + size % 2 ; i++ ){
		for ( int j = 0 ; j < ((i == size/2)? size/2 : size)  ; j++ ){
			temp = matrix [i][j];
			matrix [i][j] = matrix [size - i - 1][size - 1 - j];
			matrix[size - i - 1][size  - 1 - j] = temp;
		}
	}
}

void print_diagonals ( int** matrix , int i , int j ){
	std::cout << "Main diagonal elements are: ";
	for ( int k = 0 ; k < i ; k++ ){
		std::cout << matrix [k][k];
	}

	std::cout << std::endl;
	std::cout << "Secondary diagonal elements are: ";
	for ( int k = 0 ; k < i ; k++ ){
		std::cout << matrix[i-k-1][k];
	}	
}

int* elems_to_singleArray ( int** matrix , int i , int j ) {
	int size = i * j ;
	int pos{};
	int* arr = new int [size]; 
	for ( int k = 0 ; k < i ; k ++ ){
		for ( int x = 0 ; x < j ; x++ ){
			arr[pos] = matrix[k][x];
			pos++;
		}
	}	

	return arr;
}

void print_matrix( int** matrix , int i , int j ){
	for( int k = 0; k < i ; k++ ){
		std::cout << std::endl;
		for( int x = 0; x < j ; x++ ){
			std::cout << *(*( matrix + k ) + x ) << " ";
		}
	}
}

void delete_matrix(int** matrix,int i){
	for ( int k = 0; k < i ; k++ ){
		delete[] matrix[k];
	}
	delete[] matrix;
	matrix = nullptr;
}

void input_matrix( int** matrix , int i , int j ) {
	for ( int k = 0 ; k  <  i ; k++ ){
		matrix [k] = new int [j];
	}

	for ( int k  = 0 ; k < i ; k++ ){
		for ( int x = 0 ; x < j ; x++ ){
			std::cout << "Enter the value of element: ";
			std::cin >> *(*(matrix + k) + x );
		}
	}	
}

int main(){
	int i{};
	int j{};
	std::cout << "Enter row: ";
	std::cin >> i;
	j = i;
	int** matrix = new int*[i];
	input_matrix( matrix , i , j );	
	print_matrix( matrix , i , j );
	std::cout << std::endl;
	elems_to_singleArray ( matrix , i , j );
	print_diagonals ( matrix, i , j );
	std::cout << std::endl;
	print_reverseMatrix ( matrix , i );
	print_matrix ( matrix , i , j);
	std::cout << std::endl;
	reverse_rowsMatrix ( matrix, i);
	print_matrix ( matrix , i , j);
	delete_matrix ( matrix , i);
}
