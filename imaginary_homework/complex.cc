#include <iostream>
#include "complex.h"
#include "imaginary.h"
using namespace std;

//Class definition file for Complex

//YOU: Fill in all of these functions
//There are stubs (fake functions) in there now so that it will compile
//The stubs should be removed and replaced with your own code.

Complex::Complex() {
}

Complex::Complex(int new_real, Imaginary new_imagine) : real(new_real), imagine(new_imagine) { //Object that contains a real and imaginary. References the imaginary class. 

}

Complex Complex::operator+(const Complex &rhs) {
	//Complex()
	int result_real = rhs.real + real; //Adds the rhs real and the real #. 2 2i + 3 5i = Adds 2 and 3. 
	Imaginary result_imaginary = rhs.imagine + imagine; //Adds the rhs imaginary and the imaginary #. 2 2i + 3 5i = Adds 2i and 5i = 7i. 
	return Complex(result_real, result_imaginary);
}

Complex Complex::operator-(const Complex &rhs) {
	int result_real = real - rhs.real;
	Imaginary result_imaginary = rhs.imagine - imagine;
	return Complex(result_real, result_imaginary);
}

Complex Complex::operator*(const Complex &rhs) {
	int first = rhs.real * real;
	Imaginary outer = rhs.imagine * real;
	Imaginary inner = imagine * rhs.real; 
	int last = rhs.imagine * imagine;
	return Complex(first + last, inner + outer);
}

bool Complex::operator==(const Complex &rhs) {
	return ((real == rhs.real) && (imagine == rhs.imagine));
}
 
Complex Complex::operator^(const int &exponent) {
	Complex temp = (*this); //this -> referencing to the complex expression. Ex- 2 + 2i
	for (int i = 0; i < exponent - 1; i++) {
		temp = temp * (*this); 
		//Had it as temp = temp + (*this * *this)
	}
	return temp;
}

//This function should output 3+5i for Complex(3,5), etc.
ostream& operator<<(ostream &lhs,const Complex& rhs) {
	//Output a Complex here
	lhs << rhs.real; //Outputs real numbers
	lhs << rhs.imagine; //Outputs imaginary numbers
	return lhs; //Outputs left hand side
}

//This function should read in two ints, and construct a 
// new Complex with those two ints
istream& operator>>(istream &lhs, Complex& rhs) {
	//Read in a Complex here
	//First three lines are temporaries. 
	int real = 0; //Real #'s
	Imaginary i; //Imaginaries
	lhs >> real >> i; 
	if (!lhs) {
		cout << "-1" << endl;
		exit(0);
	}
	rhs.real = real;
	rhs.imagine = i;
	return lhs; //Returns the variables
}
