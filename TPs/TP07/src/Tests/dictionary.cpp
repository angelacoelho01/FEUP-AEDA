#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "dictionary.h"
#include "bst.h"

using namespace std;

BST<WordMeaning> Dictionary::getWords() const {
    return words;
}

//TODO
bool WordMeaning::operator < (const WordMeaning &wm1) const {
    return word < wm1.getWord();
}

//TODO
void Dictionary::readDictionary(ifstream &f){
    string word, meaning;
    while(!f.eof()){
        getline(f, word);
        getline(f, meaning);
        words.insert(WordMeaning(word, meaning));
    }
}

//TODO
string Dictionary::searchFor(string word) const{
    iteratorBST<WordMeaning> it, itAfter, itBefore;
    for(it = words.begin(); it != words.end(); it++){
        if(it.operator*().getWord() == word) return it.operator*().getMeaning();
        else if(it.operator*().getWord() < word) itBefore = it;
        else{
            itAfter = it;
            break;
        }
    }
    if(it == words.end()) throw WordInexistent(itBefore, itAfter);
}

//TODO
bool Dictionary::correct(string word, string newMeaning){
    iteratorBST<WordMeaning> it;
    for(it = words.begin(); it != words.end(); it++){
        if(it.operator*().getWord() == word) {
            words.remove(it.operator*());
            words.insert(WordMeaning(word, newMeaning));
            return true;
        }
    }
    words.insert(WordMeaning(word, newMeaning));
    return false;
}

//TODO
void Dictionary::print() const {
    BSTItrIn<WordMeaning> it(words);
    for(; !it.isAtEnd(); it.advance())
        cout <<  it.retrieve().getWord() << endl << it.retrieve().getMeaning() << endl;
}
