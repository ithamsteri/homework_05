#include "IShape.h"

struct Rectangle : IShape {
  Rectangle() = default;
  Rectangle(const std::string& data) { writeData(data); }

  std::string readData() const override;
  void writeData(const std::string &data) override;
};