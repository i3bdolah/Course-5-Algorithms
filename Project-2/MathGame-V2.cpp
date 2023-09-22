#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum enOperationType { Add = 1, Subtract, Multiply, Division, MixType };
enum enDifficultyLevel { Easy = 1, Medium, Hard, Extreme, MixDiff };

struct stQuestionInQuiz
{
    int num1 = 0;
    int num2 = 0;
    enOperationType opType;
    enDifficultyLevel difLevel;
    int correctAnswer = 0;
    int userAnswer = 0;
    bool answerResult = false;
};

struct stQuiz
{
    stQuestionInQuiz questionList[100];
    short numOfQuestions;
    enOperationType opType;
    enDifficultyLevel difLevel;
    short numOfCorrectAnswers = 0;
    short numOfWrongAnswers = 0;
    bool isPass = false;
};

short readNumOfQuestions() {
    short num = 0;
    do
    {
        cout << "Enter The number of questions : ";
        cin >> num;
    } while (num < 1 && num > 100);
    return num;
}

int readUserAnswer() {
    int num = 0;
    cin >> num;
    return num;
}

enDifficultyLevel readDifLevel() {
    short num = 0;
    do
    {
        cout << "Enter The difficulty level \n[1 - Easy \n 2 - Medium \n 3 - Hard \n 4 - Extreme \n 5 - Mix] : ";
        cin >> num;
    } while (num < 1 && num > 5);
    return (enDifficultyLevel)num;
}

enOperationType readOpType() {
    short num = 0;
    do
    {
        cout << "Enter The operation type \n[1 - Add \n 2 - Subtrcat \n 3 - Multiply \n 4 - Division \n 5 - Mix] : ";
        cin >> num;
    } while (num < 1 && num > 5);
    return (enOperationType)num;
}

int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

int simpleCalculator(int num1, int num2, enOperationType opType) {
    switch (opType) {
    case enOperationType::Add:
        return num1 + num2;
    case enOperationType::Subtract:
        return num1 - num2;
    case enOperationType::Multiply:
        return num1 * num2;
    case enOperationType::Division:
        return num1 / num2;
    default:
        return num1 + num2;
    }
}

stQuestionInQuiz generateQuestion(enDifficultyLevel difLevel, enOperationType opType) {
    stQuestionInQuiz questionInQuiz;

    if (opType == enOperationType::MixType)
    {
        opType = (enOperationType)generateRandomNumber(1, 4);
    }

    if (difLevel == enDifficultyLevel::MixDiff)
    {
        difLevel = (enDifficultyLevel)generateRandomNumber(1, 4);
    }

    questionInQuiz.opType = opType;
    questionInQuiz.difLevel = difLevel;

    // Logic
    switch (difLevel)
    {
    case enDifficultyLevel::Easy:
        questionInQuiz.num1 = generateRandomNumber(1, 50);
        questionInQuiz.num2 = generateRandomNumber(1, 50);
        questionInQuiz.correctAnswer = simpleCalculator(questionInQuiz.num1, questionInQuiz.num2, questionInQuiz.opType);
        return questionInQuiz;

    case enDifficultyLevel::Medium:
        questionInQuiz.num1 = generateRandomNumber(50, 100);
        questionInQuiz.num2 = generateRandomNumber(50, 100);
        questionInQuiz.correctAnswer = simpleCalculator(questionInQuiz.num1, questionInQuiz.num2, questionInQuiz.opType);
        return questionInQuiz;

    case enDifficultyLevel::Hard:
        questionInQuiz.num1 = generateRandomNumber(100, 300);
        questionInQuiz.num2 = generateRandomNumber(100, 300);
        questionInQuiz.correctAnswer = simpleCalculator(questionInQuiz.num1, questionInQuiz.num2, questionInQuiz.opType);
        return questionInQuiz;

    case enDifficultyLevel::Extreme:
        questionInQuiz.num1 = generateRandomNumber(300, 500);
        questionInQuiz.num2 = generateRandomNumber(300, 500);
        questionInQuiz.correctAnswer = simpleCalculator(questionInQuiz.num1, questionInQuiz.num2, questionInQuiz.opType);
        return questionInQuiz;
    }
    return questionInQuiz;
}

