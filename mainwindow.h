#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "Game.h"
#include <iostream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void clicked();

private slots:
    void buttonClicked();

    void on_ResetButton_clicked();

private:
    Ui::MainWindow *ui;
    void init();
    bool order = 1;  // X: 1, O: 0
    Game *game;
    int X;
    int O;
    bool scorless();
    int countOfRound;

};
#endif // MAINWINDOW_H
