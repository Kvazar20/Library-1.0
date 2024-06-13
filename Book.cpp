#include "Book.h"
#include <string>
#include <iostream>

using namespace std;

Book::Book() {
	id = 0;
	title = "";
	author = "";
	genre = "";
	amountLeft = 0;
}
Book::Book(int id1, string title1, string author1, string genre1, int amountLeft1) {
	id = id1;
	title = title1;
	author = author1;
	genre = genre1;
	amountLeft = amountLeft1;
}
void Book::displayInfo() {
	cout << "******************************" << endl;
	cout << "* Information about the book" << endl;
	cout << "* ID:" << id << "\n" << "* Title:" << title << "\n" << "* Author:" << author << endl;
	cout << "* Genre:" << genre << endl;
	cout << "******************************" << endl;
}
void Book::addAmount(int amount1) {
	amountLeft += amount1;
}
void Book::reduceAmount(int amount) {
	amountLeft -= amount;
	if (amountLeft < 0) {
		amountLeft = 0;
		cout << "Amount for reduction is excessive. Book amount reduced to 0" << endl;
	}
}
void Book::setAll(int id1, string title1, string author1, string genre1, int amountLeft1) {
	id = id1;
	title = title1;
	author = author1;
	genre = genre1;
	amountLeft = amountLeft1;
}
void Book::setID(int bookID) {
	id = bookID;
}
void Book::setMainInfo(string title1, string author1, string genre1) {
	title = title1;
	author = author1;
	genre = genre1;
}


void Book::setTitle(string title1) { title = title1;  }
void Book::setAuthor(string author1) { title = author1; }
void Book::setGenre(string genre1) { genre = genre1; }
string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getGenre() { return genre; }
int Book::getAmountLeft() { return amountLeft; }