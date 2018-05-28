#pragma once

#include "shapes/IShape.h"
#include "storages/IExport.h"
#include "storages/IImport.h"

class DocumentModel {
  using id_type = unsigned long;

  std::map<id_type, std::string> shapes_;
  id_type counter_ = 0;

public:
  /// Добавление сериализованного примитива в документ.
  /// @param serialised_data сериализоанные данные примитива
  /// @return идентификатор примитива в документе
  id_type addShape(const std::string &serialised_data) {
    shapes_[++counter_] = serialised_data;
    return counter_;
  }

  /// Удаление примитива из документа.
  /// @param id индентификатор примитива в документе
  /// @return `true` если примитив удалён, иначе `false`
  bool removeShape(id_type id) { return (shapes_.erase(id) > 0); }

  /// Получение сериализованных данных примитива.
  /// @param id индетификатор примитива в документе
  /// @return строка с сериализованными данными примитива
  std::string getShape(id_type id) { return shapes_[id]; }

  /// Загрузка документа из внешнего хранилища.
  /// @param importer указатель на объект, импортирующий документ
  /// @param params строка с параметрами для импортирующего объекта
  void load(IImport *importer, const std::string &params) {
    shapes_.clear();
    counter_ = 0;

    for (const auto &data : importer->importData(params)) {
      shapes_[++counter_] = data;
    }
  }

  /// Сохранение документа во внешнего хранилища.
  /// @param exporter указатель на объект, экспортирующий документ
  /// @param params строка с параметрами для экспортирующего объекта
  void save(IExport *exporter, const std::string &params) {
    std::vector<std::string> data;
    data.reserve(shapes_.size());

    for (const auto &shape : shapes_) {
      data.push_back(shape.second);
    }

    exporter->exportData(data, params);
  }
};