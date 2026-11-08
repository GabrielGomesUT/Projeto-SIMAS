#pragma once
#include <iostream>
using namespace std;

namespace Castelos_e_ruinas{

    namespace Listas{

        template<class TE>
        class Elemento{
        private:
            Elemento<TE>* pProx;
            TE* pInfo;
        public:
            Elemento();
            ~Elemento();
            void incluir(TE* p);
            void setProx(Elemento<TE>* pE);
            Elemento<TE>* getPRoximo() const; 
            TE* getInfo() const;
        };

        template<class TE>
        Elemento<TE>::Elemento(){
            pProx = NULL;
            pInfo = NULL;
        }

        template<class TE>
        Elemento<TE>::~Elemento(){

        }

        template<class TE>
        void Elemento<TE>::incluir(TE* p){
            pInfo = p;
        }

        template<class TE>
        void Elemento<TE>::setProx(Elemento<TE>* pE){
            pProx = pE;
        }

        template<class TE>
        Elemento<TE>* Elemento<TE>::getPRoximo() const{
            return pProx;
        }

        template<class TE>
        TE* Elemento<TE>::getInfo() const{
            return pInfo;
        }
    }
}