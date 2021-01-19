#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << std::endl;
    std::cout << "Agent 6, we need your hacking skills to break the level " << Difficulty << " security pin \n";
    std::cout << "Enter the pin so we can get through this door \n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 digits in the pin";
    std::cout << "\n+ The digits add up to: " << CodeSum;
    std::cout << "\n+ The digits product is: " << CodeProduct << std::endl;

    // Store player guesses
    int GuessA, GuessB, GuessC;
    std::cout << "\nEnter 3 digits: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Good work Agent 6. Let's move on.\n";
        return true;
    }
    else
    {
        std::cout << "Be careful Agent 6. Try again.\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Create new random sequence based on the time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\nGreat work Agent 6. You gained access and were undetected. Gather the intel and get out of there.\n";

    return 0;
}