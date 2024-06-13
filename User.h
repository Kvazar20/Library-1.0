#pragma once
#include <string>
#include <vector>
using namespace std;

class User
{
private:
	int userID;
	string name;
	string surname;
	string gender;
	int age;
	vector<int> borrowedBooks;
public:
	User();
	User(int id1, string name1,string surname1,string gender1,int age1);
	void showUserInfo();
	void showHisBooks();
	void borrowBook(int id);
	bool returnBook(int bookID);
	void setAll(int userID1, string name1, string surname1, string gender1, int age1);
	void setID(int newID);
};

