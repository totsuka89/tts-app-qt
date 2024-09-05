#ifndef GOOGLETTSMODEL_H
#define GOOGLETTSMODEL_H

#include "model.h"

class GoogleTtsModel : public Model {
   public:
    explicit GoogleTtsModel(QObject* parent = nullptr);

    std::string synthesis(QString language, QString text, QString apiKey) override;

    void save(QString language, QString text, QString apiKey) override;
};

#endif  // GOOGLETTSMODEL_H
