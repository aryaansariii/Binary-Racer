#include <iostream>
#include <iomanip>
#include <windows.h>
#include <sstream>

using namespace std;

string toBinary(int i)
{
    if (i < 2)
        return to_string(i);

    int reminder = i % 2;
    int quotient = i / 2;

    return toBinary(quotient) + to_string(reminder);
}

void clickAtPosition(int x, int y)
{
    SetCursorPos(x, y);

    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void clickAtBinaryPosition(string value)
{
    int x[8] = {1547, 1647, 1747, 1847, 1947, 2047, 2147, 2247};
    int y = 1261;

    for (size_t i = 0; i < value.length(); i++)
    {
        if (value[i] == '1')
        {
            clickAtPosition(x[i], 1261);
        }
    }
}

int main()
{
    while (true)
    {
        int command;
        cin >> command;

        if (command == -1)
            break;

        ostringstream output;
        output << setw(8) << setfill('0') << toBinary(command);
        cout << output.str() << '\n';
        clickAtBinaryPosition(output.str());
    }

    return 0;
}