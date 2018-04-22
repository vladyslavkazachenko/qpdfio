#include "idle_state.h"

#include "QDebug"

namespace qpdfio
{
   
namespace pdf1_0
{

void IdleState::onEntry(QEvent * event)
{
   qDebug() << "IdleState::onEntry";
}

void IdleState::onExit(QEvent * event)
{
   qDebug() << "IdleState::onExit";
}

}

}
