#include <sstream>
#include <iomanip>
#include <string>
#include "product.h"
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) 
		: Product (category, name, price, qty)
{
	size_ = size;
	brand_ = brand;
}

Clothing::~Clothing()
{

}

/**
	* Returns the appropriate keywords that this product should be associated with
	*/
std::set<std::string> Clothing::keywords() const {
	std::set<std::string> keysName = parseStringToWords(name_);
	std::set<std::string> keysCategory = parseStringToWords(category_);
	std::set<std::string> keysSize = parseStringToWords(size_);
	std::set<std::string> keysBrand = parseStringToWords(brand_);

	std::set<std::string> set1 = setIntersection(keysName, keysCategory);
	std::set<std::string> set2 = setIntersection(keysSize, keysBrand);

	return setIntersection(set1, set2);
}  //virtual =0

/**
	* Returns a string to display the product info for hits of the search
	*/
std::string Clothing::displayString() const 
{
	std::string strprice = to_string(price_);
	std::string strqty = to_string(qty_);
	std::string clothing = name_ + "\n Size: " + size_ + " Brand: " + brand_ + "\n" + strprice + " " + strqty + " left.";
	return clothing;
}//virtual =0

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Clothing::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ <<  "\n" << size_ << "\n" << brand_ << endl;
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
