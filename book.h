#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"


class Book : public Product{ // public so that book can call products fxs

public:
// constructor
// add two parameters frroom the Product constructpr
Book(const std::string category, const std::string name, double price, int qty, const std::string author_name, const std::string ISBN);
    

//keywords();
std::set<std::string> keywords() const;

//displayStrngs();
std::string displayString() const; 


// dump();
void dump(std::ostream& os) const;

// destructor
~Book();



// the data members that are private
private:

// author of book 
std::string Author;
//ISBN number
std::string IdentificationNum; 



};

#endif

