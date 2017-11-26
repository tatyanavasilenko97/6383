#include "treewidget.h"
#include <cmath>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include<QRegExpValidator>
#include "haffman.h"
#include <QTextStream>
#include <iostream>
#include "codetree1.h"
#include "codetree.h"
TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent){
    view_ = new TreeView(this);
    view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QLabel *label = new QLabel("Enter message: ");
    lineEdit_ = new QLineEdit();

    QRegExp rx("[a-z]{0,126}");
    QValidator *validator = new QRegExpValidator(rx, this);
    lineEdit_->setValidator(validator);


    button_static = new QPushButton("Static");
    button_dynamic = new QPushButton("Dynamic");
    QPushButton* back_step=new QPushButton("Previous step");
    QPushButton* next_step=new QPushButton("Next step");
    next_tree=new QPushButton("Next tree");
    back_tree=new QPushButton("Previous tree");

    step = new QLabel("");

    QHBoxLayout *layoutCode = new QHBoxLayout;
    QLabel *codeInf = new QLabel("");
    code = new QLabel("");
    code->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layoutCode->addWidget(codeInf);
    layoutCode->addWidget(code);


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit_);
    layout->addWidget(button_static);
    layout->addWidget(button_dynamic);

    QHBoxLayout *infLayout=new QHBoxLayout;
    infLayout->addWidget(back_tree);
    infLayout->addWidget(back_step);
    infLayout->addWidget(next_tree);
    infLayout->addWidget(next_step);
    infLayout->addWidget(step);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    mainLayout->addLayout(infLayout);
    mainLayout->addLayout(layoutCode);
    mainLayout->addWidget(view_);

    setLayout(mainLayout);
    //dynamic = 1;
    connect(button_static, &QPushButton::clicked, this, &TreeWidget::insert);
    connect(button_dynamic, &QPushButton::clicked, this, &TreeWidget::insert_dynamic);
    connect(next_tree, &QPushButton::clicked, this, &TreeWidget::next);
    connect(back_tree, &QPushButton::clicked, this, &TreeWidget::back);
    connect(next_step, &QPushButton::clicked, this, &TreeWidget::next_step);
    connect(back_step, &QPushButton::clicked, this, &TreeWidget::back_step);
    insert_dynamic();
}
int TreeWidget ::solve(int s){
   int  D = 1+8*s;
   return  (int) (-1 +sqrt(D))/2;
}

void TreeWidget::next(){

    if (stateIndex +2 > trees.size())
        return;
    QTextStream out(stdout);
    view_->setTree(trees[++stateIndex]->root);
    if (beginers[treeIndex+1] == stateIndex)
        treeIndex++;
    step->setText(QString::asprintf("Step = %d Tree = %d",treeIndex, stateIndex - beginers[treeIndex]));
    update();
}

void TreeWidget::back(){
    if(stateIndex<=1)return;
        view_->setTree(trees[--stateIndex]->root);
        if (beginers[treeIndex] == stateIndex+1)
            treeIndex--;
        step->setText(QString::asprintf("Step = %d Tree = %d",treeIndex, stateIndex - beginers[treeIndex]));
    update();
}

void TreeWidget::insert(){

    next_tree->show();
    back_tree->show();
    dynamic = 1;
    stateIndex=1;
    treeIndex = 0;
    step->setText(QString::asprintf("Step = %d Tree = 0",treeIndex));
    char* str = new char[256];
    str[0]='\0';
    strcpy(str,lineEdit_->text().toLatin1().data());
    haffman_demo(trees,str);
    levels = solve(trees.size() - 1);
    fill_beginers();
    view_->setTree(trees[stateIndex]->root);
    code->setText(QString::asprintf("Code = %s",encode(haffman(str),str)));
    delete[] str;
    update();
}

void TreeWidget:: next_step(){
    if (dynamic == 1){
        if (stateIndex +2 > trees.size())
            return;
        stateIndex = beginers[++treeIndex];
        view_->setTree(trees[stateIndex]->root);
        step->setText(QString::asprintf("Step = %d Tree = 0",treeIndex));
        update();
    }

    else{
        if(states.size()-1<=stateIndex)return;
            view_->setTree(states[++stateIndex]->root);
            code->setText(states[stateIndex]->msg);
            step->setText(QString::asprintf("Step = %d ",stateIndex));
            update();
    }
}

void TreeWidget::fill_beginers(){
    beginers = new int[levels];
    int n = levels;
    beginers[0] = 1;
    for (int i = 1; i<levels;i++){
        beginers[i] = beginers[i-1] + n;
        n--;
    }
}

void TreeWidget:: back_step(){
    if (dynamic == 1){
        if(treeIndex<=0)
            return;
        stateIndex = beginers[--treeIndex];
        view_->setTree(trees[stateIndex]->root);
        step->setText(QString::asprintf("Step = %d Tree = 0",treeIndex));
        update();
    }

    else {
        if(stateIndex<1)return;
            view_->setTree(states[--stateIndex]->root);
            code->setText(states[stateIndex]->msg);
            step->setText(QString::asprintf("Step = %d",stateIndex));
            update();
    }
}

void TreeWidget::insert_dynamic(){
        dynamic = 0;
        stateIndex=0;
        next_tree->hide();
        back_tree->hide();
        step->setText(QString::asprintf("Step = %d",stateIndex));
        char* str = new char[256];
        (*str)='\0';
        strcpy(str,lineEdit_->text().toLatin1().data());
        demoEncode(states,str);
        view_->setTree(states[stateIndex]->root);
        code->setText(QString::asprintf("Code = %s",str));
        delete[] str;
        update();
}

