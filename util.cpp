#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{

// step 1 is to read over the input string char by a loop
// decalire the set of strongs and string currret

    string current;
    set<string>wordList; 
// call the convToLower fx
    rawWords = convToLower(rawWords); // rawWords is the input string

  for(unsigned int i = 0; i < rawWords.size(); i++ ){
    // if statement to check if the current character is a num
    if(isalnum (rawWords[i])){
      current += rawWords[i]; // append one charcater at a time
    }
    else{ // will handle the case for when the word ends 
      if (current.size() >= 2){
        wordList.insert(current);
        
      }
        current.clear(); // reset the string 
        
    }
  }if(current.size() >= 2){
    wordList.insert(current);
  }
  return wordList;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
