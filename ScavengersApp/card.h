#ifndef CARD_H
#define CARD_H

#include <QFrame>
#include <QString>

const int MAX_NUM_TYPES = 3;

struct Card {
    int id;
    QString name;
    int salvage;
    int scrap;
    int attack;
    int defense;
    QString effects;
    QString type[MAX_NUM_TYPES];
    QString scrap_effect;
    int attack_modifier=0;
    int defense_modifier=0;
    int damage=0;
};

class CardWidget : public QFrame
{
public:
    CardWidget(Card card);
    void set_name(QString name) { card_.name = name; }
    QString name() { return card_.name; }

private:
    QString name_;
    Card card_;
};

#endif // CARD_H
