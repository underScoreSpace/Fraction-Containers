//Alexis Martinez
//06-05-2023
//Exam 3
#include <iostream>
#include "input.h"
#include "Rational.h"
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

void menuText();
char menuOption();
void vectorCase();
void listCase();
void stackCase();
void queueCase();
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
	do {
		system("cls");
		menuText();
		switch (menuOption()) {
		case 'V': vectorCase(); break;
		case 'L': listCase(); break;
		case 'S': stackCase(); break;
		case 'Q': queueCase(); break;
		case 'X': return EXIT_SUCCESS; break;
		}

		cout << "\n\n\t";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//PreCondition: None
//PostCondition: Displays main menu and returns a char
char menuOption() {
	cout << "\n\tCMPR121 Exam 3: STL (Standard Template Library) Containers and Container Adaptors by Alexis Martinez";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tV. Vector Container";
	cout << "\n\t\tL. List Container";
	cout << "\n\t\tS. Stack Container Adaptor";
	cout << "\n\t\tQ. Queue Container Adaptor";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\tX. Exit";
	cout << "\n\t" << string(100, char(205));

	return inputChar("\n\t\tOption: ", static_cast<string>("VLSQX"));
}

//PreCondition: None
//PostCondition: Displays vector sub menu text
void vectorText() {
	SetConsoleTextAttribute(color, 12);
	cout << "\n\tVectors are same as dynamic arrays with the ability to resize itself automatically when an";
	cout << "\n\telement is inserted or deleted, with their storage being handled automatically by the container.";
	cout << "\n\tVector elements are placed in  contiguous storage so that they can be accessed and traversed";
	cout << "\n\tusing iterators or indexes.";
	cout << endl;
	SetConsoleTextAttribute(color, 7);
}

//PreCondition: None
//PostCondition: Displays Vector option menu and returns integer value
int vectorMenu() {
	cout << "\n\t\tVector Menu Options";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t\t1. Add an element to the back";
	cout << "\n\t\t2. Insert an element at an index";
	cout << "\n\t\t3. Retrieve an element at an index";
	cout << "\n\t\t4. Erase element(s)";
	cout << "\n\t\t5. Sort the elements in ascending order";
	cout << "\n\t\t6. Clear all elements";
	cout << "\n\t" << string(90, char(196));
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(90, char(205));

	return inputInteger("\n\t\tOption: ", 0, 6);
}

//PreCondition: None 
//PostCondition: Runs vector opertains depending on option from menu
void vectorCase() {

	vector<Rational> myVector;

	do {
		system("cls");
		vectorText();

		if (myVector.empty()) {
			cout << "\n\tThe current vector is empty.";
		}
		else {
			cout << "\n\tThe current vector contains " << myVector.size() << " element: \n";

			cout << "\t\t";
			if (myVector.size() > 0) {
				cout << char(218) << string(4, char(196));
				for (int i = 1; i < myVector.size(); i++) {
					cout << char(194) << string(4, char(196));
				}
				cout << char(191) << endl;


				if (myVector[0].getDenominator() < 0 || myVector[0].getNumerator() < 0)
					cout << "\t\t" << char(179) << myVector[0];
				else {
					cout << "\t\t" << char(179) << " " << myVector[0];
				}
				for (int i = 1; i < myVector.size(); i++) {
					if (myVector[i].getDenominator() < 0 || myVector[i].getNumerator() < 0)
						cout << char(179) << myVector[i];
					else {
						cout << char(179) << " " << myVector[i];
					}
				}
				cout << char(179) << endl;

				cout << "\t\t" << char(192) << string(4, char(196));
				for (int i = 1; i < myVector.size(); i++) {
					cout << char(193) << string(4, char(196));
				}
				cout << char(217) << endl;
			}


			cout << "\tindex:  ";
			for (int i = 0; i < myVector.size(); i++) {
				cout << i << "    ";
			}
			cout << "\n\taddress: " << &myVector.back();
		}
		cout << endl;

		switch (vectorMenu()) {
		case 0: return; break;
		case 1:
			try
			{
				Rational fraction;
				cout << "\n\t\tInput a Rational number to be added...";
				cout << endl;

				fraction.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
				fraction.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));



				cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
				if (fraction.getNumerator() < 0 || fraction.getDenominator() < 0)
					cout << "\n\t\t" << char(179) << fraction << char(179) << " will be added to the back of the vector.";
				else
					cout << "\n\t\t" << char(179) << " " << fraction << char(179) << " will be added to the back of the vector.";
				cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

				myVector.push_back(fraction);

			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
			}

			break;

		case 2:
			try {
				Rational fraction2;
				if (myVector.size() == 0) {
					cout << "\n\t\tInput a Rational number to be inserted...";
					cout << endl;

					fraction2.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
					fraction2.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));

					cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
					if (fraction2.getNumerator() < 0 || fraction2.getDenominator() < 0)
						cout << "\n\t\t" << char(179) << fraction2 << char(179) << " will be inserted at index 0 to the vector.";
					else
						cout << "\n\t\t" << char(179) << " " << fraction2 << char(179) << " will be inserted at index 0 to the vector.";
					cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

					myVector.insert(myVector.end(), fraction2);
				}
				else {
					cout << "\n\t\tInput a Rational number to be inserted...";
					cout << endl;

					fraction2.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
					fraction2.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));
					cout << "\n\t\tInsert the element at index (0..." << myVector.size() - 1 << ")";
					int upperBound = myVector.size() - 1;
					int index = inputInteger(" of the vector: ", 0, upperBound);

					cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
					if (fraction2.getNumerator() < 0 || fraction2.getDenominator() < 0)
						cout << "\n\t\t" << char(179) << fraction2 << char(179) << " will be inserted at index " << index << " to the vector.";
					else
						cout << "\n\t\t" << char(179) << " " << fraction2 << char(179) << " will be inserted at index " << index << " to the vector.";
					cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

					myVector.insert(myVector.begin() + index, fraction2);

				}
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
			}
			break;
		case 3:
			if (myVector.empty()) {
				cout << "\n\t\tRetrieve operation cannot be performed from an empty vector.";
			}
			else {
				cout << "\n\t\tEnter an index (0..." << myVector.size() - 1 << ") of Rational number ";
				int upperBound = myVector.size() - 1;
				int index = inputInteger("to be retrieved: ", 0, upperBound);

				cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
				if (myVector.at(index).getNumerator() < 0 || myVector.at(index).getDenominator() < 0)
					cout << "\n\t\t" << char(179) << myVector.at(index) << char(179) << " is located at index " << index << " from the vector.";
				else
					cout << "\n\t\t" << char(179) << " " << myVector.at(index) << char(179) << " is located at index " << index << " from the vector.";
				cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
			}
			break;
		case 4:
			if (myVector.empty()) {
				cout << "\n\t\tErase operation cannot be performed on an empty vector.";
			}
			else {
				try {
					Rational fractionToDelete;
					cout << "\n\t\tInput a Rational number to be removed...";
					cout << endl;

					fractionToDelete.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
					fractionToDelete.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));

					auto it = find(myVector.begin(), myVector.end(), fractionToDelete);

					if (it != myVector.end()) {
						char choice = inputChar("\n\t\tDo you want to remove (O-one or A-all) element(s): ", static_cast<string>("OA"));
						if (choice == 'O') {
							myVector.erase(it);

							cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
							if (fractionToDelete.getNumerator() < 0 || fractionToDelete.getDenominator() < 0)
								cout << "\n\t\t" << char(179) << fractionToDelete << char(179) << " will be removed once from the vector.";
							else
								cout << "\n\t\t" << char(179) << " " << fractionToDelete << char(179) << " will be removed once from the vector.";
							cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

						}
						else if (choice == 'A') {
							while (it != myVector.end()) {
								if (*it == fractionToDelete)
									it = myVector.erase(it);
								else
									it++;
							}
							cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
							if (fractionToDelete.getNumerator() < 0 || fractionToDelete.getDenominator() < 0)
								cout << "\n\t\t" << char(179) << fractionToDelete << char(179) << " will be removed from the vector.";
							else
								cout << "\n\t\t" << char(179) << " " << fractionToDelete << char(179) << " will be removed from the vector.";
							cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
						}


					}
					else {
						cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
						if (fractionToDelete.getNumerator() < 0 || fractionToDelete.getDenominator() < 0)
							cout << "\n\t\t" << char(179) << fractionToDelete << char(179) << " cannot be found from the vector.";
						else
							cout << "\n\t\t" << char(179) << " " << fractionToDelete << char(179) << " cannot be found from the vector.";
						cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
					}
				}

				catch (Rational::ZeroDenominator& e) {
					cout << "\n\t\tEXCEPTIONAL ERROR: Cannot delete a Rational number, " << e.toString() << ", with a zero denominator value.";
				}
			}
			break;

		case 5:
			if (myVector.empty()) {
				cout << "\n\t\tSort operation cannot be performed on an empty vector.";
			}
			else {
				sort(myVector.begin(), myVector.end());

				cout << "\n\t\tThe vector has been sorted in ascending order.";
			}
			break;
		case 6:
			if (myVector.empty()) {
				cout << "\n\t\tClear operation cannot be performed on an empty vector.";
			}
			else {
				cout << "\n\t\tThe vector will be cleared of all elements.";
				myVector.clear();
			}
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);

}

