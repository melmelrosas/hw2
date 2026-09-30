#include "clothing.h"
#include <sstream>
#include <iomanip>
#include "util.h"

using namespace std;


Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :

  Product(category, name, price, qty), //parent var to call
  size_(size),
  brand_(brand)

{

}



string Clothing::displayString()const{
    // we can use string stream to parse the space
    stringstream ss;
    ss << name_ << "\n";
    // will write the books name to the var

    // nnext is the Size
    ss << "Size: " << size_ << " Brand: " << brand_ << "\n";
    //Brand
    ss << price_ << " " <<  qty_ << " left."; 
    return ss.str();
      
    }

// keywords()
set<string> Clothing:: keywords() const{
  // call parsefx on name and author and create a new set to hold the result

// new set will be call set_keywords
set<string> set_keywords, set_name, set_brand;
    set_name = parseStringToWords(name_);
    set_brand = parseStringToWords(brand_);

    // call set union on both list
    set_keywords = setUnion(set_name, set_brand);
    
  return set_keywords;
 }

// destructor
Clothing::~Clothing(){
}
// void fx
  void Clothing::dump(ostream& os) const{
// call Product variables first
Product::dump(os);
// then ostrea the IBSM and author
    os << size_ << "\n";
    os<< brand_ << endl;}
