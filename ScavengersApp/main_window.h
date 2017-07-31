#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QHBoxLayout>
#include <QMainWindow>
#include "client.h"
#include "../game_state.h"
#include "deck.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Initialize();
    ~MainWindow();

public slots:
    void PlayCard(CardWidget *card_widget);
    void UpdateGameState();

private:
    Ui::MainWindow *ui_;
    Deck *player_deck_;
    Client client_;
    QHBoxLayout *hand_layout_;
    QHBoxLayout *enemy_zone_layout_;
    QHBoxLayout *player_zone_layout_;
    QHBoxLayout *shared_zone_layout_;
    GameState game_state_;
};

#endif // MAIN_WINDOW_H
