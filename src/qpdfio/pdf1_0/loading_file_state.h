#pragma once

#include "QState"
#include "pdfio/pdf1_0/istream/document_reader/document_reader.h"

namespace qpdfio
{
   
namespace pdf1_0
{
   
class LoadingFileState: public QState
{
public:
   LoadingFileState(pdfio::pdf1_0::DocumentReader &reader);
   
protected:
   void onEntry(QEvent * event);
   void onExit(QEvent * event);
   
private:
   pdfio::pdf1_0::DocumentReader &reader_;
};
   
}
   
}
