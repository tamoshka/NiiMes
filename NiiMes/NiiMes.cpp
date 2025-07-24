#include "NiiMes.h"
NiiMes::NiiMes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NiiMesClass())
{
    ui->setupUi(this);
    setFixedSize(850, 300);
    QTableWidgetItem *name = new QTableWidgetItem("Имя");
    name->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 0, name);
    QTableWidgetItem* value = new QTableWidgetItem("Знач.");
    value->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 1, value);
    QTableWidgetItem* optim = new QTableWidgetItem("Оптим.");
    optim->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 2, optim);
    QTableWidgetItem* tune = new QTableWidgetItem("Тюнинг");
    tune->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 3, tune);
    QTableWidgetItem* min = new QTableWidgetItem("Мин.");
    min->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 4, min);
    QTableWidgetItem* max = new QTableWidgetItem("Макс.");
    max->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 5, max);
    QTableWidgetItem* step = new QTableWidgetItem("Шаг");
    step->setTextAlignment(Qt::AlignCenter);
    ui->ParametersTable->setItem(0, 6, step);
    AddValues();
}

NiiMes::~NiiMes()
{
    delete ui;
}

void NiiMes::AddValues()
{
    Parameters r1R = Parameters(50, 0, 10, 100, 10, false, false);
    Parameters r1W = Parameters(20, 2, 10, 50, 5, true, false);
    Parameters r1L = Parameters(200, 2, 100, 300, 10, true, false);
    Parameters l1L = Parameters(1, 3, 1, 10, 1, false, false);
    map<mode, Parameters> r1;
    r1[R] = r1R;
    r1[W] = r1W;
    r1[L] = r1L;
    map<mode, Parameters> l1;
    l1[L] = l1L;
    R1 = Element(r1, 0, "R1");
    L1 = Element(l1, 1, "L1");
    ui->ParametersTable->insertRow(1);
    QTableWidgetItem* name = new QTableWidgetItem(QString::fromStdString(R1.GetName()) + "." + "R");
    ui->ParametersTable->setItem(1, 0, name);
    ui->ParametersTable->setItem(1, 1, new QTableWidgetItem(QString::number(R1.GetParameters(R).GetValue()) + " Ohm"));
    checkBoxFirst = new QCheckBox();
    checkBoxFirst->setChecked(false);
    ui->ParametersTable->setCellWidget(1, 2, checkBoxFirst);
    QCheckBox* checkBoxSecond = new QCheckBox();
    checkBoxSecond->setChecked(false);
    ui->ParametersTable->setCellWidget(1, 3, checkBoxSecond);
    ui->ParametersTable->setItem(1, 4, new QTableWidgetItem());
    ui->ParametersTable->setItem(1, 5, new QTableWidgetItem());
    ui->ParametersTable->setItem(1, 6, new QTableWidgetItem());
    ui->ParametersTable->insertRow(2);
    QTableWidgetItem* name2 = new QTableWidgetItem(QString::fromStdString(R1.GetName()) + "." + "W");
    ui->ParametersTable->setItem(2, 0, name2);
    ui->ParametersTable->setItem(2, 1, new QTableWidgetItem(QString::number(R1.GetParameters(W).GetValue()) + " um"));
    checkBoxFirst2 = new QCheckBox();
    checkBoxFirst2->setChecked(true);
    ui->ParametersTable->setCellWidget(2, 2, checkBoxFirst2);
    QCheckBox* checkBoxSecond2 = new QCheckBox();
    checkBoxSecond2->setChecked(false);
    ui->ParametersTable->setCellWidget(2, 3, checkBoxSecond2);
    ui->ParametersTable->setItem(2, 4, new QTableWidgetItem(QString::number(R1.GetParameters(W).GetMin()) + " um"));
    ui->ParametersTable->setItem(2, 5, new QTableWidgetItem(QString::number(R1.GetParameters(W).GetMax()) + " um"));
    ui->ParametersTable->setItem(2, 6, new QTableWidgetItem(QString::number(R1.GetParameters(W).GetStep()) + " um"));
    ui->ParametersTable->insertRow(3);
    QTableWidgetItem* name3 = new QTableWidgetItem(QString::fromStdString(R1.GetName()) + "." + "L");
    ui->ParametersTable->setItem(3, 0, name3);
    ui->ParametersTable->setItem(3, 1, new QTableWidgetItem(QString::number(R1.GetParameters(L).GetValue()) + " um"));
    checkBoxFirst3 = new QCheckBox();
    checkBoxFirst3->setChecked(true);
    ui->ParametersTable->setCellWidget(3, 2, checkBoxFirst3);
    QCheckBox* checkBoxSecond3 = new QCheckBox();
    checkBoxSecond3->setChecked(false);
    ui->ParametersTable->setCellWidget(3, 3, checkBoxSecond3);
    ui->ParametersTable->setItem(3, 4, new QTableWidgetItem(QString::number(R1.GetParameters(L).GetMin()) + " um"));
    ui->ParametersTable->setItem(3, 5, new QTableWidgetItem(QString::number(R1.GetParameters(L).GetMax()) + " um"));
    ui->ParametersTable->setItem(3, 6, new QTableWidgetItem(QString::number(R1.GetParameters(L).GetStep()) + " um"));
    ui->ParametersTable->insertRow(4);
    QTableWidgetItem* name4 = new QTableWidgetItem(QString::fromStdString(L1.GetName()) + "." + "L");
    ui->ParametersTable->setItem(4, 0, name4);
    ui->ParametersTable->setItem(4, 1, new QTableWidgetItem(QString::number(L1.GetParameters(L).GetValue()) + " nH"));
    checkBoxFirst4 = new QCheckBox();
    checkBoxFirst4->setChecked(false);
    ui->ParametersTable->setCellWidget(4, 2, checkBoxFirst4);
    QCheckBox* checkBoxSecond4 = new QCheckBox();
    checkBoxSecond4->setChecked(false);
    ui->ParametersTable->setCellWidget(4, 3, checkBoxSecond4);
    ui->ParametersTable->setItem(4, 4, new QTableWidgetItem());
    ui->ParametersTable->setItem(4, 5, new QTableWidgetItem());
    ui->ParametersTable->setItem(4, 6, new QTableWidgetItem());
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            QTableWidgetItem* item = ui->ParametersTable->item(i, j);
            if (item) {
                item->setFlags(item->flags() & Qt::ItemIsEditable);
            }
        }
    }
    ui->ParametersTable->item(2, 1)->setFlags(ui->ParametersTable->item(2, 1)->flags() | Qt::ItemIsEnabled);
    ui->ParametersTable->item(2, 4)->setFlags(ui->ParametersTable->item(2, 4)->flags() | Qt::ItemIsEnabled);
    ui->ParametersTable->item(2, 5)->setFlags(ui->ParametersTable->item(2, 5)->flags() | Qt::ItemIsEnabled);
    ui->ParametersTable->item(2, 6)->setFlags(ui->ParametersTable->item(2, 6)->flags() | Qt::ItemIsEnabled);

    ui->ParametersTable->item(3, 1)->setFlags(ui->ParametersTable->item(3, 1)->flags() | Qt::ItemIsEnabled);
    ui->ParametersTable->item(3, 4)->setFlags(ui->ParametersTable->item(3, 4)->flags() | Qt::ItemIsEnabled);
    ui->ParametersTable->item(3, 5)->setFlags(ui->ParametersTable->item(3, 5)->flags() | Qt::ItemIsEnabled);
    ui->ParametersTable->item(3, 6)->setFlags(ui->ParametersTable->item(3, 6)->flags() | Qt::ItemIsEnabled);
    connect(checkBoxFirst, &QCheckBox::toggled, this, &NiiMes::FirstLine);
    connect(checkBoxFirst2, &QCheckBox::toggled, this, &NiiMes::SecondLine);
    connect(checkBoxFirst3, &QCheckBox::toggled, this, &NiiMes::ThirdLine);
    connect(checkBoxFirst4, &QCheckBox::toggled, this, &NiiMes::FourthLine);
}

