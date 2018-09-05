#ifndef PROTOTYPE_DOCUMENTCONTROLLER_HEADER
#define PROTOTYPE_DOCUMENTCONTROLLER_HEADER

#include "DocumentModel.h"
#include "DocumentView.h"
#include "shapes/IShape.h"
#include "storages/IExport.h"
#include "storages/IImport.h"
#include <string>

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/TextBox.h"

/// Enum class with all types of shapes for document
enum class Shape {
    Circle,
    Rectangle,
    TextBox,
};

/// DocumentController accepts input and converts it to commands for the model or view.
class DocumentController {
  public:
    /// Contructor requiring the DocumentModel and DocumentView.
    /// @param model DocumentModel
    /// @param view DocumentView
    DocumentController(DocumentModel &model, DocumentView &view) : model_{model}, view_{view} {}

    /// Add a vector shape in the document with redraw.
    /// @param shape a shape for adding to the document
    /// @param param parameters for the shape
    /// @return identifier of the vector shape in document
    DocumentModel::id_type addShape(Shape shape, const std::string &param) {
        DocumentModel::id_type id;

        switch (shape) {
        case Shape::Circle:
            id = model_.addShape(Circle(param).readData());
            break;
        case Shape::Rectangle:
            id = model_.addShape(Rectangle(param).readData());
            break;
        case Shape::TextBox:
            id = model_.addShape(TextBox(param).readData());
            break;
        }

        view_.draw();
        return id;
    }

    /// Delete a vector shape in the document with redraw.
    /// @param id identifier of the vector shape in the document
    /// @return `true` if successful, otherwise `false`
    bool removeShape(unsigned long id) {
        bool result = model_.removeShape(id);
        view_.draw();
        return result;
    }

    /// Delete all vector shapes from the document.
    void clear() { model_.clear(); }

    /// Get serialized data of vector shape by identifier.
    /// @param id identifier of shape in document
    /// @return string with serialized data of the shape
    std::string getShape(unsigned long id) { return model_.getShape(id); }

    /// Load a document from external storage.
    /// @param importer pointer on IImport object for import a document
    /// @param params string with parameters for the IImport object
    void load(IImport *importer, const std::string &params) { model_.load(importer, params); }

    /// Save a document to external storage.
    /// @param exporter pointer on IExport object for export a document
    /// @param params string with parameters for the IExport object
    void save(IExport *exporter, const std::string &params) { model_.save(exporter, params); }

  private:
    DocumentModel &model_;
    DocumentView &view_;
};

#endif // PROTOTYPE_DOCUMENTCONTROLLER_HEADER