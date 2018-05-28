#include "IShape.h"

struct Circle : IShape {
  Circle() = default;
  Circle(const std::string& data) { writeData(data); }

  std::string readData() const override;
  void writeData(const std::string &data) override;
};