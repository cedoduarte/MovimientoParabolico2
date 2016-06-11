#include "Widget.h"
#include "ui_Widget.h"
#include "DuScene.h"

#if defined(MY_DEBUG)
#include <QDebug>
#include <QResizeEvent>
#endif

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_scene = new DuScene(this);
    ui->graphicsView->setScene(m_scene);
    layout()->setMargin(0);
    resize(619, 621);
    m_scene->startScene();
}

Widget::~Widget()
{
    delete ui;
}

#if defined(MY_DEBUG)
void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
    QWidget::resizeEvent(event);
}
#endif
