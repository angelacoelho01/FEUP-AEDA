/*
 * Cinema.cpp
 */
#include "Cinema.h"

Cinema::Cinema(string nm, unsigned d, unsigned nr): name(nm), distance(d),
		numberOfRooms(nr),timetable(FilmTime(0,NULL, 0))
{}

Cinema::Cinema(string nm, unsigned d, unsigned nr, list<string> ls): name(nm), distance(d),
		numberOfRooms(nr),services(ls), timetable(FilmTime(0,NULL,0))
{}

Cinema::~Cinema() { }

string Cinema::getName() const
{ return name; }

unsigned Cinema::getDistance() const
{ return distance; }

list<string> Cinema::getServices() const
{ return services; }

BST<FilmTime> Cinema::getTimetable() const
{ return timetable; }

void Cinema::addService(string service1)
{ services.push_back(service1); }

void Cinema::addFilmTime(const FilmTime &ft1)
{ timetable.insert(ft1); }


// TODO

bool Cinema::operator<(const Cinema & cr) const {
    //TODO: Implement a correct version of the operator
    if (getDistance() == cr.getDistance())
        return getServices().size() > cr.getServices().size();
    return getDistance() > cr.getDistance();
}


//a1
Film *Cinema::filmAtHour(unsigned &h1) const {
	Film *res = NULL;
	// TODO
	unsigned hour;
	BSTItrIn<FilmTime> BSTiter(timetable);
	for(; !BSTiter.isAtEnd(); BSTiter.advance()){
	    auto currentFilmTime = BSTiter.retrieve();
	    if(currentFilmTime.getHour() <= h1) {
            res = currentFilmTime.getFilm();
            hour = currentFilmTime.getHour();
        }
	}
	if(res != NULL) h1 = hour;
	return res;
}


//a2
bool Cinema::modifyHour(unsigned h1, unsigned room1, unsigned h2) {
	// TODO
	bool found = false;
	vector<FilmTime> foundFilmsTime;
	BSTItrIn<FilmTime> BSTiter(timetable);
	for(; !BSTiter.isAtEnd(); BSTiter.advance()){
        unsigned hour = h1;
        auto currentFilmTime = BSTiter.retrieve();
	    if(currentFilmTime.getRoomID() == room1){
            if(currentFilmTime.getHour() == h2) return false;
            else if(currentFilmTime.getHour() == h1){
                found = true;
                foundFilmsTime.push_back(currentFilmTime);
            }
	    }
	}
	if(found){
	    for(const auto filmTime : foundFilmsTime){
            timetable.remove(filmTime);
            addFilmTime(FilmTime(h2, filmTime.getFilm(), room1));
	    }
	}
    return found;
}


//a3
unsigned Cinema::addFilm(Film *f1, unsigned h1) {
	// TODO
    unsigned maxIDRoom = 1;
    if(timetable.isEmpty()){
	    addFilmTime(FilmTime(h1, f1, maxIDRoom));
	    return maxIDRoom;
	}
	BSTItrIn<FilmTime> BSTiter(timetable);
    for(; !BSTiter.isAtEnd(); BSTiter.advance()){
	    auto& currentFilmTime = BSTiter.retrieve();
        unsigned hour = h1;
        Film* film = filmAtHour(hour);
        if(currentFilmTime.getRoomID() > maxIDRoom) maxIDRoom = currentFilmTime.getRoomID();
	    if((hour < h1) || (film == NULL)){
	        addFilmTime(FilmTime(h1, f1, currentFilmTime.getRoomID()));
	        return currentFilmTime.getRoomID();
	    }
	}
    if(++maxIDRoom <= numberOfRooms) {
       addFilmTime(FilmTime(h1, f1, maxIDRoom));
       return maxIDRoom;
    }
	return 0;
}






