/*****************************************************************
 ** Program: lab4_char_function.cpp
 ** Authors: Chelsea and Sukhjot
 ** Date: 01/27/2020
 ** Description: Different character functions
*****************************************************************/

#include <iostream>
using namespace std;

/*****************************************************************
** Function: is_vowel
** Description: ccheck whether a character is a vowel
** Parameter: a single character, c
** Pre-conditions: c is a lower-case letter (a-z)
** Post-conditions: return true if c is a vowel and otherwise false
******************************************************************/

bool is_vowel(char c)
{
  if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
  {
    return true;
  }
  else
  {
    return false;
  }
}
/******************************************************************
** Function: swap_case
** Description: generate and return the opposite case character
** (lower-case => upper-case and vice-versa)
** Parameters: a single character, c
** Pre-conditions: c is a lower-case (a-z) or upper-case (A-Z) letter
** Post-conditions: if c is lower-case, return upper-case C,
** and vice-versa
******************************************************************/

char swap_case(char c) {
  
  if ((int) c >= 65 && (int) c <= 90) {
    return c + 32;
  } else if ((int) c >= 97 && (int) c <= 122) {
    return c - 32;
  } else {
    return 'E';
  }
}


int main() {
  char c = 'a';
  char vowel = 'a';
  
  cout << "What is the character you want to swap?" <<endl;
  cin >> c;
  
  cout << "\nWhat is the vowel you want to check" <<endl;
  cin >> vowel;
  
  cout << "The swaped case: " << swap_case(c) <<endl;
  cout << "The vowel: " << is_vowel(vowel) <<endl;

  return 0;
}
