#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase)
{
    if ( phrase.length() == 0 ) return 0;

    unsigned n=1;
    size_t pos = phrase.find(' ');
    while (pos != string::npos) {
        phrase = phrase.substr(pos+1);
        pos = phrase.find(' ');
        n++;
    }
    return n;
}

// TODO
Game::Game() :
    kids(list<Kid>()){}

// TODO
Game::Game(list<Kid>& l2) :
    kids(l2){}

//Insert a kid to the end of the list
void Game::addKid(const Kid &k1){
    kids.insert(kids.end(), k1);
}

// TODO
list<Kid> Game::getKids() const{
    return kids;
}

// TODO
string Game::write() const{
    ostringstream out;
    for(const auto& kid : kids)
        out << kid.write() << endl;
    return out.str();
}

// TODO
Kid& Game::loseGame(string phrase)
{
    auto it = kids.begin();
    while(kids.size() != 1){
        auto itEnd = kids.end();
        itEnd--;
        for(int i = 1; i < numberOfWords(phrase); i++){
            if(it == itEnd)
                it = kids.begin();
            else
                it++;
        }
        kids.erase(it);
        it = kids.begin();
    }
    return *it;
}

// TODO
list<Kid>& Game::reverse(){
    kids.reverse();
    return kids;
}

// TODO
list<Kid> Game::removeOlder(unsigned id){
    list<Kid> result;
    auto it = kids.begin();
    while(it != kids.end()){
        if(it->getAge() > id){
            result.push_back(*it);
            kids.erase(it);
            it = kids.begin();
        }
        else
            it++;
    }

    return result;
}

// TODO
void Game::setKids(const list<Kid>& l1){
    kids = l1;
}

// TODO
bool Game::operator==(Game& g2)
{
    return kids == g2.getKids();
}

// TODO
list<Kid> Game::shuffle() const
{
    list<Kid> result;
    for(const auto kid : kids) {
        unsigned position = (rand() % kids.size()) - 1;
        auto it = result.begin();
        std::advance(it, position);
        result.insert(it, kid);
    }
    return result;
}