//PreCondition: None
//PostCondition: Displays List sub menu text
void listText() {
	SetConsoleTextAttribute(color, 14);
	cout << "\n\tLists are sequence containers that allow non-contiguous memory allocation. As compared to";
	cout << "\n\tvector, the list has slow traversal, but once a position has been found, insertion and";
	cout << "\n\tdeletion are quicker.";
	cout << endl;
	SetConsoleTextAttribute(color, 7);
}

//PreCondition: None
//PostCondition: Displays List Menu and returns an integer
int listMenu() {
	cout << "\n\t\tList Menu Options";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t\t1. Add an element";
	cout << "\n\t\t2. Insert an element after";
	cout << "\n\t\t3. Remove element(s)";
	cout << "\n\t\t4. Sort the elements in ascending order";
	cout << "\n\t\t5. Clear all elements";
	cout << "\n\t" << string(90, char(196));
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(90, char(205));

	return inputInteger("\n\t\tOption: ", 0, 5);
}

//PreCondition: None 
//PostCondition: Runs certain operations using list depending on menu choice 
void listCase() {
	list<Rational> myList;

	do {
		system("cls");
		listText();

		if (myList.empty()) {
			cout << "\n\tThe current list is empty.";
		}
		else {
			cout << "\n\tThe currrent list contains " << myList.size() << " element: \n";

			cout << "\t\t";
			for (int i = 0; i < myList.size(); i++) {
				cout << char(218) << string(4, char(196)) << char(191) << " ";

			}
			cout << endl;

			cout << "\t\t";
			int count = 0;
			for (const auto& element : myList) {
				if (element.getDenominator() < 0 || element.getNumerator() < 0)
					cout << char(179) << element;
				else
					cout << char(179) << " " << element;
				if (count != myList.size() - 1) {
					cout << char(179) << char(175);
				}
				else {
					cout << char(179);
				}
				count++;
			}

			cout << endl;

			cout << "\t\t";
			for (int i = 0; i < myList.size(); i++) {
				cout << char(192) << string(4, char(196)) << char(217) << " ";
			}
			cout << endl;

			cout << "\n\taddress: " << &myList.front();
		}
		cout << endl;

		switch (listMenu()) {
		case 0: return; break;
		case 1:
			try
			{
				Rational fraction;
				cout << "\n\t\tInput a Rational number to be pushed...";
				cout << endl;

				fraction.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
				fraction.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));

				char choice = inputChar("\n\t\tAdd to the (F-front) or from the (B-back): ", static_cast<string>("BF"));

				if (choice == 'F') {
					myList.push_front(fraction);

					cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
					if (fraction.getNumerator() < 0 || fraction.getDenominator() < 0)
						cout << "\n\t\t" << char(179) << fraction << char(179) << " will be pushed to the front of the list.";
					else
						cout << "\n\t\t" << char(179) << " " << fraction << char(179) << " will be pushed to the front of the list.";
					cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
				}
				else if (choice == 'B') {
					myList.push_back(fraction);

					cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
					if (fraction.getNumerator() < 0 || fraction.getDenominator() < 0)
						cout << "\n\t\t" << char(179) << fraction << char(179) << " will be pushed to the back of the list.";
					else
						cout << "\n\t\t" << char(179) << " " << fraction << char(179) << " will be pushed to the back of the list.";
					cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
				}
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
			}

			break;

		case 2:
			try
			{
				Rational fraction;
				cout << "\n\t\tInput a Rational number to be inserted...";
				cout << endl;

				fraction.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
				fraction.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));

				if (myList.empty()) {
					myList.insert(myList.begin(), fraction);

					cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
					if (fraction.getNumerator() < 0 || fraction.getDenominator() < 0)
						cout << "\n\t\t" << char(179) << fraction << char(179) << " will be inserted to the empty list.";
					else
						cout << "\n\t\t" << char(179) << " " << fraction << char(179) << " will be inserted to the empty list.";
					cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
					break;
				}

				cout << "\n\t\tInput an existing Rational number as the insert position to be added...";

				try {
					Rational fraction2;
					fraction2.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
					fraction2.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));

					auto it = find(myList.begin(), myList.end(), fraction2);

					if (it != myList.end()) {
						char choice = inputChar("\n\t\tInsert (B-before) or (A-after) the existing element : ", static_cast<string>("BA"));
						if (choice == 'B') {
							myList.insert(it, fraction);

							cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
							if (fraction.getNumerator() < 0 || fraction.getDenominator() < 0)
								cout << "\n\t\t" << char(179) << fraction << char(179) << " will be inserted before the existing element from the list.";
							else
								cout << "\n\t\t" << char(179) << " " << fraction << char(179) << " will be inserted before the existing element from the list.";
							cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);


						}
						else if (choice == 'A') {
							myList.insert(next(it), fraction);

							cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
							if (fraction.getNumerator() < 0 || fraction.getDenominator() < 0)
								cout << "\n\t\t" << char(179) << fraction << char(179) << " will be inserted after the existing element from the list.";
							else
								cout << "\n\t\t" << char(179) << " " << fraction << char(179) << " will be inserted after the existing element from the list.";
							cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
						}
					}
					else {

						cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
						if (fraction2.getNumerator() < 0 || fraction2.getDenominator() < 0)
							cout << "\n\t\t" << char(179) << fraction2 << char(179) << " cannot be found from the list.";
						else
							cout << "\n\t\t" << char(179) << " " << fraction2 << char(179) << " cannot be found from the list.";
						cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
					}


				}
				catch (Rational::ZeroDenominator& e)
				{
					cout << "\n\t\tEXCEPTIONAL ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
				}
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
			}

			break;

		case 3:
			if (myList.empty()) {
				cout << "\n\t\tDelete operation can be performed on an empty list.";
			}
			else {
				try {
					Rational fractionToDelete;
					cout << "\n\t\tInput a Rational number to be removed...";
					cout << endl;

					fractionToDelete.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
					fractionToDelete.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));

					auto it = find(myList.begin(), myList.end(), fractionToDelete);

					if (it != myList.end()) {
						char choice = inputChar("\n\t\tDo you want to remove (O-one or A-all) element(s): ", static_cast<string>("OA"));
						if (choice == 'O') {
							myList.erase(it);
							cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
							if (fractionToDelete.getNumerator() < 0 || fractionToDelete.getDenominator() < 0)
								cout << "\n\t\t" << char(179) << fractionToDelete << char(179) << " has been removed once from the list.";
							else
								cout << "\n\t\t" << char(179) << " " << fractionToDelete << char(179) << " has been removed once from the list.";
							cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
						}
						else if (choice == 'A') {
							myList.remove(*it);
							cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
							if (fractionToDelete.getNumerator() < 0 || fractionToDelete.getDenominator() < 0)
								cout << "\n\t\t" << char(179) << fractionToDelete << char(179) << " has been removed all from the list.";
							else
								cout << "\n\t\t" << char(179) << " " << fractionToDelete << char(179) << " has been removed all from the list.";
							cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
						}

					}
					else {
						cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
						if (fractionToDelete.getNumerator() < 0 || fractionToDelete.getDenominator() < 0)
							cout << "\n\t\t" << char(179) << fractionToDelete << char(179) << " cannot be found from the list.";
						else
							cout << "\n\t\t" << char(179) << " " << fractionToDelete << char(179) << " cannot be found from the list.";
						cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
					}
				}

				catch (Rational::ZeroDenominator& e) {
					cout << "\n\t\tEXCEPTIONAL ERROR: Cannot delete a Rational number, " << e.toString() << ", with a zero denominator value.";
				}
			}
			break;

		case 4:
			if (myList.empty()) {
				cout << "\n\t\tSort operation cannot be performed on an empty list.";
			}
			else {
				myList.sort();
				cout << "\n\t\tThe list has been sorted.";
			}
			break;

		case 5:
			if (myList.empty()) {
				cout << "\n\t\tClear operation can be performed on an empty list.";
			}
			else {
				myList.clear();
				cout << "\n\t\tThe list has been cleared of all element(s).";
			}
			break;

		}
		cout << "\n\n\t";
		system("pause");

	} while (true);


}

