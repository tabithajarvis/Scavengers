#ifndef CARD_H
#define CARD_H

#include <QFrame>
#include <QString>

struct Card {
    int id;
    QString name;
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
