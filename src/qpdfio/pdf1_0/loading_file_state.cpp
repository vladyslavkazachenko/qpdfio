#include "loading_file_state.h"

#include "QDebug"

namespace qpdfio
{
   
namespace pdf1_0
{

LoadingFileState::LoadingFileState(
   pdfio::pdf1_0::DocumentReader &reader)
: reader_(reader)
{
   
}

void LoadingFileState::onEntry(QEvent * event)
{
   qDebug() << "LoadingFileState::onEntry";
}

void LoadingFileState::onExit(QEvent * event)
{
   qDebug() << "LoadingFileState::onExit";
}

}

}
