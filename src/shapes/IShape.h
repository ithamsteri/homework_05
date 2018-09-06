#ifndef PROTOTYPE_SHAPES_ISHAPE_HEADER
#define PROTOTYPE_SHAPES_ISHAPE_HEADER

#include <string>

/// Interface for serialization and deserialization a vector shape.
struct IShape {
    /// Get serialization data of the vector shape.
    /// @return std::string with serialization data
    virtual std::string readData() const = 0;

    /// Set serialization data to internal state of the vector shape.
    /// @param std::string with serialization data
    virtual void writeData(const std::string &) = 0;
};

#endif // PROTOTYPE_SHAPES_ISHAPE_HEADER