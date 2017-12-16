#ifndef RESERCH_H
#define RESERCH_H

#include <QWidget>

namespace Ui {
class RESERCH;
}

class RESERCH : public QWidget
{
    Q_OBJECT

public:
    explicit RESERCH(QWidget *parent = 0);
    ~RESERCH();

private:
    Ui::RESERCH *ui;
};

#endif // RESERCH_H
