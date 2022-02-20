#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPainter>
#include <QSize>
#include <QPaintEvent>
#include <QFrame>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ResetButton->setIcon(QIcon("C:/Users/arda/OneDrive/Cs_201_Lesson/Projects_C++/TicTacToe/TicTacToe/Image/undo.png"));
    ui->ResetButton->setIconSize(QSize(25, 25));
    init();

    this->X = 0;
    this->O = 0;
    this->countOfRound = 0;

    ui->ScoreBoard_1->setDigitCount(QString("%1").arg(X).length());
    ui->ScoreBoard_1->display(X);

    ui->ScoreBoard_2->setDigitCount(QString("%1").arg(O).length());
    ui->ScoreBoard_2->display(O);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init() {
    this->game = new Game();
    QSize btnSize = QSize(200,200);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            QPushButton *button = new QPushButton();
            button->setFixedSize(btnSize);
            connect(button,&QPushButton::clicked,this,&MainWindow::buttonClicked);
            ui->gridLayout->addWidget(button,i,j);
        }
    }
}


void MainWindow::buttonClicked() {
    QPushButton* target = qobject_cast<QPushButton*>(sender());
        if (target != nullptr)
        {
            target->setStyleSheet("font: 50px");
            int index = ui->gridLayout->indexOf(target);
            cout << index << endl;
            int row = -1, column = -1, col_span, row_span;


            if(index != -1)
            {
                ui->gridLayout->getItemPosition(index, &row, &column, &col_span, &row_span);
                qDebug() << "Clicked Item is at: (" << row << "," << column << ")";
            }


            if (this->order && (game->getCurrentItemData(row,column) == -1)) { // X is gonna start
                target->setText("X");
                game->setCurrentItemData(row,column,1);
                this->order = 0;
            }

            else if (!this->order && (game->getCurrentItemData(row,column) == -1)) {
                target->setText("O");
                game->setCurrentItemData(row,column,0);
                this->order = 1;
            }

            game->printArray();
            if (game->whoWin() == 1) {
                this->X++;
                ui->ScoreBoard_1->display(X);
                ui->ScoreBoard_1->setDigitCount(QString("%1").arg(X).length());

                if (X == 3) {
                    QMessageBox::information(this,"Winner","X is the winner!");
                    this->close();
                }

                QMessageBox::information(this,"Winner","Winner: X");
                ++this->countOfRound;
                on_ResetButton_clicked();
            }

            else if (game->whoWin() == 0) {
                this->O++;
                ui->ScoreBoard_2->display(O);
                ui->ScoreBoard_2->setDigitCount(QString("%1").arg(O).length());

                if (O == 3) {
                    QMessageBox::information(this,"Winner","O is the winner!");
                    this->close();
                }

                QMessageBox::information(this,"Winner","Winner: O");
                ++this->countOfRound;
                on_ResetButton_clicked();
            }

            if (scorless()) {
                QString str = QString("Round %1 is scorless!").arg(this->countOfRound);
                QMessageBox::information(this,"Scorless",str);
                ++this->countOfRound;
                on_ResetButton_clicked();

            }



        }
}


bool MainWindow::scorless() {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (game->getCurrentItemData(row,column) == -1)
                return false;
        }
    }
    return true;
}



void MainWindow::on_ResetButton_clicked()
{
   delete  game;
   init();
}

