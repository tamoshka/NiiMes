#include "NiiMes.h"
NiiMes::NiiMes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NiiMesClass())
{
    ui->setupUi(this);
    setFixedSize(850, 300);
    QTableWidgetItem *name = new QTableWidgetItem(QString::fromUtf8("Имя"));
    name->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 0, name);
    QTableWidgetItem* value = new QTableWidgetItem(QString::fromUtf8("Знач."));
    value->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 1, value);
    QTableWidgetItem* optim = new QTableWidgetItem(QString::fromUtf8("Оптим."));
    optim->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 2, optim);
    QTableWidgetItem* tune = new QTableWidgetItem(QString::fromUtf8("Тюнинг"));
    tune->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 3, tune);
    QTableWidgetItem* min = new QTableWidgetItem(QString::fromUtf8("Мин."));
    min->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 4, min);
    QTableWidgetItem* max = new QTableWidgetItem(QString::fromUtf8("Макс."));
    max->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 5, max);
    QTableWidgetItem* step = new QTableWidgetItem(QString::fromUtf8("Шаг"));
    step->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 6, step);
}

NiiMes::~NiiMes()
{
    delete ui;
}

