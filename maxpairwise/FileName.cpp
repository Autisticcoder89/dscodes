#include<iostream>
#include<vector>
using namespace std;
double maxpairwise(vector<int>n) {
	double p = 0;
	for (int i = 0; i < n.size(); i++) {//the time complexity increses to n2
		for (int j = +1; i < n.size(); i++) {
			//if we start the index from j=i or 0 we will get duplicate pairs too
			if ((double)(n[i] * n[j]) > p) {
				p = n[i] * n[j];
			}

		}
	}
	return p;
}
void maxpairwisefast(vector<int>n) {//cant sort the array and place first largest at the last number because of n2
	int n_firstlar = 0;
	for (int j = 1; j < n.size(); j++) {
		if (n[j] > n[n_firstlar ]) {
			n_firstlar = j;
		}
	}
	cout << n[n_firstlar];

	int n_secondlar = 0;
	for (int j = 1; j < n.size(); j++) {
		if (n[j] > n[n_secondlar] && n[j]!=n[n_firstlar]) {
			n_secondlar= j;
		}
	}
	cout << n[n_secondlar];

}




int main() {
	int n;
	cout << "how many numbers do you want to enter";
	cin >> n;
	vector <int> number(n);
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	maxpairwise(number);
	return 0;

}