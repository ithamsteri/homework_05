#include <map>
#include <memory>
#include <vector>

#include "DocumentController.h"
#include "DocumentModel.h"
#include "DocumentView.h"

int main(int, char *[]) {
  DocumentController documentController(new DocumentModel, new DocumentView);

  return 0;
}
