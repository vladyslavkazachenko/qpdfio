#pragma once

#include "QWidget"

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
};
   
}

}
