#ifndef DUBALL_H
#define DUBALL_H

#include <QGraphicsItem>

class DuBall : public QGraphicsItem
{
public:
    DuBall(double x, double y, double w, double h,
           QGraphicsItem *parent = nullptr);
    void set_pos_x(double x) { m_pos_x = x; }
    void set_pos_y(double y) { m_pos_y = y; }
    void set_width(double w) { m_width = w; }
    void set_height(double h) { m_height = h; }
    double get_pos_x() const { return m_pos_x; }
    double get_pos_y() const { return m_pos_y; }
    double get_width() const { return m_width; }
    double get_height() const { return m_height; }
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;
private:
    double m_pos_x;
    double m_pos_y;
    double m_width;
    double m_height;
};

#endif // DUBALL_H
