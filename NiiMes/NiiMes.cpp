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
    Parameters* r1R = new Parameters(50, 10, 100, 10, false, false);
    Parameters* r1W = new Parameters(20, 10, 50, 5, true, false);
    Parameters* r1L = new Parameters(200, 100, 300, 10, true, false);
    Parameters* l1L = new Parameters(1, 1, 10, 1, false, false);
    elementDictionary r1;
    r1[R] = r1R;
    r1[W] = r1W;
    r1[L] = r1L;
    elementDictionary l1;
    l1[L] = l1L;
    R1 = Element(r1, 0, "R1");
    L1 = Element(l1, 1, "L1");
    _elements.append(R1);
    _elements.append(L1);
    ui->ParametersTable->insertRow(1);
    QTableWidgetItem* name = new QTableWidgetItem(QString::fromStdString(R1.GetName()) + "." + "R");
    ui->ParametersTable->setItem(1, 0, name);
    ui->ParametersTable->setItem(1, 1, new QTableWidgetItem(QString::number(R1.GetParameters(R)->GetValue()) + " Ohm"));
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
    ui->ParametersTable->setItem(2, 1, new QTableWidgetItem(QString::number(R1.GetParameters(W)->GetValue()) + " um"));
    checkBoxFirst2 = new QCheckBox();
    checkBoxFirst2->setChecked(true);
    ui->ParametersTable->setCellWidget(2, 2, checkBoxFirst2);
    QCheckBox* checkBoxSecond2 = new QCheckBox();
    checkBoxSecond2->setChecked(false);
    ui->ParametersTable->setCellWidget(2, 3, checkBoxSecond2);
    ui->ParametersTable->setItem(2, 4, new QTableWidgetItem(QString::number(R1.GetParameters(W)->GetMin()) + " um"));
    ui->ParametersTable->setItem(2, 5, new QTableWidgetItem(QString::number(R1.GetParameters(W)->GetMax()) + " um"));
    ui->ParametersTable->setItem(2, 6, new QTableWidgetItem(QString::number(R1.GetParameters(W)->GetStep()) + " um"));
    ui->ParametersTable->insertRow(3);
    QTableWidgetItem* name3 = new QTableWidgetItem(QString::fromStdString(R1.GetName()) + "." + "L");
    ui->ParametersTable->setItem(3, 0, name3);
    ui->ParametersTable->setItem(3, 1, new QTableWidgetItem(QString::number(R1.GetParameters(L)->GetValue()) + " um"));
    checkBoxFirst3 = new QCheckBox();
    checkBoxFirst3->setChecked(true);
    ui->ParametersTable->setCellWidget(3, 2, checkBoxFirst3);
    QCheckBox* checkBoxSecond3 = new QCheckBox();
    checkBoxSecond3->setChecked(false);
    ui->ParametersTable->setCellWidget(3, 3, checkBoxSecond3);
    ui->ParametersTable->setItem(3, 4, new QTableWidgetItem(QString::number(R1.GetParameters(L)->GetMin()) + " um"));
    ui->ParametersTable->setItem(3, 5, new QTableWidgetItem(QString::number(R1.GetParameters(L)->GetMax()) + " um"));
    ui->ParametersTable->setItem(3, 6, new QTableWidgetItem(QString::number(R1.GetParameters(L)->GetStep()) + " um"));
    ui->ParametersTable->insertRow(4);
    QTableWidgetItem* name4 = new QTableWidgetItem(QString::fromStdString(L1.GetName()) + "." + "L");
    ui->ParametersTable->setItem(4, 0, name4);
    ui->ParametersTable->setItem(4, 1, new QTableWidgetItem(QString::number(L1.GetParameters(L)->GetValue()) + " nH"));
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
    checkBoxes.append(checkBoxFirst);
    checkBoxes.append(checkBoxFirst2);
    checkBoxes.append(checkBoxFirst3);
    checkBoxes.append(checkBoxFirst4);
    connect(checkBoxFirst, &QCheckBox::toggled, this, &NiiMes::Line);
    connect(checkBoxFirst2, &QCheckBox::toggled, this, &NiiMes::Line);
    connect(checkBoxFirst3, &QCheckBox::toggled, this, &NiiMes::Line);
    connect(checkBoxFirst4, &QCheckBox::toggled, this, &NiiMes::Line);
    connect(ui->ParametersTable, &QTableWidget::currentCellChanged, this, &NiiMes::OnChanged);
}

