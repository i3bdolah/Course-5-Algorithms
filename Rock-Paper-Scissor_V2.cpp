#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

enum enGameChoice { Rock = 1, Paper = 2, Scissor = 3};
enum enWinner { Player = 1, Computer = 2, Draw = 3 }; 


struct stRoundInfo { 
    short RoundNumber = 0; 
    enGameChoice PlayerChoice; 
    enGameChoice ComputerChoice; 
    enWinner Winner; 
    string WinnerName; 
}; 

struct stGameResults { 
    short GameRounds = 0; 
    short PlayerWinTimes = 0; 
    short ComputerWinTimes = 0; 
    short DrawTimes = 0; 
    enWinner GameWinner; 
    string WinnerName = ""; 
};


int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from; 
}

enGameChoice readPlayerChoice() {
    short choice = 1;
    do
    {
        cout << "\nEnter Your Choice [Rock = 1, Paper = 2, Scissor = 3] : ";
        cin >> choice;
    } while (choice >= 3 && choice <= 1);
    return (enGameChoice) choice;
}

enGameChoice getComputerChoice() {
    return (enGameChoice) generateRandomNumber(1,3);
}

string winnerName(enWinner winner) {
    string arr[3] = {"Player", "Computer", "No Winner"};
    return arr[winner - 1];
}

string choiceName(enGameChoice GameChoice) {
    string arr[3] = {"Rock", "Paper", "Scissor"};
    return arr[GameChoice - 1];
}

enWinner gameWinningLogic(stRoundInfo RoundInfo) {
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice) {
        return enWinner::Draw;
    }
    else if 
    (
    RoundInfo.PlayerChoice == enGameChoice::Rock && RoundInfo.ComputerChoice == enGameChoice::Paper || 
    RoundInfo.PlayerChoice == enGameChoice::Paper && RoundInfo.ComputerChoice == enGameChoice::Scissor ||
    RoundInfo.PlayerChoice == enGameChoice::Scissor && RoundInfo.ComputerChoice == enGameChoice::Rock
    ) {
        return enWinner::Computer;
    }
    else { 
        return enWinner::Player;
    }
}

void setWinnerScreenColor(enWinner winner) {
    switch (winner)
    {
    case enWinner::Player :
        system("color 2F"); // turn screen to Green
        break;
    
    case enWinner::Computer :
        system("color 4F"); // turn screen to Red
        cout << "\a";
        break;

    default:
        system("color 6F"); // turn screen to Yellow
        break;
    }
    
}

void printRoundResults(stRoundInfo RoundInfo) {
    cout << "Player Choice                                      : " << choiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice                                    : " << choiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner                                       : " << RoundInfo.WinnerName << endl;
}

enWinner whoWinTheGame(short playerWinTimes, short computerWinTimes) {
    if (playerWinTimes < computerWinTimes)
    {
        return enWinner::Computer;
    }
    else if (playerWinTimes > computerWinTimes) {
        return enWinner::Player;
    }
    else {
        return enWinner::Draw;
    }
}

stGameResults fillGameResults(int gameRounds, short playerWinTimes, short computerWinTimes, short drawTimes) {
    stGameResults GameResults;

    GameResults.GameRounds = gameRounds;
    GameResults.PlayerWinTimes = playerWinTimes;
    GameResults.ComputerWinTimes = computerWinTimes;
    GameResults.DrawTimes = drawTimes;
    GameResults.GameWinner = whoWinTheGame(playerWinTimes, computerWinTimes);
    GameResults.WinnerName = winnerName(GameResults.GameWinner);

    return GameResults;
}

stGameResults playGame(short HowManyRounds) {
    stRoundInfo RoundInfo;
    short playerWinTimes = 0, computerWinTimes = 0, drawTimes = 0;

    for (int counter = 1; counter <= HowManyRounds; counter++)
    {
        cout << "______________________[ROUND " << counter << "]______________________\n";
        RoundInfo.RoundNumber = counter;
        RoundInfo.PlayerChoice = readPlayerChoice();
        RoundInfo.ComputerChoice = getComputerChoice();
        RoundInfo.Winner = gameWinningLogic(RoundInfo);
        RoundInfo.WinnerName = winnerName(RoundInfo.Winner);

        setWinnerScreenColor(RoundInfo.Winner);
        //Increase win/lose/draw counters
        if (RoundInfo.Winner == enWinner::Player)
            playerWinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            computerWinTimes++;
        else
            drawTimes++;
        
        printRoundResults(RoundInfo);
    }
    return fillGameResults(RoundInfo.RoundNumber, playerWinTimes, computerWinTimes, drawTimes);
}

void showFinalGameResults(stGameResults GameResults) {
    cout << "\n";
    cout << "______________________" << "[GAME RESULTS]" << "______________________\n";
    cout << "Game rounds        :   " << GameResults.GameRounds << "\n";
    cout << "Player win Times   :   " << GameResults.PlayerWinTimes << "\n";
    cout << "Computer win Times :   " << GameResults.ComputerWinTimes << "\n";
    cout << "Draw Times         :   " << GameResults.DrawTimes << "\n";
    cout << "Final Winner       :   " << GameResults.WinnerName << "\n";
    cout << "__________________________________________________________";

    setWinnerScreenColor(GameResults.GameWinner);
}

short ReadHowManyRounds() {
    short gameRounds = 1;

    do
    {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> gameRounds; 
    } while (gameRounds < 1 && gameRounds > 10);
    return gameRounds;
}

void ResetScreen() {     
    system("cls");     
    system("color 0F"); 
}

void StartGame() {
    char playAgain = 'Y';

    do
    {
        ResetScreen();
        stGameResults GameResults = playGame(ReadHowManyRounds());
        showFinalGameResults(GameResults);
        
        cout << "\nDo you wish to continue [Y/N]: ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
}

int main() {    
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}