void NiiMes::FirstLine(bool checked)
{
    if (checked == true)
    {
        ui->ParametersTable->item(1, 1)->setFlags(ui->ParametersTable->item(1, 1)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(1, 4)->setFlags(ui->ParametersTable->item(1, 4)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(1, 5)->setFlags(ui->ParametersTable->item(1, 5)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(1, 6)->setFlags(ui->ParametersTable->item(1, 6)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->setItem(1, 4, new QTableWidgetItem(QString::number(R1.GetParameters(R).GetMin()) + " Ohm"));
        ui->ParametersTable->setItem(1, 5, new QTableWidgetItem(QString::number(R1.GetParameters(R).GetMax()) + " Ohm"));
        ui->ParametersTable->setItem(1, 6, new QTableWidgetItem(QString::number(R1.GetParameters(R).GetStep()) + " Ohm"));
    }
    else
    {
        ui->ParametersTable->setItem(1, 4, new QTableWidgetItem());
        ui->ParametersTable->setItem(1, 5, new QTableWidgetItem());
        ui->ParametersTable->setItem(1, 6, new QTableWidgetItem());
        ui->ParametersTable->item(1, 1)->setFlags(ui->ParametersTable->item(1, 1)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(1, 4)->setFlags(ui->ParametersTable->item(1, 4)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(1, 5)->setFlags(ui->ParametersTable->item(1, 5)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(1, 6)->setFlags(ui->ParametersTable->item(1, 6)->flags() & Qt::ItemIsEditable);
    }
}

void NiiMes::SecondLine(bool checked)
{
    if (checked == true)
    {
        ui->ParametersTable->item(2, 1)->setFlags(ui->ParametersTable->item(2, 1)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(2, 4)->setFlags(ui->ParametersTable->item(2, 4)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(2, 5)->setFlags(ui->ParametersTable->item(2, 5)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(2, 6)->setFlags(ui->ParametersTable->item(2, 6)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->setItem(2, 4, new QTableWidgetItem(QString::number(R1.GetParameters(W).GetMin()) + " um"));
        ui->ParametersTable->setItem(2, 5, new QTableWidgetItem(QString::number(R1.GetParameters(W).GetMax()) + " um"));
        ui->ParametersTable->setItem(2, 6, new QTableWidgetItem(QString::number(R1.GetParameters(W).GetStep()) + " um"));
    }
    else
    {
        ui->ParametersTable->setItem(2, 4, new QTableWidgetItem());
        ui->ParametersTable->setItem(2, 5, new QTableWidgetItem());
        ui->ParametersTable->setItem(2, 6, new QTableWidgetItem());
        ui->ParametersTable->item(2, 1)->setFlags(ui->ParametersTable->item(2, 1)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(2, 4)->setFlags(ui->ParametersTable->item(2, 4)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(2, 5)->setFlags(ui->ParametersTable->item(2, 5)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(2, 6)->setFlags(ui->ParametersTable->item(2, 6)->flags() & Qt::ItemIsEditable);
    }
}

void NiiMes::ThirdLine(bool checked)
{
    if (checked == true)
    {
        ui->ParametersTable->item(3, 1)->setFlags(ui->ParametersTable->item(3, 1)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(3, 4)->setFlags(ui->ParametersTable->item(3, 4)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(3, 5)->setFlags(ui->ParametersTable->item(3, 5)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(3, 6)->setFlags(ui->ParametersTable->item(3, 6)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->setItem(3, 4, new QTableWidgetItem(QString::number(R1.GetParameters(L).GetMin()) + " um"));
        ui->ParametersTable->setItem(3, 5, new QTableWidgetItem(QString::number(R1.GetParameters(L).GetMax()) + " um"));
        ui->ParametersTable->setItem(3, 6, new QTableWidgetItem(QString::number(R1.GetParameters(L).GetStep()) + " um"));
    }
    else
    {
        ui->ParametersTable->setItem(3, 4, new QTableWidgetItem());
        ui->ParametersTable->setItem(3, 5, new QTableWidgetItem());
        ui->ParametersTable->setItem(3, 6, new QTableWidgetItem());
        ui->ParametersTable->item(3, 1)->setFlags(ui->ParametersTable->item(3, 1)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(3, 4)->setFlags(ui->ParametersTable->item(3, 4)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(3, 5)->setFlags(ui->ParametersTable->item(3, 5)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(3, 6)->setFlags(ui->ParametersTable->item(3, 6)->flags() & Qt::ItemIsEditable);
    }
}

void NiiMes::FourthLine(bool checked)
{
    if (checked == true)
    {
        ui->ParametersTable->item(4, 1)->setFlags(ui->ParametersTable->item(4, 1)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(4, 4)->setFlags(ui->ParametersTable->item(4, 4)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(4, 5)->setFlags(ui->ParametersTable->item(4, 5)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(4, 6)->setFlags(ui->ParametersTable->item(4, 6)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->setItem(4, 4, new QTableWidgetItem(QString::number(L1.GetParameters(L).GetMin()) + " nH"));
        ui->ParametersTable->setItem(4, 5, new QTableWidgetItem(QString::number(L1.GetParameters(L).GetMax()) + " nH"));
        ui->ParametersTable->setItem(4, 6, new QTableWidgetItem(QString::number(L1.GetParameters(L).GetStep()) + " nH"));
    }
    else
    {
        ui->ParametersTable->setItem(4, 4, new QTableWidgetItem());
        ui->ParametersTable->setItem(4, 5, new QTableWidgetItem());
        ui->ParametersTable->setItem(4, 6, new QTableWidgetItem());
        ui->ParametersTable->item(4, 1)->setFlags(ui->ParametersTable->item(4, 1)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(4, 4)->setFlags(ui->ParametersTable->item(4, 4)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(4, 5)->setFlags(ui->ParametersTable->item(4, 5)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(4, 6)->setFlags(ui->ParametersTable->item(4, 6)->flags() & Qt::ItemIsEditable);
    }
}