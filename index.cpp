#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#define MIN_SCORE 0

enum Difficulty { easy, medium, Hard };
struct Quiz {
    Difficulty difficulty;
    string content;
};

class Player
{
    int score;
    string name;
    string input;
public:
    Player(string x, int y) {
      name = x;
      score = y;
    }
    string get_name();
    int get_score();
    string get_input();
    void set_name(string x);
    void set_score(int x);
    void set_input(string x);
    
};

void Player::set_name(string x) {
    name = x;
}
void Player::set_score(int x) {
    score = x;
}
string Player::get_name() {
    return name;
}
int Player::get_score() {
    return score;
}
void Player::set_input(string x) {
    input = x;
}
string Player::get_input() {
    return input;
}

int main()
{
    cout << "\x1b[42m\tWELCOME TO MPDD TYPING GAME\t\x1b[0m" << endl;
    cout << "Please enter player 1 name" << endl;
    string p1_name,p2_name;
    getline(cin >> ws, p1_name);
    cout << "Please enter player 2 name" << endl;
    getline(cin >>ws, p2_name);
    Player player_1(p1_name, MIN_SCORE);
    Player player_2(p2_name, MIN_SCORE);
    cout<< "Player 1 is:" << "\x1b[42m\t" << player_1.get_name() << "\x1b[0m" << endl;
    cout<< "Player 2 is:" << "\x1b[42m\t" << player_2.get_name() << "\x1b[0m" << endl;
    Quiz quiz;
    time_t start_time, end_time;
    quiz.difficulty = easy;
    quiz.content = "This is an awesome project. I should get 10 for it!";
    string p1_input, p2_input;
    cout << "Type the following correct and fast to win: " << endl;
    cout << quiz.content << endl;
    cout << "\x1b[42m Player 1 turn \x1b[0m" << endl;
    start_time = time (NULL);
    getline(cin >> ws, p1_input);
    end_time = time (NULL);
    player_1.set_input(p1_input);
    player_1.set_score(end_time - start_time);
    cout << "\x1b[42m Player 2 turn \x1b[0m" << endl;
    start_time = time (NULL);
    getline(cin >> ws, p2_input);
    end_time = time (NULL);
    player_2.set_input(p2_input);
    player_2.set_score(end_time - start_time);
    cout << "player 1 took " << player_1.get_score() << " seconds" << endl;
    cout << "player 2 took " << player_2.get_score() << " seconds" << endl;
    bool game_integrity = true;
    if(strcmp(quiz.content.c_str(), player_1.get_input().c_str()) != 0) {
        cout << "Player 1 put wrong input" << endl;
        game_integrity = false;
    }
    if(strcmp(quiz.content.c_str(), player_2.get_input().c_str()) != 0) {
        cout << "Player 2 put wrong input" << endl;
        game_integrity = false;
    }
    if(game_integrity) {
        if(player_1.get_score() < player_2.get_score()) {
            cout << player_1.get_name() << " wins!" << endl;
        } else if (player_1.get_score() > player_2.get_score()) {
            cout << player_2.get_name() << " wins!" << endl;
        } else {
            cout << "Draw!" << endl;
        }
    } else {
        cout << "game is not valid!" << endl;
    }
    return 0;
}

