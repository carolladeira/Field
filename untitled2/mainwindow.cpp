#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include "oglwidget.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(updateteste()));
    //timer->start(10);
    //srand (time(NULL));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::updateteste()
//{
//    update();
//    Oglwidget x;
//    x.animate();
//    qDebug() << "update";
//}
