#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Book : public Product {
public:
    Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
    
		~Book();

    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    std::set<std::string> keywords() const;  //virtual =0

    /**
     * Allows for a more detailed search beyond simple keywords
     */
    bool isMatch(std::vector<std::string>& searchTerms) const; //virtual

    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const; //virtual =0

    /**
     * Outputs the product info in the database format
     */
    void dump(std::ostream& os) const; //virtual

    /**
     * Accessors and mutators
     */
    // double getPrice() const;
    // std::string getName() const;
    // int getQty() const;
    // void subtractQty(int num);

	private:
		std::string isbn_;
		std::string author_;
		std::string name_;
    double price_;
    int qty_;
    std::string category_;
// protected:
//     std::string name_;
//     double price_;
//     int qty_;
//     std::string category_;

};
#endif
