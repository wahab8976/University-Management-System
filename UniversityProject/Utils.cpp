#include "Utils.h"



long long Utility::getNumericInput(int length) 
{
    string finalInput = "";
    for (int i = 0; i < length;)
    {
        char input;
        input = _getch();

        if (input == '\b') {
            if (!finalInput.empty()) 
            {
                finalInput.pop_back();
                cout << '\r' << string(length, ' ') << '\r' << finalInput; // Clear the current line and print the updated finalInput
                i--;
            }
        }
        else if (input >= '0' && input <= '9')
        {
            cout << input;
            finalInput.push_back(input);
            i++;
        }
    }
    cout << endl;
    return stoll(finalInput);
}

