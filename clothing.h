#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"


class Clothing : public Product{ // public so that book can call products fxs

public:
// constructor
// add two parameters frroom the Clothing constructpr
Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
    

//keywords();
std::set<std::string> keywords() const;

//displayStrngs();
std::string displayString() const; 


// dump();
void dump(std::ostream& os) const;

// destructor
~Clothing();



// the data members that are private
private:

// size of clothing item
std::string size_;
//brand name
std::string brand_; 



};

#endif

