#pragma once
#include <vector>
#include <string>
#include <map>
#include "User.h"
#include "Book.h"
using namespace std;
class Library
{
private:
	string nameLibrary;
	map <int, User> users;
	map <int, Book> bookInventory;
public:
	Library();
	void showBookInventory();
	void showBookAmountLeftByID(int id);

	void addBooks(int bookID, int amount);
	void addNewBookToLib(Book &bk);
	void removeBookFromLib(int id3);
	void reduceBooks(int bookID, int amount);
	void editBookInfo(int bookID);
	void viewBookInfo(int bookID);

	void addUserToLib(User &usr);
	void displayUserInfo(int userID);
	void borrowBook(int userID, int bookID);
	void returnBook(int userID, int bookID);
	void showHisBooks(int userID);
	void displayWhoHasWhichBooks();
	void editUserInfo(int userID);
};

