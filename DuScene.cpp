#include "DuScene.h"
#include "DuBall.h"
#include "DuThread.h"
#include <QtMath>

DuScene::DuScene(QObject *parent)
    : QGraphicsScene(XPOS,YPOS,XSIZE,YSIZE,parent)
{
    m_thread = new DuThread(MILISECONDS, this);
    m_ball = new DuBall(XPOS,YPOS,10.0,10.0);
    m_path = calculatePath();
    m_index = 0;
    addRect(XPOS,YPOS,XSIZE,YSIZE);
    addPolygon(QPolygonF(m_path));
    addItem(m_ball);

    connect(m_thread, &DuThread::timeOut, [&]() {
        if (m_index == m_path.size() - 1) {
            m_index = 0;
        }
        const double x = m_path.at(m_index).x();
        const double y = m_path.at(m_index).y();
        m_ball->set_pos_x(x);
        m_ball->set_pos_y(y);
        update();
        ++m_index;
    });
}

void DuScene::startScene()
{
    m_thread->start();
}

QVector<QPointF> DuScene::calculatePath() const
{
    QVector<QPointF> path;
    for (double x = XPOS; x <= XSIZE; x += 0.555) {
        const double h = XSIZE/2.0;
        const double k = YSIZE;
        const double p = 30.0;
        const double y = -qPow(x-h,2.0)/(4.0*p) + k;
        path << QPointF(x, y);
    }
    return path;
}
