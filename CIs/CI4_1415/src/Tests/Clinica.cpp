
#include "Clinica.h"

#include <algorithm>

//Animal

Animal::Animal(string umNome, string umaEspecie, int numeroConsultas):
nome(umNome), especie(umaEspecie), numConsultas(numeroConsultas)
{}

string Animal::getNome() const
{ return nome; }

string Animal::getEspecie() const
{ return especie; }

int Animal::getNumConsultas() const
{ return numConsultas; }

void Animal::incNumConsultas()
{ numConsultas++; }


// Veterinario

Veterinario::Veterinario(string umNome):nome(umNome)
{}

string Veterinario::getNome() const
{ return nome; }

list<string> Veterinario::getAnimais() const
{ return meusAnimais; }

void Veterinario::addAnimal(string umNomeAnimal)
{ meusAnimais.push_back(umNomeAnimal); }


// Consulta

Consulta::Consulta(int umaHora, int umDia, int umMes, string umNomeAnimal):
	hora(umaHora), dia(umDia), mes(umMes), nomeAnimal(umNomeAnimal)
{}

string Consulta::getNomeAnimal() const
{ return nomeAnimal; }

int Consulta::getHora() const { return hora; }
int Consulta::getDia() const { return dia; }
int Consulta::getMes() const { return mes; }


void ConsultasVet::addConsulta(const Consulta &c1)
{ minhasConsultas.insert(c1); }


//Clinica

Clinica::Clinica()
{}

list<ConsultasVet> Clinica::getConsultasDisponiveis() const
{ return consultasDisponiveis; }

hashAnimal Clinica::getAnimais() const
{ return animais; }

priority_queue<Veterinario> Clinica::getVeterinarios() const
{ return veterinarios; }

void Clinica::addConsultasDisponiveisVet(const ConsultasVet &v1)
{ consultasDisponiveis.push_front(v1); }

void Clinica::addAnimal(const Animal &a1)
{ animais.insert(a1); }

void Clinica::addVeterinario(const Veterinario &v1)
{ veterinarios.push(v1); }


/////////////////////////////////////////////////////////////////////////

void Clinica::addConsultas(const vector<Consulta> consultas1, string nomeVet) {
    //TODO
    bool found = false;
    list<ConsultasVet> tempConsultasDisponiveis = consultasDisponiveis;
    for(auto it = tempConsultasDisponiveis.begin(); it != tempConsultasDisponiveis.end(); it++){
        if(it->nomeVeterinario == nomeVet){
            found = true;
            for(const auto& c : consultas1)
                it->addConsulta(c);
        }
    }
    if(!found){
        ConsultasVet newCV(nomeVet);
        for(const auto& c : consultas1)
            newCV.addConsulta(c);
        consultasDisponiveis.push_front(newCV);
    }
}

list<Consulta> Clinica::veConsultasDisponiveis(int dia1, int dia2, int mesC, string nomeVet) const {
    //TODO
    list<Consulta> res;
    list<ConsultasVet> tempAvailableConsults = consultasDisponiveis;
    for(auto it = tempAvailableConsults.begin(); it != tempAvailableConsults.end(); it++){
        if(it->nomeVeterinario == nomeVet){
            auto tempMyConsults = it->minhasConsultas;
            for(BSTItrIn<Consulta> BSTiter(tempMyConsults); !BSTiter.isAtEnd(); BSTiter.advance()){
                auto currentConsult = BSTiter.retrieve();
                if((currentConsult.getMes() == mesC) && (dia1 <= currentConsult.getDia()) && (currentConsult.getDia() <= dia2))
                    res.push_back(currentConsult);
            }
        }
    }
    return res;
}

bool Clinica::marcaConsulta(int &horaC, int &diaC, int &mesC, string nomeAnimal, string nomeVet) {
    //TODO
    Consulta consultToFind(horaC, diaC, mesC, nomeAnimal);
    auto it = find_if(consultasDisponiveis.begin(), consultasDisponiveis.end(), [nomeVet](const ConsultasVet& cv){
        return nomeVet == cv.nomeVeterinario;
    });
    if(it == consultasDisponiveis.end()) return false;
    BSTItrIn<Consulta> BSTiter(it->minhasConsultas);
    for(; !BSTiter.isAtEnd(); BSTiter.advance()) {
        auto& currentConsult = BSTiter.retrieve();
        if((currentConsult.getMes()) == mesC && (currentConsult.getDia() == diaC) &&
        (currentConsult.getHora() == horaC) || ((consultToFind < currentConsult))){
            horaC = currentConsult.getHora();
            diaC = currentConsult.getDia();
            mesC = currentConsult.getMes();
            it->minhasConsultas.remove(currentConsult);
            return true;
        }
    }
    return false;
}

Animal Clinica::fimConsulta(string umNomeAnimal, string umNomeEspecie) {
    //TODO
    for(auto it = animais.begin(); it != animais.end(); it++){
        if(it->getNome() == umNomeAnimal){
            Animal animal = *it;
            animais.erase(it);
            Animal newAnimal(animal.getNome(), animal.getEspecie(), animal.getNumConsultas() +1);
            animais.insert(newAnimal);
            return newAnimal;
        }
    }
    Animal newAnimal = Animal(umNomeAnimal, umNomeEspecie, 1);
    animais.insert(newAnimal);
    return newAnimal;
}

int Clinica::numAnimaisEspecie(string umNomeEspecie) const {
    int counter = 0;
    for(auto it = animais.begin(); it != animais.end(); it++){
        if(it->getEspecie() == umNomeEspecie)
            counter++;
    }
    return counter;
}

Veterinario Clinica::alocaVeterinario(string umNomeAnimal) {
    //TODO
    if(veterinarios.empty()) return Veterinario("");
    Veterinario assignVet = veterinarios.top();
    veterinarios.pop();
    assignVet.addAnimal(umNomeAnimal);
    veterinarios.push(assignVet);
    return assignVet;
}

list<string> Clinica::veterinariosMaisN(int n) const {
    //TODO
    list<string> res;
    priority_queue<Veterinario> tempVets = veterinarios;
    while(!tempVets.empty()){
        auto currentVet = tempVets.top();
        tempVets.pop();
        if(currentVet.getAnimais().size() > n)
            res.push_front(currentVet.getNome());
    }
    return res;
}

//TODO: Implementar corretamente o construtor e inicializacao da BST!
ConsultasVet::ConsultasVet(string umNomeVet): nomeVeterinario(umNomeVet),
		minhasConsultas(Consulta(0,0,0)){

}


bool Consulta::operator < (const Consulta &c2) const {
	//TODO: Implementar corretamente o operador
	if(mes == c2.getMes()){
	    if(dia == c2.getDia())
	        return getHora() < c2.getHora();
	    return dia < c2.getDia();
	}
	return mes < c2.getMes();
}

bool Veterinario::operator<(const Veterinario& v1) const{
	//TODO: Implementar corretamente o operador
	if(meusAnimais.size() == v1.getAnimais().size())
	    return nome > v1.getNome();
	return meusAnimais.size() > v1.getAnimais().size();
}

