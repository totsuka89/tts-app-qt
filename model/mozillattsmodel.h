#ifndef MOZILLATTSMODEL_H
#define MOZILLATTSMODEL_H

#include "model.h"

class MozillaTtsModel : public Model {
   public:
    explicit MozillaTtsModel(QObject* parent = nullptr);

    std::string synthesis(QString language, QString text, QString option) override;

    void save(QString language, QString text, QString option) override;
};

#endif  // MOZILLATTSMODEL_H
