#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <string>
#include <vector>
#include "datastore.h"
#include <map>
#include <set>


// implement the mydatastore claas
class MyDataStore : public DataStore{
public:
// constructor and desctructo
MyDataStore();

// add the variables from the .h fx
void addProduct(Product* p);


void addUser(User* u);


std::vector<Product*> search(std::vector<std::string>& terms, int type);

void dump(std::ostream& ofile);


bool userExists(std::string username);
void addToCart(std::string username, Product* p);
void viewCart(std::string username);
void buyCart(std::string username);



~MyDataStore();




private:
// declare a vector for our Product*
std::vector <Product*> products_;
// set up the vars

// create a map to find the user to the string
std::map<std::string, User*> users_;



// map for the keywords
std::map<std::string, std::set<Product*> > keyWords_map ;

std::map<std::string, std::vector<Product*> > carts;



};





#endif




