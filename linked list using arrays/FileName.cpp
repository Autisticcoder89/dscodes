
#include<iostream>
using namespace std;
void display_array(int arr[], int &count) {
	for (int i = 0; i < count; i++) {
		cout << arr[i] << " ";
	}
}
void insertstart(int arr[], int element, int &count) {//passing by reference so that the count is updated in the main
	for (int i = count; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = element;
	count++;
}
void insertioninthemiddle(int arr[], int element, int& count,int pos) {
		for (int i = count; i >=pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos] = element;
		count++;

	
}

void insertatend(int arr[], int element, int& count) {
	arr[count] = element;
	count++;
}

void delete_array(int arr[],  int& count) {
	for (int i = 0; i < count-1; i++) {
		arr[i] = arr[i + 1];

	}
	count--;
}
void delete_end(int arr[], int& count) {

}
int main() {
	int count = 8;
	int i = 0;
	int arr[19] = { 1,2,3,4,5,6,7,8 };
	cout << "displaying the original array";
	display_array(arr, count);
	cout << endl;
	//cout << "inserting at the start if an array:" << endl;/]
	//insertstart(arr, 6, count);

	//display_array(arr, count);
	cout << endl;
	//cout << "inserting at the end of the array:" << endl;
	//insertatend(arr, 56, count);
	//display_array(arr, count);
	//cout<<endl;
	//cout<<inserting in the middle;
	//insertioninthemiddle(arr,45,count,4);
	//display_array(arr, count);
	cout << endl;
	cout << "deleting the array:";
	delete_array(arr,count);
	display_array(arr, count);
	cout << endl;
	cout << "deleting from the end";
	delete_end(arr, count);
	


}


