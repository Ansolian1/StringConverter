#include <iostream>
#include <string>
#include <algorithm>

std::string toLowerCase(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return word;
}

std::string convertWord(std::string word)
{
    word = toLowerCase(word);
    std::string convertedWord = "";

    for (size_t i = 0; i < word.size(); i++)
    {
        if (word.find_last_of(word[i]) == word.find_first_of(word[i])) {
            convertedWord.append(1, '(');
        }
        else {
            convertedWord.append(1, ')');
        }
    }
    return convertedWord;
}

int main()
{
    std::string word = "";
    while (true) 
    {
        std::cout << "Enter a word (-1 to exit):" << "\n";
        std::getline(std::cin, word);
        if (word == "-1") 
        {
            break;
        }

        std::cout << convertWord(word) << "\n";
    }
}