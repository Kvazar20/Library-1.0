#pragma once
#include <string>
using namespace std;
class Book
{
private:
	int id;
	string title;
	string author;
	string genre;
	int amountLeft;
public:
	Book();
	Book(int id1, string title1, string author1, string genre1, int amountLeft1);
	void displayInfo();
	void addAmount(int amount);
	void reduceAmount(int amount);
	void setID(int bookID);
	void setTitle(string title1);
	void setAuthor(string autthor1);
	void setGenre(string Genre1);
	string getTitle();
	string getAuthor();
	string getGenre();
	int getAmountLeft();
	void setAll(int id1, string title1, string author1, string genre1, int amountLeft1);
	void setMainInfo(string title1, string author1, string genre1);
};

