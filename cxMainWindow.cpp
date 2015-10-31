/*=========================================================================
This file is part of CustusX, an Image Guided Therapy Application.

Copyright (c) 2008-2014, SINTEF Department of Medical Technology
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors 
   may be used to endorse or promote products derived from this software 
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=========================================================================*/

#include "cxMainWindow.h"

#include <QtWidgets>

#include "QVTKWidget.h"
#include "vtkSmartPointer.h"
#include "vtkRenderWindow.h"

typedef vtkSmartPointer<class vtkRenderWindow> vtkRenderWindowPtr;

namespace cx
{

MainWindow::MainWindow()
{
	this->setObjectName("MainWindow");

	QVTKWidget* widget = new QVTKWidget();
	vtkRenderWindowPtr rw = vtkRenderWindowPtr::New();
	widget->SetRenderWindow(rw);
	rw->GetInteractor()->EnableRenderOff();

	this->setCentralWidget(widget);
//	this->setCentralWidget(viewService()->getLayoutWidget(this, 0));

	this->createToolBars();

	this->setTabPosition(Qt::AllDockWidgetAreas, QTabWidget::North);

	this->addDock("A");
	this->addDock("B");

	this->resize(800,500);
}

void MainWindow::createToolBars()
{
	QToolBar* toolbar = new QToolBar("Data");
	this->addToolBar(toolbar);
	toolbar->hide();
	toolbar->addAction("NewPatient");
}

void MainWindow::addDock(QString name)
{
	QDockWidget* dockWidget = new QDockWidget(name, this);
	dockWidget->setWidget(new QTextBrowser(this));
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
}

MainWindow::~MainWindow()
{

}


////#ifdef CX_APPLE
////	// HACK
////	// Toolbars are not correctly refreshed on mac 10.8,
////	// Cause is related to QVTKWidget (removing it removes the problem)
////	// The following "force refresh by resize" solves repaint, but
////	// inactive toolbars are still partly clickable.
////	QSize size = this->size();
////	this->resize(size.width()-1, size.height());
////	this->resize(size);
////#endif
//}


}//namespace cx
