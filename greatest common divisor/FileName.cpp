#include<iostream>
#include<vector>
using namespace std;
int greatest_common_divisor(vector<int>n) {
	int a=n[0];
	int b = n[1];
	int smallest;
	int gcd=0;
	if (a < b) {
		smallest = a;

	}
	else {
		smallest = b;
	}
	for (int i = 1; i <=smallest; i++) {//common divisor is always gonna be smaller or equal to smallest number
		if (a % i == 0 && b % i == 0 ) {
			gcd = i;//updates the value
		}
			
		
	}
	return gcd;
}
//more efficient test
//euclidean theorem
int greatest_common_divisor2(int a,int b) {
	int remainder = 0;
	while (b != 0) {
		a = b;
		
		b = remainder;
		greatest_common_divisor2(a, b);

	}
	return a;



}







int main() {
	int n=2;
	vector <int> numbers(n);
	cout << "enter two numbers you want to find greatest common divisor of";
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	cout << greatest_common_divisor(numbers) << endl;
	cout << greatest_common_divisor2(numbers[0], numbers[1]) << endl;
	return 0;
	
}