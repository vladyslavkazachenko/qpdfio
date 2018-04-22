add_executable(qpdfio_pdf1_0_testapp pdf1_0_testapp.cpp main_window.cpp)
target_link_libraries(qpdfio_pdf1_0_testapp Qt4::QtCore Qt4::QtGui $<TARGET_OBJECTS:documentview> pdfio)
