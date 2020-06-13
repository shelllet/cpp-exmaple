#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Thread.h"

class Thread : public QMainWindow
{
    Q_OBJECT

public:
    Thread(QWidget *parent = Q_NULLPTR);


public slots:
    void save();
    void set();
    void test();
    void mainTest();
    void moveToThread();
public:
    QString text() const;
private:
    Ui::ThreadClass ui;
};
