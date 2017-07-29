#include "carddb.h"

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
    for(int i=0; i<cards.size();i++) {
        card.id = cards[i].toObject().value("id").toInt();
        card.name = cards[i].toObject().value("name").toString();
        map[card.id] = card;
    }
}

Card CardDB::GetCard(int id) {
    return map[id];
}