//PreCondition: None
//PostCondition: Displays Stack sub menu text
void stackText() {
	SetConsoleTextAttribute(color, 11);
	cout << "\n\tStacks are a type of container adaptors with LIFO(Last In First Out) type of working, where";
	cout << "\n\ta new element is added(push) at one end(top) and an element is removed(pop) from that end";
	cout << "\n\tonly. Stack uses an encapsualted object of either vector or deque(by default) or list (sequential";
	cout << "\n\tcontainer class) as its underlying container,providing a specific set of member functions to";
	cout << "\n\taccess its elements.";
	cout << endl;
	SetConsoleTextAttribute(color, 7);
}

//PreCondition: None
//PostCondition: Displays stack option menu and returns an integer value
int stackMenu() {
	cout << "\n\t\tStack Menu Options";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t\t1. Push";
	cout << "\n\t\t2. Top";
	cout << "\n\t\t3. Pop";
	cout << "\n\t" << string(90, char(196));
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(90, char(205));

	return inputInteger("\n\t\tOption: ", 0, 3);
}

//PreCondition: Needs a stack of Rationals -- from the Rational.h file
//PostCondition: Recursive way to display stack contents 
void displayStack(stack<Rational>& stack)
{
	if (stack.empty())
		return;

	Rational topElement = stack.top();

	if (topElement.getNumerator() < 0 || topElement.getDenominator() < 0)
		cout << char(179) << topElement << char(179);
	else
		cout << char(179) << " " << topElement << char(179);

	stack.pop();

	displayStack(stack);

	stack.push(topElement);

}

