#ifndef CXMAINWINDOW_H_
#define CXMAINWINDOW_H_

#include <QMainWindow>

class  MainWindow: public QMainWindow
{
public:
	MainWindow();
private:
	void addHiddenToolbar(); ///< creates and adds toolbars for convenience
	void addDock(QString name);
};

#endif /* CXMAINWINDOW_H_ */
