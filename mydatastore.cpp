#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <vector>
#include "product.h"
#include "user.h"
#include "mydatastore.h"
#include "datastore.h"
#include "util.h"
#include <cstddef>


using namespace std;

// MyDataStore::MyDataStore () {


MyDataStore::~MyDataStore() {
	for (unsigned int i = 0; i < users_.size(); i++) 
	{
		delete users_[i];
	}
	for (unsigned int i = 0; i < prods_.size(); i++) 
	{
		delete prods_[i];
	}
}

/**
	* Adds a product to the data store
	*/
void MyDataStore::addProduct(Product* p)
{
	prods_.push_back(p);

} //virtual =0

/**
	* Adds a user to the data store
	*/
void MyDataStore::addUser(User* u)
{
	users_.push_back(u);
} //virtual =0

/**
	* Performs a search of products whose keywords match the given "terms"
	*  type 0 = AND search (intersection of results for each term) while
	*  type 1 = OR search (union of results for each term)
	*/
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
	std::vector<Product*> matchingProds;
	if (type) //or
	{
		for (unsigned int i = 0; i < prods_.size(); i++)
		{
			for (unsigned int j = 0; j < terms.size(); j++)
			{
				std::set<std::string> currentProdKeys = prods_[i]->keywords();
				for(std::set<std::string>::iterator it = currentProdKeys.begin(); it != currentProdKeys.end(); i++)
				{
					if (currentProdKeys.find(terms[j]) != currentProdKeys.end())
					{
						matchingProds.push_back(prods_[i]);
					}
				}
			}
		}
	}
	else { //and
		std::set<std::string> termsSet;
		std::set<std::string> currentInter;
		for (unsigned int j = 0; j < terms.size(); j++)
		{
			termsSet.insert(terms[j]);
		}
		for (unsigned int i = 0; i < prods_.size(); i++) {
			std::set<std::string> currentProdKeys = prods_[i]->keywords();
			currentInter = setIntersection(termsSet, currentProdKeys);
			if (currentInter.size() == termsSet.size())
			{
				matchingProds.push_back(prods_[i]);
			}
		}
	}
	return matchingProds;
} //virtual =0

/**
	* Reproduce the database file from the current Products and User values
	*/
void MyDataStore::dump(std::ostream& ofile)
{
	std::cout << "<products>" << std::endl;
	for (unsigned int i = 0; i < prods_.size(); i++)
	{
		prods_[i]->dump(ofile);
	}
	std::cout << "</products>" << std::endl;
	std::cout << "<users>" << std::endl;
	for (unsigned int i = 0; i < users_.size(); i++)
	{
		users_[i]->dump(ofile);
	}
	std::cout << "</users>" << std::endl;
} //virtual =0

User* MyDataStore::getUser(std::string un) {
	for (unsigned int i = 0; i < users_.size(); i++)
	{
		if (users_[i]->getName() == un)
		{
			return users_[i];
		}
	}
	return NULL;
}


