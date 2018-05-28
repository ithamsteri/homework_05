#pragma once

#include <string>
#include <vector>

/// Интерфейс для загрузки данных документа из внешнего хранилища.
struct IImport {
  virtual std::vector<std::string> importData(const std::string &params) = 0;
};
