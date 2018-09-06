#include "DocumentController.h"
#include "DocumentModel.h"
#include "DocumentView.h"
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

    // ****************************
    // * Work with empty document *
    // ****************************
    controller.addShape(Shape::Circle, "x=100;y=323;radius=3");
    controller.addShape(Shape::Rectangle, "x=10;y=30;width=100;height=390");
    controller.clear();

    // *****************************************
    // * Load from storage and modify document *
    // *****************************************
    SVGStorage storage;
    controller.load(&storage, "filename: funny.svg");
    auto rect_id = controller.addShape(Shape::Rectangle, "x=100;y=10;width=140;height=30");
    auto circle_id = controller.addShape(Shape::Circle, "x=10;y=5;radius=12");
    controller.removeShape(rect_id);

    std::clog << "Serialized data of Circle: " << controller.getShape(circle_id) << '\n';

    // save to storage with new filename
    controller.save(&storage, "filename: funny_new.svg");

    return 0;
}
