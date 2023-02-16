#include <sstream>
#include <iomanip>
#include <string>
#include "product.h"
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author) 
		: Product (category, name, price, qty)
		// , isbn_(isbn), author_(author)
{
	// category_ = category;
	// name_ = name;
	// price_ = price;
	// qty_ = qty;
	isbn_ = isbn;
	author_ = author;
}

Book::~Book(){}

/**
	* Returns the appropriate keywords that this product should be associated with
	*/
std::set<std::string> Book::keywords() const {
	std::set<std::string> keysName = parseStringToWords(name_);
	std::set<std::string> keysCategory = parseStringToWords(category_);
	std::set<std::string> keysISBN = parseStringToWords(isbn_);
	std::set<std::string> keysAuthor = parseStringToWords(author_);

	std::set<std::string> set1 = setIntersection(keysName, keysCategory);
	std::set<std::string> set2 = setIntersection(keysISBN, keysAuthor);

	return setIntersection(set1, set2);
}  //virtual =0

/**
	* Returns a string to display the product info for hits of the search
	*/
std::string Book::displayString() const 
{
	std::string strprice = to_string(price_);
	std::string strqty = to_string(qty_);
	std::string book = name_ + "\n Author: " + author_ + " ISBN: " + isbn_ + "\n" + strprice + " " + strqty + " left.";
	return book;
}//virtual =0

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Book::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ <<  "\n" << isbn_ << "\n" << author_ << endl;
}

// std::set<std::string> parseStringToWords(string rawWords)
// {
// 	std::stringstream ss(rawWords);
// 	std::string temp; //temporary holder for every word
// 	std::string kw = ""; //kw short for keyword
// 	std::set <std::string> keywords;
// 	while (ss >> temp)
// 	{
// 		for (unsigned int i=0; i < temp.size(); i++)
// 		{
// 			if ((temp[i] > 47 && temp[i] < 58) || (temp[i] > 64 && temp[i] < 91) 
// 			|| (temp[i] > 96 && temp[i] < 123) || temp[i] == 43 || temp[i] == 45) //all the ascii values that aren't punctuation
// 			{
// 					kw += temp[i];
// 			}
// 		}
// 		if (kw.size() > 1)
// 		{
// 			keywords.insert(kw);
// 		}
// 		kw = "";
// 	}
// 	return keywords;
// }
