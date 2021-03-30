/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: Word class
   The Word object that stores word's keyword, a string contains five words 
   before the keyword, a string contains five words after the keyword and a 
   lowercase form of the keyword.
*/

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Word 
{
   public:
//--------------------------------------------------------------
//                  CONSTRUCTORS & DESTRUCTOR
//--------------------------------------------------------------
   //default contructor
   Word();

   //copy constructor takes 3 strings: keyword, 1 string contains 5 words 
   //before and 1 string contains 5 word after keyword.
   Word(string, string, string);

   //destructor
   ~Word();

//--------------------------------------------------------------
//                        FUNCTIONS
//--------------------------------------------------------------
   //pre-condition: the keyword valid
   //return: keyword value
   string getWord() const;

   //pre-condition: the lowercase keyword valid
   //return: lowercase keyword value
   string getWordLower() const;

   //pre-condition: the beforeWord string valid
   //return: beforeWord value
   string getBeforeWord() const;

   //pre-condition: the afterWord string valid
   //return: afterWord value
   string getAfterWord() const;

//--------------------------------------------------------------
//                       OPERATORS OVERLOAD
//--------------------------------------------------------------
   //pre-condition: word object valid
   //post-condition: printout keyword and its context(before keyword and after keyword strings)
   //function called: Word::getWord(), Word::getBeforeWord(), Word::getAfterWord()
   //return: out_stream
   friend ostream& operator<<(ostream& out_stream, const Word &word);

   //class operator that takes other Word object to compare
   //pre-condition: word and the comparison word objects valid
   //post-condition: compare if this word < other by their lower case keyword (case insensitive)
   //function called: Word::getWordLower()
   //return: keywordLower_
   bool operator<(const Word&) const;

   //class operator that takes other Word object to compare
   //pre-condition: word and the comparison word objects valid
   //post-condition: compare if this word > other by their lower case keyword (case insensitive)
   //function called: Word::getWordLower()
   //return: keywordLower_
   bool operator>(const Word&) const;

   //class operator that takes other Word object to compare
   //pre-condition: word and the comparison word objects valid
   //post-condition: compare if 2 words are equal by their lower case keyword (case insensitive)
   //function called: Word::getWordLower()
   //return: keywordLower_
   bool operator==(const Word&) const;


   private:  
//--------------------------------------------------------------
//                        VARIABLES
//--------------------------------------------------------------
   string keyword_;        //keyword
   string beforeWord_;     //5 words before keyword
   string afterWord_;      //5 words after keyword
   string keywordLower_;   //lower case form of keyword

};

