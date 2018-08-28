#include "DocumentController.h"
#include "DocumentModel.h"
#include "DocumentView.h"
#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "storages/SVG_Storage.h"
#include <iostream>
#include <string>

int main(int, char *[]) {
    // ***************************
    // *  Setup MVC components   *
    // ***************************
    DocumentModel model;
    DocumentView view(model);
    DocumentController controller(model, view);

    // ***************************
    // *   Shapes and storages   *
    // ***************************
    Circle circle;
    Rectangle rectangle;
    SVGStorage storage;

    // ****************************
    // * Work with empty document *
    // ****************************
    controller.addShape(&circle);
    controller.addShape(&rectangle);
    controller.clear();

    // *****************************************
    // * Load from storage and modify document *
    // *****************************************
    controller.load(&storage, "filename: funny.svg");
    auto rect_id = controller.addShape(&rectangle);
    auto circle_id = controller.addShape(&circle);
    controller.removeShape(rect_id);

    std::clog << "Serialized data of Circle: " << controller.getShape(circle_id) << '\n';

    // save to storage with new filename
    controller.save(&storage, "filename: funny_new.svg");

    return 0;
}
