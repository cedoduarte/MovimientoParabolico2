#include "DuBall.h"
#include <QPainter>

DuBall::DuBall(double x, double y, double w, double h, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    m_pos_x = x;
    m_pos_y = y;
    m_width = w;
    m_height = h;
}

QRectF DuBall::boundingRect() const
{
    return QRectF(m_pos_x-m_width,m_pos_y-m_height,m_width*2.0,m_height*2.0);
}

void DuBall::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    (void) option;
    (void) widget;
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPointF(m_pos_x,m_pos_y),m_width,m_height);
//    painter->setBrush(Qt::NoBrush);
//    painter->drawRect(boundingRect());
}
