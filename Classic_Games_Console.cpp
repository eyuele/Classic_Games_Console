#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

bool RockPaperScissors(){
    system(CLEAR);
    bool running = true;
    int val, cont, user, computer, userc, computerc, round;
    const string name[3] = {"ROCK", "PAPER", "SCISSORS"};
    round = 0;
    userc = 0;
    computerc = 0;
    cout << "ROCK, PAPER, SCISSORS GAME "<< endl;
    cout << "1.ROCK\n" << "2.PAPER\n" << "3.SCISSORS\n" <<endl;
    //Loops untill the one of them wins
    while (userc < 3 && computerc < 3){
        ++round;
        cout << "Round "<< round << endl;

        //user input and valid input verfier
        cout << "Please Enter Your choice(1-3): ";
        cin >> user;
        if (user < 1 || user > 3) {
        cout << "Enter a valid number (1-3)" << endl;
        round--;
        continue;
        }
        cout << "YOU Chose "<<name[user - 1]<<endl;

        //Computer Randomizer
        computer= rand() % 3 + 1;
        cout << "COMPUTER Chose " << name[computer - 1] << endl;
        //checks for round winner
            //checks if the user won the round
        if ((user == 2 && computer == 1) ||
            (user == 3 && computer == 2) ||
            (user == 1 && computer == 3) ){

            cout << "YOU won Round" << round<< endl;
            ++userc;
            //checks if the computer won the round
        }
        else if((computer == 2 && user == 1) ||
                (computer == 3 && user == 2) ||
                (computer == 1 && user == 3) ){

            cout << "COMPUTER won Round" << round<< endl;
            ++computerc;
        }
        else if (user == computer){
            cout <<"draw"<< endl;
        }

        //To unnounce if one of them wins

        if (userc == 3){
            cout << "YOU WON THIS GAME"<< endl;
            break;
        }
        else if (computerc == 3){
            cout << "COMPUTER WON THIS GAME"<< endl;
            break;
        }
        cout << endl;
        }

        //exit or return to main menu
        while(running == true){
        cout << "1 to go back ,  0 to exit : ";
        cin>> val;
        if (val == 1){
            cout <<"going back to main menue..."<<endl;
            break;
            }
        else if (val == 0){

            cout << "type '0' to conform: ";
            cin>> cont;
            if (cont == 0){
                cout << "closing the game"<<endl;
                running = false;
                break;
            }
        }
        }
    return running;

}
bool GuessTheNum(){
    bool running = true;
    int val, cont;
    system(CLEAR);


    int num, randnum, score;
    score = 100;
    randnum = rand() % 100 + 0;

    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<
            "-----------------GUSS THE NUMBER----------------"<< endl<<
            "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    for (int attempt = 10; attempt > 0; attempt--){
        cout << "**********************************************" <<endl;
        if (score > 100){
            score = 100;
        }
        cout << "__________________SCORE: "<< score<<"_________________"<< endl<<
                "=============================================="<<endl;
        cout << "___________YOU HAVE "<<attempt<< " ATTEMPT LEFT___________" <<endl;

        cout << "**********************************************"<<endl;
        cout << "GUESS THE NUMBER: ";
        cin >> num ;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a valid number!" << endl;
            attempt++; // cancel penalty
            continue;
        }

        if (num == randnum){

            cout << "YOU GUSSED THE RIGHT NUMBER"<<endl;
            cout << "====================================="<<endl;
            cout << "------------'''VICTORY!'''-----------"<<endl<<
                    "====================================="<<endl;

            cout << "--------------SCORE: "<< score<<"-------------"<< endl;
            cout << "====================================="<<endl;
            score = score + 8;
            break;
        }
        else if (num > randnum - 5 && num <= randnum - 1 || num >= randnum + 1 && num < randnum + 5){
            cout << "VERY HOT"<< endl;
            score = score + 4;
        }
        else if (num >= randnum - 10 && num <= randnum - 5  || num >= randnum + 5 && num < randnum + 10){
            cout << "HOT"<<endl;
            score = score + 2;
        }
        else if (num < randnum - 10 && num >= randnum - 20 || num > randnum + 10 && num <= randnum + 20){
            cout << "COLD "<<endl;
            score = score -10;
        }
        else if (num < randnum - 20 || num > randnum + 20){
            cout << "VERY COLD"<<endl;
            score = score -15;

        }


        if (score <= 0 || attempt == 0){
            cout << "######################################################"<<endl<<
                    "THE NUMBER WAS: "<<randnum<<endl<<
                    "######################################################"<<endl;
            cout << "====================================="<<endl;
            cout << "--------------GAME OVER!--------------"<<endl<<
                    "====================================="<<endl;
            if (score >= 100){
                score = 20;
            }
            else if (score <= 0){
                score = 0;
            }
            cout << "--------------SCORE: "<< score<<"-------------"<< endl;
            cout << "====================================="<<endl;
            break;
        }
    }



        while(running == true){
        cout << "1 to go back ,  0 to exit : ";
        cin>> val;
        if (val == 1){
            cout <<"going back to main menue..."<<endl;
            break;
            }
        else if (val == 0){

            cout << "type '0' to conform: ";
            cin>> cont;
            if (cont == 0){
                cout << "closing the game"<<endl;
                running = false;
                break;
            }
        }
        }
    return running;
}
int main()
{
    srand(time(0));
    int choice;
    bool running = true;
    while (running){
        system(CLEAR);
        cout<< endl;
        cout << "============== GAMES ============="<< endl;
        cout << "------1. Rock Paper Scissors------"<<endl<<
                "------2. Guess The Number---------"<<endl<<
                "------0. Exit---------------------"<<endl<<
                "=================================="<<endl;
        cout << "choose your prefered game: ";

        cin >> choice;
        if (choice == 1){
            running = RockPaperScissors();
        }
        else if (choice == 2){
            running = GuessTheNum();
        }
        else if (choice == 0){
            running = false;
        }
        else {
            cout << "   ENTER A VALID INPUT"<<endl;
        }
    }
    return 0;
}
