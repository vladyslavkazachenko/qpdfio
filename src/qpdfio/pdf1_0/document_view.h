#pragma once

#include "QWidget"
#include "QErrorMessage"
#include "document_view_ctl.h"

namespace qpdfio
{

namespace pdf1_0
{
   
class DocumentView: public QWidget
{
Q_OBJECT
   
public:
   DocumentView(QWidget *parent = nullptr);
   
public slots:
   void loadFile(const QString &fullFileName);
   void processFileLoadingFail();
   
signals:
   void fileSelected(const QString &);
   void fileLoadingFailed(const QString &);
   
private:
   DocumentViewCtl ctl_;
   QErrorMessage errorMsg_;
};
   
}

}
