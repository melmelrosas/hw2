#include "book.h"
#include <sstream>
#include "util.h"

using namespace std;


Book::Book(const std::string category, const std::string name, double price, int qty, const std::string author_name, const std::string ISBN) :

  Product(category, name, price, qty), //parent var to call
  Author(author_name),
  IdentificationNum(ISBN)

{

}



string Book::displayString()const{
    // we can use string stream to parse the space
    stringstream ss;
    ss << name_ << "\n";
    // will write the books name to the var

    // nnext is the author
    ss << "Author: " << Author << " ISBN: " << IdentificationNum << "\n";
    // price qty lefy over
    ss << price_ << " " <<  qty_ << " left."; 
    return ss.str();
      
    }

// keywords()
set<string> Book:: keywords() const{
  // call parsefx on name and author and create a new set to hold the result

// new set will be call set_keywords
set<string> set_keywords,  name_words, author_words;
    name_words = parseStringToWords(name_);
    author_words = parseStringToWords(Author);

    // call set union on both list
    set_keywords = setUnion(name_words, author_words);
    set_keywords.insert(IdentificationNum);
    
  return set_keywords; }

// destructor
Book::~Book(){
}
// void fx
  void Book::dump(ostream& os) const{
// call Product variables first
Product::dump(os);
// then ostrea the IBSM and author
    os << IdentificationNum << "\n";
    os<< Author << endl;}
