#pragma once

#include "IExport.h"
#include "IImport.h"

/// Класс для загрузки/сохранения данных из SVG файла.
class SVGFormatStorage : IImport, IExport {
  /// Загрузка сериализованных данных из SVG файла.
  /// @param params параметры для открытия SVG файла
  /// @return вектор сериализованных данных примитивов в документе
  std::vector<std::string> importData(const std::string &params) override {
    return std::vector<std::string>{};
  }

  /// Сохранение сериализованных данных в SVG файл.
  /// @param params параметры для открытия SVG файла
  /// @param data вектор сериализованных данных примитивов для сохранения
  void exportData(const std::vector<std::string> &data,
                  const std::string &params) override{};
};