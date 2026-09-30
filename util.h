#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
 // declare our resulted new set which is empty
std::set<T> newList;
// have an interator to loop over the first set then use the .find() fx to see if its in the other set
// declare iterator first
// typename std::set< T>:: iterator it; // so an iterator for our set int
for(typename std::set< T>:: iterator it = s1.begin(); it !=s1.end(); ++it){
  // .. begin() will point to the furst item and end will point to one step past the last item
// check if our iterator iten from s1 is in s2.find ... if yes add it to our new newList

  if(s2.find(*it) != s2.end() ){
    newList.insert(*it); // we would insett the item that the it* is at to the newList
  }

}
return newList;
}


template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
// ok so for setUnion we will iterate over the set as wekk abd create a new set w no dupes and just one 
// item of each set
// declare our returned set 
std::set<T> UnionedList;
for(typename std::set< T>:: iterator it = s1.begin(); it !=s1.end(); ++it){
  // just insert into our Unioned list since sets dont carry dupes
    // add the *it to our new newList
    UnionedList.insert(*it);
}
for(typename std::set< T>:: iterator it = s2.begin(); it !=s2.end(); ++it){
  // just insert into our Unioned list since sets dont carry dupes
    // add the *it to our new newList
    UnionedList.insert(*it);
}
// return 
return UnionedList;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
