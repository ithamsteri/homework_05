#ifndef PROTOTYPE_SHAPES_RECTANGLE_HEADER
#define PROTOTYPE_SHAPES_RECTANGLE_HEADER

#include "IShape.h"
#include <string>

/// Rectangle is a vector shape.
struct Rectangle : IShape {
    Rectangle() = default;
    Rectangle(const std::string &data) { writeData(data); }

    std::string readData() const override;
    void writeData(const std::string &) override;
};

#endif // PROTOTYPE_SHAPES_RECTANGLE_HEADER