# issue1044
Test code for CustusX issue1044: Bad interference between QDockWidget, Toolbar and QVTKWidget.
Where: Mac + Qt5

How to reproduce:
* start application.
* drag the lower dockwidget onto the upper.
* A white box appears, covering the upper right corner of the mainwindow.

This is a boiled-down version of the problem. The white box is one issue, another problem is that the toolbar is corrupted in the same process (not shown in this test code).
