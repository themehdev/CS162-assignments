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
                cout << ret[strlen(ret)];
                break;
        }
    }
}

string removeVowels(string guessed){
    string substrArr[255];
    const string vowels = "aAeEiIoOuU";
    int first = 0;
    int last = -1;
    while(last != first){
        last = first;
        for(int i = 0; i < size(vowels); i ++){
            int found = guessed.find(vowels.at(i), last);
            if(first == -1 || (found != -1 && found < first)){
                cout << found;
                first = found;
            }
        }
        if(first == -1){ 
            substrArr[0] = guessed;
            break;
        }
        substrArr[sizeof(substrArr) / sizeof(vowels)] = guessed.substr(last, first - last);
    }
    string ret = "";
    for(int i = 0; i < sizeof(substrArr) / sizeof(vowels); i ++){
        ret += substrArr[i];
    }
    return ret;
}

void cStringDemo(){
    char name[] = "Michael Candrian";
    char guessed[255];

    cout << "Guess my name (first last): ";
    cin.get(guessed, 255);

    cout << "\n";

    if(guessed == name) {
        cout << "Nice, you got it! \nwait why do you know my name\nhave you been spying on me??" << endl;
    }else{
        cout << "womp womp (incorrect)" << endl;
    }

    cout << "\n";

    cout << "You guessed " << guessed << endl;

    char WOVowels[255];

    removeVowels(guessed, WOVowels);
    // for(char ch : WOVowels){
    //     cout << ch;
    // }
    
    cout << "Without vowels, thats " << WOVowels << endl;

    cout << "\n";

    strcat(guessed, " the Barbarian");

    cout << "And in less civilized times, it would be " << guessed;

    cout << "\n";
}

void stringTypeDemo(){
    string name = "Michael Candrian";
    string guessed;

    cout << "Guess my name (first last): ";
    cin >> guessed;

    cout << "\n";

    if(guessed == name) {
        cout << "Nice, you got it! \nwait why do you know my name\nhave you been spying on me??" << endl;
    }else{
        cout << "womp womp (incorrect)" << endl;
    }

    cout << "\n";

    cout << "You guessed " << guessed << endl;

    string WOVowels = removeVowels(guessed);

    cout << "Without vowels, thats " << WOVowels << endl;

    cout << "\n";

    guessed += " the Barbarian";

    cout << "And in less civilized times, it would be " << guessed;

    cout << "\n\n";
}



int main() {
    //cStringDemo();
    stringTypeDemo();
    return 0;
}