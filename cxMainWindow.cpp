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

