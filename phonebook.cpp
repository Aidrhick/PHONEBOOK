#include <iostream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <unistd.h>
#include <vector>

using namespace std;

bool isChecking;
bool isDigitOnly;

bool isValid;
bool userFound;


vector<string> contactName = {"EMERGENCY HOTLINE","RED CROSS","PNP","NDRRMC","BFP","PHIVOLCS","DSWD","PAGASA","DOH","MMDA"};
vector<string> contactNumber = {"911","143","117","8911-1406","3410-6319","8929-8958","8511-1259","8927-1541","8711-1001","136"};



void InputBuffer() {
    cin.clear();
    cin.ignore(100, '\n');
}

void ClearLine(int time) {
    usleep(time);
    cout << "\033[2K\033[1A";
    cout << "\033[2K\r";
}

void ClearScreen() {
    system("cls");
}

void dividerBg(){
    cout << "\n\n\033[103m\t                                                                                                        \033[0m\n\n";
}

void DisplayTitleScreen() {
    isValid = true;

    cout << "\n\n\n\n\n\n\033[5m";
    cout << "\033[34m";

    cout <<      "\t\t\t _____                                                                _____ \n"
                 "\t\t\t( ___ )                                                              ( ___ )\n"
                 "\t\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n"
                 "\t\t\t |   |  _____  _    _  ____  _   _ ______   ____   ____   ____  _  __ |   | \n"
                 "\t\t\t |   | |  __ \\| |  | |/ __ \\| \\ | |  ____| |  _ \\ / __ \\ / __ \\| |/ / |   | \n"
                 "\t\t\t |   | | |__) | |__| | |  | |  \\| | |__    | |_) | |  | | |  | | ' /  |   | \n"
                 "\t\t\t |   | |  ___/|  __  | |  | | . ` |  __|   |  _ <| |  | | |  | |  <   |   | \n"
                 "\t\t\t |   | | |    | |  | | |__| | |\\  | |____  | |_) | |__| | |__| | . \\  |   | \n"
                 "\t\t\t |   | |_|    |_|  |_|\\____/|_| \\_|______| |____/ \\____/ \\____/|_|\\_\\ |   | \n"
                 "\t\t\t |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| \n"
                 "\t\t\t(_____)                                                              (_____)\n";

                  cout << "\033[0m";

                  cout << "\033[3m\n\n\n\t\t\t\t\t\tPress\033[0m" << "\033[92m ENTER \033[0m" << "\033[3mto proceed...";
                            while(getchar() != '\n');
                            ClearScreen();




}



