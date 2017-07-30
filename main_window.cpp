#include "main_window.h"
#include "ui_main_window.h"

#include <QLabel>
#include <QDebug>

#include "card.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow){
    ui_->setupUi(this);

    player_deck_ = new Deck();
    player_deck_->ParseDeckList(":test_deck_all_same.json");
    player_deck_->StartGame();

    QHBoxLayout *hand = new QHBoxLayout();
    //QHBoxLayout *library = new QHBoxLayout();
    for(int i=0; i<player_deck_->hand_size(); i++) {
        hand->addWidget(new CardWidget(player_deck_->Draw()));
    }
    ui_->hand->setLayout(hand);
}

void MainWindow::Initialize() {
}

MainWindow::~MainWindow()
{
    delete ui_;
    delete player_deck_;
}
