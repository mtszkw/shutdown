#pragma once

#include <QMainWindow>
#include "scheduler.h"

using namespace caretaker;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addHourBtn_clicked();
    void on_add30MinsBtn_clicked();
    void on_add10MinsBtn_clicked();
    void on_add5MinsBtn_clicked();

    void on_scheduleShutdownBtn_clicked();
    void on_abortShutdownBtn_clicked();

private:
    void updateTimerText();

    Ui::MainWindow *ui;
    Scheduler _scheduler;
};
