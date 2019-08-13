#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main() 
{

	int size = 2;					// initial size of array
	int *arr = new int[size];		// creation of dynamic array
	char option;
	int element;
	int count = 0;					// counts how many elements are in the array (not including initial values of 0)

	for (int i = 0; i < size; ++i)
		arr[i] = 0;					// fills array with 0's
	
	do 
	{
		cout << "\n(p): Print elements" << endl;	//
		cout << "(a): Add element" << endl;			//
		cout << "(d): Delete element" << endl;		//
		cout << "(r): Return size" << endl;			//		menu
		cout << "(e): Exit" << endl;				//
		cout << "\nEnter Option: ";					//
		cin >> option;								//

		if (option == 'p')
		{
			if (count == 0) {
				cout << "No elements" << endl;		//if array is empty, print "no elements"
			}
			
			else {
				for (int i = 0; i < count; ++i)
					if (i == count - 1) {
						cout << arr[i] << endl;		//if last element in the array, print value w/out comma
						continue;
					}
					else {
						cout << arr[i] << ", ";		//print "value, "
					}
			}
		}

		else if (option == 'a') {
			cout << "Enter element: ";
			cin >> element;

			if (count < size) {
				arr[count] = element;			//if theres open space within the array, add value and increase count
				++count;
			}
			
			else {
				size = size * 2;
				int *tempArr = new int[size]; // creates new temp array
				for (int i = 0; i < size; ++i)
					tempArr[i] = 0;					//assigns '0' to all indexes past size of previous array
				for (int i = 0; i < size; ++i)
					tempArr[i] = arr[i];			//copies values from arr to tempArr
				delete[] arr;			// deallocation of arr
				arr = new int[size];//increases size value
				arr = tempArr;
				arr[count] = element;	//assigns newest element to the next open index
				++count;				//increases counter
				cout << "Array Expanded" << endl;
			}
			cout << endl;
		}

		else if (option == 'd') {
			cout << "Enter Element:";
			cin >> element;
			for (int i = 0; i < count; i++)
			{
				if (element != arr[i]) {
					if (i == count - 1) {								// if the user enters value currently stored in the array,
						cout << "Not there" << endl;
					}
				}
				else
				{
					arr[i] = 0;				  //  it will change the value to 0
					break;
				}
			}
			for (int i = 0; i < count; i++)
			{
				if (arr[i] == 0) {
					arr[i] = arr[i + 1];		// moves value of 0 to the end of the array
					arr[i + 1] = 0;
				}
			}
			count--;							// decreases value of count
			if (count == size / 2) {
				size = size / 2;
				int *tempArr = new int[size]; // creates new temp array
				for (int i = 0; i < size; ++i)
					tempArr[i] = 0;					//assigns '0' to all indexes of new array
				for (int i = 0; i < size; ++i)
					tempArr[i] = arr[i];			//copies values from arr to tempArr
				delete[] arr;// deallocation of arr
				arr = new int[size];
				arr = tempArr;			// copies temp array to arr
				cout << "Array Shrunk" << endl;
			}
		}

		else if (option == 'r') 
		{
			cout << "S: " << size << ", E: " << count << endl;
		}

		else if (option == 'e') 
		{
			delete[] arr;
			break;
		}

	} while (option != 'e');

	system("pause");
	return 0;
}