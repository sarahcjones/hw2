#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <set> //sarah u added this
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
	std::stringstream ss(rawWords);
	std::string temp; //temporary holder for every word
	std::string kw = ""; //kw short for keyword
	std::set <std::string> keywords;
	while (ss >> temp)
	{
		for (unsigned int i=0; i < temp.size(); i++)
		{
			if ((temp[i] > 47 && temp[i] < 58) || (temp[i] > 64 && temp[i] < 91) 
			|| (temp[i] > 96 && temp[i] < 123) || temp[i] == 43 || temp[i] == 45) //all the ascii values that aren't punctuation
			{
					kw += temp[i];
			}
		}
		if (kw.size() > 1)
		{
				keywords.insert(kw);
		}
		kw = "";
	}
	return keywords;
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
