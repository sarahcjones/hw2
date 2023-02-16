#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"

class MyDataStore : public DataStore {
public:
    
		// MyDataStore(std::vector<Product*> prods, std::vector<User*> users);
    // MyDataStore();
		~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p); //virtual =0

    /**
     * Adds a user to the data store
     */
    void addUser(User* u); //virtual =0

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type); //virtual =0

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile); //virtual =0

    User* getUser(std::string un);

private:
  std::vector<Product*> prods_;
  std::vector<User*> users_;
};

#endif