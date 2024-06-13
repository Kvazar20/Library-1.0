#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"
#include "Library.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	Library lib;
	Book books[10];
	for (int i = 0; i < 10; i++) {                             // Generating 10 random books
		int id = i+1;
		string title = "Title" + to_string(i+1);
		string author = "Author" + to_string(i+1);
		string genre = "Genre" + to_string(i+1);
		books[i].setAll(id, title, author, genre, 200);
	}

	for (int i = 0; i < 10; i++) {                            // Adding all books to library
		lib.addNewBookToLib(books[i]);                       
	}
	
	User users[5];
	for (int i = 0; i < 5; i++) {                                    // Generating 5 random users
		string name = "name" + to_string(i + 1);
		string surname = "surname" + to_string(i + 1);
		string gender = "gender" + to_string(i + 1);
		int age = rand() % 20 + 20;
		users[i].setAll(i + 1, name, surname, gender, age);            // Adding users to the library
		lib.addUserToLib(users[i]);
	}
	
	bool endCondition = false;
	while (endCondition == false) {
		system("cls");
		cout << "****************************************************************************" << endl;
		cout << "**                      New-York Central Library                          **" << endl;
		cout << "****************************************************************************" << endl;
		cout << "**                     What you would like to do?                         **" << endl;
		cout << "**                                                                        **" << endl;
		cout << "** 0)  Close app!                                                         **" << endl;
		cout << "**                                                                        **" << endl;
		cout << "****************************************************************************" << endl;
		cout << "** 1)  Display book inventory            ** 5)  Add amount of books       **" << endl;
		cout << "** 2)  Show amount of books left by ID   ** 6)  Reduce amount of books    **" << endl;
		cout << "** 3)  Add new book                      ** 7)  Edit book info            **" << endl;
		cout << "** 4)  Remove book from Library          ** 8)  View book info            **" << endl;
		cout << "****************************************************************************" << endl;
		cout << "** 9)  Borrow book                       ** 13) Add user to library       **" << endl;
		cout << "** 10) Return book                       ** 14) Display user info         **" << endl;
		cout << "** 11) Show user's borrowed books        ** 15) Edit user info            **" << endl;
		cout << "** 12) Display who has which books                                        **" << endl;
		cout << "****************************************************************************" << endl;

		int choice;
		cout << "Enter your choice:";
		cin >> choice;
		cout << endl;
		int userID;
		int bookID;
		int amount;
		switch (choice) {
		case 0:
			cout << "Thanks for using Library app! " << endl;
			endCondition = true;
			break;
		case 1:
			lib.showBookInventory();
			break;
		case 2:
			int id;
			cout << "Enter ID:";
			cin >> id;
			lib.showBookAmountLeftByID(id);
			break;
		case 3: {
			cout << "Enter book info" << endl;
			string title;
			cout << "Title:";
			cin >> title;
			string author;
			cout << "Author:";
			cin >> author;
			string genre;
			cout << "Genre:";
			cin >> genre;
			int amountLeft;
			cout << "Amount:";
			cin >> amountLeft;
			Book bk(0, title, author, genre, amountLeft);
			lib.addNewBookToLib(bk);
			break;
		}
		case 4:
			cout << "Book ID:";
			cin >> bookID;
			lib.removeBookFromLib(bookID);
			break;
		case 5:
			cout << "Book ID:";
			cin >> bookID;
			cout << "Amount:";
			cin >> amount;
			lib.addBooks(bookID, amount);
			break;
		case 6:
			cout << "Book ID:";
			cin >> bookID;
			cout << "Amount:";
			cin >> amount;
			lib.reduceBooks(bookID, amount);
			break;
		case 7: {
			cout << "Enter book ID: ";
			cin >> bookID;
			lib.editBookInfo(bookID);
			break;
		}
		case 8:
			cout << "Enter book ID: ";
			cin >> bookID;
			lib.viewBookInfo(bookID);
			break;
		case 9:
			cout << "User ID:";
			cin >> userID;
			cout << "Book ID:";
			cin >> bookID;
			lib.borrowBook(userID, bookID);
			break;
		case 10:
			cout << "User ID:";
			cin >> userID;
			cout << "Book ID:";
			cin >> bookID;
			lib.returnBook(userID, bookID);
			break;
		case 11:
			cout << "User ID:";
			cin >> userID;
			cout << endl;
			lib.showHisBooks(userID);
			break;
		case 12:
			lib.displayWhoHasWhichBooks();
			break;
		case 13: {
			string name;
			string surname;
			string gender;
			int age;
			cout << "Name:";
			cin >> name;
			cout << "Surname:";
			cin >> surname;
			cout << "Gender:";
			cin >> gender;
			cout << "Age:";
			cin >> age;
			User usr(0, name, surname, gender, age);
			lib.addUserToLib(usr);
			break;
		}
		case 14:
			cout << "User ID:";
			cin >> userID;
			lib.displayUserInfo(userID);
			break;
		case 15:
			cout << "Enter user ID: ";
			cin >> userID;
			lib.editUserInfo(userID);
			break;
		default:
			cout << "Invalid option. Choose again" << endl;
		}
		if (endCondition == false) {
			cout << "Press Enter to continue...";
			cin.ignore();
			cin.get();
		}
		
	}

	system("pause");
	return 0;
}
