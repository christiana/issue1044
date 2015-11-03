project(issue1044)

cmake_minimum_required(VERSION 2.8.12)

find_package(Qt5Widgets REQUIRED)
find_package(VTK COMPONENTS vtkRenderingQt NO_MODULE)
include(${VTK_USE_FILE})

add_executable(issue1044 MACOSX_BUNDLE cxMain.cpp cxMainWindow.cpp cxMainWindow.h)

target_link_libraries(issue1044
    Qt5::Widgets
	${VTK_LIBRARIES}
)
