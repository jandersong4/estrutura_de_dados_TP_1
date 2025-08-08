#include <iostream>
#include <string>
#include <usuario.h>

using namespace std;

Usuario::Usuario(){
    primeiro = new Mensagem();
    ultimo = primeiro;
}

Usuario::~Usuario(){
    Limpa();
    delete primeiro;
}

Mensagem* Usuario::Posiciona(int pos, bool antes = false){
    Mensagem *p;

    if((pos>tamanho) || (pos <= 0)){
       
    };

    //posiciona celula anterior a desejada
    p = primeiro;
    for(int i = 1; i<pos;  i++){
        p = p->prox;
    }
    //vai para a proxima se antes for false
    if(!antes){
        p = p->prox;
    }
    return p;
}



void Usuario::SetId(int id){
    this->Id = id;

}

void Usuario::InsereInicio(Mensagem mensagem){
    Mensagem *nova;
    nova =  new Mensagem();
    nova->prioridade = mensagem.prioridade;
    nova->texto = mensagem.texto;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

    if(nova->prox == NULL){
        ultimo = nova;
    }
}



void Usuario::InserePosicao(Mensagem mensagem, int pos){
    Mensagem *p, *nova;

    p = Posiciona(pos,true); //posiciona na celula anterior
    nova = new Mensagem();
    nova->prioridade = mensagem.prioridade;
    nova->texto = mensagem.texto;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;

    if(nova->prox == NULL){
        ultimo = nova;
    }
}

Mensagem Usuario::RemoveInicio(){
    Mensagem aux;
    Mensagem *p;
    if(tamanho == 0){
        cout << "CONSULTA "<< Id << ": CAIXA DE ENTRADA VAZIA " << endl;
    }else{
        p = primeiro->prox;
        primeiro->prox = p->prox;
        tamanho--;
        if(primeiro->prox == NULL){
        ultimo = primeiro;
        }
        aux.prioridade = p->prioridade;
        aux.texto = p->texto;
        cout << "CONSULTA "<< Id << ": " << p->texto << endl;
        delete p;
    }
    return aux;
}



void Usuario::Limpa(){
    Mensagem *p;
    p = primeiro->prox;
    while(p!=NULL){
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

void Usuario::InserePrioridade(Mensagem mensagem){
    Mensagem *p;
    int contadorParaPosicaoIgual = 0;
    int contadorParaPosicaoMaior = 0;
    p = primeiro->prox;

    while(p!=NULL){
        if(p->getPrioridade() == mensagem.getPrioridade()){
            contadorParaPosicaoIgual++;
       
        }else if(p->getPrioridade() > mensagem.getPrioridade()){
            contadorParaPosicaoMaior++;
        }
        p = p->prox;
    }
    Mensagem mensagemAux = mensagem;
    if((contadorParaPosicaoIgual == 0) && (contadorParaPosicaoMaior == 0)){
        InsereInicio(mensagemAux);
    }else{
        InserePosicao(mensagemAux, (contadorParaPosicaoMaior + (contadorParaPosicaoIgual+1)));
    }
   
}

