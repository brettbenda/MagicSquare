#include "pa1.h"
//pa1.h contains the necessary libraries and the methods used by main


//MAIN METHOD
int main(){
	
	//variables
	int n = 0; //real side length
	double k = 0; //user input
	int s = 0; //expected row/column/diagonal sum
	int i = 0; //counter var for loops
	int j = 0; //counter var for loops
	
	//ask for input and check that it is valid
	while(/*k < 3 || k > 15 ||*/ (int)k%2==0){	
		cout <<"Enter the size of a magic square:";
		cin >> k;
		
		//check for text
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			k=0;
		}
		
		//check for if not int
		if(fmod(k,1) != 0){
			k=0;
		}
	
		//check for not between 3 and 15 or if even
		if(k < 3 || k > 15 || (int)k%2==0){
			cout << "ERROR: The size must be an odd integer between 3 and 15" << endl;
		}
    }
    
    //after k is determined to be valid, set int n = to the double k
    n = k;
    
    //calculate total sum based off input
    while(i <= n*n){
		s += i;
		i++;
	}
	s = (s/n);
	
    
    //declare squares and pointers  
    int **s1 = new int*[n];
    int **s2 = new int*[n];
    int **s3 = new int*[n];
    for(int i=0; i<n; i++){
		s1[i]= new int[n];
		s2[i]= new int[n];
		s3[i]= new int[n];
	}
    
    //set base values
    i=0; 
    j=0;
    while(j<n){
		while(i<n){
			s1[i][j] = 0;
			s2[i][j] = 0;
			s3[i][j] = 0;
			i++;	
		}
		j++;
		i=0;
	}
	
	//MAKE S1
	//Use populate function to create first magic square
	s1 = populate(s1, n, s);
	cout << "Magic Square #1 is: " << endl;
	//print s1
	printSquare(s1, n);
	//check and print sums for s1
	checkRow(s1, s, n);
	checkColumn(s1, s, n);
	checkDiagonal(s1, s, n);
	cout << "" << endl;
	
	
	//MAKE S2
	//modify s1 to make s2
	s2 = yFlip(s1, n);
	cout << "Magic Square #2 is: " << endl;
	//print s2
	j=0;
	i=0;
	printSquare(s2,n);
	//check and print sums for s2
	checkRow(s2, s, n);
	checkColumn(s2, s, n);
	checkDiagonal(s2, s, n);
	cout << "" << endl;
	
	
	//MAKE S3
	//modify s2 to make s3
	s3 = xFlip(s2, n);
	cout << "Magic Square #3 is: " << endl;
	//print s3
	printSquare(s3, n);
	//check and print sums for s3
	checkRow(s3, s, n);
	checkColumn(s3, s, n);
	checkDiagonal(s3, s, n);
	cout << "" << endl;
    
    return 0;
}
