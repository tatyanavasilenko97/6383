#include <QPainter>
#include <QFontMetrics>
#include "reserch.h"
#include "ui_reserch.h"

RESERCH::RESERCH(QWidget *parent) :
    QWidget(parent), ui(new Ui::RESERCH)
{
    ui->setupUi(this);
     update();
}

RESERCH::~RESERCH()
{
    delete ui;
}
