#include <iostream>
#include <string>

std::string START = "";

const int MAX_HEIGHT = 23;
const int MAX_LENGTH = 50;

const char move_up    = 'w';
const char move_down  = 's';
const char move_left  = 'a';
const char move_right = 'd';
const char game_exit  = 'e';

// const char move_up_a    = (char) 72;
// const char move_down_a  = (char) 80;
// const char move_left_a  = (char) 75;
// const char move_right_a = (char) 77;

unsigned int GAME_FRAME = 0;

class Snake{
  private:
    int X_POS;
    int Y_POS;
  public:
    Snake(){
      X_POS = 0;
      Y_POS = 0;
    }

    int get_x_pos(){return X_POS;}
    int get_y_pos(){return Y_POS;}

    void move_up(unsigned int Power){
      Y_POS -= Power;
      while (Y_POS < 0) Y_POS += MAX_HEIGHT;
    }
    void move_down(unsigned int Power){
      Y_POS += Power;
      while (Y_POS >= MAX_HEIGHT) Y_POS -= MAX_HEIGHT;
    }
    void move_left(unsigned int Power){
      X_POS = X_POS - Power;
      while (X_POS < 0) X_POS += MAX_LENGTH;
    }
    void move_right(unsigned int Power){
      X_POS = X_POS + Power;
      while (X_POS >= MAX_LENGTH) X_POS -= MAX_LENGTH;
    }
};

void moving_update(char, unsigned int, Snake*);

int main(){

  Snake player;

  while(1){
    std::cout << "Frame: " << GAME_FRAME << ". ";
    std::cout << "x: " << player.get_x_pos() << " y: " << player.get_y_pos() << std::endl;
    for (int Y = 0; Y < MAX_HEIGHT; Y++){
      for (int X = 0; X < MAX_LENGTH; X++){
        if (X == player.get_x_pos() && Y == player.get_y_pos())
          std::cout << "@";
        else std::cout << "-";
      }
      std::cout << std::endl;
    }
    std::cout << "Your move: ";
    std::string userCommand;
    std::cin >> userCommand; 

    char userMove = userCommand[0];
    if (userMove == game_exit) return 0;

    unsigned int userMovePower = 1;
    if (userCommand.length() == 2)
      userMovePower = (unsigned int)userCommand[1];
    
    moving_update(userMove, userMovePower, &player);
    GAME_FRAME++;
  }
  return 0;
}

void moving_update(char cmdMove,
                   unsigned int cmdMovePower,
                   Snake* player){
  switch (cmdMove){
      case move_up: player->move_up(cmdMovePower); break;
      case move_down: player->move_down(cmdMovePower); break;
      case move_left: player->move_left(cmdMovePower); break;
      case move_right: player->move_right(cmdMovePower); break;
      default: break;
  }
}