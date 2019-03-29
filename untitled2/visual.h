#ifndef VISUAL_H
#define VISUAL_H

#include "inimigo.h"
#include "agente.h"
#include <QOpenGLWidget>

class Visual: public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Visual(QWidget *parent = 0);
//    void desenha_cenario(Cenario *cenario, Grafo *grafo, Fugitivo *fugitivo, Inimigo **inimigo, int num_inimigos);
//    void desenha_bordas(Cenario *cenario);
//    void desenha_parede(Cenario *cenario);
//    void desenha_meshes(Cenario *cenario);
//    void desenha_front_walls(Cenario *cenario);
//    void desenha_caminho_mesh(Grafo *grafo, Agente *agente);
    void desenha_agentes (Agente *agente);
    void desenha_inimigos (Inimigo *inimigo);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

};

#endif // VISUAL_H
