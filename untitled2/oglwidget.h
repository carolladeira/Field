#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include "gameagents.h"

#include <QWidget>
#include <QOpenGLWidget>

class Oglwidget : public QOpenGLWidget
{
public:
    Oglwidget(QWidget *parent = 0);
    ~Oglwidget();
    void animate();


protected:
       void initializeGL();
       void resizeGL(int w, int h);
       void paintGL();


       void desenha_agentes(float x, float y, float theta);
       float normalize(double x1, double x2);
       void posicoes();
       void updateteste();

private:
       GameAgents agentes[5];

};

#endif // OGLWIDGET_H
