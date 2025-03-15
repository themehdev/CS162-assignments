#include "iostream"
#include "cstring"
using namespace std;

void removeVowels(char *name, char *ret){
    for(int i = 0; i < strlen(name); i ++){
        char lett = name[i];
        switch(lett){
            case 'a': 
            case 'A': 
            case 'e': 
            case 'E': 
            case 'i': 
            case 'I': 
            case 'o': 
            case 'O': 
            case 'u': 
            case 'U':
                break;
            default: 
                ret[strlen(ret)] = lett;
                //cout << ret[strlen(ret)];
                break;
        }
    }
    ret[strlen(ret)] = '\0';
}

void removeVowels(string guessed, string &ret){
    const string vowels = "aAeEiIoOuU";
    for(int i = guessed.size() - 1; i >= 0; i --){
        for(int j = 0; j < vowels.size(); j ++){
            if(guessed[i] == vowels[j]){
                guessed.erase(i, 1);
                break;
            }
        }
    }
    ret = guessed;
}

void cStringDemo(){
    char name[] = "Michael Candrian";
    char guessed[255];

    cout << "Guess my name (first last): ";
    cin.get(guessed, 255);

    cout << "\n";

    if(strcmp(guessed, name) == 0) {
        cout << "Nice, you got it! \nwait why do you know my name\nhave you been spying on me??" << endl;
    }else{
        cout << "womp womp (incorrect)" << endl;
    }

    cout << "\n";

    cout << "You guessed " << guessed << endl;

    char WOVowels[255];

    removeVowels(guessed, WOVowels);
    
    cout << "Without vowels, thats " << WOVowels << endl;

    cout << "\n";

    strcat(guessed, " the Barbarian");

    cout << "And in less civilized times, it would be " << guessed;

    cout << "\n";
}

void stringTypeDemo(){
    string name = "Michael Candrian";
    string guessed;
    string guessed1, guessed2;

    cout << "Guess my name (first last): ";
    cin >> guessed1 >> guessed2;
    guessed = guessed1 + " " + guessed2;

    cout << "\n";

    if(guessed == name) {
        cout << "Nice, you got it! \nwait why do you know my name\nhave you been spying on me??" << endl;
    }else{
        cout << "womp womp (incorrect)" << endl;
    }

    cout << "\n";

    cout << "You guessed " << guessed << endl;

    string WOVowels = ""; 
    removeVowels(guessed, WOVowels);

    cout << "Without vowels, thats " << WOVowels << endl;

    cout << "\n";

    guessed.append(" the Barbarian");

    cout << "And in less civilized times, it would be " << guessed;

    cout << "\n\n";
}



int main() {
    cStringDemo();
    stringTypeDemo();
    return 0;
}