// Курсовая работа
// treewidget.cpp
// Азаревич Артём, гр. 6383
// 11.12.17
//
// Бинарные алгоритмы поиска. БДП случайного типа

#include "treewidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include<QRegExpValidator>


TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent)
{
    view_ = new TreeView(this);
    view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // "Введите искомый элемент: "
    QLabel *label = new QLabel("Введите искомый элемент: ");


    // Окошко для вводимых значений
    lineEdit_ = new QLineEdit();
    lineEdit_->setValidator( new QIntValidator( -2147483648, 2147483647 ) );

    // Кнопка
    button_ = new QPushButton("Искать");


    step = new QLabel("Начните строить дерево");


    // Горизонтальные виджеты (1)
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit_);
    layout->addWidget(button_);

    // Горизонтальные виджеты (2)
    QHBoxLayout *infLayout=new QHBoxLayout;
    infLayout->addWidget(step);

    // Выравниваем виджеты
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    mainLayout->addLayout(infLayout);
    mainLayout->addWidget(view_);


    setLayout(mainLayout);

    connect(button_, &QPushButton::clicked, this, &TreeWidget::insert);
}


void TreeWidget::insert()
{
    Elem a = lineEdit_->text().toInt();
    view_->Push_key(a);

    if (view_->tree == NULL)
    {
        step->setText(QString::asprintf("Постройка дерева начата"));
        view_->tree = new BTS(a);
        view_->Push_flag(false);
    }
    else
       if (view_->tree->Find_Add(a))
       {
           step->setText(QString::asprintf("Элемент уже есть"));
           view_->Push_flag(true);
       }
        else
       {
          step->setText(QString::asprintf("Элемент добавлен"));
          view_->Push_flag(false);
       }

    update();
}
