#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_hour_clicked();
    void on_pushButton_minute_clicked();
    void on_pushButton_sec_clicked();
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void on_pushButton_equally_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_clear_clicked();
};
#endif // MAINWINDOW_H
