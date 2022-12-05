#include "strFuncs.h"
#include <cctype>

using namespace std;


/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 *
 * Palindromes are NOT case-sensitive - "RaCecaR" is a valid palindrome
 *
 *You should provide a recursive solution*/
bool isPalindrome(const string s1){
    //STUB: Replace the following with the correct code.
    string s2 = s1;
    if (tolower(s2.at(0))==(tolower(s2.at(s2.length()-1)))){
        if (s1.length() == 1 || s1.length() == 2) {
            return true;
        }
        s2.erase(0,1);
        s2.erase(s1.length()-2);
        return isPalindrome(s2);
    }
    return false;
}
