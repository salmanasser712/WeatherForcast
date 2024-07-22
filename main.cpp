#include "mainwindow.h"

#include <QApplication>

extern Cities cities;

int main(int argc, char *argv[])
{
    cities.AddCity("Cairo", "30.06263", "31.24967");
    cities.AddCity("Alexandria", "31.21564", "29.95527");
    cities.AddCity("Giza", "30.00808", "31.21093");
    cities.AddCity("Port Said", "31.25654", "32.28411");
    cities.AddCity("Luxor", "25.69893", "32.6421");
    cities.AddCity("Suez", "29.97371","32.52627");
    cities.AddCity("Al Mahala Al Kobra", "30.97063", "31.1669");
    cities.AddCity("Asyut", "27.18096", "31.18368");
    cities.AddCity("Mansoura", "31.03637", "31.38069");
    cities.AddCity("Tanta", "30.78847", "31.00192");
    cities.AddCity("Faiyum", "29.30995", "30.8418");
    cities.AddCity("Zagazig", "30.58768", "31.502");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
