#pragma once
#include "Ente.hpp"
#include "GerenciadorEstados.hpp"

namespace Castelos_e_ruinas{

    namespace Estados{

        class Estado:public Ente{
        protected:
            static Gerenciadores::Gerenciador_Estados* pGEstado;
        public:
            Estado(const IDs::ID ID);
            virtual ~Estado();
            void setRemover(const bool Remover);
            const bool getRemover();
            virtual void executar() = 0;
            //virtual void mudarEstadoObserver() = 0;
        };
    }
}