void generateQuizQuestions(stQuiz& quiz) {
    for (int i = 0; i < quiz.numOfQuestions; i++)
    {
        quiz.questionList[i] = generateQuestion(quiz.difLevel, quiz.opType);
    }

}

string getOperationTypeString(enOperationType opType) {
    string arr[5] = { "+", "-", "*", "/", "Mix" };

    switch (opType)
    {
    case enOperationType::Add:
        return arr[0];
    case enOperationType::Subtract:
        return arr[1];
    case enOperationType::Multiply:
        return arr[2];
    case enOperationType::Division:
        return arr[3];
    default:
        return arr[4];
    }
}

string getDifficultyLevelString(enDifficultyLevel difLevel) {
    string arr[5] = { "Easy", "Medium", "Hard", "Extreme", "Mix" };

    switch (difLevel)
    {
    case enDifficultyLevel::Easy:
        return arr[0];
    case enDifficultyLevel::Medium:
        return arr[1];
    case enDifficultyLevel::Hard:
        return arr[2];
    case enDifficultyLevel::Extreme:
        return arr[3];
    default:
        return arr[4];
    }
}

void printTheQuestion(stQuiz quiz, short i) {
    cout << "______[Question number: " << i + 1 << " - ";
    cout << getDifficultyLevelString(quiz.questionList[i].difLevel) << " Question]______\n";

    cout << quiz.questionList[i].num1 << endl;
    cout << quiz.questionList[i].num2 << "  " << getOperationTypeString(quiz.questionList[i].opType) << endl;
    cout << "----------------------\n";
}

void correctAnswerScreen() {
    system("color 2F"); // turn screen to Green
}

void wrongAnswerScreen() {
    system("color 4F"); // turn screen to Red
}

void correctUserAnswer(stQuiz& quiz, short i) {
    if (quiz.questionList[i].userAnswer != quiz.questionList[i].correctAnswer) {
        quiz.numOfWrongAnswers++;
        quiz.questionList[i].answerResult = false;

        cout << "\nWrong Answer :-(\n";
        cout << "The Right Answer is : " << quiz.questionList[i].correctAnswer << "\n\n";
        wrongAnswerScreen();
    }
    else {
        quiz.numOfCorrectAnswers++;
        quiz.questionList[i].answerResult = true;

        correctAnswerScreen();
        cout << "Right Answer :-)\n\n";
    }
}

void askUserThenCheckAnswer(stQuiz& quiz) {
    for (int i = 0; i < quiz.numOfQuestions; i++)
    {

        printTheQuestion(quiz, i);

        quiz.questionList[i].userAnswer = readUserAnswer();

        correctUserAnswer(quiz, i);
    }

    quiz.isPass = (quiz.numOfCorrectAnswers > quiz.numOfWrongAnswers);
}

string isPassString(bool isPass) {
    if (isPass) {
        correctAnswerScreen();
        return "Pass";
    }
    else {
        wrongAnswerScreen();
        return "Fail";
    }
}

void printQuizResult(stQuiz quiz) {
    cout << "\n";
    cout << "____________________________________________________________" << endl;
    cout << "Final Result is : " << isPassString(quiz.isPass) << endl;
    cout << "____________________________________________________________" << endl;
    cout << "Number Of Questions Asked  : " << quiz.numOfQuestions << endl;
    cout << "Difficulty Level           : " << getDifficultyLevelString(quiz.difLevel) << endl;
    cout << "Operation Type             : " << getOperationTypeString(quiz.opType) << endl;
    cout << "Number Of Right Questions  : " << quiz.numOfCorrectAnswers << endl;
    cout << "Number Of Wrong Questions  : " << quiz.numOfWrongAnswers << endl;
    cout << "____________________________________________________________" << endl;
    cout << "\n\n";
}

void playMathGame() {
    stQuiz quiz;

    quiz.numOfQuestions = readNumOfQuestions();
    quiz.difLevel = readDifLevel();
    quiz.opType = readOpType();

    generateQuizQuestions(quiz);
    askUserThenCheckAnswer(quiz);
    printQuizResult(quiz);
}

void resetScreen() {
    system("cls");
    system("color 0F");
}

void startGame() {
    char playAgain = 'y';

    do
    {

        resetScreen();
        playMathGame();

        cout << "Do you want to continue playing [Y/N] : ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

}

int main() {
    srand((unsigned)time(NULL));

    startGame();

    return 0;
}