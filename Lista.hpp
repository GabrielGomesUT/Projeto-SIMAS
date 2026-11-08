#pragma once
#include "Elemento.hpp"

namespace Castelos_e_ruinas{

    namespace Listas{

        template<class TL>
        class Lista{
        private:
            Elemento<TL>* pPrimeiro;
            Elemento<TL>* pAtual;
            int tam;
        public:
            Lista();
            ~Lista();
            void incluirElemento(Elemento<TL>* p);
            void incluirInfo(TL* pInfo);
            void removeElemento(TL* pE);
            void limpar();
            int getTam() const;
            TL* operator[](int pos);
        };

        template<class TL>
        Lista<TL>::Lista():tam(0){
            pPrimeiro = NULL;
            pAtual = NULL;
        }

        template<class TL>
        Lista<TL>::~Lista(){
            limpar();
        }

        template<class TL>
        void Lista<TL>::incluirElemento(Elemento<TL>* p){
            if(p != NULL){
                if(pPrimeiro == NULL){
                    pPrimeiro = p;
                    pAtual = p;
                }
                else{
                    pAtual->setProx(p);
                    pAtual = p;
                }
                tam++;    
            }
            else
                cerr<<"Ponteiro nulo para incluir"<<endl;
        }

        template<class TL>
        void Lista<TL>::limpar(){
            Elemento<TL>* pAux;
            Elemento<TL>* pAux2;
            pAux = pPrimeiro;
            while(pAux != NULL){
                pAux2 = pAux->getPRoximo();
                delete pAux;
                pAux = pAux2;
            }
            pPrimeiro = NULL;
            pAtual = NULL;
        }

        template<class TL>
        int Lista<TL>::getTam() const{
            return tam;
        }

        template<class TL>
        void Lista<TL>::incluirInfo(TL* pInfo){
            if(pInfo != NULL){
                Elemento<TL>* pAux = NULL;
                pAux = new Elemento<TL>();
                pAux->incluir(pInfo);
                incluirElemento(pAux);
            }
            else
                cerr<<"Ponteiro de informacao nulo"<<endl;
        }

        template<class TL>
        void Lista<TL>::removeElemento(TL* pE){
            if((pE != NULL) && (pPrimeiro != NULL)){
                Elemento<TL>* pAux = NULL;
                if(pPrimeiro->getInfo() == pE){
                    pAux = pPrimeiro;
                    pPrimeiro = pAux->getPRoximo();
                    delete pAux;
                    pAux = NULL;
                }
                else{
                    for(pAux = pPrimeiro ; pAux->getPRoximo() != NULL ; pAux = pAux->getPRoximo()){
                        if(pAux->getPRoximo()->getInfo() == pE){
                            pAux->setProx(pAux->getPRoximo()->getPRoximo());
                            delete pAux->getPRoximo();
                            break;
                        }                    
                    }
                }
            }

        }

        template<class TL>
        TL* Lista<TL>::operator[](int pos){
            if((pos > 0) || (pos < tam)){
                int i = 0;
                Elemento<TL>* pAux = pPrimeiro;
                for(i = 0;i < pos;i++){
                    pAux = pAux->getPRoximo();
                }
                return pAux->getInfo();
            }
            else{
                cerr<<"Posicao invalida"<<endl;
                return NULL;
            }
        }

    }
}