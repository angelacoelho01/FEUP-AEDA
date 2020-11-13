#include "Kart.h"

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
    bool avariados[3]  = {true,false,false};

    srand (1);   //Criar Pistas e Karts de Teste
    for(int i=1;i<=50;i++){
        vector<CKart> frota;
        for(int j=1;j<=50;j++){
            frota.push_back(CKart(avariados[rand()% 3],
                                  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
        }
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}

vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}
 
//Exercicio 1 a)     
vector<CKart> CGrupo::ordenaKarts(){
    vector<CKart> sortedKarts;
	for(auto p : pistasG){
	    for(auto k : p.getFrotaActual())
	        sortedKarts.push_back(k);
	}
	sort(sortedKarts.begin(), sortedKarts.end(), [](CKart k1, CKart k2){
	   return k1.getNumero() < k2.getNumero();
	});
	return sortedKarts;
}

//Exercicio 1 b)  
int CGrupo::numAvariados(int cilind){
    int kartsAvariados = 0;
    for(auto& p : pistasG){
        for(auto& k : p.getKartsAvariados()) {
            if (((int)k.getCilindrada()) == cilind)
                kartsAvariados++;
        }
    }
    return kartsAvariados;
}

//Exercicio 1 c)   
bool CPista::prepararCorrida(int numeroKarts, int cilind){
    vector<CKart> selectedKarts;
    for(auto& k : frotaKartsPista){
        if(((int)k.getCilindrada()) == cilind && !k.getAvariado() && kartsLinhaPartida.size() <= numeroKarts)
            kartsLinhaPartida.push(k);
    }
    if(kartsLinhaPartida.size() < numeroKarts) return false;
    return true;
}

//Exercicio 1 d) 
int CPista::inicioCorrida(){
    int numKartsEmProva = 0;
    while(!kartsLinhaPartida.empty()){
        kartsEmProva.push_back(kartsLinhaPartida.front());
        kartsLinhaPartida.pop();
        numKartsEmProva++;
    }
    return numKartsEmProva;
}
