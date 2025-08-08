#include <iostream>
#include <string>


using namespace std;

class Mensagem{ //declaração da celula da fila de prioridade

    private:
    int prioridade;
    string texto;
    Mensagem *prox;

    public:
    Mensagem();
    Mensagem(int prioridade, string texto);
    ~Mensagem();
    int getPrioridade();
    void setPrioridade(int prioridade);
    string getTexto();
    void setTexto(string texto);
    void imprime();

    friend class Usuario;
};