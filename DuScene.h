#ifndef DUSCENE_H
#define DUSCENE_H

#include <QGraphicsScene>
#include <QVector>

#define XPOS 0.0 // left
#define YPOS 0.0 // top
#define XSIZE 600.0 // width
#define YSIZE 600.0 // height
#define MILISECONDS 2

class DuBall;
class DuThread;

class DuScene : public QGraphicsScene
{
    Q_OBJECT
public:
    DuScene(QObject *parent = nullptr);
    void startScene();
private:
    QVector<QPointF> calculatePath() const;

    int m_index;
    DuBall *m_ball;
    DuThread *m_thread;
    QVector<QPointF> m_path;
};

#endif // DUSCENE_H
