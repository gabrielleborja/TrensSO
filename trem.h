#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread {
    Q_OBJECT
public:
    Trem(int, int, int, int velocidadeInicial = 100); //construtor
    void run() override; //função a ser executada pela thread
    void setVelocidade(int);

//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
    int x;           //posição X do trem na tela
    int y;           //posição Y do trem na tela
    int ID;          //ID do trem
    int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem

    // Mutexes estaticos para regioes criticas
    static QMutex mutex1, mutex2, mutex3, mutex4, mutex5, mutex6, mutex7;

    // Metodo para testar e navegar regioes criticas
    void verificaRegiaoCritica();
};

#endif // TREM_H
