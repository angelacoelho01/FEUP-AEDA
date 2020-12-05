#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "bst.h"


class WordMeaning {
        string word;
        string meaning;
        public:
        WordMeaning(string w, string m): word(w), meaning(m) {}
        string getWord() const { return word; }
        string getMeaning() const { return meaning; }
        void setWord(string w) {word=w; }
        void setMeaning(string m) { meaning=m; }
        bool operator < (const WordMeaning &wm1) const;
};


class Dictionary
{
    BST<WordMeaning> words;
public:
    Dictionary(): words(WordMeaning("","")){};
    BST<WordMeaning> getWords() const;
    void readDictionary(ifstream &f);
    string searchFor(string word) const;
    bool correct(string word, string newMeaning);
    void print() const;
};


//TODO
class WordInexistent{
    iteratorBST<WordMeaning> _itBefore, _itAfter;
public:
    WordInexistent(iteratorBST<WordMeaning> itBefore, iteratorBST<WordMeaning> itAfter) : _itBefore(move(itBefore)), _itAfter(move(itAfter)){};
    string getWordBefore() const { return _itBefore.operator*().getMeaning(); }
    string getMeaningBefore() const { return _itBefore.operator*().getMeaning(); }
    string getWordAfter() const { return _itAfter.operator*().getWord(); }
    string getMeaningAfter() const { return _itAfter.operator*().getMeaning(); }
};

#endif