//PreCondition: None
//PostCondition: Runs certain stack functions based of user choice in menu
void stackCase() {
	stack<Rational>myStack;

	do {
		system("cls");
		stackText();

		if (myStack.empty())
			cout << "\n\tThe current stack is empty.";
		else {
			cout << "\n\tThe current stack contains " << myStack.size() << " element: \n";
			cout << endl;
			SetConsoleTextAttribute(color, 11);
			cout << "\t\t" << string(6 * myStack.size(), char(205)) << char(187);
			SetConsoleTextAttribute(color, 7);
			cout << "\n\t\t";

			for (int i = 0; i < myStack.size(); i++) {
				cout << char(218) << string(4, char(196)) << char(191);

			}
			SetConsoleTextAttribute(color, 11);
			cout << char(186) << char(32) << endl;
			cout << "\ttop " << char(175) << "   ";
			SetConsoleTextAttribute(color, 7);
			displayStack(myStack);

			SetConsoleTextAttribute(color, 11);
			cout << char(186) << char(32) << endl;
			SetConsoleTextAttribute(color, 7);
			cout << "\t\t";
			for (int i = 0; i < myStack.size(); i++) {
				cout << char(192) << string(4, char(196)) << char(217);
			}
			SetConsoleTextAttribute(color, 11);
			cout << char(186) << char(32) << endl;
			cout << "\t\t" << string(6 * myStack.size(), char(205)) << char(188);
			SetConsoleTextAttribute(color, 7);
		}
		cout << endl;

		switch (stackMenu()) {
		case 0: return; break;
		case 1:
			try
			{
				Rational fraction;
				cout << "\n\t\tInput a Rational number to be pushed...";
				cout << endl;

				fraction.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
				fraction.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));

				cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
				if (fraction.getNumerator() < 0 || fraction.getDenominator() < 0)
					cout << "\n\t\t" << char(179) << fraction << char(179) << " will be pushed onto the stack.";
				else
					cout << "\n\t\t" << char(179) << " " << fraction << char(179) << " will be pushed onto the stack.";
				cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

				myStack.push(fraction);

			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
			}

			break;

		case 2:
			if (myStack.empty()) {
				cout << "\n\t\tNo top element can be retrieved from an empty stack.";
				break;
			}

			cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
			if (myStack.top().getNumerator() < 0 || myStack.top().getDenominator() < 0)
				cout << "\n\t\t" << char(179) << myStack.top() << char(179) << " is at the top of the stack.";
			else
				cout << "\n\t\t" << char(179) << " " << myStack.top() << char(179) << " is at the top of the stack.";
			cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);


			break;
		case 3:
			if (myStack.empty()) {
				cout << "\n\t\tNo pop operation can be performed from an empty stack.";
				break;
			}

			cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
			if (myStack.top().getNumerator() < 0 || myStack.top().getDenominator() < 0)
				cout << "\n\t\t" << char(179) << myStack.top() << char(179) << " will be popped from the stack.";
			else
				cout << "\n\t\t" << char(179) << " " << myStack.top() << char(179) << " will be popped from the stack.";
			cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

			myStack.pop();
			break;
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);


}

