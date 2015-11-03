#include "cxMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setApplicationName("issue1044");

  MainWindow window;
  window.resize(800,500);
  window.show();

  return app.exec();
}


