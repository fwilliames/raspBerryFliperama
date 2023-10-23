#include "hello_daemon_cpp.h"


using namespace std;                    // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::hello {            // Entra no pacote devtitans::hello

void HelloDaemonCpp::pinMode(char pin[], char mode[], size_t npin, size_t nmode) {

  FILE *sysfs_export;
  FILE *sysfs_direction;
  char path[40] = "";
  sysfs_export = fopen("/sys/class/gpio/export", "w");
  fwrite(pin, 1, sizeof(npin), sysfs_export);
  fclose(sysfs_export);

  strcpy(path, "/sys/class/gpio/gpio");
  strcat(path, pin);
  strcat(path, "/direction");

  sysfs_direction = fopen(path, "w");
  fwrite(mode, 1, sizeof(nmode), sysfs_direction);
  fclose(sysfs_direction);
}

void HelloDaemonCpp::digitalWrite(char pin[], char value[], size_t nvalue) {
    char path[40];
    FILE *sysfs_value;
    strcpy(path, "/sys/class/gpio/gpio");
    strcat(path, pin);
    strcat(path, "/value");

    sysfs_value = fopen(path, "w");
    fwrite(value, 1, sizeof(nvalue), sysfs_value);
    fclose(sysfs_value);
}


/*void HelloDaemonCpp::cleanUp(char pin[]) {
    FILE *sysfs_unexport;
    sysfs_unexport = fopen("/sys/class/gpio/unexport", "w");
    fwrite(pin, 1, sizeof(pin), sysfs_unexport);
    fclose(sysfs_unexport);
}*/

void HelloDaemonCpp::startDaemon() {    // Implementa o método printHello da classe HelloCpp
    ALOG(LOG_INFO, "DevTITANS", "Daemon Hello iniciando ...");

    //definindo os char array dos modos de operação das portas
    char OUTPUT[] = "out";
    char INPUT[] = "in";

    //definindo as variaveis de tamanho dos arrays de modo
    size_t outPutModeSize = sizeof(OUTPUT) / sizeof(OUTPUT[0]);
    size_t inPutModeSize = sizeof(INPUT) / sizeof(INPUT[0]);

    //definindo os char array dos niveis de tensao das portas
    char HIGH[] = "1";
    char LOW[] = "0";

    //definindo as variaveis de tamanho dos arrays dos valores de tensao das portas
    size_t highValueSize = sizeof(HIGH) / sizeof(HIGH[0]); // pegando o tamanho do value poder AHIGH OU LOW
    size_t lowValueSize = sizeof(LOW) / sizeof(LOW[0]);


    //definindo os char array dos portas
    //char pin18[] = "18";
    char pin6[] = "6";
    char pin8[] = "8";
    char pin15[] = "15";
    char pin16[] = "16";
    char pin17[] = "17";
    char pin23[] = "23";
    char pin25[] = "25";
    //definindo as variaveus de tamanho das portas
    //size_t pin18Size = sizeof(pin18) / sizeof(pin18[0]);
    //size_t pin17Size = sizeof(pin17) / sizeof(pin17[0]);
    size_t pin6Size = sizeof(pin6) / sizeof(pin6[0]);
    size_t pin8Size = sizeof(pin8) / sizeof(pin8[0]);
    size_t pin15Size = sizeof(pin15) / sizeof(pin15[0]);
    size_t pin16Size = sizeof(pin16) / sizeof(pin16[0]);
    size_t pin17Size = sizeof(pin17) / sizeof(pin17[0]);
    size_t pin23Size = sizeof(pin23) / sizeof(pin23[0]);
    size_t pin25Size = sizeof(pin25) / sizeof(pin25[0]);

    ALOG(LOG_INFO, "DevTITANS", "variaveis iniciadas ...");

    /*pinMode(pin18, OUTPUT, pin18Size, outPutModeSize); //setando a porta de 18 para modo de saida
    digitalWrite(pin18, HIGH, highValueSize);*/
    pinMode(pin6, OUTPUT, pin6Size, outPutModeSize); //setando a porta de 18 para modo de saida
    digitalWrite(pin6, HIGH, highValueSize);

    pinMode(pin8, OUTPUT, pin8Size, outPutModeSize); //setando a porta de 18 para modo de saida
    digitalWrite(pin8, HIGH, highValueSize);

    pinMode(pin15, OUTPUT, pin15Size, outPutModeSize); //setando a porta de 18 para modo de saida
    digitalWrite(pin15, HIGH, highValueSize);

    pinMode(pin16, OUTPUT, pin16Size, outPutModeSize); //setando a porta de 18 para modo de saida
    digitalWrite(pin16, HIGH, highValueSize);

    pinMode(pin17, OUTPUT, pin17Size, outPutModeSize); //setando a porta de 18 para modo de saida
    digitalWrite(pin17, HIGH, highValueSize);

    pinMode(pin23, OUTPUT, pin23Size, outPutModeSize); //setando a porta de 18 para modo de saida
    digitalWrite(pin23, HIGH, highValueSize);

    pinMode(pin25, OUTPUT, pin25Size, outPutModeSize); //setando a porta de 18 para modo de saida
    digitalWrite(pin25, HIGH, highValueSize);

    ALOG(LOG_INFO, "DevTITANS", "pinMode Definido ...");

    ALOG(LOG_INFO, "DevTITANS", "Daemon Hello INICIOU ...");

    /*while (true) {

        // Implemente aqui o serviço

        ALOG(LOG_INFO, "DevTITANS", "Blinked");
    }*/

    // Nunca deve chegar aqui ...
}

} // namespace


using namespace devtitans::hello;       // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main() {

    HelloDaemonCpp daemon;              // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    daemon.startDaemon();               // Executa o método printHello
    // Nunca deve chegar aqui ...
    return 0;
}
