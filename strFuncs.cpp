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
    //so i didnt know how to do it with const so i copied s1 so i could modify its value
    string s2 = s1;
    //if the lowercase first char and lowercase last char are equal
    if (tolower(s2.at(0))==(tolower(s2.at(s2.length()-1)))){
        //if there is only 1 or 2 chars left and they are equal then it is a plaindrome so return true
        if (s1.length() == 1 || s1.length() == 2) {
            return true;
        }
        //if longer than 2 erase the first and last chars and then call again on shortened string
        s2.erase(0,1);
        s2.erase(s1.length()-2);
        return isPalindrome(s2);
    }
    //if they are not equal then its not a palindrome so return false
    return false;
}
