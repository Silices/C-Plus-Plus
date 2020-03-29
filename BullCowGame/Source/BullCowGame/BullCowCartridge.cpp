// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(Words);

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
    // if game is over do ClearScreen() and SetupGame() the game
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else{   // else Checking Player Guess

        ProcessGuess(PlayerInput);  
    }
}
void UBullCowCartridge::SetupGame() {

    HiddenWord = Isograms[FMath::RandRange(0,Isograms.Num()-1)]; 
    Lives = HiddenWord.Len()*2; 
    bGameOver = false;

    //Welcoming the Player
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine(TEXT("You have %i lives to do so."), Lives); 
    PrintLine(TEXT("Type in your guess.\nPress enter to continue..."));

}

void UBullCowCartridge::EndGame(){
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again.."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess){
    
    if (HiddenWord == Guess)
    {
        PrintLine(TEXT("You're right!"));
        EndGame();
        return;
    }
    
    if(Guess.Len() != HiddenWord.Len()) // Checking if Input is right size
    {
        PrintLine(TEXT("Wrong number of letters.\nTry guessing again!"));
        PrintLine(TEXT("The word is %i letters long."), HiddenWord.Len());
        PrintLine(TEXT("You have %i lives remaining."), Lives);
        return;
    }

    if (!IsIsogram(Guess))
    {
        /* code */
        PrintLine(TEXT("No repeating letters, guess again!"));
        return;
    }


    PrintLine(TEXT("Lost a life!"));
    --Lives;

            
    if (Lives <= 0)
    {
        PrintLine(TEXT("You have no lives left."));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }
    
    
    FBullCowCount Count = GetBullsCows(Guess);
    PrintLine(TEXT("You have %i Bulls: %s and %i Cows: %s "), Count.Bulls, *Count.BullsLetters, Count.Cows, *Count.CowsLetters);

    FString Life = TEXT("lives");

    if (Lives == 1)
    Life = TEXT("life");

    PrintLine(TEXT("You only have %i %s left!"), Lives, *Life);

    PrintLine(TEXT("Try guessing again!"));
                
}
        
bool UBullCowCartridge::IsIsogram (const FString& Word) const{

    for (int32 i = 0; i < Word.Len(); i++){
        for (int32 y = i+1; y < Word.Len();y++){
            if (Word[i]==Word[y])
            return false;
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const{
    
    TArray<FString> ValidWords;
    
    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <=8 && IsIsogram(Word))
            ValidWords.Emplace(Word);

    }
    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullsCows(const FString& Guess) const{

    FBullCowCount Count;

    for (int32 i=0; i<Guess.Len(); i++){
        
        if(Guess[i] == HiddenWord[i]){
            Count.Bulls++;
            Count.BullsLetters += Guess[i];
            continue;
        }

        for (int y = 0; y < Guess.Len(); y++){

            if (Guess [i] == HiddenWord[y]){
                Count.Cows++;
                Count.CowsLetters += Guess[i];
                break;
            }
        }
    }
    return Count;
}