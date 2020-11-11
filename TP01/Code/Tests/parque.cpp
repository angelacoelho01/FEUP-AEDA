#include "parque.h"


using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli)
{
    vagas = lot;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome) {
    bool adicionar = true;
    int indice = posicaoCliente(nome);

    //Verifica se há vagas ou se o cliente está registado
    if(vagas == 0 || indice != -1)
        adicionar = false;

    //Verifica se ainda há vagas no registo de clientes
    if(clientes.size() < numMaximoClientes)
    {
        InfoCartao cliente;
        cliente.nome = nome;
        cliente.presente = false;
        clientes.push_back(cliente);
    }
    else
        adicionar = false;

    return adicionar;
}

bool ParqueEstacionamento::retiraCliente(const string &nome) {

    bool podeRetirar = true;
    int indice = posicaoCliente(nome);

    //Verifica se a pessoa faz parte dos clientes ou se está fora do parque
    if(indice == -1 || clientes[indice].presente)
        podeRetirar = false;

    //Retira o cliente do parque se cumprir os requisitos
    if(podeRetirar)
        clientes.erase(clientes.begin()+indice);

    return podeRetirar;
}

bool ParqueEstacionamento::entrar(const string &nome) {

    bool podeEntrar = true;
    int indice = posicaoCliente(nome);

    //Verifica se o cliente está registado ou se está presente
    if(indice == -1 || clientes[indice].presente)
        podeEntrar = false;

    //Verifica se passou nos testes anteriores e se há vagas
    if(podeEntrar && vagas > 0)
    {
        vagas--;
        clientes[indice].presente = true;
    }
    else
        podeEntrar = false;

    return podeEntrar;

}

bool ParqueEstacionamento::sair(const string &nome) {

    bool podeSair = true;
    int indice = posicaoCliente(nome);

    //Verifica se o cliente está registado ou se está dentro do parque
    if(indice == -1 || !clientes[indice].presente)
        podeSair = false;

    //Se o cliente puder sair atualiza as vagas e modifica a sua presença
    if(podeSair)
    {
        vagas++;
        clientes[indice].presente = false;
    }
    
    return podeSair;
}

int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    //Se não for encontrado retorna -1 por defeito
    int posicao = -1;
    //Procura o cliente na lista
    for(int i=0; i<clientes.size();i++)
    {
        //Caso esteja presente retorna o seu índice
        if(clientes[i].nome == nome)
            posicao = i;
    }

    return posicao;
}

unsigned ParqueEstacionamento::getNumLugares() const
{
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const
{
    return numMaximoClientes;
}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const
{
    return lotacao - vagas;
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const
{
    return clientes.size();
}






