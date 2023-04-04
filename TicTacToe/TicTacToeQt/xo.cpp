#include "xo.h"
#include "ui_xo.h"
#include "board.h"

XO::XO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::XO)
{
    ui->setupUi(this);

    connect(ui->button1, &QPushButton::clicked, this, &XO::HandleButton1Clicked);
    connect(ui->button2, &QPushButton::clicked, this, &XO::HandleButton2Clicked);
    connect(ui->button3, &QPushButton::clicked, this, &XO::HandleButton3Clicked);
    connect(ui->button4, &QPushButton::clicked, this, &XO::HandleButton4Clicked);
    connect(ui->button5, &QPushButton::clicked, this, &XO::HandleButton5Clicked);
    connect(ui->button6, &QPushButton::clicked, this, &XO::HandleButton6Clicked);
    connect(ui->button7, &QPushButton::clicked, this, &XO::HandleButton7Clicked);
    connect(ui->button8, &QPushButton::clicked, this, &XO::HandleButton8Clicked);
    connect(ui->button9, &QPushButton::clicked, this, &XO::HandleButton9Clicked);

    WhoGoesFirstMessage();

    connect(ui->yesButton, &QPushButton::clicked, this, &XO::ResetGame);
    connect(ui->noButton, &QPushButton::clicked, qApp, &QApplication::quit);

    ui -> yesButton->hide();
    ui -> noButton->hide();
}

XO::~XO()
{
    delete ui;
}

void XO::HandleButton1Clicked()
{
    ui -> button1 -> setText(QString(game -> GetTurn()));
    ui -> button1 -> setEnabled(false);
    game -> MarkAndChangeTurn(0, 0);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::HandleButton2Clicked()
{
    ui -> button2 -> setText(QString(game -> GetTurn()));
    ui -> button2 -> setEnabled(false);
    game -> MarkAndChangeTurn(0, 1);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::HandleButton3Clicked()
{
    ui -> button3 -> setText(QString(game -> GetTurn()));
    ui -> button3 -> setEnabled(false);
    game -> MarkAndChangeTurn(0, 2);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::HandleButton4Clicked()
{
    ui -> button4 -> setText(QString(game -> GetTurn()));
    ui -> button4 -> setEnabled(false);
    game -> MarkAndChangeTurn(1, 0);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::HandleButton5Clicked()
{
    ui -> button5 -> setText(QString(game -> GetTurn()));
    ui -> button5 -> setEnabled(false);
    game -> MarkAndChangeTurn(1, 1);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::HandleButton6Clicked()
{
    ui -> button6 -> setText(QString(game -> GetTurn()));
    ui -> button6 -> setEnabled(false);
    game -> MarkAndChangeTurn(1, 2);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::HandleButton7Clicked()
{
    ui -> button7 -> setText(QString(game -> GetTurn()));
    ui -> button7 -> setEnabled(false);
    game -> MarkAndChangeTurn(2, 0);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::HandleButton8Clicked()
{
    ui -> button8 -> setText(QString(game -> GetTurn()));
    ui -> button8 -> setEnabled(false);
    game -> MarkAndChangeTurn(2, 1);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::HandleButton9Clicked()
{
    ui -> button9 -> setText(QString(game -> GetTurn()));
    ui -> button9 -> setEnabled(false);
    game -> MarkAndChangeTurn(2, 2);
    if (isPlayerVsComputerMode == true && !(game->GetOccupiedPositionsCount() == 9) && (game->IsWinner() == '\0' || game->IsWinner() == 'D'))
    {
        HandleComputerMove();
    }
    else
    {
        CheckEndOfGame();
    }
}

void XO::DisableAllButtons()
{
    ui -> button1 -> setEnabled(false);
    ui -> button2 -> setEnabled(false);
    ui -> button3 -> setEnabled(false);
    ui -> button4 -> setEnabled(false);
    ui -> button5 -> setEnabled(false);
    ui -> button6 -> setEnabled(false);
    ui -> button7 -> setEnabled(false);
    ui -> button8 -> setEnabled(false);
    ui -> button9 -> setEnabled(false);
}

void XO::WhoGoesFirstMessage()
{
    computerSymbol = game -> WhoGoesFirst();

    if (computerSymbol == game -> GetTurn() && isPlayerVsComputerMode == true)
    {
        ui -> currentMessage -> setText(("Flipping a coin...\n") + QString(game -> GetTurn()).append(" goes first."));
        HandleComputerMove();
    }
    else
    {
        if (computerSymbol == 'X')
        {
            playerSymbol = 'O';
        }
        else
        {
            playerSymbol = 'X';
        }

        game -> SetTurn(playerSymbol);

        ui -> currentMessage -> setText(("Flipping a coin...\n") + QString(game -> GetTurn()).append(" goes first."));
    }
}

void XO::HandleComputerMove()
{
    int i, j;

    do
    {
        i = rand() % 3;
        j = rand() % 3;
    } while (game -> IsAlreadyMarked(i, j));

    game -> MarkAndChangeTurn(i, j);

    QString buttonName = "button" + QString::number(i * 3 + j + 1);
    QPushButton* button = findChild<QPushButton*>(buttonName);

    if (button)
    {
        button->setText(QString(computerSymbol));
        button->setEnabled(false);
    }
    CheckEndOfGame();
}

void XO::ResetGame()
{
    ui -> button1 -> setText("");
    ui -> button1 -> setEnabled(true);

    ui -> button2 -> setText("");
    ui -> button2 -> setEnabled(true);

    ui -> button3 -> setText("");
    ui -> button3 -> setEnabled(true);

    ui -> button4 -> setText("");
    ui -> button4 -> setEnabled(true);

    ui -> button5 -> setText("");
    ui -> button5 -> setEnabled(true);

    ui -> button6 -> setText("");
    ui -> button6 -> setEnabled(true);

    ui -> button7 -> setText("");
    ui -> button7 -> setEnabled(true);

    ui -> button8 -> setText("");
    ui -> button8 -> setEnabled(true);

    ui -> button9 -> setText("");
    ui -> button9 -> setEnabled(true);

    game = new Board();

    WhoGoesFirstMessage();

    ui->yesButton->hide();
    ui->noButton->hide();
}


void XO::CheckEndOfGame()
{
    char winner = game -> IsWinner();
    if (winner != '\0' && winner != 'D')
    {
        DisableAllButtons();
        ui -> currentMessage -> setText(QString(winner).append(" won! ") + ("Would you like to play again?"));

        ui -> yesButton->show();
        ui -> noButton->show();
    }
    else if (winner == 'D')
    {
        DisableAllButtons();
        ui -> currentMessage -> setText(QString().append("Draw! ") + ("Would you like to play again?"));

        ui -> yesButton->show();
        ui -> noButton->show();
    }
}
