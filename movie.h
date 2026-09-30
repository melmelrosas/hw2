#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"


class Movie : public Product{ // public so that book can call products fxs

public:
// constructor
// add two parameters frroom the Clothing constructpr
Movie(const std::string category, const std::string name, double price, int qty, const std::string rating, const std::string genre);
    

//keywords();
std::set<std::string> keywords() const;

//displayStrngs();
std::string displayString() const; 


// dump();
void dump(std::ostream& os) const;

// destructor
~Movie();



// the data members that are private
private:


std::string rating_;
//brand name
std::string genre_; 



};

#endif

