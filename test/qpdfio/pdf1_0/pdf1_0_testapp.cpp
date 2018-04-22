#include "QApplication"
#include "QDebug"
#include "main_window.h"
#include "pdfio/log.h"

int main(int argc, char **argv)
{
   pdfio::gLogErrorHandler = [](const std::string &msg)
   {
     qDebug() << "E\t" << msg.c_str(); 
   };
   pdfio::gLogWarningHandler = [](const std::string &msg)
   {
     qDebug() << "W\t" << msg.c_str(); 
   };
   pdfio::gLogDebugHandler = [](const std::string &msg)
   {
     qDebug() << "D\t" << msg.c_str(); 
   };
   QApplication app(argc, argv);
   qpdfio::pdf1_0::MainWindow mainWindow;
   mainWindow.resize(600, 500);
   mainWindow.show();
   return app.exec();
}
