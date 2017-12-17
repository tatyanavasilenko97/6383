#include "treewidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegExpValidator>
#include "huffman.h"
#include "fh.h"

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent)
{
    view_ = new TreeView(this);
    view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);   // задаем размры элемента
    QLabel *label = new QLabel("Enter message: ");                          // задаем текст лейбла
    button_huffman = new QPushButton("Huffman");
    button_shennon_fano = new QPushButton("Shennon-Fano");
   // button_huffman->setEnabled(false);
   // button_shennon_fano->setEnabled(false);
    lineEdit_ = new QLineEdit();                                            // однострочный текст
    QRegExp exp("[a-zA-Z0-9]{0,100}");                                       // ограничение на ввод входных данных
    lineEdit_->setValidator(new QRegExpValidator(exp, this));               // контроль вводимых даннных
    connect(lineEdit_, SIGNAL(textChanged(QString)), this, SLOT(buttonEnabledHuff()));
    connect(lineEdit_, SIGNAL(textChanged(QString)), this, SLOT(buttonEnabledShennon_Fano()));
    next_tree=new QPushButton("Next tree");
    back_tree=new QPushButton("Previous tree");
    step = new QLabel("");
    QHBoxLayout *layoutCode = new QHBoxLayout;
    QLabel *codeInf = new QLabel("");
    code = new QLabel("");
    code->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    message = new QLabel("");
    message->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layoutCode->addWidget(codeInf);
    layoutCode->addWidget(code);
    layoutCode->addWidget(message);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit_);
    layout->addWidget(button_huffman);
    layout->addWidget(button_shennon_fano);
    QHBoxLayout *infLayout=new QHBoxLayout;
    infLayout->addWidget(back_tree);
    infLayout->addWidget(next_tree);
    infLayout->addWidget(step);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    mainLayout->addLayout(infLayout);
    mainLayout->addLayout(layoutCode);
    mainLayout->addWidget(view_);
    setLayout(mainLayout);
    connect(button_huffman, &QPushButton::clicked, this, &TreeWidget::insert_huff);
    connect(button_shennon_fano, &QPushButton::clicked, this, &TreeWidget::insert_shf);
    connect(next_tree, &QPushButton::clicked, this, &TreeWidget::next);
    connect(back_tree, &QPushButton::clicked, this, &TreeWidget::back);
}

void TreeWidget::buttonEnabledHuff()
{
    button_huffman->setEnabled(lineEdit_->hasAcceptableInput());
}

void TreeWidget::buttonEnabledShennon_Fano()
{
    button_shennon_fano->setEnabled(lineEdit_->hasAcceptableInput());
}

int TreeWidget::solve(int s)
{
   int  D = 1 + 8 * s;
   return  (int) (-1 + sqrt(D)) / 2;
}

void TreeWidget::next()
{

    if (stateIndex +2 > trees.size())
        return;
    view_->setTree(trees[++stateIndex]->root);
    step->setText(QString::asprintf("Tree = %d", stateIndex));
    update();
}

void TreeWidget::back()
{
    if(stateIndex<=1)return;
        view_->setTree(trees[--stateIndex]->root);
        //treeIndex--;
        step->setText(QString::asprintf("Tree = %d", treeIndex));
    update();
}

void TreeWidget::insert_huff()
{
    next_tree->show();
    back_tree->show();
    stateIndex = 1;
    step->setText(QString::asprintf("Tree = 0"));
    char* str = new char[256];
    str[0]='\0';
    strcpy(str,lineEdit_->text().toLatin1().data());
    huffman(trees,str);
    levels = solve(trees.size() - 1);
    view_->setTree(trees[stateIndex]->root);
    char* _encode = encode(huffman(trees,str)/*huffman(str)*/, str);
    code->setText(QString::asprintf("Encode: %s", _encode));
    char* _decode = decode(huffman(trees,str)/*huffman(str)*/, _encode);
    message->setText(QString::asprintf("Decode: %s", _decode));
    delete[] str;
    update();
}

void TreeWidget::insert_shf()
{

    next_tree->show();
    back_tree->show();
    stateIndex = 1;
    step->setText(QString::asprintf("Tree = 0"));
    char* str = new char[256];
    str[0]='\0';
    strcpy(str,lineEdit_->text().toLatin1().data());
    fanno_shannon(trees,str);
    levels = solve(trees.size() - 1);
    view_->setTree(trees[stateIndex]->root);
    char* _encode = encode(fanno_shannon(trees,str)/*fanno_shannon(str)*/,str);
    code->setText(QString::asprintf("Encode: %s", _encode));
    char* _decode = decode(fanno_shannon(trees,str)/*fanno_shannon(str)*/, _encode);
    message->setText(QString::asprintf("Decode: %s", _decode));
    delete[] str;
    update();
}