void MenuScreen() {
    int choice;

    isValid = true;

    while (isValid) {

    cout << "\n\n\033[103m\t                                                                                                        \033[0m\n";
    cout <<
    "\033[92m\t\t\t\t__, _,____,_,  _,_,  ,_                                                              \n"
            "\t\t\t\t(-|\\/|(-|_,(-|\\ |(-|  |                                                             \n"
            "\t\t\t\t _| _|,_|__,_| \\|,_|__|                                                             \n"
            "\t\t\t\t(     (    (     (      \033[0m\n\n";


    cout <<
    "\t\t\t\033[36m ___,.   ____,____,____,  ____,____, _,  _,____,____,____,____,____,                \n"
    "\t\t\t(-/|    (-/_|(-|  (-|  \\ (-/  (-/  \\(-|\\ |(-|  (-/_|(-/  (-|  (-(__                 \n"
    "\t\t\t '_|,   _/  |,_|__/_|__/  _\\__,_\\__/,_| \\|,_|, _/  |,_\\__,_|,  ____)                \n"
    "\t\t\t (     (     (    (      (    (     (     (   (     (    (    (                     \033[0m\n\n"


    "\t\t\t\033[36m __,.  ____,____, ____,____, ____,__, _,  ____,____, _,  _,____,____,____,____,____,\n"
    "\t\t\t(- )  (-(__(-|_, (-/_|(-|__)(-/  (-|__|  (-/  (-/  \\(-|\\ |(-|  (-/_|(-/  (-|  (-(__ \n"
    "\t\t\t ,'_,  ____)_|__,_/  |,_|  \\,_\\__,_|  |,  _\\__,_\\__/,_| \\|,_|, _/  |,_\\__,_|,  ____) \n"
    "\t\t\t(     (    (    (     (     (    (       (    (     (     (   (     (    (    (     \033[0m\n\n"


    "\t\t\t\033[36m __,.  ____,__, _,____, _   _,  ____,____, _,  _,____,____,____,____,____,          \n"
    "\t\t\t(-_)  (-(__(-|__|(-/  \\(-|  |  (-/  (-/  \\(-|\\ |(-|  (-/_|(-/  (-|  (-(__           \n"
    "\t\t\t __)   ____)_|  |,_\\__/,_|/\\|,  _\\__,_\\__/,_| \\|,_|, _/  |,_\\__,_|,  ____)          \n"
    "\t\t\t(     (    (     (     (       (    (     (     (   (     (    (    (               \033[0m\n\n"


    "\t\t\t\033[36m ____,.  ____,_, _,__, ____,                                                       \n"
    "\t\t\t(-/_|_, (-|_,(-\\_/(-| (-|                                                          \n"
    "\t\t\t   _|,   _|__,_/ \\,_|_,_|,                                                         \n"
    "\t\t\t  (     (    (    (   (                                                            \033[0m\n\n\n";


    cout << "\033[103m\t                                                                                                        \033[0m\n\n";


        cout << "\033[96m\t\t\t\t\t\tEnter your choice\033[0m: ";
        cin >> choice;



        if (cin.fail()) {
            InputBuffer();
            cout << "\033[91m\t\t\t\t\t\tInvalid input!\033[0m";
            ClearLine(1000 * 1000);
            ClearScreen();
        } else if (choice < 1 || choice > 4) {
            InputBuffer();
            cout << "\033[91m\t\t\t\t\t\tInvalid input!\033[0m";
            ClearLine(1000 * 1000);
            ClearScreen();
        } else {
            InputBuffer();
            ClearLine(1);
            cout << "\033[96m\t\t\t\t\t\tEnter your choice\033[0m: " << choice;
            usleep(1000*1000);


            switch (choice) {
                case 1: {
                    ClearScreen();
                    if (contactName.size() == 15 || contactNumber.size() == 15){
                    cout << "\n\n\n\033[103m\t                                                                                                        \033[0m\n\n\n";
                    cout << "\033[91m\t\t\t\t\t\tContact is Full\033[0m";
                    cout << "\n\n\n\033[103m\t                                                                                                        \033[0m\n\n\n";
                    ClearLine(1000 * 1000);
                    ClearScreen();
                    break;
                    }

                    string inputName;
                    string inputNumber;


                        cout << "\n\n\n\033[103m\t                                                                                                        \033[0m\n\n";
                        cout << "\033[91m\t\t\t\t\t\t...New Contact...\033[0m";
                        cout << "\n\n\033[103m\t                                                                                                        \033[0m\n\n";

                        isChecking = true;

                        while (isChecking){

                            cout << "\033[3m\t\t\t\t\t\tEnter contact name\e[0m: ";
                            getline(cin,inputName);
                            cout << "\n\033[103m\t                                                                                                        \033[0m\n\n";

                            if (inputName.empty()){
                                cout << "\t\t\t\t\t\tPlease enter something";
                                ClearLine(400000);
                                ClearLine(0);
                                ClearLine(0);
                                ClearLine(0);
                            }else {
                                isChecking = false;
                            }
                        }



//                        isAlphaOnly = true;
                        for (char& x : inputName) {
                            x = toupper(x);
//                            if (!isalpha(x)) {
//                                isAlphaOnly = false;
//                                break;
//                            }
                        }
//
//                        if (!isAlphaOnly) {
//                            cout << "Invalid Input!";
//                            ClearLine(1000 * 1000);
//                        } else {
//                            isChecking = false;
//                        }


                    isChecking = true;

                    while (isChecking) {

//                        isChecking2 = true;
//
//                        while (isChecking2){

                            cout << "\t\t\t\t\t\tEnter contact number:(+63) ";
                            getline(cin, inputNumber);


                        //}

                        isDigitOnly = true;
                        for (auto& y : inputNumber) {
                            if (!isdigit(y)) {
                                isDigitOnly = false;
                                break;
                            }
                        }

                            if (inputNumber.empty()){

                                    cout << "\t\t\t\t\t\tPlease enter something";
                                    ClearLine(400000);

                                }

                        else if (!isDigitOnly) {
                            cout << "\t\t\t\t\t\tInvalid Input!";
                            ClearLine(1000 * 1000);
                        } else if (inputNumber.length() != 10) {
                            cout << "\t\t\t\t\t\tInvalid Input!";
                            ClearLine(1000 * 1000);
                        } else {
                            if (inputNumber[0] != '9') {
                                cout << "\t\t\t\t\t\tInvalid Input!";
                                ClearLine(1000 * 1000);
                            } else {
                                isChecking = false;
                            }
                        }
                    } // while loop

                    contactName.push_back(inputName);
                    contactNumber.push_back(inputNumber);
                    cout << "\n\n\033[103m\t                                                                                                        \033[0m\n\n";
                    cout << "\033[93m\t\t\t\t\t\tSuccessfully Added to Contacts!\033[0m";
                    ClearLine(1000 * 1000);
                    ClearLine(10);
                    ClearLine(10);
                        ClearScreen();
                    break;
                }

                case 2: {
                    ClearScreen();
                    userFound = false;
                    string findUser;

                    dividerBg();


                    while (1){
                        cout << "\033[3m\033[94m\t\t\t\t\t\tSearch contact\033[0m\e[0m: ";
                        getline(cin, findUser);

                        if (findUser.empty()){
                                    cout << "\t\t\t\t\t\tPlease enter something";
                                    ClearLine(400000);
                                } else {
                                    break;
                                }
                    }



                    cout << "\n\033[103m\t                                                                                                        \033[0m\n\n";
                    for (auto& x : findUser) {
                        x = toupper(x);
                    }

                    for (int i = 0; i < contactName.size(); i++) {
                        if (findUser == contactName[i]) {
                            userFound = true;
                            ClearScreen();

                            if (findUser == "EMERGENCY HOTLINE" || findUser == "RED CROSS" || findUser == "PNP" || findUser == "NDRRMC" || findUser == "BFP" || findUser == "PHIVOLCS" || findUser == "DSWD" || findUser == "PAGASA" || findUser == "DOH" || findUser == "MMDA"){
                                cout << "\n\n\n";
                                dividerBg();
                                cout << "\033[92m\t\t\t\t\t\tContact Found\n\033[0m";
                                cout << "\t\t\t\t\t\tName: " << contactName[i] << endl;
                                cout << "\t\t\t\t\t\tNumber: " << contactNumber[i] << endl;
                                cout << "\t\t\t\t\t\t(1) Update Contact\n\t\t\t\t\t\t(2) Delete Contact\n\t\t\t\t\t\t(3) Exit\n";
                                dividerBg();//break;
                            } else {
                                cout << "\n\n\n";
                                dividerBg();
                                cout << "\033[92m\t\t\t\t\t\tContact Found\n\033[0m";
                                cout << "\t\t\t\t\t\tName: " << contactName[i] << endl;
                                cout << "\t\t\t\t\t\tNumber: \033[94m(+63) \033[0m" << contactNumber[i] << endl;
                                cout << "\t\t\t\t\t\t(1)" << "\033[92m Update\033[0m" << " Contact\n";
                                cout << "\t\t\t\t\t\t(2)" << "\033[91m Delete\033[0m"<< " Contact\n";
                                cout << "\t\t\t\t\t\t(3) Exit\n";
                                dividerBg();
                            }


                            isChecking = true;

                            while (isChecking){

                            cout << "\t\t\t\t\t\tEnter your choice: ";
                            int subChoice;
                            cin >> subChoice;
                            InputBuffer();
                            dividerBg();

                            if (findUser == "EMERGENCY HOTLINE" || findUser == "RED CROSS" || findUser == "PNP" || findUser == "NDRRMC" || findUser == "BFP" || findUser == "PHIVOLCS" || findUser == "DSWD" || findUser == "PAGASA" || findUser == "DOH" || findUser == "MMDA"){
                                    if (subChoice == 1){
                                        cout << "\033[91m\t\t\t\t\t\tYou are unable to edit this contact\n\033[0m";
                                        ClearLine(1000*1000);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                    } else if (subChoice == 2){
                                        cout << "\033[91m\t\t\t\t\t\tYou are unable to edit this contact\n\033[0m";
                                        ClearLine(1000*1000);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                    } else {
                                        ClearScreen();
                                        break;
                                    }


                            } else{

                                    if (subChoice == 1) {
                                    ClearLine(1000*1000);
                                    ClearLine(10);
                                    ClearLine(10);
                                    ClearLine(10);
                                    ClearLine(10);

                                    cout << "\t\t\t\t\t\tEnter your choice: " << subChoice;

                                        string newName, newNumber;
                                        dividerBg();
                                        cout << "\033[3m\t\t\t\t\t\tEnter new contact name\033[3m: ";
                                        cin >> newName;
                                        dividerBg();
                                        for (auto& x : newName) {
                                            x = toupper(x);

                                        }

                                        isChecking = true;

                                        while (isChecking){
                                        cout << "\033[3m\t\t\t\t\t\tEnter new contact number\033[3m: (+63) ";
                                        cin >> newNumber;

                                                isDigitOnly = true;
                                                    for (auto& y : newNumber) {
                                                        if (!isdigit(y)) {
                                                            isDigitOnly = false;
                                                            break;
                                                        }
                                                    }

                                                    if (!isDigitOnly) {
                                                        cout << "\t\t\t\t\t\tInvalid Input!";
                                                        ClearLine(1000 * 1000);
                                                    } else if (newNumber.length() != 10) {
                                                        cout << "\t\t\t\t\t\tInvalid Input!";
                                                        ClearLine(1000 * 1000);
                                                    } else {
                                                        if (newNumber[0] != '9') {
                                                            cout << "\t\t\t\t\t\tInvalid Input!";
                                                            ClearLine(1000 * 1000);
                                                        } else {
                                                            isChecking = false;
                                                        }
                                                    }
                                        }

                                        dividerBg();
                                        contactName[i] = newName;
                                        contactNumber[i] = newNumber;

                                        cout << "\033[93m\t\t\t\t\t\tContact updated successfully!\n\033[0m";

                                        ClearLine(1000 * 1000);
                                        ClearScreen();
                                        break;
                                    } else if (subChoice == 2) {
                                        ClearLine(1000*1000);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                        cout << "\t\t\t\t\t\tEnter your choice: " << subChoice << endl;
                                        dividerBg();
                                        contactName.erase(contactName.begin() + i);
                                        contactNumber.erase(contactNumber.begin() + i);

                                        cout << "\033[91m\t\t\t\t\t\tContact deleted successfully!\033[0m";
                                       dividerBg();
                                        _sleep(1000);
                                        ClearScreen();
                                        break;
                                     } else if (subChoice == 3){
                                        ClearScreen();
                                        break;
                                    } else {
                                        cout << "\033[91m\t\t\t\t\t\tInvalid choice!\033[0m";
                                        ClearLine(1000*1000);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                        ClearLine(10);
                                    }
                                }

                            } // loop for enter choice

//                            break;
                        } // if use found
                    } // for loop

                    if (!userFound) {
                        cout << "\033[3m\033[91m\t\t\t\t\t\tUser Not Found!\033[0m\e[0m" << endl;
                        ClearLine(1000 * 1000);
                        ClearLine(10);
                        ClearLine(10);
                        ClearLine(10);
                        ClearLine(10);
                        ClearLine(10);
                        ClearLine(10);
                    }
                    break;
                }

                case 3: {
                        ClearScreen();
                        int counter = 0;
                            dividerBg();
                            cout << "\033[94m\t\t\t\t\t\t\tAll Contacts\n\033[0m";
                            cout << "\t\t\t\t\t" << left << setw (25) << "\033[95mName\033[0m" << "\t\033[95m Number\033[0m" << endl;


                            for (int i = 0; i < contactName.size(); i++) {
                                if (contactName[i] == "EMERGENCY HOTLINE" || contactName[i] == "RED CROSS" || contactName[i] == "PNP" || contactName[i] == "NDRRMC" || contactName[i] == "BFP" || contactName[i] == "PHIVOLCS" || contactName[i] == "DSWD" || contactName[i] == "PAGASA" || contactName[i] == "DOH" || contactName[i] == "MMDA"){
                                    cout << "\t\t\t\t\t" << left << setw(25) << contactName[i] << contactNumber[i] << endl;
                                }else {
                                    while (counter == 0){

                                    cout << "\033[93m\n\t\t\t\t\t\t\tNew Contacts\n\n\033[0m";
                                    counter = 1;
                                    }
                                    cout  << "\t\t\t\t\t" << left << setw(25) << contactName[i] << "(+63)" << contactNumber[i] << endl;
                                }

                            }
                            dividerBg();
                            cout << "\n\n\t\t\t\t\t\tPress" "\033[92m ENTER\033[0m"<< " to exit.";
                            while(getchar() != '\n');
                            ClearScreen();
                            break;



                    }
                    case 4: {
                        ClearScreen();
                        DisplayTitleScreen();

                    }
                }// switch case choice

            } // correct menu choice (else)
        } // main loop



    } // menu screen function


int main() {
    DisplayTitleScreen();
    MenuScreen();
    return 0;
}

