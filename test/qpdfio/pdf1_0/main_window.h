#include "QMainWindow"

namespace qpdfio
{
   
namespace pdf1_0
{
   
class MainWindow: public QMainWindow
{
Q_OBJECT 
public:
   MainWindow();
   
signals:
   void fileSelected(const QString &);

private slots:
   void showFileDialog();
};
   
}
   
}
