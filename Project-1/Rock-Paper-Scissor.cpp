#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

enum enGameChoice { Rock = 1, Paper = 2, Scissor = 3};

struct stGameResult
{
    int roundCount; // For Printing in Acceding order.
    int numOfRounds; // For managing while.
    int PlayerWinTimes;
    int PlayerLossTimes;
    int PlayerDrawTimes;
};


int readPositiveNums(string msg) {
    int num = 0;
    do
    {
        cout << msg;
        cin >> num;
    } while (num > 3 && num < 1);
    return num;
}

int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from; 
}

string whatIsThisChoice(int playerNum) {
    if (playerNum == enGameChoice::Rock) {
        return "Rock";
    }
    else if (playerNum == enGameChoice::Paper) {
        return "Paper";
    }
    else {
        return "Scissor";
    }
}

void gameWinningLogic(int player1, int player2, stGameResult& playerResult) {
    if (player1 == player2) {
        playerResult.PlayerDrawTimes++;
   		system("color 6F"); // Turn Screen Green
        cout << "The Round result is                                : Draw\n";
    }
    else if 
    (
    player1 == enGameChoice::Rock && player2 == enGameChoice::Paper || 
    player1 == enGameChoice::Paper && player2 == enGameChoice::Scissor ||
    player1 == enGameChoice::Scissor && player2 == enGameChoice::Rock
    ) {
        playerResult.PlayerLossTimes++;
        system("color 4F"); cout << '\a'; // Turn Screen Red
        Beep(200, 500); // Windows beeb sound
        cout << "The Round result is                                : Loosing\n";
    }
    else { 
        playerResult.PlayerWinTimes++;
   		system("color 2F"); // Turn Screen Green
        cout << "The Round result is                                : Winning\n";
    }
}

string finalWinnerLogic(stGameResult playerResult) {
    if (playerResult.PlayerLossTimes > playerResult.PlayerWinTimes)
    {
        return "Computer Wins";
    }
    else if (playerResult.PlayerLossTimes < playerResult.PlayerWinTimes)
    {
        return "Player Wins";
    }
    else {
        return "No Winner, Draw";
    }
    
}

void printGameResult(stGameResult& playerResult) {
    cout << "\n";
    cout << "______________________" << "[GAME RESULTS]" << "______________________\n";
    cout << "Game rounds        :   " << playerResult.numOfRounds << "\n";
    cout << "Player win Times   :   " << playerResult.PlayerWinTimes << "\n";
    cout << "Computer win Times :   " << playerResult.PlayerLossTimes << "\n";
    cout << "Draw Times         :   " << playerResult.PlayerDrawTimes << "\n";
    cout << "Final Winner       :   " << finalWinnerLogic(playerResult) << "\n";
}

void printRoundDetails(stGameResult& playerResult) {
    int userInput = readPositiveNums("\nYour Choice [ Rock = 1 , Paper = 2 , Scissor = 3 ] : ");
    int computerInput = generateRandomNumber(1,3);
    cout << "Player Choice                                      : " << whatIsThisChoice(userInput) << endl;
    cout << "Computer Choice                                    : " << whatIsThisChoice(computerInput) << endl;
    gameWinningLogic(userInput, computerInput, playerResult);
}

void restartGame(stGameResult& playerResult) {
    system("color 0a"); cout << '\a'; // Turn Screen Red
    playerResult.numOfRounds = readPositiveNums("\nEnter The Number of Rounds : ");
    playerResult.PlayerDrawTimes = 0;
    playerResult.PlayerLossTimes = 0;
    playerResult.PlayerWinTimes = 0;
    playerResult.roundCount = 1;
}

bool wishToContinue() {
    return readPositiveNums("\nDo you wish to continue [Yes = 1, No = 0]: ");
}

void gameFlow(stGameResult& playerResult) {
    playerResult.roundCount = 1;
    while (playerResult.numOfRounds != 0)
    {
        cout << "\n___________ROUND NO." << playerResult.roundCount << "___________";
        printRoundDetails(playerResult);
        playerResult.numOfRounds--;
        playerResult.roundCount++;

        if (playerResult.numOfRounds == 0)
        {
            printGameResult(playerResult);
            if (wishToContinue())
            {
                restartGame(playerResult);
            }
        }
    }
}

void StartGame() {
    stGameResult playerResult;

    // Intialize struct variables:
    playerResult.numOfRounds = readPositiveNums("\nEnter The Number of Rounds : ");
    playerResult.PlayerDrawTimes = 0;
    playerResult.PlayerLossTimes = 0;
    playerResult.PlayerWinTimes = 0;

    gameFlow(playerResult);
}

int main() {    
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}