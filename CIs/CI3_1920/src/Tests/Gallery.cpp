#include "Gallery.h"
#include <ostream>
#include <algorithm>

using namespace std;

Gallery::Gallery(vector<Paint*> c): catalog(PaintCatalogItem("", "", 0, 0.00)), collection(c) {

}

vector<Paint*> Gallery::getCollection() const {
    return collection;
}

void Gallery::setCollection(vector<Paint*> c) {
    collection = c;
}

priority_queue<ExhibitionItem> Gallery::getPaintsToShow() const {
    return paintsToShow;
}
HashTableAuthorRecord Gallery::getAuthorRecords () const {
    return  authorRecords;
}

void Gallery::addAuthorRecord(AuthorRecord ar) {
    authorRecords.insert(ar);
}

void Gallery::generateCatalog() {
    catalog.makeEmpty();
    for(int i = 0; i < collection.size(); i++) {
        catalog.insert(collection[i]);
    }
}

BST<PaintCatalogItem> Gallery::getCatalog() const {
    return catalog;
}


void Gallery::prepareExhibition() {
    while( !paintsToShow.empty())
        paintsToShow.pop();
    for(int i = 0; i < collection.size(); i++) {
        ExhibitionItem ei(collection[i]);
        paintsToShow.push(ei);
    }
}

//-------------------------------------------------------------------------------

//TODO
vector<Paint*> Gallery::getPaintsBy(string a) const {
    vector<Paint*> res;
    for(auto it = catalog.begin(); it != catalog.end(); it++)
        if(it.operator*().getAuthor() == a) res.push_back(it.operator*().getPaint());
    return res;
}

//TODO
vector<Paint*> Gallery::getPaintsBetween(int y1, int y2) const {
    vector<Paint*> res;
    for(auto it = catalog.begin(); it != catalog.end(); it++)
        if((y1 <= it.operator*().getYear()) && (it.operator*().getYear() <= y2)) res.push_back(it.operator*().getPaint());
    return res;
}

//TODO
bool Gallery::updateTitle(Paint* p, string tnew) {
    Paint* newPaint = new Paint(p->getAuthor(), tnew, p->getYear(), p->getPrice());
    for(auto it  = catalog.begin(); it != catalog.end(); it++) {
        if (it.operator*() == p){
            catalog.remove(it.operator*());
            catalog.insert(newPaint);
            return true;
        }
    }
    catalog.insert(newPaint);
    return false;
}


//TODO
int Gallery::recordAvailablePainters() { //carrega a tabela de dispersao com AuthorRecords
    for(unsigned i = 0; i < collection.size(); i++){
        Paint* paint = collection.at(i);
        AuthorRecord ar =  AuthorRecord(paint->getAuthor());
        auto it = find_if(authorRecords.begin(), authorRecords.end(), [ar](const AuthorRecord& p){
            return ar.getAuthor() == p.getAuthor();
        });
        if(it == authorRecords.end()){
            ar.setTotalSells(paint->getPrice());
            authorRecords.insert(ar);
        }
        else{
            AuthorRecord temp = it.operator*();
            temp.addAvaliablePaint();
            temp.setTotalSells(temp.getTotalSells()+paint->getPrice());
            authorRecords.erase(it);
            authorRecords.insert(temp);
        }
    }
    return authorRecords.size();
}

//TODO
double Gallery::totalSells() const {
    double counter = 0;
    for(auto it = authorRecords.begin(); it != authorRecords.end(); it++)
        counter += it->getTotalSells();
    return counter;
}

//TODO
double Gallery::sellPaint(string a, string t) {
    double price = 0;
    auto it = find_if(collection.begin(), collection.end(), [t](const Paint* p){
        return p->getTitle() == t;
    });
    if(it != collection.end()) {
        price = it.operator*()->getPrice();
        auto iter = find_if(authorRecords.begin(), authorRecords.end(), [a](const AuthorRecord &ar) {
            return a == ar.getAuthor();
        });
        if (iter != authorRecords.end()) {
            AuthorRecord temp = *iter;
            temp.subAvailablePaint();
            temp.setTotalSells(temp.getTotalSells() + price);
            authorRecords.erase(iter);
            authorRecords.insert(temp);
        }
        collection.erase(it);
    }
    return price;

}

//TODO
vector<Paint*> Gallery::nBestExibition(int n, int maxPerYear) {  //escolhe as N mais caras pinturas, dos anos mais antigos, para realizar uma exposição
    vector<Paint*> paints;
    priority_queue<ExhibitionItem> temp ;
    while(!paintsToShow.empty()){
        ExhibitionItem top = paintsToShow.top();
        paintsToShow.pop();
        if(n > 0){
            int year = top.getYear();
            int counter = count_if(paints.begin(), paints.end(), [year](const Paint* p){
                return year == p->getYear();
            });
            if(counter < maxPerYear) {
                paints.push_back(top.getPaint());
                n--;
            }
            else temp.push(top);
        }
        else temp.push(top);
    }
    paintsToShow = temp;
    return paints;
}

//TODO
int Gallery::itemExibitionOrder(string a, string t) {
    int order = 0;
    priority_queue<ExhibitionItem> temp = paintsToShow;
    while(!temp.empty()){
        order++;
        ExhibitionItem top = temp.top();
        temp.pop();
        if((top.getAuthor() == a) && (top.getTitle() == t)) return order;
    }
    return 0;
}

