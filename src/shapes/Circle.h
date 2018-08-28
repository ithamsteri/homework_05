#ifndef PROTOTYPE_SHAPES_CIRCLE_HEADER
#define PROTOTYPE_SHAPES_CIRCLE_HEADER

#include "IShape.h"
#include <string>

/// Circle is a vector shape.
struct Circle : IShape {
    Circle() = default;
    Circle(const std::string &data) { writeData(data); }

    std::string readData() const override;
    void writeData(const std::string &) override;
};

#endif // PROTOTYPE_SHAPES_CIRCLE_HEADER