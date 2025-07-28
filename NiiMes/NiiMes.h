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
    void Line(bool);
    void Tune(bool);
    void OnChanged(int, int, int, int);
private:
    Ui::NiiMesClass *ui;
    QList<Element*> _elements;
    QList <QCheckBox*> checkBoxes;
    QList <QCheckBox*> tuneCheckBoxes;
    Element* R1;
    Element* L1;
};

