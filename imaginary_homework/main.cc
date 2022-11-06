#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include "imaginary.h"
#include "complex.h"
//YOU: include the header file for complex numbers

using namespace std;

int main() {
	//cout << boolaplha; //Print "true" instead of "1" when outputting bools
	//Imaginary i,j; //These three lines are test code, delete them later
	//cin >> i >> j; //Read two Imaginaries in - won't work till cstors (constructors) are done
	
	while (true) {
		//YOU: Read in a complex number
		Complex x,y; //First object =first Int and imaginary. Second = second int and imaginary. 
		/* Example
		2 2i + 3 5i 
		x = 2 2i
		*/
		//int rx = 0, ix = 0, ry = 0, iy = 0;
		string s, line;
		getline(cin, line);
		stringstream ss(line);
		//const char test17 = '\n';
		//ss >> x >> s >> y;
		ss >> x;	
		if (!ss) {
			cout << "-1\n";
			exit(EXIT_SUCCESS);
		}
		/*
		if (!cin) {
			cout << "-1\n";
			exit(EXIT_SUCCESS);
		}
		//If input is 0 0, exit	
		*/
		else if (x == Complex(0,0)) exit(EXIT_SUCCESS);

		else {	
			//YOU: Read in an operator (+,-,*,==,or ^)
			ss >> s;
		
			if (s == "+") { //Addition
				ss >> y;
				cout << (x) + (y) << endl;
				//break;
			}

			else if (s == "-") { //Subtraction
				ss >> y;
				cout << (x) - (y) << endl;
				//break;
			}
		
			else if (s == "*") { //Multiplication
				ss >> y;
				cout << (x) * (y) << endl;
				//break;
			}
			
			else if (s == "^") { //Exponentiation
				int exponent;
				ss >> exponent;
				cout << (x ^ exponent) << endl;
				//break;
			}

			else if (s == "==") {
				ss >> y;
				if (x == y) cout << "true\n";
				else cout << "false\n";
			} 
			else {
				cout << "-1\n";
				exit(EXIT_SUCCESS);
			}
		}

		//YOU: Read in the second operand (another complex or an int)
		//YOU: Output the result
	}
}
