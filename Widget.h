#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class DuScene;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
#if defined(MY_DEBUG)
    void resizeEvent(QResizeEvent *event) override;
#endif
private:
    Ui::Widget *ui;
    DuScene *m_scene;
};

#endif // WIDGET_H
