#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMediaPlayer>
#include <QMainWindow>
#include <QDebug>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMediaPlayer *player1;
    QMediaPlayer *player2;
    QTimer timer;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_button_play_pause_clicked();
    void on_actionAbout_triggered();
    void on_volume1_sliderMoved(int position);
    void on_volume2_sliderMoved(int position);

    void player1_duration_set(qint64 time);
    void player2_duration_set(qint64 time);
    void player1_seekable_set(qint64 time);
    void player2_seekable_set(qint64 time);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
