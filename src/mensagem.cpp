#include <iostream>
#include <string>
#include <mensagem.h>

using namespace std;


Mensagem::Mensagem(){
    this->prioridade = 0;
    this->texto = " ";
}

Mensagem::Mensagem(int prioridade, string texto){
    this->prioridade = prioridade;
    this->texto = texto;
}

Mensagem::~Mensagem(){
}

int Mensagem::getPrioridade(){
    return this->prioridade;
}

void Mensagem::setPrioridade(int prioridade){
    this->prioridade =  prioridade;
}

string Mensagem::getTexto(){
    return  this->texto;
}

void Mensagem::setTexto(string texto){
    this->texto = texto;
}
