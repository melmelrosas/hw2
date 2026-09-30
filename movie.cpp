#include "movie.h"
#include <sstream>
#include <iomanip>
#include "util.h"

using namespace std;


Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string rating, const std::string genre) :

  Product(category, name, price, qty), //parent var to call
  rating_(rating),
  genre_(genre)
// must add the two new categories
{

}



string Movie::displayString()const{
    // we can use string stream to parse the space
    stringstream ss;
    ss << name_ << "\n";
    // will write the movie name to the var

    // nnext is the Size
    ss << "Genre: " << genre_ << " Rating: " << rating_ << "\n";
    //Brand
    ss << price_ << " " <<  qty_ << " left."; 
    return ss.str();
      
    }

// keywords()
set<string> Movie:: keywords() const{
  // call parsefx on genre and brand and create a new set to hold the result

// new set will be call set_keywords
set<string> set_keywords;
   set_keywords =  parseStringToWords(name_);
    set_keywords.insert(convToLower(genre_));

    
  return set_keywords;
 }

// destructor
Movie::~Movie(){
}
// void fx
  void Movie::dump(ostream& os) const{
// call Product variables first
Product::dump(os);
    os << genre_ << "\n";
    os<< rating_ << endl;
  }
