#include <iostream>
#include <string>
#include <servidor.h>
#include <memlog.h>

using namespace std;

    Servidor::Servidor(){
        primeiro = new Usuario();
        ultimo = primeiro;
   }

    Servidor::~Servidor(){ //preciso chamar o destrutor????? em variavel n precisa
        Limpa();
        delete primeiro;
    }

    Usuario* Servidor::Posiciona(int pos, bool antes = false){
        Usuario *p; int i;
        if((pos > tamanho) ||(pos <= 0)){
            cout << "ERRO:  Posicao Invalida!";
        }
        p = primeiro; //posiciona na celula anterior a desejada
        for(i = 1; i<pos; i++){
            p = p->prox;
        }

        if(!antes){
            p = p->prox;
        }

        return p;
    }



    void Servidor::InsereFinal(Usuario *usuario){

        if(usuario->Id < 0 || usuario->Id > 1000000){ // Estratégia de robustez para caso o id não atenda aos limites. Nada acontece.

        }else{
            if(Pesquisa(usuario) == 1){
                cout << "ERRO:  CONTA " << usuario->Id <<" JA EXISTENTE" << endl;
            }else{
                Usuario *nova;
                nova = new Usuario(); //
                nova->Id = usuario->Id;
                ultimo->prox = nova;
                ultimo =  nova;
                tamanho++;
                cout << "OK:  CONTA " << usuario->Id <<" CADASTRADA" << endl;
                
            }
        }

    }

  

    Usuario Servidor::RemovePosicao(int pos){
        Usuario aux;
        Usuario *p, *q;

        if(tamanho == 0){
          
        }
        
        p = Posiciona(pos, true);
        q = p->prox;
        p->prox = q->prox;
        tamanho--;
        aux.Id = q->Id;
        q->Limpa();
        delete q;
        if(p->prox == NULL){
            ultimo = p;
        }
        return aux;
    }

    bool Servidor::Pesquisa(Usuario *usuario){
        Usuario aux;
        Usuario *p;
        bool existente = false;

        if(tamanho == 0){
           
        }
        p = primeiro->prox;
        aux.Id = -1;
        while(p!=NULL){
            if(p->Id == usuario->Id){
                aux.Id = p->Id;
                existente = true;
                break;
            }
            p = p->prox;
        }
        return existente;
    }



    void Servidor::Limpa(){
        Usuario *p;
        p = primeiro->prox;
        while(p!=NULL){
            primeiro->prox = p->prox;
            delete p;
            p = primeiro->prox;
        }
        ultimo = primeiro;
        tamanho = 0;
    }

     void Servidor::RemoveId(int id){
        Usuario aux;
        Usuario *p;
        bool existente = false;
        int posicaoAux = 0;

        if(tamanho == 0){
            cout << "ERRO: CONTA " << id << " NÃO EXISTE" << endl;
        }
        p = primeiro->prox;
        aux.Id = -1;
        while(p!=NULL){
            posicaoAux++;
            if(p->Id == id){
                RemovePosicao(posicaoAux);
                cout << "OK: Conta " << id << " removida" << endl;
                break;
            }
            p = p->prox;
        }

     }



    void Servidor::ConsultaID(int id){
        Usuario aux;
        Usuario *p;
        bool existente = false;
        int posicaoAux = 0;

        if(tamanho == 0){
            cout << "ERRO: CONTA " << id << " NÃO EXISTENTE" << endl;
        }
        p = primeiro->prox;
        aux.Id = -1;
        while(p!=NULL){
            posicaoAux++;
            if(p->Id == id){
                p->RemoveInicio();
                break;
            }
            p = p->prox;
        }


    }

    void Servidor::EnviaMsgID(int id, Mensagem mensagem){
        Usuario aux;
        Usuario *p;
        bool existente = false;
        int posicaoAux = 0;

        if(mensagem.getPrioridade() < 0 || mensagem.getPrioridade() > 9){

        }else{
            if(tamanho == 0){
                cout << "CONTA " << id << " NÃO EXISTENTE" << endl;
            }
            p = primeiro->prox;
            aux.Id = -1;
            while(p!=NULL){
                posicaoAux++;
                if(p->Id == id){
                    p->InserePrioridade(mensagem);
                    cout << "OK: MENSAGEM PARA " <<p->Id << "ENTREGUE"<< endl;
                    break;
                }
                p = p->prox;
            }

        }
    }