//PreCondition: None 
//PostCondition: Displays queue sub menu text 
void queueText() {
	SetConsoleTextAttribute(color, 10);
	cout << "\n\tQueues are a type of container adaptors that operate in a first in first out (FIFO) type of";
	cout << "\n\tarrangement. Elements are inserted(enqueued) at the back and are deleted (dequeued) from the";
	cout << "\n\tfront. Queues use an encapsulated object of deque or list(sequential container class) as its";
	cout << "\n\tunderlying container, providing a specific set of member functions to access elements.";
	cout << endl;
	SetConsoleTextAttribute(color, 7);
}

//PreCondition: None
//PostCondition: Displays queue option menu and returns an integer 
int queueMenu() {
	cout << "\n\t\tQueue Menu Options";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t\t1. Enqueue (push in from the back)";
	cout << "\n\t\t2. Front";
	cout << "\n\t\t3. Back";
	cout << "\n\t\t4. Dequeue (pop from the front)";
	cout << "\n\t" << string(90, char(196));
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(90, char(205));

	return inputInteger("\n\t\tOption: ", 0, 4);
}

//PreCondition: Accepts a queue of Rationals -- from Rational.h
//PostCondition: Recursive way to display queue contents
void displayQueue(queue<Rational>& myqueue) {
	if (myqueue.empty()) {
		return;
	}
	queue<Rational> tempQueue = myqueue;


	Rational frontElement = tempQueue.front();
	tempQueue.pop();


	displayQueue(tempQueue);
	if (frontElement.getNumerator() < 0 || frontElement.getDenominator() < 0)
		cout << char(179) << frontElement << char(179);
	else
		cout << char(179) << " " << frontElement << char(179);
}

