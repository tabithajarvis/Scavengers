#ifndef CARD_H
#define CARD_H

#include <QFrame>
#include <QString>
#include <QPushButton>

const int MAX_NUM_TYPES = 3;

enum class PlayArea {
    kLibrary = 0,
    kHand,
    kGraveyard,
    kPlayerZone,
    kSharedZone,
    kEnemyZone
};


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
};

struct CardInstance {
    Card card;
    int attack_modifier=0;
    int defense_modifier=0;
    int damage=0;
    int player_id;
    PlayArea play_area = PlayArea::kLibrary;
};

class CardWidget : public QPushButton
{
    Q_OBJECT

public:
    CardWidget(CardInstance card_instance);
    CardInstance *card_instance() { return &card_instance_; }

public slots:
    void CardSelected();

signals:
    void CardToBattlefield(CardWidget *card);

private:
    QString name_;
    CardInstance card_instance_;
};

#endif // CARD_H
