#include <iostream>
#include <string>
#include <usuario.h>

using namespace std;

class Servidor{

    private:
    int tamanho = 0;
    Usuario* primeiro;
    Usuario* ultimo;
    Usuario* Posiciona(int pos, bool antes);

    public:
    Servidor();
    ~Servidor();
    void InsereFinal(Usuario *usuario);
    Usuario RemovePosicao(int pos);
    bool Pesquisa(Usuario *usuario);
    void Imprime();
    void Limpa();
    void RemoveId(int id);
    void ConsultaID(int id);
    void EnviaMsgID(int id, Mensagem Mensagem);


};