//PreCondition: None
//PostCondition: Runs certain queue operations depending on user choice in menu 
void queueCase() {
	queue<Rational> myQueue;

	do {
		system("cls");
		queueText();

		if (myQueue.empty())
			cout << "\n\tThe current queue is empty.";
		else {
			cout << "\n\tThe current queue contains " << myQueue.size() << " element: \n";
			SetConsoleTextAttribute(color, 10);
			cout << "\t\t" << string(6 * myQueue.size(), char(205));
			cout << "\n\t\t";
			SetConsoleTextAttribute(color, 7);
			for (int i = 0; i < myQueue.size(); i++) {
				cout << char(218) << string(4, char(196)) << char(191);

			}
			cout << endl;
			SetConsoleTextAttribute(color, 10);
			cout << "\tback " << char(175) << "  ";
			SetConsoleTextAttribute(color, 7);
			displayQueue(myQueue);
			SetConsoleTextAttribute(color, 10);
			cout << char(32) << char(174) << " front";
			cout << endl;
			SetConsoleTextAttribute(color, 7);
			cout << "\t\t";
			for (int i = 0; i < myQueue.size(); i++) {

				cout << char(192) << string(4, char(196)) << char(217);
			}
			cout << endl;
			SetConsoleTextAttribute(color, 10);
			cout << "\t\t" << string(6 * myQueue.size(), char(205));
			SetConsoleTextAttribute(color, 7);
		}
		cout << endl;


		switch (queueMenu()) {
		case 0: return; break;
		case 1:
			try
			{
				Rational fraction;
				cout << "\n\t\tInput a Rational number to be enqueued...";
				cout << endl;

				fraction.setNumerator(inputInteger("\n\t\tEnter a numerator(-9...9): ", -9, 9));
				fraction.setDenominator(inputInteger("\n\t\tEnter a denominator(-9...9): ", -9, 9));

				cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
				if (fraction.getNumerator() < 0 || fraction.getDenominator() < 0)
					cout << "\n\t\t" << char(179) << fraction << char(179) << " will be enqueued (pushed) onto the queue.";
				else
					cout << "\n\t\t" << char(179) << " " << fraction << char(179) << " will be enqueued (pushed) onto the queue.";
				cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

				myQueue.push(fraction);

			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
			}

			break;
		case 2:
			if (myQueue.empty()) {
				cout << "\n\t\tNo front element can be retrieved from an empty queue.";
			}
			else {

				cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
				if (myQueue.front().getNumerator() < 0 || myQueue.front().getDenominator() < 0)
					cout << "\n\t\t" << char(179) << myQueue.front() << char(179) << " is at the front of the queue.";
				else
					cout << "\n\t\t" << char(179) << " " << myQueue.front() << char(179) << " is at the front of the queue.";
				cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
			}
			break;

		case 3:
			if (myQueue.empty()) {
				cout << "\n\t\tNo front element can be retrieved from an empty queue.";
			}
			else {
				cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
				if (myQueue.back().getNumerator() < 0 || myQueue.back().getDenominator() < 0)
					cout << "\n\t\t" << char(179) << myQueue.back() << char(179) << " is at the back of the queue.";
				else
					cout << "\n\t\t" << char(179) << " " << myQueue.back() << char(179) << " is at the back of the queue.";
				cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
			}
			break;

		case 4:
			if (myQueue.empty()) {
				cout << "\n\t\tNo dequeue (pop) operation can be performed on an empty stack";
			}
			else {
				cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
				if (myQueue.front().getNumerator() < 0 || myQueue.front().getDenominator() < 0)
					cout << "\n\t\t" << char(179) << myQueue.front() << char(179) << " will be dequeued (popped) from the stack.";
				else
					cout << "\n\t\t" << char(179) << " " << myQueue.front() << char(179) << " will be dequeued (popped) from the stack.";
				cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

				myQueue.pop();
			}
			break;
		}

		cout << "\n\n\t";
		system("pause");

	} while (true);


}

