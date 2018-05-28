#pragma once

#include <string>
#include <vector>

/// Интерфейс для сохранения данных документа во внешнее хранилище.
struct IExport {
  virtual void exportData(const std::vector<std::string> &data,
                          const std::string &params) = 0;
};