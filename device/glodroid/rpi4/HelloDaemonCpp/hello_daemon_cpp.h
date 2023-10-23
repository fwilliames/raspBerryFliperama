#pragma once                            // Inclui esse cabeçalho apenas uma vez

#include <log/log.h>                    // LogCat
#include <stdio.h>      // Função sleep
#include <string>
#include <cstring>
#include <unistd.h>

using namespace std;

namespace devtitans::hello {            // Pacote que a classe abaixo pertence

class HelloDaemonCpp {                  // Classe

    public:
        void startDaemon();             // Método público

    private:
        void pinMode(char pin[], char mode[], size_t npin, size_t nmode);
        void digitalWrite(char pin[], char value[], size_t nvalue);
        //void cleanUp(char pin[]); // nao esta funcionando corretamente




};

} // namespace
