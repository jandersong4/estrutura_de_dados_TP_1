#include <iostream>
#include <string>
#include <servidor.h>
#include <fstream>
#include <memlog.h>
#include <string.h>




using namespace std;

int main(int argc, char **argv){
    
    Servidor servidorEmail;
   
    ifstream arquivo;
    arquivo.open(argv[1]);
    if (!arquivo.is_open()) {
        cout << "Arquivo não foi aberto." << endl;
        return 1;
    }
    
    string operacao , stringAux, mensagem; //string utilizada apenas para identificar o comando passado
    int id,prioridade;
    Mensagem mensagemAuxiliar;
    int i = 0;

    while (!arquivo.eof()){
        operacao = "";
        id = 0;
        arquivo >> operacao;
        if(operacao == "CADASTRA"){
            arquivo >> id;
            Usuario *usuarioAux = new Usuario();
            usuarioAux->SetId(id);
            servidorEmail.InsereFinal(usuarioAux);
        
         }else if(operacao == "CONSULTA"){
             arquivo >> id;
             servidorEmail.ConsultaID(id);
         }else if(operacao == "REMOVE"){
            arquivo >> id;
            servidorEmail.RemoveId(id);
         }else if(operacao == "ENTREGA"){
            arquivo >> id;
            arquivo >> prioridade;
            stringAux = " ";
            arquivo >> mensagem;
            arquivo >> stringAux;

            while (stringAux != "FIM"){
                mensagem = mensagem + " " + stringAux;
                arquivo >> stringAux;
            }
            
            mensagemAuxiliar.setPrioridade(prioridade);
            mensagemAuxiliar.setTexto(mensagem);
            servidorEmail.EnviaMsgID(id,mensagemAuxiliar);
         }
        
    };


    return 0;
}

