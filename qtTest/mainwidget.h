#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLFunctions>

#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>

QT_BEGIN_NAMESPACE
class QBasicTimer;
class QGLShaderProgram;
QT_END_NAMESPACE

class GeometryEngine;

class MainWidget : public QGLWidget, protected QGLFunctions
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    virtual ~MainWidget();

signals:

public slots:

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void timerEvent(QTimerEvent *e);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void initShaders();
    void initTextures();

private:
    QBasicTimer *timer;
    QGLShaderProgram *program;
    GeometryEngine *geometries;

    GLuint texture;

    QMatrix4x4 projection;

    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    qreal angularSpeed;
    QQuaternion rotation;
};

#endif // MAINWIDGET_H
