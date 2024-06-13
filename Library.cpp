#include "Library.h"
#include <iostream>
#include <map>
#include <string>
#include "User.h"
using namespace std;

Library::Library() {
	nameLibrary = "Central New-York Library";
}
void Library::showBookInventory() {
	cout << "Book inventory display:" << endl;
	for (auto itr = bookInventory.begin(); itr != bookInventory.end(); ++itr) {
		cout << "* ID:" << (*itr).first << "    Amount left:" << (*itr).second.getAmountLeft() << endl;
	}
}
void Library::showBookAmountLeftByID(int ID1) {
	cout << "* Amount of books left with ID " << ID1 << ": " << bookInventory[ID1].getAmountLeft() << endl;
}
void Library::addBooks(int id1, int amount1) {
	bookInventory[id1].addAmount(amount1);
}
void Library::addNewBookToLib(Book &bk) {
	int newID;
	if (bookInventory.empty()) {
		newID = 1; // Start IDs from 1 if the inventory is empty
	}
	else {
		auto itr = prev(bookInventory.end());
		newID = (*itr).first + 1;
	}
	bk.setID(newID);
	bookInventory[newID] = bk;
}
void Library::removeBookFromLib(int id3) {
	bookInventory.erase(id3);
}
void Library::reduceBooks(int bookID, int amount) {
	if (bookInventory.find(bookID) == bookInventory.end()) {
		cout << "Book with such ID does not exist" << endl;
	}
	else {
		bookInventory[bookID].reduceAmount(amount);
	}
}
void Library::borrowBook(int userID, int bookID) {
	if (users.find(userID) == users.end()) {
		cout << "User with such ID does not exist" << endl;
	}
	else if (bookInventory.find(bookID) == bookInventory.end()) {
		cout << "Book with such ID does not exist" << endl;
	}
	else if (bookInventory[bookID].getAmountLeft() == 0) {
		cout << "This book is out of stock. Sorry" << endl;
	}
	else {
		users[userID].borrowBook(bookID);
		bookInventory[bookID].reduceAmount(1);
	}
}
void Library::showHisBooks(int userID) {
	users[userID].showHisBooks();
}
void Library::displayWhoHasWhichBooks() {
	for (auto itr = users.begin(); itr != users.end(); ++itr) {
		(*itr).second.showHisBooks();
		cout << endl;
	}
}

void Library::addUserToLib(User &usr) {
	int newID;
	if (users.empty()) {
		newID = 1;
	}
	else {
		auto itr = prev(users.end());
		newID = (*itr).first + 1;
	}
	usr.setID(newID);
	users[newID] = usr;

}
void Library::displayUserInfo(int userID) {
	users[userID].showUserInfo();
}
void Library::returnBook(int userID, int bookID) {
	if (users[userID].returnBook(bookID) == true) {
		bookInventory[bookID].reduceAmount(1);
	}
	else {
		cout << "User doesn't have this book" << endl;
	}
}
void Library::editBookInfo(int bookID) {
	bookInventory[bookID].displayInfo();
	string title1;
	string author1;
	string genre1;
	cout << "* New info: *" << endl;
	cout << "Title: ";
	cin >> title1;
	cout << "Author: ";
	cin >> author1;
	cout << "Genre: ";
	cin >> genre1;
	bookInventory[bookID].setMainInfo(title1, author1, genre1);
	cout << "* Book info changed successfully *" << endl;
}
void Library::viewBookInfo(int bookID) {
	bookInventory[bookID].displayInfo();
}
void Library::editUserInfo(int userID) {
	string name1;
	string surname1;
	string gender1;
	int age1;
	cout << "* New info: *" << endl;
	cout << "Name: ";
	cin >> name1;
	cout << "Surname: ";
	cin >> surname1;
	cout << "Gender: ";
	cin >> gender1;
	cout << "Age: ";
	cin >> age1;
	users[userID].setAll(userID, name1, surname1, gender1, age1);
	cout << "* User info changed successfully *" << endl;
}