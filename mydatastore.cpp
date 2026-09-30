#include "mydatastore.h"
#include "util.h"
#include<iostream>

MyDataStore::MyDataStore(){

}


MyDataStore::~MyDataStore(){
// delete the two loops
  for(unsigned int i = 0; i < products_.size(); i++){
    delete products_[i];
  }
  for(std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
{
  delete it->second;
}


}
void MyDataStore::addProduct(Product* p){

// std::vector <Product*> products_;
products_.push_back(p);
// get the keywords of a string
std::set<std::string> keew = p -> keywords();
// loop over the key words andadd it to the keywords map
for(std::set<std::string>::iterator it = keew.begin(); it!= keew.end(); ++it){
  keyWords_map[*it].insert(p);
}
}


void MyDataStore:: addUser(User* u){

  // stpre the string in a variable first
  std::string NameUser = u->getName();


  // override out nameUsser to lowercase
  NameUser = convToLower(NameUser);
//now we can store the user in the map using their key which was just the name of user
users_[NameUser] = u;

}


std::vector <Product*> MyDataStore::search(std::vector<std::string>& terms,
   int type){
// we need to first get the first term
  // declare results set 

  // create the vector we will return
  std::vector<Product*> complete;

  // case if vector is empty
  if(terms.empty()){
    return complete;
  }
  std::string term;
  std::set<Product*> result = keyWords_map[convToLower(terms[0])];


   // next we have to combine and get the rest of the terns so create a loop
   // start at 1 since we have our 0 index already
    for(unsigned int i = 1; i < terms.size(); i++){
      std::set<Product*> next;
      term = convToLower(terms[i]);

      if(keyWords_map.find(term) != keyWords_map.end()){
        next = keyWords_map[term];
      }

      // case if 0
          if (type == 0){
            //update our result
        result = setIntersection(result, next);
          }else{
            result = setUnion(result, next);
          }
        }
      // call pushback on out vector so it returns the complete 
    for(std::set<Product*>::iterator it = result.begin(); it!=result.end(); ++it){
      complete.push_back(*it);
    }      
    return complete;

    }




void MyDataStore:: dump(std::ostream& ofile){

ofile << "<products>" << "\n";
for(unsigned int i = 0; i<products_.size(); i++){
products_[i]->dump(ofile);
}

// cout it 
ofile<< "</products>" << "\n";


// now the users

ofile << "<users>" << "\n";
for(std::map<std::string, User*>::iterator it = users_.begin(); it!=users_.end(); ++it){
  it->second->dump(ofile);
}


ofile << "</users>" << "\n";
  
}


bool MyDataStore::userExists(std::string username){
    username = convToLower(username);
    return users_.find(username) != users_.end();
}






void MyDataStore::addToCart(std::string username, Product* p){

    username = convToLower(username);

    carts[username].push_back(p);

}
void MyDataStore::viewCart(std::string username){
username = convToLower(username);

  std::vector<Product*>& cart = carts[username];
  for(unsigned int i =0; i <cart.size(); i++){
    std::cout << "Item " << i+1 << std::endl;
    std::cout << cart[i]->displayString() << std::endl;
    std::cout << std::endl;

  }

}


void MyDataStore::buyCart(std::string username){
 username = convToLower(username);
 User* u = users_[username];
  // create the vectors  of cart
std::vector<Product*>& cart = carts[username];
std::vector<Product*> notPurchased;
 
for(unsigned int i =0; i < cart.size(); i++){
  Product* p = cart[i];
  // check if p is on one 
  if(p->getQty() > 0 && u->getBalance() >= p->getPrice()){
    p->subtractQty(1);
    u->deductAmount(p->getPrice());
  }else{
    notPurchased.push_back(p);
    // we can leave it in the cart if it was not purchased
  }
}
cart = notPurchased;

}
