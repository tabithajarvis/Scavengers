#include "card.h"

#include <QLabel>
#include <QVBoxLayout>

CardWidget::CardWidget(Card card)
    : QFrame(),
      card_(card) {

    setFixedSize(150, 200);
    setStyleSheet("background-color: white; border-radius: 10px");
    setFrameStyle(QFrame::Panel | QFrame::Raised);

    QLabel *name_label = new QLabel(card_.name);
    QVBoxLayout *layout = new QVBoxLayout();
    name_label->setAlignment(Qt::AlignHCenter);
    layout->addWidget(name_label);
    setLayout(layout);
}
