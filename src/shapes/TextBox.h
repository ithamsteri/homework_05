#include "IShape.h"

struct TextBox : IShape {
  TextBox() = default;
  TextBox(const std::string& data) { writeData(data); }

  std::string readData() const override;
  void writeData(const std::string &data) override;
};