//PreCondition: None
//PostCondition: Displays main menu text and graphic 
void menuText() {
	SetConsoleTextAttribute(color, 11);
	cout << "\n\t\t\t\t\t\t\t\t   " << char(186) << " in/out " << char(186) << "            ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186) << "   in   " << char(186);
	SetConsoleTextAttribute(color, 11);
	cout << "\n\t\t\t\t\t\t\t\t   " << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(218) << string(4, char(196)) << char(191) << " ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186) << "            ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(218) << string(4, char(196)) << char(191) << " ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 11);
	cout << "\n\t\t\t\t\t\t\t       " << "top" << char(175) << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(179) << " 1/2" << char(179) << " ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186) << "       ";
	SetConsoleTextAttribute(color, 10);
	cout << "rear" << char(175) << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(179) << " 5/6" << char(179) << " ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 11);
	cout << "\n\t\t\t\t\t\t\t\t   " << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(195) << string(4, char(196)) << char(180) << " ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186) << "            ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(195) << string(4, char(196)) << char(180) << " ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << "\n\t  " << char(218) << string(4, char(196)) << char(194) << string(4, char(196)) << char(194) << string(4, char(196)) << char(191) << "         " << char(218) << string(4, char(196)) << char(191) << " ";
	cout << char(218) << string(4, char(196)) << char(191) << " " << char(218) << string(4, char(196)) << char(191) << "            ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(179) << " 3/4" << char(179) << " ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186);
	SetConsoleTextAttribute(color, 10);
	cout << "\t\t " << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(179) << " 3/4" << char(179) << " ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << "\n\t  " << char(179) << " 1/2" << char(179) << " 3/4" << char(179) << " 5/6" << char(179) << "       " << char(218);
	SetConsoleTextAttribute(color, 14);
	cout << char(175);
	SetConsoleTextAttribute(color, 7);
	cout << char(179) << " 1/2" << char(179);
	SetConsoleTextAttribute(color, 14);
	cout << char(175);
	SetConsoleTextAttribute(color, 7);
	cout << char(179) << " 3/4" << char(179);
	SetConsoleTextAttribute(color, 14);
	cout << char(175);
	SetConsoleTextAttribute(color, 7);
	cout << char(179) << " 5/6" << char(179) << "            ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(195) << string(4, char(196)) << char(180) << " ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186);
	SetConsoleTextAttribute(color, 10);
	cout << "            " << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(195) << string(4, char(196)) << char(180) << " ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << "\n\t  " << char(192) << string(4, char(196)) << char(193) << string(4, char(196)) << char(193) << string(4, char(196)) << char(217) << "       " << char(179) << " " << char(192);
	cout << string(4, char(196)) << char(217) << " " << char(192) << string(4, char(196)) << char(217) << " " << char(192) << string(4, char(196)) << char(217) << "            ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(179) << " 5/6" << char(179) << " ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186) << "      ";
	SetConsoleTextAttribute(color, 10);
	cout << "front" << char(175) << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(179) << " 1/2" << char(179) << " ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 12);
	cout << "\n\t  0    1    2     ";
	SetConsoleTextAttribute(color, 14);
	cout << "       head\t\t\t\t   ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(192) << string(4, char(196)) << char(217) << " ";
	SetConsoleTextAttribute(color, 11);
	cout << char(186);
	SetConsoleTextAttribute(color, 10);
	cout << "            " << char(186);
	SetConsoleTextAttribute(color, 7);
	cout << " " << char(192) << string(4, char(196)) << char(217) << " ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186);
	SetConsoleTextAttribute(color, 12);
	cout << "\n\t  (index)\t\t";
	SetConsoleTextAttribute(color, 14);
	cout << " (pointer)\t\t\t   ";
	SetConsoleTextAttribute(color, 11);
	cout << char(200) << string(8, char(205)) << char(188) << "            ";
	SetConsoleTextAttribute(color, 10);
	cout << char(186) << "  out   " << char(186);
	cout << endl;
	SetConsoleTextAttribute(color, 12);
	cout << "\n\t  Vector (list array)";
	SetConsoleTextAttribute(color, 14);
	cout << "        Linked List\t\t";
	SetConsoleTextAttribute(color, 11);
	cout << "      Stack";
	SetConsoleTextAttribute(color, 10);
	cout << "\t\t   Queue ";
	cout << endl;
	SetConsoleTextAttribute(color, 7);
	cout << "\n\tA container is a holder object that stores a collection of other objects (its elements). They";
	cout << "\n\tare implemented as class templates, which allows great flexibility in the types supported as";
	cout << "\n\telements. The container manages the storage space for its elements and provides member functions";
	cout << "\n\tto access them, either directly or through iterators(reference objects with similar properties";
	cout << "\n\tto pointers).";
	cout << endl;
}