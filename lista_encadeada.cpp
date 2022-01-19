#include <stdlib.h>
#include <new>
#include <iostream>
#include <string>

using namespace std;

void limpaTela(){

    system("CLS");

}

struct pessoa{

    string nome;
    int rg;
    struct pessoa *proximo;

};


int retornaTamanho(pessoa *ponteiroEncadeada){

    if(ponteiroEncadeada->nome == ""){

        return 0;
    }

    int tamanho = 0;

    pessoa *p = ponteiroEncadeada;

    while(p != NULL){
        p = p->proximo;

        tamanho++;

   }

   return tamanho;

}

void imprimeEncadeada(pessoa *ponteiroEncadeada){

    pessoa *p = ponteiroEncadeada;

    while(p != NULL){

        cout << p->nome << "," << p->rg << "\n";

        p = p->proximo;



   }

}

void adcComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor-> nome = nome;
    novoValor->rg = rg;

    if(ponteiroEncadeada->nome == ""){
        novoValor->proximo = NULL;

    }else{
        novoValor->proximo = ponteiroEncadeada;
    }

    ponteiroEncadeada = novoValor;

}

void adcFimEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor-> nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeada;

    while(p != NULL){

        //faz ele apontar para um novo valor
        if(p->proximo == NULL){

            p->proximo= novoValor;
            return;

        }

        p = p->proximo;
    }

}

void adcPosicaoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg, int posicao){

    pessoa *novoValor = new pessoa;
    novoValor-> nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeada;

    //contador

    int cont = 0;

    while(cont <= posicao){

        if(cont == posicao -1){

            pessoa *aux = new pessoa;

            // armazena o proximo valor
            aux->proximo = p->proximo;

            //coloca o novo valor como o proximo dele
            p->proximo = novoValor;

            novoValor->proximo = aux->proximo;

            free(aux);

        }


        //atualiza para o proximo item

        p = p->proximo;

    }

}

void removeInicioEncadeada(pessoa *&ponteiroEncadeada){

    if(ponteiroEncadeada->proximo == NULL){

        pessoa *novoValor = new pessoa;
        novoValor->nome = "";
        novoValor->rg = 0;
        novoValor->proximo = NULL;

        ponteiroEncadeada = novoValor;

    }else{

        ponteiroEncadeada = ponteiroEncadeada->proximo;

    }

}

void removeFimEncadeada(pessoa *&ponteiroEncadeada){

    //auxiliares

    pessoa *p = new pessoa;
    pessoa *aux = new pessoa;

    p = ponteiroEncadeada;

    while(p->proximo != NULL){

        aux = p;
        p = p->proximo;
    }

    aux->proximo = NULL;

}

void removePosicaoEncadeada(pessoa *&ponteiroEncadeada, int posicao){

    pessoa *p = ponteiroEncadeada;

    int cont = 0;

    while(cont <= posicao){

        if(cont == posicao - 1){
            pessoa *aux = new pessoa;

            aux = p->proximo;

            p->proximo = aux->proximo;

            free(aux);


        }

        p = p->proximo;

        cont++;

    }

}

string retornaNomeEncadeada(pessoa *&ponteiroEncadeada, int rg){

    string nome = "Não Encontrado";

    pessoa *p = ponteiroEncadeada;

    while(p->proximo != NULL){

        if(p->rg == rg){

            nome = p->nome;

            return nome;
        }

        p = p->proximo;
    }

    return nome;
}


