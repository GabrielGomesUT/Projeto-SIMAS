#pragma once
#include "Ente.hpp"

namespace Castelos_e_ruinas{

    namespace Estados{

        class Estado:public Ente{
        private:
            bool remover;
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