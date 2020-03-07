#include <iostream>
#include <ctime>

void PrintIntroduction (){
    // Print starting message to the terminal
    std:: cout << "\n\nHOW DARE YOU INTRUDE IN MY TOMB YOU PESKY ADVENTURER?!? \n";
    std:: cout << "Normaly I would kill you directly because of that but since I am in a good mood, I will give you a chance of survival.. \n";
    std:: cout << "To survive, you have to answer my riddles, each more difficult than the previous one.. \n";
    std:: cout << "If you get all the correct answers, I may let you live, if you don't...you DIE! \n";
    std:: cout << "*Insert sinister music* \n\n";
}

void PreLevelMessage(int CurrRiddle){
    std:: cout << "There are "<< CurrRiddle << " riddles left for you to answer..\n";

}

bool PlayGame (int CurrRiddle){

    PreLevelMessage(CurrRiddle);

    int Difficulty = 6 - CurrRiddle;
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeProduct to the terminal
    std:: cout << std::endl;
    std:: cout << "My hands are showing 3 numbers \n";
    std:: cout << "Once add-up, we get: "<< CodeSum << std::endl;
    std:: cout << "Once multiplied, we get: " << CodeProduct << std::endl;
    std:: cout << "Now tell me.. What are these 3 numbers? \n";

    //Players Guess
    int GuessA, GuessB, GuessC;
    std:: cin >> GuessA;
    std:: cin >> GuessB;
    std:: cin >> GuessC;

    std:: cout << "You've chosen "<< GuessA << GuessB << GuessC <<"? \n";
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;


    //Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
    std:: cout << "What a stupid choice, there is no way that this is ri..Wait..It's correct?! \n";
    std:: cout << "Hmpf! Probably just a lucky guess, but will you be this lucky the next time? I doubt it.. \n";
    std:: cout << "MUHAHAHAHAHAHA \n";
    std:: cout << "*Insert sinister music \n\n";

    return true;
    }
    else {
    std:: cout << "That is correct!..Not! \n";
    std:: cout << "Did you really believe that you had the right answer? \n";
    std:: cout << "How gullible can you be? \n";
    std:: cout << "Oh my god you are so stupid! Watching your stupidity almost made me forget that I wanted to kill you. \n";
    std:: cout << "*A trapdoor opens beneath the Adventurer and he falls to his doom!* \n";

    return false;
    }
}
int main(){

    srand(time(NULL));
    int RiddlesLeft = 5;
    int LastRiddle = 0;
    bool bLevelComplete;
    
    PrintIntroduction ();
    
    while (RiddlesLeft >= LastRiddle)
    {
       bLevelComplete = PlayGame (RiddlesLeft);
       std::cin.clear();
       std::cin.ignore();

       if (bLevelComplete)
       RiddlesLeft--;

       if (!bLevelComplete)
       break;
    }
    
    if(RiddlesLeft == LastRiddle){
    std:: cout << "Oh my.. I didn't expect that you would be able to answer all my riddles correctly.. \n";
    std:: cout << "Your wit has impressed me adventurer, which is why you are allowed to leave now. \n";
    std:: cout << "*A trapdoor opens beneath the Adventurer and he falls to his doom!* \n";
    std:: cout << "*An evil laugh can be heard coming from the surronding walls* \n";
    }
    return 0;
}
