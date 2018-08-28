#ifndef PROTOTYPE_DOCUMENTMODEL_HEADER
#define PROTOTYPE_DOCUMENTMODEL_HEADER

#include "shapes/IShape.h"
#include "storages/IExport.h"
#include "storages/IImport.h"
#include <map>
#include <string>
#include <vector>

/// DocumentModel directly manages the data, logic and rules of the application.
class DocumentModel {
  public:
    using id_type = unsigned long;

    /// Add a vector shape as serialized data.
    /// @param serialized_data string with serialized data of a vector shape
    /// @return identifier of the vector shape in document
    id_type addShape(const std::string &serialized_data) {
        shapes_[++current_id_] = serialized_data;
        return current_id_;
    }

    /// Remove a vector shape from document.
    /// @param id identifier of shape in document
    /// @return `true` if successful, otherwise `false`
    bool removeShape(id_type id) { return (shapes_.erase(id) > 0); }

    /// Delete all vector shapes from the document.
    void clear() {
        shapes_.clear();
        current_id_ = 0;
    }

    /// Get serialized data of vector shape by identifier.
    /// @param id identifier of shape in document
    /// @return string with serialized data of the shape
    std::string getShape(id_type id) const { return shapes_.at(id); }

    /// Get a pair of iterators for all vector shapes in document.
    /// @return std::pair with constant iterators of start and end the data
    auto getData() const {
        using pair_element = decltype(shapes_)::const_iterator;
        return std::make_pair<pair_element, pair_element>(shapes_.cbegin(), shapes_.cend());
    }

    /// Load a document from external storage.
    /// @param importer pointer on IImport object for import a document
    /// @param params string with parameters for the IImport object
    void load(IImport *importer, const std::string &params) {
        clear();
        for (const auto &data : importer->importData(params)) {
            shapes_[++current_id_] = data;
        }
    }

    /// Save a document to external storage.
    /// @param exporter pointer on IExport object for export a document
    /// @param params string with parameters for the IExport object
    void save(IExport *exporter, const std::string &params) const {
        std::vector<std::string> data;
        data.reserve(shapes_.size());

        for (const auto &shape : shapes_) {
            data.push_back(shape.second);
        }

        exporter->exportData(data, params);
    }

  private:
    std::map<id_type, std::string> shapes_;
    id_type current_id_ = 0;
};

#endif // PROTOTYPE_DOCUMENTMODEL_HEADER