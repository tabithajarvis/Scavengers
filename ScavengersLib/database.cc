#include "database.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QDebug>

Database::Database()
{
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName("C:\\Users\\Tabi\\OneDrive\\Documents\\QtScavengers\\Scavengers\\Scavengers.db");

    if(!db_.open()) {
        qDebug() << "Database failed to open!";
        qDebug() << db_.lastError().text();
    }

/*
    QFile card_db("../json/card_db.json");
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
        card.type = card_object.value("types").toString();
        card.scrap_effect = card_object.value("scrap_effect").toString();
        map[card.id] = card;
    }*/
}

Database::~Database() {
    db_.close();
}

Card Database::GetCard(int id) {
    QSqlQuery query;
    query = db_.exec(QString("SELECT * FROM Card WHERE id = %1").arg(id));

    Card card;

    if(query.first()) {
        card.id = query.value("id").toInt();
        card.name = query.value("name").toString();
        card.salvage = query.value("salvage").toInt();
        card.scrap = query.value("scrap").toInt();
        card.attack = query.value("attack").toInt();
        card.defense = query.value("defense").toInt();
        card.effects = query.value("effects").toString();
        card.type = query.value("type").toString();
        card.scrap_effect = query.value("scrap_effect").toString();
    } else {
        qDebug() << "Card with id " << id << " not found.";
    }

    return card;
}
