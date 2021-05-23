#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

QString oper_first;
double num_first, num_second, label_result;
bool plus, minus, multiply, divide, hour, minute, sec;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    QPixmap pix(":/img/img/vss3pFiWtmo.png");
    int w = ui->image->width();
    int h = ui->image->height();

    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    ui->pushButton_hour->setCheckable(false);
    ui->pushButton_minute->setCheckable(false);
    ui->pushButton_sec->setCheckable(false);

    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_hour_clicked()
{


    num_first = ui->result_show->text().toDouble();
    if (num_first == 0)
    {
        num_first = ui->result_show->text().toDouble();
        ui->oper_show->setText(ui->result_show->text() );
    }
    else
    {
        num_second = ui->result_show->text().toDouble();
        if (sec)
        {
            num_first = num_first / 3600;
            sec = 0;
        }
        else if (minute)
        {
            num_first = num_first / 60;
            minute = 0;
        }

        oper_first = QString::number(num_first, 'g', 10);
        ui->oper_show->setText(oper_first );
    }
    ui->result_show->setText(oper_first);
    ui->oper_show_2->setText("Часы");
    hour = 1;
    minute = 0;
    sec = 0;
}
void MainWindow::on_pushButton_minute_clicked()
{
    num_first = ui->result_show->text().toDouble();
    if (num_first == 0)
    {
        num_first = ui->result_show->text().toDouble();
        ui->oper_show->setText(ui->result_show->text()  );
    }
    else
    {
        num_second = ui->result_show->text().toDouble();
        if (sec)
        {
            num_first = num_first / 60;
            sec = 0;
        }
        else if (hour)
        {
            num_first = num_first * 60;
            hour = 0;
        }

        oper_first = QString::number(num_first, 'g', 10);
        ui->oper_show->setText(oper_first  );
    }
    ui->result_show->setText(oper_first);
    ui->oper_show_2->setText("Минуты");
    hour = 0;
    minute = 1;
    sec = 0;
}

void MainWindow::on_pushButton_sec_clicked()
{
    {
        num_first = ui->result_show->text().toDouble();
        if (num_first == 0)
        {
            num_first = ui->result_show->text().toDouble();
            ui->oper_show->setText(ui->result_show->text() );
        }
        else
        {
            num_second = ui->result_show->text().toDouble();
            if (minute)
            {
                num_first = num_first * 60;
                hour = 0;
            }
            else if (hour)
            {
                num_first = num_first * 3600;
                minute = 0;
            }

            oper_first = QString::number(num_first, 'g', 10);
            ui->oper_show->setText(oper_first );
        }
        ui->result_show->setText(oper_first);
        ui->oper_show_2->setText("Секунды");
        hour = 0;
        minute = 0;
        sec = 1;
    }
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if (ui->result_show->text().contains(".") && button->text() == "0")
    {
        new_label = ui->result_show->text() + button->text();
    }
    else
    {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 11);
    }

    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if ((!ui->result_show->text().contains('.')))
    {
        ui->result_show->setText(ui->result_show->text() + ".");
    }

}

void MainWindow::on_pushButton_equally_clicked()
{
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if (plus)
    {
        label_result = num_first + num_second;
        new_label = QString::number(label_result, 'g', 11);

        ui->result_show->setText(new_label);
        plus = 0;
    }
    else if (minus)
    {
        if ( num_first - num_second >= 0)
        {
        label_result = num_first - num_second;
        new_label = QString::number(label_result, 'g', 11);

        ui->result_show->setText(new_label);
        }
        else
            ui->result_show->setText("Error");

        minus = 0;
    }

    ui->oper_show->setText(ui->oper_show->text() + QString::number(num_second, 'g', 11) + " = ");
    num_first = 0;
    num_second = 0;
}





void MainWindow::on_pushButton_plus_clicked()
{
    if (num_first == 0)
    {
        num_first = ui->result_show->text().toDouble();
        ui->oper_show->setText(ui->result_show->text() + " + ");
    }
    else
    {
        num_second = ui->result_show->text().toDouble();
        if (plus)
        {
            num_first += num_second;
            plus = 0;
        }
        else if (minus)
        {
            if ( num_first -  num_second >= 0 )
            {
                num_first -= num_second;
                minus = 0;
            }
            else
                    ui->oper_show->setText("Error");
        }

        oper_first = QString::number(num_first, 'g', 10);
        ui->oper_show->setText(oper_first + " + ");
    }
    ui->result_show->setText("0");
    plus = 1;
}

void MainWindow::on_pushButton_minus_clicked()
{
    if (num_first == 0)
    {
        num_first = ui->result_show->text().toDouble();
        ui->oper_show->setText(ui->result_show->text() + " - ");
    }
    else
    {
        num_second = ui->result_show->text().toDouble();
        if (plus)
        {
            num_first += num_second;
            plus = 0;
        }
        else if (minus)
        {
            if ( num_first -  num_second >= 0 )
            {
                num_first -= num_second;
                minus = 0;
            }
            else
                    ui->oper_show->setText("Error");
        }

        oper_first = QString::number(num_first, 'g', 10);
        ui->oper_show->setText(oper_first + " - ");
    }
    ui->result_show->setText("0");
    minus = 1;
}


void MainWindow::on_pushButton_clear_clicked()
{
    plus = 0;
    minus = 0;
    multiply = 0;
    divide = 0;

    ui->result_show->setText("0");
    ui->oper_show->setText(0);
}
