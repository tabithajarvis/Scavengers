#include "card.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

#include <QDebug>

CardWidget::CardWidget(CardInstance card_instance)
    : QPushButton(),
      card_instance_(card_instance) {

    setFixedSize(150, 200);
    setStyleSheet("background-color: white; border-radius: 5px;font: \"Arial\"; font-size: 10px; ");
    //setFrameStyle(QFrame::Panel | QFrame::Raised);

    // Set card properties
    QLabel *name_label         = new QLabel(card_instance.card.name);
    QLabel *salvage_label      = new QLabel(QString::number(card_instance.card.salvage));
    QLabel *scrap_label        = new QLabel(QString::number(card_instance.card.scrap));
    QLabel *attack_label       = new QLabel(QString::number(card_instance.card.attack));
    QLabel *defense_label      = new QLabel(QString::number(card_instance.card.defense));
    QLabel *effects_label      = new QLabel(card_instance.card.effects);
    QLabel *type_label         = new QLabel(card_instance.card.type[0]);
    QLabel *scrap_effect_label = new QLabel(card_instance.card.scrap_effect);

    effects_label->setWordWrap(true);

    QVBoxLayout *vert_layout = new QVBoxLayout();
    QHBoxLayout *top_layout = new QHBoxLayout();
    QHBoxLayout *bottom_layout = new QHBoxLayout();
    top_layout->addWidget(salvage_label, 1, Qt::AlignLeft);
    top_layout->addWidget(name_label, 3, Qt::AlignCenter);
    top_layout->addWidget(scrap_label, 1, Qt::AlignRight);

    bottom_layout->addWidget(attack_label, 1, Qt::AlignLeft);
    bottom_layout->addWidget(type_label, 3, Qt::AlignCenter);
    bottom_layout->addWidget(defense_label, 1, Qt::AlignRight);

    vert_layout->addLayout(top_layout, 1);
    vert_layout->addLayout(new QHBoxLayout(), 4);
    vert_layout->addWidget(effects_label, 2);
    vert_layout->addWidget(scrap_effect_label, 1);
    vert_layout->addLayout(bottom_layout, 1);
    setLayout(vert_layout);

    connect(this, SIGNAL(clicked()), this, SLOT(CardSelected()));
}

void CardWidget::CardSelected() {
    emit CardToBattlefield(this);
}
