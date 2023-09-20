#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum enOperationType { Add = 1, Subtract, Multiply, Division, Mix };
enum enDifficultyLevel { Easy = 1, Medium, Hard, MixDifficulty };

struct stGameRules
{
    int totalQuestions;
    enDifficultyLevel difficultyLevel;
    enOperationType operationType;
};

struct stRoundInfo
{
    int totalQuestions;
    int firstNum;
    int secondNum;
    int playerResult;
    int result;
};

struct stGameSummary
{
    int totalQuestions;
    enDifficultyLevel difficultyLevel;
    enOperationType operationType;
    int correctQuestions;
    int wrongQuestions;
    string passOrFail;
};

int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from; 
}

int readPlayerResultNumber(string msg) {
    int num = 0;
    do
    {
        cout << msg;
        cin >> num;
    } while (num <= 0);
    return num;
}

int getNumberByDifficultyLevel(enDifficultyLevel difficultyLevel) {
    switch (difficultyLevel)
    {
    case enDifficultyLevel::Easy :
        return rand() % (50 - 1 + 1) + 1; 
        break;
    
    case enDifficultyLevel::Medium :
        return rand() % (100 - 50 + 1) + 50; 
        break;

    case enDifficultyLevel::Hard :
        return rand() % (200 - 100 + 1) + 100; 
        break;

    case enDifficultyLevel::MixDifficulty :
        return rand() % (200 - 1 + 1) + 1; 
        break;

    default:
        return rand() % (200 - 1 + 1) + 1; 
        break;
    }

}

int performAddition(int a, int b) {
    return a + b;
}

int performSubtraction(int a, int b) {
    return a - b;
}

int performMultiplication(int a, int b) {
    return a * b;
}

int performDivision(int a, int b) {
    return a / b;
}

int getResultByOperationType(enOperationType operationType, int a, int b) {
    switch (operationType) {
    case enOperationType::Add:
        return performAddition(a, b);
        break;
    case enOperationType::Subtract:
        return performSubtraction(a, b);
        break;
    case enOperationType::Multiply:
        return performMultiplication(a, b);
        break;
    case enOperationType::Division:
        return performDivision(a, b);
        break;
    case enOperationType::Mix:
        return rand() % (200 - 1 + 1) + 1;
        break;
    default:
        return rand() % (200 - 1 + 1) + 1;
        break;
    }
}

void resetScreen() {     
    system("cls");     
    system("color 0F"); 
}

void correctAnswerScreen() {     
    system("color 2F"); // turn screen to Green
}

void wrongAnswerScreen() {
    system("color 4F"); // turn screen to Red
}

enDifficultyLevel getDifficultyLevelFromInput(int input) {
    switch (input) {
        case 1: return enDifficultyLevel::Easy;
        case 2: return enDifficultyLevel::Medium;
        case 3: return enDifficultyLevel::Hard;
        case 4: return enDifficultyLevel::MixDifficulty;
        default: return enDifficultyLevel::Easy; // Default to Easy if input is invalid
    }
}

enOperationType getOperationTypeFromInput(int input) {
    switch (input) {
        case 1: return enOperationType::Add;
        case 2: return enOperationType::Subtract;
        case 3: return enOperationType::Multiply;
        case 4: return enOperationType::Division;
        case 5: return enOperationType::Mix;
        default: return enOperationType::Add; // Default to Add if input is invalid
    }
}

stGameRules rulesQuestions() {
    stGameRules gameRules;
    int operationType, difficultyLevel;

    cout << "Enter The number of questions : ";
    cin >> gameRules.totalQuestions;

    cout << "Enter The difficulty level /[1-Easy, 2-Medium, 3-Hard, 4-Mix] : ";
    cin >> difficultyLevel;
    gameRules.difficultyLevel = getDifficultyLevelFromInput(difficultyLevel);

    cout << "Enter The operation type /[1-Add, 2-Sub, 3-Mul, 4-Div, 5-Mix] : ";
    cin >> operationType;
    gameRules.operationType = getOperationTypeFromInput(operationType);

    return gameRules;
}

