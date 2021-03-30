/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: Word class
   The Word object that stores word's keyword, a string contains five words 
   before the keyword, a string contains five words after the keyword and a 
   lowercase form of the keyword. The class printout the word in KWIC format.
*/


#include "Word.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

//default contructor
Word::Word()
{
   keyword_ =  "";
   beforeWord_ = "";
   afterWord_ = "";
   keywordLower_ = "";
}


//copy constructor takes 3 strings: keyword:keyword, before:5 words before keyword
//after: 5 word after keyword.
//set value for keyword_, beforeWord_, afterWord_, and convert keyword to
//lower case and set the value for keywordLower_
Word::Word(string keyword, string before, string after)
{
   keyword_ =  keyword;
   beforeWord_ = before;
   afterWord_ = after;
   keywordLower_ = keyword;     //same value with keyword
   
   //transform keyword to lower case
   transform(keywordLower_.begin(), keywordLower_.end(), keywordLower_.begin(), ::tolower);
}

//destrutor
Word::~Word()
{}


//pre-condition: the keyword valid
//return: keyword value
string Word::getWord() const
{
   return keyword_;
}


//pre-condition: the beforeWord string valid
//return: beforeWord value
string Word::getBeforeWord() const
{
   return beforeWord_;
}


//pre-condition: the afterWord string valid
//return: afterWord value
string Word::getAfterWord() const
{
   return afterWord_;
}


//pre-condition: the lowercase keyword valid
//return: lowercase keyword value
string Word::getWordLower() const
{
   return keywordLower_;
}


//class operator that takes other Word object to compare
//pre-condition: word and the comparison word objects valid
//post-condition: compare if this word < other by their lower case keyword (case insensitive)
//function called: Word::getWordLower()
//return: keywordLower_
bool Word::operator<(const Word& other) const
{
   return keywordLower_ < other.getWordLower();
}


//class operator that takes other Word object to compare
//pre-condition: word and the comparison word objects valid
//post-condition: compare if this word > other by their lower case keyword (case insensitive)
//function called: Word::getWordLower()
//return: keywordLower_
bool Word::operator>(const Word& other) const
{
   return keywordLower_ > other.getWordLower();
}


//class operator that takes other Word object to compare
//pre-condition: word and the comparison word objects valid
//post-condition: compare if 2 words are equal by their lower case keyword (case insensitive)
//function called: Word::getWordLower()
//return: keywordLower_
bool Word::operator==(const Word& other) const
{
   return keywordLower_ == other.getWordLower();
}


//pre-condition: word object valid
//post-condition: printout keyword and its context(before keyword and after keyword strings)
//function called: Word::getWord(), Word::getBeforeWord(), Word::getAfterWord()
//return: out_stream
ostream& operator<<(ostream& out_stream, const Word &word)
{
   out_stream.width(55); out_stream << right << word.getBeforeWord() << "|";
   out_stream << word.getWord() << "|" << word.getAfterWord();
   return out_stream;
}