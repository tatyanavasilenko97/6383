#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treap.h"
#include "task.h"
#include <chrono>
#include <set>
#include <ctime>
#include <QSet>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

treap<int>* newTreapElement = new treap<int>;
treap<int>* newRandTreap = new treap<int>;

void MainWindow::on_pushButton_4_clicked()
{
    QString resultPlainTextTwo = "";
    QString resultPlainText = "";


    QString dataString = ui->lineEdit->text();
    auto begin = std::chrono::steady_clock::now();
    if (ui->lineEdit_3->isEnabled()) {
        ui->plainTextEdit_2->clear();
        if(addFirstElement(newTreapElement,ui->lineEdit_3->text(),ui->lineEdit_4->text())){
            ui->lineEdit_3->setEnabled(false);
            ui->lineEdit_4->setEnabled(false);
            ui->lineEdit->setEnabled(true);
            ui->lineEdit_2->setEnabled(true);
        } else{

            ui->plainTextEdit_2->insertPlainText("Incorrect Data");
        }} else{

        resultPlainTextTwo = addOrDelIntTreapElLine(newTreapElement,dataString,true);

        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        resultPlainTextTwo += "Time = " + QString::number(elapsed_ms.count()) + " ns";
        QPrintTreap(newTreapElement,0,true,resultPlainText);
        ui->plainTextEdit->clear();
        ui->plainTextEdit->insertPlainText(resultPlainText);
        ui->plainTextEdit_2->clear();
        ui->plainTextEdit_2->insertPlainText(resultPlainTextTwo);
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("(A,B)");
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->lineEdit->clear();
}



void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("1");
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("2");
}

void MainWindow::on_pushButton_3_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("3");
}

void MainWindow::on_pushButton_5_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("4");
}

void MainWindow::on_pushButton_7_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("5");
}

void MainWindow::on_pushButton_8_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("6");
}

void MainWindow::on_pushButton_9_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("7");
}

void MainWindow::on_pushButton_10_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("8");
}

void MainWindow::on_pushButton_11_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("9");
}

void MainWindow::on_pushButton_12_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("0");}

void MainWindow::on_pushButton_13_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert("(");
}

void MainWindow::on_pushButton_14_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert(",");
}

void MainWindow::on_pushButton_15_clicked()
{
    if (ui->lineEdit->isEnabled())
        ui->lineEdit->insert(")");
}



void MainWindow::on_pushButton_18_clicked()
{
    if (ui->lineEdit_3->isEnabled()){
        ui->plainTextEdit->clear();
        ui->plainTextEdit_2->clear();
        ui->plainTextEdit_2->insertPlainText("Tree is empty/");
    } else{
        QString resultPlainTextTwo;
        QString resultPlainText;
        QString dataString;
        dataString = ui->lineEdit->text();
        auto begin = std::chrono::steady_clock::now();
        resultPlainTextTwo = addOrDelIntTreapElLine(newTreapElement,dataString,false);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        resultPlainTextTwo += "Time = " + QString::number(elapsed_ms.count()) + " ns";
        QPrintTreap(newTreapElement,0,true,resultPlainText);

        ui->plainTextEdit->clear();
        ui->plainTextEdit->insertPlainText(resultPlainText);
        ui->plainTextEdit_2->clear();
        ui->plainTextEdit_2->insertPlainText(resultPlainTextTwo);
    }}

void MainWindow::on_pushButton_6_clicked()
{
    QFile read(ui->lineEdit_2->text());
    if(read.open(QIODevice::ReadOnly |QIODevice::Text))
        ui->lineEdit->setText(read.readLine());
    else ui->lineEdit_2->setText("incorrect dir");
}

void MainWindow::on_pushButton_19_clicked()
{
    Explenetion lol;
    lol.setTree(newTreapElement);
    lol.exec();
}


void MainWindow::on_pushButton_20_clicked()
{
    QString dataString, otchet_1 = "_____________\n" , otchet_2 = "_____________\n";

    addFirstElement(newTreapElement,QString::number(rand() % 2000 - 1000),QString::number(rand() % 2000 - 1000));

    QString resultPlainTextTwo = "";

    int kol = ui->lineEdit_5->text().toInt();
    QSet <int> pri;
    QSet <int> key;
    //int rand;

    srand(time(NULL));
    while (key.size() < kol-1){
        key<<(rand() % 2000 - 1000);
    }
    while (pri.size() < kol-1){
        pri<<(rand() % 2000 - 1000);
    }

    auto list1 = pri.toList();
    auto list2 = key.toList();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle (list1.begin(), list1.end(), std::default_random_engine(seed));
    shuffle (list2.begin(), list2.end(), std::default_random_engine(seed));
    for (int i = 0; i < key.size();i++){
        dataString = "(" + QString::number(list1[i]) + "," + QString::number(list2[i]) + ")";
        auto begin = std::chrono::steady_clock::now();
        resultPlainTextTwo = addOrDelIntTreapElLine(newTreapElement,dataString,true);
        otchet_2 += "height(" + QString::number(i+1) + ") = " + QString::number(HeigthOfTree(*newTreapElement)) + "\n";
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        resultPlainTextTwo =+ "Time = " + QString::number(elapsed_ms.count()) + " ns";
        otchet_1 += resultPlainTextTwo + "\n";
    }
    ui->plainTextEdit_3->clear();
    ui->plainTextEdit_3->insertPlainText(otchet_1);
    ui->plainTextEdit_4->clear();
    ui->plainTextEdit_4->insertPlainText(otchet_2);



}

void MainWindow::on_pushButton_21_clicked()
{
    QString otchet_3 = "_____________\n", ls; int lev;
    while (HeigthOfTree(*newTreapElement) > 1){
    ls = DelRandEl(newTreapElement, lev);
    auto begin = std::chrono::steady_clock::now();
    otchet_3 += "Level = " + QString::number(lev) + "  " +addOrDelIntTreapElLine(newTreapElement,ls,false);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    otchet_3 += "Time = " + QString::number(elapsed_ms.count()) + " ns";
    ui->plainTextEdit_5->clear();
    ui->plainTextEdit_5->insertPlainText(otchet_3);}
}
