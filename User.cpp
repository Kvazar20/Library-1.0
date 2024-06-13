#include "User.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

User::User() {
	userID = 0;
	name = "";
	surname = "";
	gender = "";
	age = 0;
}
User::User(int id1, string name1, string surname1, string gender1, int age1) {
	userID = id1;
	name = name1;
	surname = surname1;
	gender = gender1;
	age = age1;
}
void User::showUserInfo() {
	cout << "***************************" << endl;
	cout << "*******  User info  *******" << endl;
	cout << "* ID: " << userID << endl;
	cout << "* Name: " << name << " " << surname << endl;
	cout << "* Gender: " << gender << endl;
	cout << "* Age: " << age << endl;
	cout << "***************************" << endl;
}
void User::showHisBooks() {
	cout << "User with ID " << userID << " borrowed books: ";
	for (int i = 0; i < borrowedBooks.size(); i++) {
		cout << borrowedBooks[i] << " ";
	}
	cout << endl;
}
void User::borrowBook(int id) {
	bool inVector = false;
	for (auto itr = borrowedBooks.begin(); itr != borrowedBooks.end(); ++itr) {
		if (*itr == id) {
			inVector = true;
			cout << "User has already borrowed this book" << endl;
			break;
		}
	}
	if (inVector == false) {
		borrowedBooks.push_back(id);
	}
}
bool User::returnBook(int bookID) {
	bool found = false;
	for (auto itr = borrowedBooks.begin(); itr != borrowedBooks.end(); ++itr) {
		if (*itr == bookID) {
			borrowedBooks.erase(itr);
			found = true;
			break;
		}
	}
	return found;
}
void User::setAll(int userID1, string name1, string surname1, string gender1, int age1) {
	userID = userID1;
	name = name1;
	surname = surname1;
	gender = gender1;
	age = age1;
}
void User::setID(int newID) { userID = newID; }