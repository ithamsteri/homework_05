#ifndef PROTOTYPE_SHAPES_TEXTBOX_HEADER
#define PROTOTYPE_SHAPES_TEXTBOX_HEADER
#include "IShape.h"

/// TextBox is a vector shape.
struct TextBox : IShape {
    TextBox() = default;
    TextBox(const std::string &data) { writeData(data); }

    std::string readData() const override;
    void writeData(const std::string &data) override;
};

#endif // PROTOTYPE_SHAPES_TEXTBOX_HEADER