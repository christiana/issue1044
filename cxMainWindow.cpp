#include "cxMainWindow.h"
#include <QtWidgets>
#include "QVTKWidget.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"

#define SHOW_ERROR

MainWindow::MainWindow()
{
#ifdef SHOW_ERROR
	QVTKWidget* widget = new QVTKWidget();
	// add a renderer for a less messy view: The bug appears without it as well.
	vtkRenderer* renderer = vtkRenderer::New();
	renderer->SetBackground(0,0,1);
	widget->GetRenderWindow()->AddRenderer(renderer);
	renderer->Delete();
#else
	QWidget* widget = new QLabel("Hello QVTK");
#endif
	this->setCentralWidget(widget);

	// The hidden toolbar makes the bug more obvious.
	// Without this the drag/drop of QDockWidgets is still messed up.
	this->addHiddenToolbar();

	// drag A on top of B -> white square appears (if not already present at startup)
	this->addDock("A");
	this->addDock("B");
}

void MainWindow::addHiddenToolbar()
{
	QToolBar* toolbar = new QToolBar("FooBar");
	this->addToolBar(toolbar);
	toolbar->hide();
	toolbar->addAction("Foo");
}

void MainWindow::addDock(QString name)
{
	QDockWidget* dockWidget = new QDockWidget(name, this);
	dockWidget->setWidget(new QLabel(name));
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
}

