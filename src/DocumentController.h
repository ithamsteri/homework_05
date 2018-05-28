#pragma once

#include "DocumentModel.h"
#include "DocumentView.h"
#include "shapes/IShape.h"
#include "storages/IExport.h"
#include "storages/IImport.h"
#include <memory>

/// Контроллер документа, который взаимодействует с пользователем.
class DocumentController {
  std::unique_ptr<DocumentModel> model_;
  std::unique_ptr<DocumentView> view_;

public:
  DocumentController(DocumentModel *model, DocumentView *view)
      : model_{model}, view_{view} {}

  /// Добавление примитива в документ и перерисовка примитивов.
  /// @param shape указатель на примитив
  /// @return индентификатор примитива в документе
  unsigned long addShape(IShape *shape) {
    auto id = model_->addShape(shape->readData());
    view_->draw();
    return id;
  }

  /// Удаление примитива из документа и перерисовка примитивов.
  /// @param id индетификатор примитива в документе
  /// @return `true` если примитив удалён, иначе `false`
  bool removeShape(unsigned long id) {
    bool result = model_->removeShape(id);
    view_->draw();
    return result;
  }

  /// Получение сериализованных данных примитива.
  /// @param id индетификатор примитива в документе
  /// @return строка с сериализованными данными примитива
  std::string getShape(unsigned long id) { return model_->getShape(id); }

  /// Загрузка документа из внешнего хранилища.
  /// @param importer указатель на объект, импортирующий документ
  /// @param params строка с параметрами для импортирующего объекта
  void load(IImport *importer, const std::string &params) {
    model_->load(importer, params);
  }

  /// Сохранение документа во внешнего хранилища.
  /// @param exporter указатель на объект, экспортирующий документ
  /// @param params строка с параметрами для экспортирующего объекта
  void save(IExport *exporter, const std::string &params) {
    model_->save(exporter, params);
  }
};