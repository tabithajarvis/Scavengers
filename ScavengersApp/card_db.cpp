#include "card_db.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

#include <QDebug>

CardDB::CardDB()
{
    QFile card_db(":card_db.json");
    if(!card_db.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open Card DB.");
    }

    QJsonParseError error;
    QJsonObject load_cards = QJsonDocument::fromJson(card_db.readAll(), &error).object();
    card_db.close();

    qDebug() << error.errorString();

    QJsonArray cards = load_cards["cards"].toArray();

    Card card;
    QJsonObject card_object;
    for(int i=0; i<cards.size();i++) {
        QJsonObject card_object = cards[i].toObject();
        card.id = card_object.value("id").toInt();
        card.name = card_object.value("name").toString();
        card.salvage = card_object.value("salvage").toInt();
        card.scrap = card_object.value("scrap").toInt();
        card.attack = card_object.value("attack").toInt();
        card.defense = card_object.value("defense").toInt();
        card.effects = card_object.value("effects").toString();
        card.type[0] = card_object.value("types").toArray().at(0).toString();
        // TODO: add multi-type support.
        card.scrap_effect = card_object.value("scrap_effect").toString();
        map[card.id] = card;
    }
}

Card CardDB::GetCard(int id) {
    return map[id];
}
