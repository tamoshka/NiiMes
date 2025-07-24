#include "NiiMes.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    NiiMes window;
    window.show();
    return app.exec();
}
