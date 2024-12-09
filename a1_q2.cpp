// Write a C program to calculate the LCM and HCF of two numbers.

#include <iostream>
using namespace std;

int lcm(int num1, int num2) {
	static int lowestCommonMultiple = 1;
	if(lowestCommonMultiple%num1 == 0 && lowestCommonMultiple%num2 == 0) {
		return lowestCommonMultiple;
	} else {
		lowestCommonMultiple++;
		lcm(num1,num2);
		return lowestCommonMultiple;
	}
}

int main() {
	int num1,num2;
	cout << "num1: ";
	cin >> num1;
	cout << "num2: ";
	cin >> num2;
	
	int lcm_result = lcm(num1, num2);
	int hcf_result = 0;
	
	cout << "Result (LCM): " << lcm_result << endl;
	cout << "Result (HCF): " << hcf_result;
	
};