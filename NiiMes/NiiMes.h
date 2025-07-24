#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NiiMes.h"
#include "Element.h"
#include "qcheckbox.h"
QT_BEGIN_NAMESPACE
namespace Ui { class NiiMesClass; };
QT_END_NAMESPACE

class NiiMes : public QMainWindow
{
    Q_OBJECT

public:
    NiiMes(QWidget *parent = nullptr);
    ~NiiMes();
    void AddValues();
    void FirstLine(bool);
    void SecondLine(bool);
    void ThirdLine(bool);
    void FourthLine(bool);
private:
    Ui::NiiMesClass *ui;
    QList<Element> _elements;
    QCheckBox* checkBoxFirst;
    QCheckBox* checkBoxFirst2;
    QCheckBox* checkBoxFirst3;
    QCheckBox* checkBoxFirst4;
    Element R1;
    Element L1;
};

