#pragma once

#include "QObject"
#include "QStateMachine"
#include "QFutureWatcher"
#include "pdfio/pdf1_0/istream/document_reader/document_reader.h"

namespace qpdfio
{
   
namespace pdf1_0
{
   
class DocumentViewCtl: public QObject
{
Q_OBJECT

public:
   DocumentViewCtl();

public slots:
   void loadFile(const QString &);
   void startLoadingFile();
   void checkFileLoadingResult();
   void startReadingFile();

signals:
   void fileSelected();
   void fileLoaded();
   void fileLoadingFailed();
   
private:
   pdfio::pdf1_0::DocumentReader reader_;
   QString fileName_;
   QFutureWatcher<bool> watcher_;
   QState *idleState_;
   QState *loadingFileState_;
   QState *loadedState_;
   QStateMachine fsm_;
};
   
}
   
}
