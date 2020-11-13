/*
 * Hospital.cpp
 */

#include "Hospital.h"


Hospital::Hospital(unsigned trayC):trayCapacity(trayC) {
}

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}


//-------------------------------------------------------------------------


unsigned Hospital::numPatients(string medicalSpecialty) const{
	unsigned counter = 0;
	for(auto it = doctors.begin(); it != doctors.end(); it++)
	    if(it->getMedicalSpecialty() == medicalSpecialty) counter+=it->getPatients().size();
	return counter;
}

void Hospital::sortDoctors() {
	doctors.sort([](const Doctor& d1,const Doctor& d2){
	    if(d1.getPatients().size() == d2.getPatients().size()){
	        if(d1.getMedicalSpecialty() == d2.getMedicalSpecialty())
	            return d1.getCode() < d2.getCode();
	        return d1.getMedicalSpecialty() < d2.getMedicalSpecialty();
	    }
	    return d1.getPatients().size() < d2.getPatients().size();
	});

}

bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
	unsigned counter = 0;
	for(auto it = doctors.begin(); it != doctors.end(); it++){
	    if(it->getMedicalSpecialty() == medicalSpecialty1) counter++;
	}
	if(counter >= 3) return false;
    doctors.push_back(Doctor(codM1, medicalSpecialty1));
    return true;
}

queue<Patient> Hospital::removeDoctor(unsigned codM1) {
    queue<Patient> patients;
	for(auto it = doctors.begin(); it != doctors.end(); it++){
	    if(it->getCode() == codM1) {
            patients = it->getPatients();
            doctors.erase(it);
            return patients;
        }
	}
	throw DoctorInexistent();
}

bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
    bool foundSpeciality = false;
    unsigned lessBusyQueue = doctors.begin()->getPatients().size();
    auto itLessBusyDoctor = doctors.begin();
    for(auto it = doctors.begin(); it != doctors.end(); it++){
        if(it->getMedicalSpecialty() == medicalSpecialty1){
            foundSpeciality = true;
            if(it->getPatients().size() < lessBusyQueue){
                lessBusyQueue = it->getPatients().size();
                itLessBusyDoctor = it;
            }
        }
    }
    if(foundSpeciality){
        itLessBusyDoctor->addPatient(Patient(cod1, medicalSpecialty1));
        return true;
    }
	return false;
}



void Hospital::processPatient(unsigned codM1) {
    bool processedPatient = false;
    Patient removedPatient(0, "");
    auto it = doctors.begin();
    for(it; it != doctors.end(); it++) {
        if (it->getCode() == codM1)
            removedPatient = it->removeNextPatient();
    }
    for(auto iter = letterTray.begin(); iter != letterTray.end(); iter++){
        if(iter->size() < trayCapacity) {
            processedPatient = true;
            iter->push(removedPatient);
            break;
        }
    }
    if(!processedPatient) {
        stack<Patient> aux;
        aux.push(removedPatient);
        letterTray.push_back(aux);
    }
}


unsigned Hospital::removePatients(unsigned codP1) {
    unsigned counter = 0;
	for(auto it = letterTray.begin(); it != letterTray.end(); it++){
	    if(it->top().getCode() == codP1) {
            counter++;
            it->pop();
            if (it->empty()) {
                auto removeIt = it; it--;
                letterTray.erase(removeIt);
            }
        }
	}
    return counter;
}



