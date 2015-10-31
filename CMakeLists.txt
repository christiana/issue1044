project(issue1044)

cmake_minimum_required(VERSION 2.8.12)

    find_package(Qt5Core REQUIRED) # attempt to remove warning in cmake
    find_package(Qt5Widgets REQUIRED)

	find_package(VTK COMPONENTS
		vtkCommonCore
		vtkRenderingCore vtkRenderingQt vtkRenderingOpenGL vtkRenderingFreeTypeOpenGL vtkInteractionStyle
		vtkRenderingVolume vtkRenderingVolumeOpenGL
		vtkIOGeometry vtkIOLegacy vtkIOMINC
		vtkIOXMLParser
		vtkFiltersModeling
		vtkInteractionWidgets
		vtkParallelCore
		vtkFiltersParallel
		vtkImagingMath vtkImagingMorphological vtkImagingColor vtkImagingStatistics
		NO_MODULE)
	#find_package(VTK REQUIRED) # import all libs - try this for debugging lib includes
    include(${VTK_USE_FILE})

add_executable(CustusX cxMain.cpp cxMainWindow.cpp cxMainWindow.h) 

target_link_libraries(CustusX
    Qt5::Core
    Qt5::Widgets
	${VTK_LIBRARIES}
)
