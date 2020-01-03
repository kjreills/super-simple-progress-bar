#include <iostream>
#include <thread>
#include <chrono>
#include "../utils/write_line.h"
#include "../utils/progress_bar.h"
#include "../utils/colors.h"

using namespace std;
using namespace console;

void test(progress_bar progress) 
{
    for (int i = 0; i <= 60; i++)
    {
        progress.update(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
    }
}

int main() {
    write_line("Welcome to the Progress Bar Tester!");

    progress_bar progress;
    colors colors;

    // Default
    write_line("Testing default progress bar...");
    progress.init();
    test(progress);
    write_line();

    // Blue
    write_line("Testing Blue progress bar...");
    progress.init(colors.FgBlue);
    test(progress);
    write_line();

    // Green
    write_line("Testing Green progress bar...");
    progress.init(colors.FgGreen);
    test(progress);
    write_line();

    // Red
    write_line("Testing Red progress bar...");
    progress.init(colors.FgRed);
    test(progress);
    write_line();

    // Magenta
    write_line("Testing Magenta progress bar...");
    progress.init(colors.FgMagenta);
    test(progress);
    write_line();

    write_line();
}
