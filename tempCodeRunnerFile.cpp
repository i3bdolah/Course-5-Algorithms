#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum enGameChoice { Rock = 1, Paper = 2, Scissor = 3};

struct stGameResult
{
    int numOfRounds;
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

string choiceString(int playerNum) {
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
        playerResult.PlayerDrawTimes = PlayerDrawTimes + 1;
        cout << "The Round result is : Draw\n";
    }
    else if 
    (
    player1 == enGameChoice::Rock && player2 == enGameChoice::Paper || 
    player1 == enGameChoice::Paper && player2 == enGameChoice::Scissor ||
    player1 == enGameChoice::Scissor && player2 == enGameChoice::Rock
    ) {
        playerResult.PlayerLossTimes = PlayerLossTimes + 1;
        cout << "The Round result is : Loosing\n";
    }
    else { 
        playerResult.PlayerWinTimes = PlayerWinTimes + 1;
        cout << "The Round result is : Winning\n";
    }
}

void printRoundDetails(stGameResult& playerResult) {
    int userInput = readPositiveNums("\nYour Choice [ Rock = 1 , Paper = 2 , Scissor = 3 ] : ");
    int computerInput = generateRandomNumber(1,3);

    cout << "___________ROUND NO." << playerResult.numOfRounds << "___________\n";
    cout << "Player Choice: " << choiceString(userInput) << endl;
    cout << "Computer Choice: " << choiceString(computerInput) << endl;
    gameWinningLogic(userInput, computerInput, playerResult);
}


void gameFlow(stGameResult& playerResult) {
    // int roundCount = 1;
    while (playerResult.numOfRounds != 0)
    {
        printRoundDetails(playerResult);
        playerResult.numOfRounds--;
        // roundCount++;
    }
}

void StartGame() {
    stGameResult playerResult;

    // Intialize struct variables:
    playerResult.numOfRounds = 0;
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