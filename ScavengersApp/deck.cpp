#include "deck.h"

#include <iostream>
#include <fstream>
#include <random>

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "card_db.h"

Deck::Deck()
{

}

void Deck::StartGame() {
    for(Card card : all_cards_) {
        library_.emplace_back(card);
    }
    Shuffle();
}

void Deck::Shuffle() {
    std::random_device seed;
    std::mt19937 rng(seed());

    std::shuffle(library_.begin(), library_.end(), rng);
}

void Deck::AddCard(Card card) {
    all_cards_.emplace_back(card);
}

CardInstance Deck::Draw() {
    Card card_draw = library_.back();
    CardInstance card_instance;
    card_instance.card = card_draw;
    hand_.emplace_back(card_instance);
    library_.pop_back();
    return card_instance;
}

bool Deck::ParseDeckList(const QString &file_name) {
    QFile deck_file(file_name);
    if(!deck_file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return false;
    }

    QJsonObject load_deck = QJsonDocument::fromJson(deck_file.readAll()).object();
    deck_file.close();
    QJsonArray cards = load_deck["deck"].toArray();


    CardDB *card_db = new CardDB();
    for(int i=0; i<cards.size();i++) {
        for(int j=0; j<cards[i].toObject().value("amount").toInt(); j++)
            AddCard(card_db->GetCard(cards[i].toObject().value("id").toInt()));
    }

    qDebug() << "Cards loaded: " << all_cards_.size();
    return true;
}
