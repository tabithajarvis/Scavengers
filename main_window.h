#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "deck.h"

namespace Ui {
class MainWindow;
class Card;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Initialize();
    ~MainWindow();

private:
    Ui::MainWindow *ui_;
    Deck *player_deck_;
};

#endif // MAIN_WINDOW_H
