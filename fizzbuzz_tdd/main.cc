#include <gtest/gtest.h>
#include <iostream>
//#include <cstring>
using namespace std;

//YOU: Write fizzbuzz
//Return "Fizz" if x is divisible by 3
//Return "Buzz" if x is divisible by 5
//Return "Fizzbuzz" if x is divisible by both 3 and 5
//Return a string containing the number otherwise
//Return "Error" if x is less than 1 or greater than 100
string fizzbuzz(int x) {
	//This won't compile, since it's not returning anything - DONE?
	if (x >= 1 and x <= 100) {
		if ((x % 3 == 0) and (x % 5 == 0)) return "Fizzbuzz";
		else if (x % 3 == 0) return "Fizz";
		else if (x % 5 == 0) return "Buzz";
		else return to_string(x);
	}
		else return "Error";
		/*
		return ""; //Function stub: not correct, but will compile. 
		*/
}

//-NEED HELP 
//YOU: Write tests to test your fizzbuzz implementation
TEST(Fizzbuzz, GoodTests) {
	EXPECT_EQ(fizzbuzz(33), "Fizz"); //Expect the output to equal to Fizz 
	EXPECT_EQ(fizzbuzz(20), "Buzz");
	EXPECT_EQ(fizzbuzz(30), "Fizzbuzz");
	EXPECT_EQ(fizzbuzz(75), "");
	EXPECT_EQ(fizzbuzz(33), "Fizz");
}

//YOU: Write your own tests to check bad inputs here
TEST(Fizzbuzz, BadTests) {
	EXPECT_EQ(fizzbuzz(0), "Error");
	EXPECT_EQ(fizzbuzz(150), "Error");
	EXPECT_EQ(fizzbuzz(-15), "Error");
	EXPECT_EQ(fizzbuzz(100000), "Error");
	EXPECT_EQ(fizzbuzz(-123456), "Error");
}

//YOU: Write your own tests to check edge inputs here (CONSIDERED THE BOUNDARIES OF GOOD AND BAD CASES)
TEST(Fizzbuzz, EdgeTests) {
	EXPECT_EQ(fizzbuzz(3), "Fizz");
	EXPECT_EQ(fizzbuzz(30), "Fizzbuzz");
	EXPECT_EQ(fizzbuzz(101), "Error");
	EXPECT_EQ(fizzbuzz(-1), "Error");
	EXPECT_EQ(fizzbuzz(90), "Buzz");
}

//-NEED HELP
//YOU: Now write a function called fizzbuzz2, that is exactly the same as fizzbuzz, but with one important change.
//Before returning a number, add the digits of the number together, and use the result from that sum with the same
// rules. For example, 23 would return "Buzz" because 2+3 = 5. 
string fizzbuzz2(int x) {
	if (x >= 1 and x <= 100) {
		int tens = x / 10;
		int ones = x % 10;
		int total = tens + ones;
		if ((x % 3 == 0) and (x % 5 == 0)) return "Fizzbuzz";
		else if (x % 3 == 0) return "Fizz";
		else if (x % 5 == 0) return "Buzz";
		
		if ((total % 3 == 0) and (total % 5 == 0)) return "Fizzbuzz";
		else if (total % 3 == 0) return "Fizz";
		else if (total % 5 == 0) return "Buzz";
		else return to_string(x);
	}
	else return "Error"; /*
		return ""; //Function stub: not correct, but will compile. 
		*/
}

//-NEED HELP
//YOU: Now write good, bad, and edge cases for fizzbuzz2 as well.
//Testing for good cases
TEST(Fizzbuzz2, GoodTests) {
	EXPECT_EQ(fizzbuzz(33), "Fizz"); //Expect the output to equal to Fizz 
	EXPECT_EQ(fizzbuzz(20), "Buzz");
	EXPECT_EQ(fizzbuzz(30), "Fizzbuzz");
	EXPECT_EQ(fizzbuzz(75), "");
	EXPECT_EQ(fizzbuzz(3), "Fizz");
	EXPECT_EQ(fizzbuzz(20), "Buzz");
}

//Testing for bad cases
TEST(Fizzbuzz2, BadTests) {
	EXPECT_EQ(fizzbuzz(0), "Error");
	EXPECT_EQ(fizzbuzz(150), "Error");
	EXPECT_EQ(fizzbuzz(-15), "Error");
	EXPECT_EQ(fizzbuzz(100000), "Error");
	EXPECT_EQ(fizzbuzz(-123456), "Error");
}

//Testing for edge cases
TEST(Fizzbuzz2, EdgeTests) {
	EXPECT_EQ(fizzbuzz(3), "Fizz");
	EXPECT_EQ(fizzbuzz(1), "Fizzbuzz");
	EXPECT_EQ(fizzbuzz(10), "Buzz");
	EXPECT_EQ(fizzbuzz(-1), "Error");
	EXPECT_EQ(fizzbuzz(100000), "Error");
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
#ifndef FOO
	//Stop people from compiling this code using 'compile'
	static_assert(false,"Type 'make' to build this, not 'compile'");
#endif
	cout << "Welcome to Fizzbuzz 2000(tm). Choose one of the following options:\n";
	cout << "fizzbuzz   - will run fizzbuzz from 1 to 100.\n";
	cout << "fizzbuzz2  - will run fizzbuzz2 from 1 to 100.\n";
	cout << "(a number) - will run fizzbuzz and fizzbuzz2 on just that number.\n";
	cout << "test       - will run the test suite you've created.\n";
	string s;
	getline(cin,s);
	
//-NEED HELP
	if (s == "test") return RUN_ALL_TESTS(); 
	else if (s == "fizzbuzz") {
		//YOU: Write code that will output the result of the fizzbuzz function from 1 to 100 here:

		for (int i = 0; i < 100; i++) {
			cout << fizzbuzz(i + 1) << endl;

		}
	
	}
	else if (s == "fizzbuzz2") {
		//YOU: Write code that will output the result of the fizzbuzz2 function from 1 to 100 here:
		
		for (int i = 0; i < 100; i++) {
			cout << fizzbuzz2(i + 1) << endl;
		}
	}
	else { //Just a number, so feed it to each function and output the result
		int x = stoi(s);
		cout << "Fizzbuzz (" << x << ") = " << fizzbuzz (x) << endl;
		cout << "Fizzbuzz2(" << x << ") = " << fizzbuzz2(x) << endl;
	}
}
