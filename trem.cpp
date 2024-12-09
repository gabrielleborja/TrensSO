#include "trem.h"
#include <QtCore>

// Inicializa static mutexes
QMutex Trem::mutex1(QMutex::Recursive);
QMutex Trem::mutex2(QMutex::Recursive);
QMutex Trem::mutex3(QMutex::Recursive);
QMutex Trem::mutex4(QMutex::Recursive);
QMutex Trem::mutex5(QMutex::Recursive);
QMutex Trem::mutex6(QMutex::Recursive);
QMutex Trem::mutex7(QMutex::Recursive);

//Construtor
Trem::Trem(int ID, int x, int y, int velocidadeInicial) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = velocidadeInicial;
}

void Trem::setVelocidade(int v) {
    velocidade = v;
}

//Função a ser executada após executar trem->START
void Trem::run() {
    while(true) {
        switch(ID) {
        case 1: // Trem 1 - top left
            verificaRegiaoCritica();
            if (y == 30 && x < 330)
                x += 10;
            else if (x == 330 && y < 150)
                y += 10;
            else if (x > 60 && y == 150)
                x -= 10;
            else
                y -= 10;
            break;

        case 2: // Trem 2 - top right
            verificaRegiaoCritica();
            if (y == 30 && x < 600)
                x += 10;
            else if (x == 600 && y < 150)
                y += 10;
            else if (x > 330 && y == 150)
                x -= 10;
            else
                y -= 10;
            break;

        case 3: // Trem 3 - bottom left
            verificaRegiaoCritica();
            if (y == 280 && x < 270)
                x += 10;
            else if (x == 270 && y < 400)
                y += 10;
            else if (x > 0 && y == 400)
                x -= 10;
            else
                y -= 10;
            break;

        case 4: // Trem 4 - bottom middle
            verificaRegiaoCritica();
            if (y == 280 && x < 520)
                x += 10;
            else if (x == 520 && y < 400)
                y += 10;
            else if (x > 240 && y == 400)
                x -= 10;
            else
                y -= 10;
            break;

        case 5: // Trem 5 - bottom right
            verificaRegiaoCritica();
            if (y == 280 && x < 770)
                x += 10;
            else if (x == 770 && y < 400)
                y += 10;
            else if (x > 520 && y == 400)
                x -= 10;
            else
                y -= 10;
            break;
        }

        emit updateGUI(ID, x, y); //Emite um sinal
        msleep(velocidade);
    }
}

void Trem::verificaRegiaoCritica() {
    switch(ID) {
    case 1:
        if (x == 310 && y == 30) {
            mutex1.lock();
            mutex2.lock();
        }
        if (x == 310 && y == 140) {
            mutex1.unlock();
            mutex2.unlock();
        }
        break;

    case 2:
        if (x == 330 && y == 30) {
            mutex1.lock();
            mutex3.lock();
        }
        if (x == 330 && y == 140) {
            mutex1.unlock();
            mutex3.unlock();
        }
        break;

    case 3:
        if (x == 0 && y == 260) {
            mutex2.lock();
            mutex4.lock();
            mutex6.lock();
        }
        if (x == 270 && y == 260) {
            mutex2.unlock();
            mutex4.unlock();
            mutex6.unlock();
        }
        break;

    case 4:
        if (x == 240 && y == 260) {
            mutex3.lock();
            mutex4.lock();
            mutex5.lock();
            mutex6.lock();
        }
        if (x == 520 && y == 260) {
            mutex3.unlock();
            mutex4.unlock();
            mutex5.unlock();
            mutex6.unlock();
        }
        break;

    case 5:
        if (x == 520 && y == 260) {
            mutex5.lock();
            mutex7.lock();
        }
        if (x == 770 && y == 260) {
            mutex5.unlock();
            mutex7.unlock();
        }
        break;
    }
}

