#include "oglwidget.h"
#include <QDebug>
#include <QTimer>


//ROBOCUP
#define FIELD_MAX_X 5200
#define FIELD_MIN_X -5200
#define FIELD_MAX_Y 3700
#define FIELD_MIN_Y -3700

#define VIRTUAL_FIELD_MAX_X 1.0
#define VIRTUAL_FIELD_MIN_X -1.0
#define VIRTUAL_FIELD_MAX_Y 0.711
#define VIRTUAL_FIELD_MIN_Y -0.711


#define PI 3.1415926535898

Oglwidget::Oglwidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(posicoes()));

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

     //agentes = posicoes();
}

Oglwidget::~Oglwidget()
{

}

void Oglwidget::initializeGL()
{
    glClearColor(0,0,0,1);

}

void Oglwidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float radius = 0.14;     // Not sure what the radius of the center circle should be?

    glBegin (GL_QUADS);
    glColor3f  (0.20, 0.60, 0.20);               // GreenYard
    glVertex2f (VIRTUAL_FIELD_MIN_X, VIRTUAL_FIELD_MIN_Y); //A (x,y)
    glVertex2f (VIRTUAL_FIELD_MAX_X, VIRTUAL_FIELD_MIN_Y);  //B
    glVertex2f (VIRTUAL_FIELD_MAX_X, VIRTUAL_FIELD_MAX_Y);   //C
    glVertex2f (VIRTUAL_FIELD_MIN_X, VIRTUAL_FIELD_MAX_Y);  //D


    glColor3f  (1.0, 1.0, 0.4);
    glVertex2f (0.97, 0.14); glVertex2f (0.86, 0.14);        // Goal - Right
    glVertex2f (0.86, -0.14); glVertex2f (0.97, -0.14);

    glVertex2f (-0.97, 0.14); glVertex2f (-0.86, 0.14);        // Goal - Left
    glVertex2f (-0.86, -0.14); glVertex2f (-0.97, -0.14);
    glEnd ();

    glColor3f (1.0, 1.0, 1.0);   //LINHA LATERAL E DE FUNDO
    glBegin (GL_LINE_LOOP);
    glVertex2f (-0.86,-0.57);
    glVertex2f (0.86, -0.57);
    glVertex2f (0.86, 0.57);
    glVertex2f (-0.86, 0.57);
    glEnd ();

    glColor3f (1.0, 1.0, 1.0);                                  // Change color to black

    glBegin (GL_LINES);
    glVertex2f (0.0, -0.57); glVertex2f (0.0, 0.57);     // LINHA DO MEIO

    // Left side of the Ground
    glVertex2f (0.75, 0.21); glVertex2f (0.75, -0.21);        // Goal keeper front line
    glVertex2f (-0.75, 0.21); glVertex2f (-0.86, 0.21);        // Goal keeper left line
    glVertex2f (-0.75, -0.21); glVertex2f (-0.86, -0.21);        // Goal keeper right line

//     Right Side of the Ground
    glVertex2f (-0.75, 0.21); glVertex2f (-0.75, -0.21);        // Goal keeper front line
    glVertex2f (0.75, 0.21); glVertex2f (0.86, 0.21);        // Goal keeper left  Line
    glVertex2f (0.75,- 0.21); glVertex2f (0.86, -0.21);        // Goal keeper left  Line
    glEnd ();


    float angle;
    int i;
    GLfloat circle_points = 100;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < circle_points; i++) {
        angle = 2*PI*i/circle_points;
        glVertex2f(radius * cos(angle), radius *sin(angle));
    }
    glEnd();
    posicoes();
    for(int i=0;i<5;i++){
        desenha_agentes(agentes[i].x, agentes[i].y, agentes[i].theta);

    }
    qDebug() <<"---teste->";

}

void Oglwidget::resizeGL(int w, int h)
{
//    glViewport(0,0,w,h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
}

void Oglwidget::desenha_agentes(float x, float y, float theta)
{
    //normalização
//    float m = agentes->x;
    float new_x, new_y;
    new_x = (x - FIELD_MIN_X)/(FIELD_MAX_X - FIELD_MIN_X);
    new_x = new_x *(VIRTUAL_FIELD_MAX_X - VIRTUAL_FIELD_MIN_X) + VIRTUAL_FIELD_MIN_X;
    new_y = (y - FIELD_MIN_Y)/(FIELD_MAX_Y - FIELD_MIN_Y);
    float angle = theta *2 *PI/360;
    float novo = new_x + 0.051800000f * cos(angle);
    float novoy = new_y + 0.05800000f * sin(angle);
//   qDebug() <<"---->"<<m;
    glPointSize((GLfloat)8.0f);
    glColor3f (0.0, 0.0, 1.7);
    glBegin(GL_POINTS);
    glVertex2f(new_x, new_y);
    glEnd();

    //glPointSize((GLfloat)8.0f);
    glColor3f (0.0,0.0, 1.7);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(new_x, new_y);
    glVertex2f(novo, novoy);

    glEnd();



}

void Oglwidget::posicoes()
{
    for(int i=0; i<5;i++)
    {
        this->agentes[i].x = rand() % FIELD_MAX_X + FIELD_MIN_X; ;
        this->agentes[i].y = rand() % FIELD_MAX_Y + FIELD_MIN_Y;
        this->agentes[i].theta = rand() % 360  + (-360);
        qDebug() <<"---aaa->"<< this->agentes[i].theta;
    }
}

void Oglwidget::updateteste()
{
    update();

}
void Oglwidget::animate(){
    //this->update();
}

