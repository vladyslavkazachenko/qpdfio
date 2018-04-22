#include "main_window.h"

#include "QMenuBar"
#include "QFileDialog"
#include "qpdfio/pdf1_0/document_view.h"

namespace qpdfio
{
   
namespace pdf1_0
{

MainWindow::MainWindow()
{
   DocumentView *docView = new DocumentView;
   setCentralWidget(docView);
   QAction *openAction = menuBar()->addAction(tr("Open"));
   connect(openAction, SIGNAL(triggered()), this, 
      SLOT(showFileDialog()));
   connect(this, SIGNAL(fileSelected(const QString &)), docView, 
      SLOT(loadFile(const QString &)));
}

void MainWindow::showFileDialog()
{
   QString fullFileName = QFileDialog::getOpenFileName(
      this, tr("Open File"), "/home", tr("*.pdf"));
   if(!fullFileName.isNull())
   {
      emit fileSelected(fullFileName);
   }
}

}

}
