#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,60,30, ui->horizontalSlider->value());
    trem2 = new Trem(2,330,30, ui->horizontalSlider_2->value());
    trem3 = new Trem(3, 0, 280, ui->horizontalSlider_3->value());
    trem4 = new Trem(4,240,280, ui->horizontalSlider_4->value());
    trem5 = new Trem(5,490,280, ui->horizontalSlider_5->value());

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1, SIGNAL(updateGUI(int,int,int)), this, SLOT(updateInterface(int,int,int)));
    connect(trem2, SIGNAL(updateGUI(int,int,int)), this, SLOT(updateInterface(int,int,int)));
    connect(trem3, SIGNAL(updateGUI(int,int,int)), this, SLOT(updateInterface(int,int,int)));
    connect(trem4, SIGNAL(updateGUI(int,int,int)), this, SLOT(updateInterface(int,int,int)));
    connect(trem5, SIGNAL(updateGUI(int,int,int)), this, SLOT(updateInterface(int,int,int)));

    // Inicia os trens automaticamente
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y)
{
    switch(id) {
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1_3->setGeometry(140, 50, 21, 17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2_4->setGeometry(390, 50, 21, 17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem1_4->setGeometry(0, 280, 21, 17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem1_5->setGeometry(240, 280, 21, 17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem1_6->setGeometry(490, 280, 21, 17);
        break;
    }
}

// Slot para controle de velocidade dos trens
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    trem1->setVelocidade(200 - value);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    trem2->setVelocidade(200 - value);
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    trem3->setVelocidade(200 - value);
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    trem4->setVelocidade(200 - value);
}

void MainWindow::on_horizontalSlider_5_valueChanged(int value)
{
    trem5->setVelocidade(200 - value);
}
