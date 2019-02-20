#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double rockHistory = 1, paperHistory = 1, scissorHistory = 1, rockChance, paperChance, scissorChance, randomNum;
double randomNumber();
double createRandom();
double verifyAnswer();
int checkAnswer();
double npcChance();
double recordPlayer();
int checkResult();
int checkContinue();
int startGame();
int npc, choice, npcScore = 0, playerScore = 0, endGame = 0, continueGame, maxNumber, i = 0;

int main(){
  printf("\033[1;32m");
  puts("Welcome to Rock-paper-scissor's game");
  startGame();
  return 0;
}

int startGame(){
  paperChance = ( rockHistory / ( rockHistory + paperHistory + scissorHistory ) ) * 100;
  scissorChance = ( paperHistory / ( rockHistory + paperHistory + scissorHistory ) ) * 100;
  rockChance = ( scissorHistory / ( rockHistory + paperHistory + scissorHistory ) ) * 100;
  puts("________________________________________________________________\n");
  printf("\033[1;36m");
  puts("Choose between Rock, Paper, or Scissor:");
  puts(" \033[1;33mType 1 \033[0;0mfor Rock.");
  puts(" \033[1;33mType 2 \033[0;0mfor Paper.");
  puts(" \033[1;33mType 3 \033[0;0mfor Scissor.");
  printf("\033[0;0m");
  printf("\n\033[1;32mYour choice: ");
  scanf("%d", &choice);
  recordPlayer();
  printf("\033[1;0m");
  checkAnswer();
  verifyAnswer();
  puts("\n");
  checkResult();
  printf("\n\n\033[1;36mYour score is %d  \nNPC score is %d\n", playerScore, npcScore);
  checkContinue();
  return 0;
}

double recordPlayer(){
  if(choice == 1) {
    rockHistory++;
  }else if(choice == 2){
    paperHistory++;
  }else if(choice == 3){
    scissorHistory++;
  }
  return 0;
}

int checkAnswer(){
  if(choice == 1){
    puts("\nYou choose Rock.");
  } else if(choice == 2){
    puts("\nYou choose Paper.");
  } else if(choice == 3){
    puts("\nYou choose Scissor.");
  } else{
    puts("\n\033[1;31mPlease choose it correctly.");
    startGame();
  }
  fflush(stdin);
  return 0;
}

double verifyAnswer(){
  double guess = createRandom();
  printf("NPC Choose : ");
  if(guess > scissorChance){
    if(guess > (paperChance + scissorChance) ){
      npc = 1;
      printf("Rock\n");
      printf("Guess : %f while RockChance : %f - %f: ", guess, paperChance + scissorChance, paperChance + scissorChance + rockChance);
    }else{
      npc = 2;
      printf("Paper\n");
      printf("Guess : %f while PaperChance : %f - %f: ", guess, scissorChance, paperChance + scissorChance);
    }
  }else if(guess < scissorChance){
    npc = 3;
    printf("Scissor\n");
    printf("Guess : %f while ScissorChance : %f : %f", guess, scissorChance - scissorChance ,scissorChance);
  }else{
    printf("Error");
  }
  return 0;
}

int checkResult(){
  if(npc == choice){
    printf("\033[1;34m-----------------------It's a tie.-----------------------");
  }else{
    if( (npc == 2 && choice == 1) || (npc == 1 && choice == 3) || (npc == 3 && choice == 2) ){
      puts("\033[1;31m-----------------------NPC won the match.-----------------------");
      npcScore++;
    }else{
      puts("\033[1;34m-----------------------You won the match.-----------------------");
      playerScore++;
    }
  }
  return 0;
}

int checkContinue(){
  npcChance();
  printf("\n\033[1;32mDo you want to continue or not? \n \n\033[1;0mType in 1 to continue, or 0 to end the game: ");
  scanf("%d", &continueGame);
  puts("");
  if(continueGame == 1){
    puts("\033[1;33mYou have continue the game!");
    startGame();
  }else {
    if(continueGame == 0){
      return 0;
    }else{
      checkContinue();
      return 0;
    }
  }
}

double npcChance(){
  paperChance = ( rockHistory / ( rockHistory + paperHistory + scissorHistory ) ) * 100;
  scissorChance = ( paperHistory / ( rockHistory + paperHistory + scissorHistory ) ) * 100;
  rockChance = ( scissorHistory / ( rockHistory + paperHistory + scissorHistory ) ) * 100;
  printf("Random Number is %f ", randomNum);
  printf("Rock = %f", rockChance);
  printf(" and Paper = %f", paperChance);
  printf(" and Scissor = %f", scissorChance);
  return 0.0;
}

double createRandom(){
  srand(time(NULL));
  randomNum = rand() % 100 + 1;
  return randomNum;
}
