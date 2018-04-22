#include "document_view_ctl.h"

#include "QtConcurrentRun"

namespace qpdfio
{
   
namespace pdf1_0
{
   
DocumentViewCtl::DocumentViewCtl()
: idleState_(new QState)
, loadingFileState_(new QState)
, loadedState_(new QState)
{
   connect(loadingFileState_, SIGNAL(entered()), this, 
      SLOT(startLoadingFile()));
   connect(loadedState_, SIGNAL(entered()), this, 
      SLOT(startReadingFile()));
   
   fsm_.addState(idleState_);
   fsm_.addState(loadingFileState_);
   fsm_.addState(loadedState_);
   
   idleState_->addTransition(this, SIGNAL(fileSelected()), 
      loadingFileState_);
   loadingFileState_->addTransition(this, SIGNAL(fileLoaded()), 
      loadedState_);
   loadingFileState_->addTransition(this, SIGNAL(fileLoadingFailed()), 
      idleState_);
   loadedState_->addTransition(this, SIGNAL(fileSelected()), 
      loadingFileState_);
   
   fsm_.setInitialState(idleState_);
   fsm_.start();
}

void DocumentViewCtl::loadFile(const QString &fileName)
{
   fileName_ = fileName;
   emit fileSelected();
}

void DocumentViewCtl::startLoadingFile()
{
   watcher_.setFuture(QtConcurrent::run([this]()
   {
      return reader_.loadFile(fileName_.toStdString());
   }));
   connect(&watcher_, SIGNAL(finished()), this, 
      SLOT(checkFileLoadingResult()));
}

void DocumentViewCtl::checkFileLoadingResult()
{
   if(watcher_.future().result())
   {
      emit fileLoaded();
   }
   else
   {
      emit fileLoadingFailed();
   }
}

void DocumentViewCtl::startReadingFile()
{
   qDebug() << "DocumentViewCtl::startReadingFile";
}
   
}

}
