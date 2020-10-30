#include "game.h"

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

Game::Game() :
    kids(list<Kid>()){}

Game::Game(list<Kid>& l2) :
    kids(l2){}

void Game::addKid(const Kid &k1){
    kids.insert(kids.end(), k1);
}

list<Kid> Game::getKids() const{
    return kids;
}

string Game::write() const{
    ostringstream out;
    for(const auto& kid : kids)
        out << kid.write() << endl;
    return out.str();
}

Kid& Game::loseGame(string& phrase)
{
    auto it = kids.begin();
    auto removeIt = it;
    while(kids.size() != 1){
        std::advance(it, numberOfWords(phrase)-1);
        if(it == kids.end()) it=kids.begin();
        removeIt = it;
        it++;
        if(it == kids.end()) it=kids.begin();
        kids.erase(removeIt);
    }
    return kids.front();
}

list<Kid>& Game::reverse(){
    kids.reverse(); return kids;
}

list<Kid> Game::removeOlder(unsigned id){
    list<Kid> result;
    auto it = kids.begin();
    while(it != kids.end()) {
        if (it->getAge() > id) {
            result.push_back(*it);
            kids.erase(it);
            it = kids.begin();
        }
        else it++;
    }
    return result;
}

void Game::setKids(const list<Kid>& l1){
    kids = l1;
}

bool Game::operator==(Game& g2)
{
    return kids == g2.getKids();
}

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
