#include "document_view.h"

namespace qpdfio
{

namespace pdf1_0
{
   
DocumentView::DocumentView(QWidget *parent)
: QWidget(parent)
, errorMsg_(this)
{
   connect(this, SIGNAL(fileSelected(const QString &)), &ctl_, 
      SLOT(loadFile(const QString &)));
   connect(&ctl_, SIGNAL(fileLoadingFailed()), this,
      SLOT(processFileLoadingFail()));
   connect(this, SIGNAL(fileLoadingFailed(const QString &)), 
      &errorMsg_, SLOT(showMessage(const QString &)));
}

void DocumentView::loadFile(const QString &fullFileName)
{
   emit fileSelected(fullFileName);
}

void DocumentView::processFileLoadingFail()
{
   emit fileLoadingFailed(tr("Cannot open file"));
}
   
}

}
