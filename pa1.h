#include <iostream>
#include <cmath>


using namespace std;

//METHODS USED BY MAIN FOR CREATING/CHECKING MAGIC SQUARES

//This method creates a magic square using the Siamese method.
int** populate(int** array, int size, int sum){
	//variables needed for "Siamese method" of generating magic squares
	int i = size-1;
	int j = (size/2);
	int l = 1;
	
	//generate square using "Siamese method"
	while(l <=size*size){
		//check for values of i and j that would produce errors in setting array and adjust values as necessay
		if(j==-1 && i==size){
			i = size-2;
			cout<<"!"<<endl;
			j = 0;
		}else{
			if(j<0){
				j=size-1;
			}
			if(i==size){
				i=0;
			}
		}
		
		//check that array[i][j] is not already filled, as per the "Siamese method", and adjust
		if(array[i][j] != 0){
			i = i-2;
			j++;
			continue;
		}else{
			//if value is [i][j] is 0, then set [i][j] to next highest int
			array[i][j] = l;
			l++;
		}
		i++;
		j--;
	}
	//return filled array
	return array;
}

//This method takes in a magic square array and prints the sum of the rows.
void checkRow(int** array, int sum, int size){
	int i = 0;
	int j = 0;
	int s = 0;
	cout<< "Checking the sums of every row: \t";
	while(i<size){
		while(j<size){
			s+=array[i][j];
			j++;
		}
		cout << s << " ";
		i++;
		j=0;
		s=0;
	}
	cout<< "" << endl;
}

//This method takes in a magic square array and prints the sum of the columns.
void checkColumn(int** array, int sum, int size){
	int i = 0;
	int j = 0;
	int s = 0;
	cout<< "Checking the sums of every column: \t";
	while(j<size){
		while(i<size){
			s+=array[i][j];
			i++;
		}
		cout << s << " ";
		j++;
		i=0;
		s=0;
	}
	cout<< "" << endl;
}

//This method takes in a magic square array and prints the sum of the diagonals.
void checkDiagonal(int** array, int sum, int size){
	int i = 0;
	int j = 0;
	int s = 0;
	cout << "Checking the sums of every diagonal: \t";
	while(i<size){
		while(j<size){
			s += array[i][j];
			j++;
			i++;
		}
	}
	cout << s << " ";
	
	i=size-1;
	j=0;
	s=0;
	
	while(i>=0){
		while(j<size){
			s+= array[i][j];
			j++;
			i--;
		}
	}
	cout << s << endl;	
}

//This method flips the array over the "y" axis to produce a new magic square.
int** yFlip(int** array, int size){
	int i = 0;
	int j = 0;
	int temp;
	while(i<(size)){
		while(j<size/2){
			temp = array[i][j];
			array[i][j] = array[i][size-j-1];
			array[i][size-j-1] = temp;
			j++;
		}
		i++;
		j=0;
	}
	return array;
}

//This method flips the array over the "x" axis to produce a new magic square.
int** xFlip(int** array, int size){
	int i = 0;
	int j = 0;
	int temp;
	while(j<(size)){
		while(i<size/2){
			temp = array[i][j];
			array[i][j] = array[size-i-1][j];
			array[size-i-1][j] = temp;
			i++;
		}
		j++;
		i=0;
	}
	return array;
}

//This methos takes in and the prints out a 2d array
void printSquare(int** array, int size){
	int j=0;
	int i=0;
	while(i < size){
		while(j < size){
			cout << array[i][j] << "\t";
			j++;
		}
		cout << ""<< endl;
		i++;
		j=0;
	}
}

