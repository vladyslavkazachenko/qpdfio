#include "main_window.h"

#include "qpdfio/pdf1_0/document_view.h"

namespace qpdfio
{
   
namespace pdf1_0
{

MainWindow::MainWindow()
{
   DocumentView *docView = new DocumentView;
   setCentralWidget(docView);
   
}

}

}
