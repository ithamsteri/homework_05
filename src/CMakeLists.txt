# make executable file for application
add_executable(prototype
        main.cpp
        DocumentController.h
        DocumentModel.h
        DocumentView.h
        shapes/IShape.h
        shapes/Circle.h shapes/Circle.cpp
        shapes/Rectangle.h shapes/Reactangle.cpp
        shapes/TextBox.h shapes/TextBox.cpp
        storages/IImport.h storages/IExport.h
        storages/SVG_Storage.h)

set_target_properties(prototype PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON)

install(TARGETS prototype RUNTIME DESTINATION bin)
