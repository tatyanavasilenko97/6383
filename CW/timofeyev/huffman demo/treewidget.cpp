// Курсовая работа
// treewidget.cpp
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману


#include "treewidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include<QRegExpValidator>


TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent){
    view_ = new TreeView(this);
    view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLabel *label = new QLabel("Введите сообщение: ");
    lineEdit_ = new QLineEdit();

    QRegExp rx("[a-z]{0,26}");
    QValidator *validator = new QRegExpValidator(rx, this);
    lineEdit_->setValidator(validator);


    button_ = new QPushButton("Кодировать");

    QPushButton* back=new QPushButton("Предыдущий шаг");
    QPushButton* next=new QPushButton("Следующий шаг");
    step = new QLabel("-1");

    QHBoxLayout *layoutCode = new QHBoxLayout;
    QLabel *codeInf = new QLabel("Код: ");
    code = new QLabel("");
    code->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layoutCode->addWidget(codeInf);
    layoutCode->addWidget(code);


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit_);
    layout->addWidget(button_);

    QHBoxLayout *infLayout=new QHBoxLayout;
    infLayout->addWidget(back);
    infLayout->addWidget(step);
    infLayout->addWidget(next);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    mainLayout->addLayout(infLayout);
    mainLayout->addLayout(layoutCode);
    mainLayout->addWidget(view_);


    setLayout(mainLayout);

    connect(button_, &QPushButton::clicked, this, &TreeWidget::insert);
    connect(next, &QPushButton::clicked, this, &TreeWidget::next);
    connect(back, &QPushButton::clicked, this, &TreeWidget::back);

    insert();
}

void TreeWidget::next(){
    if(states.size()-1<=stateIndex)return;
    view_->setTree(states[++stateIndex]->root);
    code->setText(states[stateIndex]->msg);
    step->setText(QString::asprintf("Номер шага = %d",stateIndex));
    update();
}

void TreeWidget::back(){
    if(stateIndex<1)return;
    view_->setTree(states[--stateIndex]->root);
    code->setText(states[stateIndex]->msg);
    step->setText(QString::asprintf("Номер шага = %d",stateIndex));
    update();
}

void TreeWidget::insert(){
    stateIndex=0;
    step->setText(QString::asprintf("Номер шага = %d",stateIndex));
    char* str = new char[lineEdit_->text().length()+1];
    (*str)='\0';
    strcpy(str,lineEdit_->text().toLatin1().data());
    demo_haffman::demoEncode(states,str);
    view_->setTree(states[stateIndex]->root);
    code->setText("");
    delete[] str;
    update();
}
