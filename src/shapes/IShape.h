#pragma once

#include <string>

/// Интерфейс для сериализации и десериализации примитивов
struct IShape {
  virtual std::string readData() const = 0;
  virtual void writeData(const std::string&) = 0;
};