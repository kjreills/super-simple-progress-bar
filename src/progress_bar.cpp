#include "progress_bar.hpp"
#include "colors.hpp"
#include <iostream>

using namespace std;
using namespace console;

colors _colors;

void progress_bar::init()
{
    cout << color;

    for (int i = 0; i < 100; i++)
    {
        cout << incomplete_symbol;
    }

    cout << " 0%";
    cout << _colors.Reset;
    cout << flush;
}

void progress_bar::init(string mainColor) 
{
    color = mainColor;
    init();
}

void progress_bar::update(int percentComplete)
{
    cout << "\x1b[500D"; // move cursor backward by 500 characters
    cout << color;

    for (int i = 0; i < 100; i++)
    {
        if (i < percentComplete)
        {
            cout << complete_symbol;
        }
        else
        {
            cout << incomplete_symbol;
        }
    }

    cout << " " << percentComplete << "%";

    cout << _colors.Reset;
    cout << flush;
}
