#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "board.h"

namespace Ui { class XO; }

class XO : public QWidget
{
    Q_OBJECT

public:
    explicit XO(QWidget *parent = nullptr);
    ~XO();

public slots:
    void SetIsPlayerVsComputerMode(bool value)
    {
        isPlayerVsComputerMode = value;
    }

private slots:
    void HandleButton1Clicked();

    void HandleButton2Clicked();

    void HandleButton3Clicked();

    void HandleButton4Clicked();

    void HandleButton5Clicked();

    void HandleButton6Clicked();

    void HandleButton7Clicked();

    void HandleButton8Clicked();

    void HandleButton9Clicked();

private:
    Ui::XO *ui;
    Board *game = new Board();

    bool isPlayerVsComputerMode;
    char playerSymbol, computerSymbol;

    void WhoGoesFirstMessage();
    void DisableAllButtons();
    void CheckEndOfGame();
    void ResetGame();
    void HandleComputerMove();
};

#endif // GAMEWINDOW_H
