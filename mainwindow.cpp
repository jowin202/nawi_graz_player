#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMultimedia>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.setInterval(1000);

    player1 = new QMediaPlayer;
    player2 = new QMediaPlayer;

    player1->setVolume(100);
    player2->setVolume(0);

    player1->setVideoOutput(this->ui->video1);
    player2->setVideoOutput(this->ui->video2);

    connect(player1, SIGNAL(durationChanged(qint64)), this, SLOT(player1_duration_set(qint64)));
    connect(player2, SIGNAL(durationChanged(qint64)), this, SLOT(player2_duration_set(qint64)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //choose video 1
    QString video_file = "/media/johannes/DATA/videos/dctp/1-100/002_Anime-Conan_3E743379.avi"; //QFileDialog::getOpenFileName(this, "Video 1 wählen", QDir::homePath());
    this->player1->setMedia(QUrl::fromLocalFile(video_file));
}

void MainWindow::on_pushButton_2_clicked()
{
    //choose video 2
    QString video_file = "/media/johannes/DATA/videos/dctp/realfilm/Detective Conan - JDrama [KnKF][6C34F857].avi"; //QFileDialog::getOpenFileName(this, "Video 2 wählen", QDir::homePath());
    this->player2->setMedia(QUrl::fromLocalFile(video_file));}

void MainWindow::on_button_play_pause_clicked()
{
    QPushButton *btn = (QPushButton*)sender();
    if (btn!= 0)
    {
        qDebug() << btn->text();
        if (btn->text().endsWith("Play"))
        {
            btn->setText("Pause");
            player1->play();
            player2->play();
        }
        else
        {
            btn->setText("Play");
            player1->pause();
            player2->pause();
        }
    }
}

void MainWindow::on_actionAbout_triggered()
{

}

void MainWindow::on_volume1_sliderMoved(int position)
{
    this->player1->setVolume(position);
}

void MainWindow::on_volume2_sliderMoved(int position)
{
    this->player2->setVolume(position);
}

void MainWindow::player1_duration_set(qint64 time)
{
    this->ui->slider1->setMaximum((int)time);
}

void MainWindow::player2_duration_set(qint64 time)
{
    this->ui->slider2->setMaximum((int)time);
}

void MainWindow::player1_seekable_set(qint64 time)
{
    this->ui->slider1->setValue((int)time);
}

void MainWindow::player2_seekable_set(qint64 time)
{
    this->ui->slider2->setValue((int)time);
}