string getOperationSignString(enOperationType operationType) {
    string arr[] = {"+", "-", "*", "/"};

    switch (operationType)
    {
    case enOperationType::Add :
        return arr[0];
        break;

    case enOperationType::Subtract :
        return arr[1];
        break;

    case enOperationType::Multiply :
        return arr[2];
        break;

    case enOperationType::Division :
        return arr[3];
        break;

    case enOperationType::Mix :
        return arr[generateRandomNumber(0,3)];
        break;
    
    default:
        return arr[generateRandomNumber(0,3)];
        break;
    }

}

string getOperationTypeString(enOperationType operationType) {
    string arr[5] = {"Add", "Subtract", "Multiply", "Division", "Mix"};
    return arr[operationType - 1];
}


string getDifficultyLevelString(enDifficultyLevel difficultyLevel) {
    string arr[4] = {"Easy", "Medium", "Hard", "Mix"};
    return arr[difficultyLevel - 1];
}

void correctAnswerMsg(int result) {
    cout << "Correct Answer :-)\n";
    cout << "The answer is = \n\n" << result;
    correctAnswerScreen();
}

void wrongAnswerMsg(int result) {
    cout << "Wrong Answer :-)\n";
    cout << "The answer is = \n\n" << result;
    wrongAnswerScreen();
}

string passOrFailToString(int correctQuestions, int wrongQuestions) {
    if (correctQuestions >= wrongQuestions)
    {
        return "Pass";
    }
    else {
        return "Fail";
    }   
}

stGameSummary fillGameSummary(stRoundInfo roundInfo, stGameRules gameRules, int correctQuestionsFromLoop, int wrongQuestionsFromLoop) {
    stGameSummary gameSummary;

    gameSummary.correctQuestions = correctQuestionsFromLoop;
    gameSummary.wrongQuestions = wrongQuestionsFromLoop;
    gameSummary.difficultyLevel = gameRules.difficultyLevel;
    gameSummary.operationType = gameRules.operationType;
    gameSummary.totalQuestions = gameRules.totalQuestions;
    gameSummary.passOrFail = passOrFailToString(correctQuestionsFromLoop, wrongQuestionsFromLoop);

    return gameSummary;
}

stGameSummary playGame(stGameRules gameRules) {
    stRoundInfo roundInfo;
    int correctQuestions = 0, wrongQuestions = 0;

    roundInfo.totalQuestions = gameRules.totalQuestions;

    for (int i = 1; i <= roundInfo.totalQuestions ; i++)
    {
        roundInfo.firstNum = getNumberByDifficultyLevel(gameRules.difficultyLevel);
        roundInfo.secondNum = getNumberByDifficultyLevel(gameRules.difficultyLevel);
        // Calculating Result
        roundInfo.result = getResultByOperationType(gameRules.operationType, roundInfo.firstNum, roundInfo.secondNum);
        
        cout << roundInfo.firstNum << endl;
        cout << roundInfo.secondNum << "    " << getOperationSignString(gameRules.operationType) << endl;
        cin >> roundInfo.playerResult;

        if (roundInfo.result == roundInfo.playerResult) {
            correctAnswerMsg(roundInfo.result);
            correctQuestions++;
        }
        else {
            wrongAnswerMsg(roundInfo.result);
            wrongQuestions++;
        }
        
    }
    return fillGameSummary(roundInfo, gameRules, correctQuestions, wrongQuestions);
}

void printSummary(stGameSummary gameSummary) {
    cout << "\n\n_____________[" << gameSummary.passOrFail << "]_____________\n";
    cout << "Number Of Questions         : " << gameSummary.totalQuestions << endl;
    cout << "Operation Type              : " << getOperationTypeString(gameSummary.operationType) << endl;
    cout << "Difficulty Level            : " << getDifficultyLevelString(gameSummary.difficultyLevel) << endl;
    cout << "Number Correct Questions    : " << gameSummary.correctQuestions << endl;
    cout << "Number Wrong Questions      : " << gameSummary.wrongQuestions << endl << endl;
}

void startGame() {
    char playAgain = 'y';

    do
    {
        resetScreen();
        // Logic
        stGameSummary gameSummary = playGame(rulesQuestions());
        printSummary(gameSummary);
        cout << "Do you want to continue playing [Y/N] : ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
}

int main() {    
    srand((unsigned)time(NULL));

    startGame();

    return 0;
}