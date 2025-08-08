#include <iostream>
#include <string>
#include <mensagem.h>

using namespace std;

class Usuario{

    private:
    int tamanho = 0;
    int Id;
    Usuario *prox;
    Mensagem* primeiro;
    Mensagem* ultimo;
    Mensagem* Posiciona(int pos, bool antes);

    public:
    Usuario();
    ~Usuario();
    void InsereInicio(Mensagem mensagem);
    void InserePosicao(Mensagem mensagem, int pos);
    Mensagem RemoveInicio();
    void Imprime();
    void Limpa();
    void InserePrioridade(Mensagem mensagem);
    void SetId(int id);
    
    friend class Servidor;

};