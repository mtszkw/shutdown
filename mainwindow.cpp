#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTimerText()
{
    using std::to_string;
    const Timer& timer = _scheduler.getTime();
    const std::string timerText = to_string(timer.hours) + " hour(s) and " + to_string(timer.minutes) + " minute(s)";
    ui->timerTextLabel->setText(QString::fromStdString(timerText));
}

void MainWindow::on_addHourBtn_clicked()
{
    _scheduler.addTime(1, 0);
    updateTimerText();
}

void MainWindow::on_add30MinsBtn_clicked()
{
    _scheduler.addTime(0, 30);
    updateTimerText();
}

void MainWindow::on_scheduleShutdownBtn_clicked()
{
    _scheduler.scheduleShutdown();
}

void MainWindow::on_abortShutdownBtn_clicked()
{
    _scheduler.abortShutdown();
}

void MainWindow::on_add10MinsBtn_clicked()
{
    _scheduler.addTime(0, 10);
    updateTimerText();
}

void MainWindow::on_add5MinsBtn_clicked()
{
    _scheduler.addTime(0, 5);
    updateTimerText();
}
