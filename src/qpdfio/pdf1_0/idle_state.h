#pragma once

#include "QState"

namespace qpdfio
{
   
namespace pdf1_0
{
   
class IdleState: public QState
{
protected:
   void onEntry(QEvent * event);
   void onExit(QEvent * event);
};
   
}
   
}
