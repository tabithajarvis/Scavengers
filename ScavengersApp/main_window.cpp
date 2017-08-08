#include "main_window.h"
#include "ui_main_window.h"

#include <QLabel>
#include <QDebug>

#include "card_widget.h"
#include "player.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow) {
    ui_->setupUi(this);

    Player player;
    player.id = 0;
    player.starting_life = 30;
    player.current_life = 30;

    player_deck_ = new Deck();
    player_deck_->ParseDeckList("../json/test_deck.json");
    player_deck_->StartGame();
    qDebug() << "Game started";
    hand_layout_ = new QHBoxLayout();
    enemy_zone_layout_ = new QHBoxLayout();
    player_zone_layout_ = new QHBoxLayout();
    shared_zone_layout_ = new QHBoxLayout();

    for(int i=0; i<player_deck_->hand_size(); i++) {
        CardInstance card_instance = player_deck_->Draw();
        qDebug() << "Card drawn";
        card_instance.player_id = player.id;
        qDebug() << "Player ID set";
        CardWidget *card_widget = new CardWidget(card_instance);
        qDebug() << "Card widget created";
        hand_layout_->addWidget(card_widget);
        connect(card_widget, SIGNAL(CardToBattlefield(CardWidget*)), this, SLOT(PlayCard(CardWidget*)));
    }
    ui_->hand->setLayout(hand_layout_);
}

void MainWindow::Initialize() {
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::PlayCard(CardWidget *card_widget) {
    //card_widget->card_instance()

    player_zone_layout_->addWidget(card_widget);
    hand_layout_->removeWidget(card_widget);
    ui_->player_area->setLayout(player_zone_layout_);

    UpdateGameState();
}

void MainWindow::UpdateGameState() {
    game_state_.cards_in_play.clear();

    for (CardInstance card : player_deck_->player_side()) {
        game_state_.cards_in_play.emplace_back(&card);
    }

    client_.SetGameState(game_state_);
    client_.SendGameState();
}
