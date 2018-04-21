#include "QApplication"
#include "main_window.h"

int main(int argc, char **argv)
{
   QApplication app(argc, argv);
   qpdfio::pdf1_0::MainWindow mainWindow;
   mainWindow.show();
   return app.exec();
}
