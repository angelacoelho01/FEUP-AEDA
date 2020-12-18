/*
 * ReadingClub.cpp
 *
 *  Created on: 11/12/2016
 *      Author: RRossetti
 */

#include "ReadingClub.h"

ReadingClub::ReadingClub(): catalogItems(BookCatalogItem("", "", 0)) {
	//do nothing!
}

ReadingClub::ReadingClub(vector<Book*> books): catalogItems(BookCatalogItem("", "", 0)) {
	this->books = books;
}

void ReadingClub::addBook(Book* book) {
	this->books.push_back(book);
}

void ReadingClub::addBooks(vector<Book*> books) {
	this->books = books;
}

vector<Book*> ReadingClub::getBooks() const{
	return this->books;
}

BookCatalogItem ReadingClub::getCatalogItem(string title, string author) {
	BookCatalogItem itemNotFound("", "", 0);
	BSTItrIn<BookCatalogItem> it(catalogItems);
	while (!it.isAtEnd())
	{
		if( it.retrieve().getTitle() == title && it.retrieve().getAuthor() == author) {
			BookCatalogItem bci(it.retrieve().getTitle(), it.retrieve().getAuthor(), 0);
			bci.setItems(it.retrieve().getItems());
			return bci;
		}
		it.advance();
	}
	return itemNotFound;
}

void ReadingClub::addCatalogItem(Book* book) {
	BookCatalogItem itemNotFound("", "", 0);
	BookCatalogItem bci(book->getTitle(), book->getAuthor(), book->getYear());
	BookCatalogItem bciX = catalogItems.find(bci);
	if(bciX == itemNotFound) {
		bci.addItems(book);
		this->catalogItems.insert(bci);
	}
	else {
		this->catalogItems.remove(bciX);
		bciX.addItems(book);
		this->catalogItems.insert(bciX);
	}
	books.push_back(book);
}

BST<BookCatalogItem> ReadingClub::getCatalogItems() const {
	return this->catalogItems;
}

vector<UserRecord> ReadingClub::getUserRecords() const {
	vector<UserRecord> records;
	HashTabUserRecord::const_iterator it1 = this->userRecords.begin();
	HashTabUserRecord::const_iterator it2 = this->userRecords.end();
	for(; it1 != it2; it1++) {
			records.push_back(*it1);
	}
	return records;
}

void ReadingClub::setUserRecords(vector<UserRecord>& urs) {
	for(int i = 0; i < urs.size(); i++) userRecords.insert(urs[i]);
}

priority_queue<User> ReadingClub::getBestReaderCandidates() const {
	return readerCandidates;
}
void ReadingClub::setBestReaderCandidates(priority_queue<User>& candidates) {
	readerCandidates = candidates;
}



//
// TODO: Part I   - BST
//

void ReadingClub::generateCatalog() {
	//TODO:
	for(const auto& book : books) {
	    bool found = false;
	    BookCatalogItem bookCI(book->getTitle(), book->getAuthor(), book->getYear());
	    BSTItrIn<BookCatalogItem> BSTiter(catalogItems);
	    for(; !BSTiter.isAtEnd(); BSTiter.advance()){
	        auto& currentBookCI = BSTiter.retrieve();
	        if(currentBookCI == bookCI) {
                currentBookCI.addItems(book);
                found = true;
            }
	    }
	    if(!found){
	        bookCI.addItems(book);
	        catalogItems.insert(bookCI);
	    }
    }
}

vector<Book*> ReadingClub::getAvailableItems(Book* book) const {
	vector<Book*> temp;
	//TODO:
	BSTItrIn<BookCatalogItem> BSTiter(catalogItems);
	BookCatalogItem bookCI(book->getTitle(), book->getAuthor(), book->getYear());
	for(; !BSTiter.isAtEnd(); BSTiter.advance()){
	    auto currentBookCI = BSTiter.retrieve();
	    if(currentBookCI == bookCI){
	        for(const auto& b : currentBookCI.getItems()){
	            if(b->getReader() == nullptr)
	                temp.push_back(b);
	        }
	    }
	}
	return temp;
}

bool ReadingClub::borrowBookFromCatalog(Book* book, User* reader) {
	//TODO:
    BSTItrIn<BookCatalogItem> BSTiter(catalogItems);
    BookCatalogItem bookCI(book->getTitle(), book->getAuthor(), book->getYear());
    for(; !BSTiter.isAtEnd(); BSTiter.advance()){
        auto& currentBookCI = BSTiter.retrieve();
        if(currentBookCI == bookCI){
            for(const auto& b : currentBookCI.getItems()){
                if(b->getReader() == nullptr){
                    reader->addReading(book->getTitle(), book->getAuthor());
                    b->setReader(reader);
                    return true;
                }
            }

        }
    }
	return false;
}


//
// TODO: Part II  - Hash Table
//

void ReadingClub::addUserRecord(User* user) {
	//TODO:
	userRecords.insert(user);

}

void ReadingClub::changeUserEMail(User* user, string newEMail) {
	//TODO:
	user->setEMail(newEMail);
}


//
// TODO: Part III - Priority Queue
//

void ReadingClub::addBestReaderCandidates(const vector<User>& candidates, int min) {
	//TODO:
    for(const auto& user : candidates){
        unsigned numReads = user.getReadings().size() + (user.getReading() != pair<string, string>() ? 1 :0);
        if(numReads >= min)
            readerCandidates.push(user);
    }

}

int ReadingClub::awardReaderChampion(User& champion) {
	//TODO:
	if(readerCandidates.empty()) return 0;
    auto top1 = readerCandidates.top();
    unsigned numMax1 = top1.getReadings().size() + (top1.getReading() != pair<string, string>() ? 1 : 0);
    readerCandidates.pop();
    auto top2 = readerCandidates.top();
    unsigned numMax2 = top2.getReadings().size() + (top2.getReading() != pair<string, string>() ? 1 : 0);
    readerCandidates.push(top1);
    if(numMax1 == numMax2) return 0;
    champion = top1;
	return readerCandidates.size();
}
























