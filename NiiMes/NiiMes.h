#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NiiMes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NiiMesClass; };
QT_END_NAMESPACE

class NiiMes : public QMainWindow
{
    Q_OBJECT

public:
    NiiMes(QWidget *parent = nullptr);
    ~NiiMes();

private:
    Ui::NiiMesClass *ui;
};

