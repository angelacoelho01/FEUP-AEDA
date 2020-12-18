/*
 * CinemaFinder.cpp
 */

#include "CinemaFinder.h"
#include "Cinema.h"
#include "Film.h"
#include <algorithm>

CinemaFinder::CinemaFinder() { }

CinemaFinder::~CinemaFinder() { }

void CinemaFinder::addFilm(Film *f1) {
	FilmPtr fp1;
	fp1.film = f1;
	films.insert(fp1);
}

void CinemaFinder::addCinema(const Cinema &c1)
{ cinemas.push(c1); }

tabHFilm CinemaFinder::getFilms() const
{ return films; }

priority_queue<Cinema> CinemaFinder::getCinemas() const
{ return cinemas; }


// TODO


//b1
list<string> CinemaFinder::filmsWithActor(string actorName) const {
	list<string> res;
	// TODO
    bool found = false;
    for(auto it = films.begin(); it != films.end(); it++){
        auto actors = it->film->getActors();
        for(auto itActors = actors.begin(); itActors != actors.end(); itActors++){
            auto currentActorName = *itActors;
            if(currentActorName == actorName)
                res.push_back(it->film->getTitle());
        }
    }
	return res;
}


//b2
void CinemaFinder::addActor(string filmTitle, string actorName) {
	// TODO
	bool found = false;
	for(auto it = films.begin(); it != films.end(); it++){
	    auto currentFilm = it->film;
	    if(currentFilm->getTitle() == filmTitle) {
            found = true;
            currentFilm->addActor(actorName);
        }
	}
	if(!found){
	    FilmPtr newFilm = {new Film(filmTitle)};
	    newFilm.film->addActor(actorName);
	    films.insert(newFilm);
	}
}


//c1
string CinemaFinder::nearestCinema(string service1) const {
	string cName="";
	// TODO
	priority_queue<Cinema> tempCinemas = cinemas;
	while(!tempCinemas.empty()){
	    auto currentCinema = tempCinemas.top();
	    auto currentCinemaServices = currentCinema.getServices();
	    tempCinemas.pop();
	    auto it = find_if(currentCinemaServices.begin(), currentCinemaServices.end(), [service1](const string service2){
	        return service1 == service2;
	    });
	    if(it != currentCinemaServices.end()) return currentCinema.getName();
	}
	return cName;
}


//c2
void CinemaFinder::addServiceToNearestCinema(string service1, unsigned maxDistance) {
	// TODO
	if(cinemas.empty()) throw CinemaNotFound();
	Cinema nearestCinema = cinemas.top();
	cout << "DISTANCE = " <<  nearestCinema.getDistance() << endl;
	if(nearestCinema.getDistance() < maxDistance){
        cinemas.pop();
        nearestCinema.addService(service1);
        cinemas.push(nearestCinema);
    }
	else throw CinemaNotFound();
}
