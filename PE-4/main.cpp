
/****************************************************************************
 * Project Euler - Problem 1                                                *
 *                                                                          *
 * Description: A palindromic number reads the same both ways. The largest	*
 *   palindrome made from the product of two 2-digit numbers is				*
 *	9009 = 91 × 99. Find the largest palindrome made from the product of    *
 *	two 3-digit numbers.													*
 *                                                                          *
 * Written by: Kyle Williams @ 23 Dec 2015                                  *
 ****************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int getDigit(int, int);

int main() {
	vector<int> palindromes;
	int largest = 0;

	for (int x = 999; x >= 100; x--) {
		for (int y = 999; y >= 100; y--) {
			if (getDigit(x*y, 6) == getDigit(x*y, 1) && getDigit(x*y, 5) == getDigit(x*y, 2) && getDigit(x*y, 4) == getDigit(x*y, 3)) {
				palindromes.push_back(x*y);
			}
		}
	}

	for (vector<int>::iterator it = palindromes.begin(); it != palindromes.end(); it++) {
		if (*it > largest) {
			largest = *it;
		}
	}
	
	cout << "largest palindrome made from the product of two 3-digit numbers: " << largest;
	cin.get();
}

int getDigit(int num, int powTen) {
	int digit = 0;
	
	for (int i = 0; i < powTen; i++) {
		digit = num % 10;
		num = num / 10;
	}

	return digit;
}