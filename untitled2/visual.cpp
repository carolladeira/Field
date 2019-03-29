#include "visual.h"
#include <QtOpenGL>
#include <QOpenGLShaderProgram>


Visual::Visual(QWidget *parent)
    : QOpenGLWidget(parent)

{



}

void Visual::desenha_agentes(Agente *agente)
{
    glPointSize((GLfloat)10.0f);
    for(int i = 0; i < 5; i++)
    {
        glColor3f (0.0, 0.0, 1.7);
        glBegin(GL_POINTS);
            glVertex2f(agente[i].x, agente[i].y);
        glEnd();
    }
}

void Visual::desenha_inimigos(Inimigo *inimigo)
{
    glPointSize((GLfloat)10.0f);
    for(int i = 0; i < 5; i++)
    {
        glColor3f (0.0, 0.0, 0.7);
        glBegin(GL_POINTS);
            glVertex2f(inimigo[i].x, inimigo[i].y);
        glEnd();

    }


}
