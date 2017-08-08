#ifndef CARD_WIDGET_H
#define CARD_WIDGET_H

#include <QFrame>
#include <QString>
#include <QPushButton>

#include "../ScavengersLib/card.h"
#include "../ScavengersLib/database.h"

enum class PlayArea {
    kLibrary = 0,
    kHand,
    kGraveyard,
    kPlayerZone,
    kSharedZone,
    kEnemyZone
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
    CardInstance card_instance() { return card_instance_; }

public slots:
    void CardSelected();

signals:
    void CardToBattlefield(CardWidget *card);

private:
    QString name_;
    CardInstance card_instance_;
};

#endif // CARD_WIDGET_H