void NiiMes::Line(bool checked)
{
    int i = 0;
    QCheckBox* checkBox = qobject_cast<QCheckBox*>(sender());
    for (auto var : checkBoxes)
    {
        if (checkBoxes[i] == checkBox)
        {
            i += 1;
            break;
        }
        i++;
    }
    Element element;
    string str = ui->ParametersTable->item(i, 0)->text().toUtf8().constData();
    size_t pos = str.find('.');
    string name = str.substr(0, pos);
    string mode1 = str.substr(pos + 1);
    for (auto var : _elements)
    {
        if (var.GetName() == name)
        {
            element = var;
        }
    }
    mode curMode;
    if (mode1 == "R")
    {
        curMode = R;
    }
    else if (mode1 == "L")
    {
        curMode = L;
    }
    else if (mode1 == "W")
    {
        curMode = W;
    }
    if (checked == true)
    {
        ui->ParametersTable->item(i, 1)->setFlags(ui->ParametersTable->item(i, 1)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(i, 4)->setFlags(ui->ParametersTable->item(i, 4)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(i, 5)->setFlags(ui->ParametersTable->item(i, 5)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->item(i, 6)->setFlags(ui->ParametersTable->item(i, 6)->flags() | Qt::ItemIsEnabled);
        ui->ParametersTable->setItem(i, 4, new QTableWidgetItem(QString::number(element.GetParameters(curMode)->GetMin()) + " um"));
        ui->ParametersTable->setItem(i, 5, new QTableWidgetItem(QString::number(element.GetParameters(curMode)->GetMax()) + " um"));
        ui->ParametersTable->setItem(i, 6, new QTableWidgetItem(QString::number(element.GetParameters(curMode)->GetStep()) + " um"));
    }
    else
    {
        ui->ParametersTable->setItem(i, 4, new QTableWidgetItem());
        ui->ParametersTable->setItem(i, 5, new QTableWidgetItem());
        ui->ParametersTable->setItem(i, 6, new QTableWidgetItem());
        ui->ParametersTable->item(i, 1)->setFlags(ui->ParametersTable->item(i, 1)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(i, 4)->setFlags(ui->ParametersTable->item(i, 4)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(i, 5)->setFlags(ui->ParametersTable->item(i, 5)->flags() & Qt::ItemIsEditable);
        ui->ParametersTable->item(i, 6)->setFlags(ui->ParametersTable->item(i, 6)->flags() & Qt::ItemIsEditable);
    }
}

void NiiMes::OnChanged(int currentRow, int currentCol, int row, int col)
{
    if (row!=-1 && col!=2 && col!=3)
    {
        string str = ui->ParametersTable->item(row, 0)->text().toUtf8().constData();
        size_t pos = str.find('.');
        string name = str.substr(0, pos);
        string mode = str.substr(pos + 1);
        for (auto var : _elements)
        {
            if (var.GetName() == name)
            {
                try
                {
                    string newstr = ui->ParametersTable->item(row, col)->text().toUtf8().constData();
                    size_t newpos = newstr.find(' ');
                    string strvalue = newstr.substr(0, newpos);
                    QString qstrvalue = QString::fromUtf8(strvalue);
                    int value = qstrvalue.toInt();
                    if (mode == "R")
                    {
                        if (col == 1)
                        {
                            var.GetParameters(R)->SetValue(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(R)->GetValue()) + " Ohm"));
                        }
                        if (col == 4)
                        {
                            var.GetParameters(R)->SetMin(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(R)->GetMin()) + " um"));
                        }
                        if (col == 5)
                        {
                            var.GetParameters(R)->SetMax(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(R)->GetMax()) + " um"));
                        }
                        if (col == 6)
                        {
                            var.GetParameters(R)->SetStep(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(R)->GetStep()) + " um"));
                        }
                    }
                    else if (mode == "L")
                    {
                        if (col == 1)
                        {
                            var.GetParameters(L)->SetValue(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(L)->GetValue()) + " Ohm"));
                        }
                        if (col == 4)
                        {
                            var.GetParameters(L)->SetMin(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(L)->GetMin()) + " um"));
                        }
                        if (col == 5)
                        {
                            var.GetParameters(L)->SetMax(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(L)->GetMax()) + " um"));
                        }
                        if (col == 6)
                        {
                            var.GetParameters(L)->SetStep(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(L)->GetStep()) + " um"));
                        }
                    }
                    else if (mode == "W")
                    {
                        if (col == 1)
                        {
                            var.GetParameters(W)->SetValue(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(W)->GetValue()) + " Ohm"));
                        }
                        if (col == 4)
                        {
                            var.GetParameters(W)->SetMin(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(W)->GetMin()) + " um"));
                        }
                        if (col == 5)
                        {
                            var.GetParameters(W)->SetMax(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(W)->GetMax()) + " um"));
                        }
                        if (col == 6)
                        {
                            var.GetParameters(W)->SetStep(value);
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(W)->GetStep()) + " um"));
                        }
                    }
                }
                catch (const exception&)
                {
                    if (mode == "R")
                    {
                        if (col == 1)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(R)->GetValue()) + " Ohm"));
                        }
                        if (col == 4)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(R)->GetMin()) + " um"));
                        }
                        if (col == 5)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(R)->GetMax()) + " um"));
                        }
                        if (col == 6)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(R)->GetStep()) + " um"));
                        }
                    }
                    else if (mode == "L")
                    {
                        if (col == 1)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(L)->GetValue()) + " nH"));
                        }
                        if (col == 4)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(L)->GetMin()) + " um"));
                        }
                        if (col == 5)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(L)->GetMax()) + " um"));
                        }
                        if (col == 6)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(L)->GetStep()) + " um"));
                        }
                    }
                    else if (mode == "W")
                    {
                        if (col == 1)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(W)->GetValue()) + " um"));
                        }
                        if (col == 4)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(W)->GetMin()) + " um"));
                        }
                        if (col == 5)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(W)->GetMax()) + " um"));
                        }
                        if (col == 6)
                        {
                            ui->ParametersTable->setItem(row, col, new QTableWidgetItem(QString::number(var.GetParameters(W)->GetStep()) + " um"));
                        }
                    }
                }
            }
        }
    }
}