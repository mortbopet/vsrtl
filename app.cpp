#include <QApplication>
#include "components/vsrtl_adderandreg.h"
#include "components/vsrtl_counter.h"
#include "components/vsrtl_manynestedcomponents.h"
#include "components/vsrtl_nestedexponenter.h"
#include "components/vsrtl_rannumgen.h"
#include "vsrtl_mainwindow.h"
#include "vsrtl_manynestedcomponents.h"
#include "vsrtl_nestedexponenter.h"
#include "vsrtl_rannumgen.h"

#include <chrono>

#include <QDebug>
#include <QFile>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    Q_INIT_RESOURCE(icons);

    vsrtl::Counter<8> design;
    vsrtl::MainWindow w(design);

    w.show();

    app.exec();
}