int main(){

    int funcaoDesejada = 1;

    pessoa *ponteiroEncadeada = new pessoa;
    ponteiroEncadeada->nome = "";
    ponteiroEncadeada->rg = 0;
    ponteiroEncadeada->proximo = NULL;

    /*pessoa *ponteiroEncadeada;


    pessoa *novoPrimeiroValor = new pessoa;
    novoPrimeiroValor->nome = "jonh";
    novoPrimeiroValor->rg = 123;
    novoPrimeiroValor->proximo = NULL;

    ponteiroEncadeada = novoPrimeiroValor;

    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "Jorge";
    novoSegundoValor->rg = 393;
    novoSegundoValor->proximo = NULL;

    novoPrimeiroValor->proximo = novoSegundoValor;*/


    while(funcaoDesejada < 9 && funcaoDesejada > 0){
    cout << "Tamanho da função:" << retornaTamanho(ponteiroEncadeada)<< "\n";
    cout << "Operacoes \n";
    cout << "1 - Insercao de um node no inicio da lista\n";
    cout << "2 - Insercao de um node no fim da lista\n";
    cout << "3 - Insercao de um node na posicao x na lista\n";
    cout << "4 - Retirar de um node no inicio da lista\n";
    cout << "5 - Retirar de um node no fim da lista\n";
    cout << "6 - Retirar de um node na posicao x na lista\n";
    cout << "7 - Procurar Rg\n";
    cout << "8 - Imprimir a Lista\n";
    cout << "9 - Sair do Sistema\n";
    cout << "Escolha um numero e aperte Enter\n\n";
    cout << "Tamanho da funcao:" << retornaTamanho(ponteiroEncadeada)<< "\n";


    if(retornaTamanho(ponteiroEncadeada)==0){

        cout << "\nLista Vazia";

    }else{
        imprimeEncadeada(ponteiroEncadeada);
    }

    cin >> funcaoDesejada;

    limpaTela();

    string nome;
    int rg;

    switch(funcaoDesejada){

        case 1:
            cout << "Funcao Escolhida 1\n";

            cout <<  "\n Digite o nome:";
            cin >> nome;
            cout << "\n Digite o Rg:";
            cin >> rg;

            adcComecoEncadeada(ponteiroEncadeada, nome, rg);

            break;

        case 2:
            cout << "Funcao Escolhida 2\n";
            cout <<  "\n Digite o nome:";
            cin >> nome;
            cout << "Digite o Rg:";
            cin >> rg;

            if(retornaTamanho(ponteiroEncadeada)==0){

            adcComecoEncadeada(ponteiroEncadeada, nome, rg);

            }else{
            adcFimEncadeada(ponteiroEncadeada, nome, rg);
            }

            break;

        case 3:

            int posicao;
            cout << "Funcao Escolhida 3\n";
            cout << "Digite a posicao";
            cin >> posicao;
            cout <<  "\n Digite o nome:";
            cin >> nome;
            cout << "Digite o Rg:";
            cin >> rg;

            if(posicao == 0){
                adcComecoEncadeada(ponteiroEncadeada, nome, rg);
            }else if(posicao == retornaTamanho(ponteiroEncadeada)-1){
                adcFimEncadeada(ponteiroEncadeada, nome, rg);
            }else{

                adcPosicaoEncadeada(ponteiroEncadeada, nome, rg, posicao);

            }

            if(retornaTamanho(ponteiroEncadeada)==0){

            adcComecoEncadeada(ponteiroEncadeada, nome, rg);

            }else{
            adcFimEncadeada(ponteiroEncadeada, nome, rg);
            }

            break;

        case 4:

            removeInicioEncadeada(ponteiroEncadeada);

            break;

        case 5:

            if(retornaTamanho(ponteiroEncadeada)==0){

            adcComecoEncadeada(ponteiroEncadeada, nome, rg);

            }else{
            removeFimEncadeada(ponteiroEncadeada);
            }

            break;

        case 6:

            cout << "Digite a posicao";
            cin >> posicao;

            if(posicao == 0){

                removeFimEncadeada(ponteiroEncadeada);

            }else if(retornaTamanho(ponteiroEncadeada)-1){

                removeFimEncadeada(ponteiroEncadeada);

            }else{
                removePosicaoEncadeada(ponteiroEncadeada, posicao);
            }


            break;

        case 7:

            cout<< "Digitr o RG:";
            cin >> rg;

            cout << "O nome do Rg é:" << rg << "eh:" << retornaNomeEncadeada(ponteiroEncadeada, rg);

            break;

    }

    }
    return 0;




}
