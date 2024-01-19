#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

class Options {
    private:
        int temp = 0;
        string cursorOptions = ">";
        int cursorPos = 0;
        int returnCode = 0;
        string optionsMenu[4][2] = {{" ", " Red\n"}, 
                                 {" ", " Green\n"}, 
                                 {" ", " Blue\n"},
                                 {" ", " Default\n"}};
        void rtCode(int code) {
            returnCode = code;
        }
    public:
        void setRTCode() {
            returnCode = 0;
        }
        int rtCodeGet() {
            return returnCode;
        }
        void showOptions() {
            system("cls");
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << optionsMenu[i][j];
                }
            }
        }
        void changeCursorPos(char key) {
            switch (key)
            {
            case 72:
                temp = cursorPos;
                cursorPos--;
                if (cursorPos < 0) {
                    cursorPos = 3;
                }
                break;
            case 80:
                temp = cursorPos;
                cursorPos++;
                if (cursorPos >= 4) {
                    cursorPos = 0;
                }
                break;
            case 13:
                if (optionsMenu[cursorPos][1] == " Red\n") {
                    rtCode(4);
                }
                else if (optionsMenu[cursorPos][1] == " Green\n")
                {
                    rtCode(2);
                }
                else if (optionsMenu[cursorPos][1] == " Blue\n")
                {
                    rtCode(1);
                }
                else if (optionsMenu[cursorPos][1] == " Default\n")
                {
                    rtCode(7);
                }
                break;
            default:
                break;
            }
        }
        void changePos() {
            optionsMenu[temp][0] = " ";
            optionsMenu[cursorPos][0] = cursorOptions;
        }
};

class testMenu {
    private:
        int temp = 0;
        string cursorMenu = ">";
        int cursorPos = 0;
        int optCode = 0;
        int exitCode = 0;
        string mainMenu[3][2] = {{" ", " Start\n"}, 
                                 {" ", " Console Options\n"}, 
                                 {" ", " Exit\n"}};
        void sysExit() {
            exitCode = 1;
        }
        void options() {
            optCode = 1;
        }
    public:
        void resetOptCode() {
            this -> optCode = 0;
        }
        int getoptCode() {
            return optCode;
        }
        int getCode() {
            return exitCode;
        }
        void showMenu() {
            system("cls");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << mainMenu[i][j];
                }
            }
        }
        void changeCursorPos(char key) {
            switch (key)
            {
            case 72:
                temp = cursorPos;
                cursorPos--;
                if (cursorPos < 0) {
                    cursorPos = 2;
                }
                break;
            case 80:
                temp = cursorPos;
                cursorPos++;
                if (cursorPos >= 3) {
                    cursorPos = 0;
                }
                break;
            case 13:
                if (mainMenu[cursorPos][1] == " Exit\n") {
                    sysExit();
                }
                else if (mainMenu[cursorPos][1] == " Console Options\n")
                {
                    options();
                }
                break;
            default:
                break;
            }
        }
        void changePos() {
            mainMenu[temp][0] = " ";
            mainMenu[cursorPos][0] = cursorMenu;
        }
};

int main() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &structCursorInfo );

    testMenu root;
    while (true)
    {
        system("cls");
        root.showMenu();
        int key = _getch();
        root.changeCursorPos(key);
        root.changePos();
        if (root.getCode() == 1) {
            break;
        }
        else if (root.getoptCode() == 1)
        {
            Options optMenu;
            while (true)
            {
                system("cls");
                optMenu.showOptions();
                int key_1 = _getch();
                optMenu.changeCursorPos(key_1);
                optMenu.changePos();
                if (optMenu.rtCodeGet() == 4) {
                    SetConsoleTextAttribute(hConsole, 4);
                    root.resetOptCode();
                    break;
                }
                else if (optMenu.rtCodeGet() == 2) {
                    SetConsoleTextAttribute(hConsole, 2);
                    root.resetOptCode();
                    break;
                }
                else if (optMenu.rtCodeGet() == 1) {
                    SetConsoleTextAttribute(hConsole, 1);
                    root.resetOptCode();
                    break;
                }
                else if (optMenu.rtCodeGet() == 7) {
                    SetConsoleTextAttribute(hConsole, 7);
                    root.resetOptCode();
                    break;
                }
            }
        }
    }
    return 0;
}
