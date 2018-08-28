#ifndef PROTOTYPE_DOCUMENTVIEW_HEADER
#define PROTOTYPE_DOCUMENTVIEW_HEADER

#include "DocumentModel.h"
#include <memory>

/// DocumentView can be any output representation of information.
class DocumentView {
  public:
    /// Contructor requiring the DocumentModel as data source.
    /// @param model DocumentModel
    DocumentView(const DocumentModel &model) : model_{model} {}

    /// Draw elements in GUI.
    void draw() {
        auto iters = model_.getData();
        for (auto iter = iters.first; iter != iters.second; ++iter) {
            DocumentModel::id_type id;
            std::string data;

            std::tie(id, data) = (*iter);
            // draw vector shape
        }
    }

  private:
    const DocumentModel &model_;
};

#endif // PROTOTYPE_DOCUMENTVIEW_HEADER