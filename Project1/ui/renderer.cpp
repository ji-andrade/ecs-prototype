#include "renderer.h"

//test 

void mainCurses(World& world)
{
    initscr();        
    noecho();
    keypad(stdscr, TRUE);

    cursesPerson(world);

    endwin();
}

void cursesPerson(World& world)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    int termHeight = getmaxy(stdscr);
    int termWidth = getmaxx(stdscr);

    WINDOW* leftWin = newwin(termHeight, 38, 0, 0);
    box(leftWin, 0, 0);
    WINDOW* rightWin = newwin(termHeight, termWidth - 40, 0, 40);
    box(leftWin, 0, 0);

    keypad(leftWin, TRUE);

    int currentID = 0;
    //temporary
    int maxID = 20;

    while (true)
    {

        wclear(leftWin);
        wclear(rightWin);
        box(leftWin, 0, 0);   
        box(rightWin, 0, 0);

        mvwprintw(leftWin, 0, 0, "Day %d", world.currDay);
        mvwprintw(leftWin, 0, 0, "UP/DOWN to cycle, Q to quit");

        int row = 3;
        for (auto& [id, name] : world.nameMap)
        {
            if (id == currentID)
                mvwprintw(leftWin, row++, 1, "o %s", name.val.c_str());
            else
                mvwprintw(leftWin, row++, 1, "  %s", name.val.c_str());
        }

 
        std::string desc = describePerson(world, currentID);
        std::istringstream stream(desc);
        std::string line;
        int maxWidth = (termWidth - 40) - 4;
        row = 1;
        while (std::getline(stream, line) && row < termHeight - 1) {
            while (line.size() > maxWidth) {
                std::string chunk = line.substr(0, maxWidth);
                int lastSpace = chunk.rfind(' ');
                if (lastSpace != std::string::npos)
                    chunk = line.substr(0, lastSpace);
                mvwprintw(rightWin, row++, 2, chunk.c_str());
                line = line.substr(chunk.size() + 1);
                if (row >= termHeight - 1) break;
            }
            if (row < termHeight - 1)
                mvwprintw(rightWin, row++, 2, line.c_str());
        }

        wrefresh(leftWin);
        wrefresh(rightWin);

        int key = wgetch(leftWin);
        if (key == 'q') break;
        if (key == KEY_UP && currentID > 0)      currentID--;
        // value 20 is temporary refer to maxID
        if (key == KEY_DOWN && currentID < 20 - 1) currentID++;

        if (key == KEY_RESIZE) {
            resize_term(0, 0);
            termHeight = getmaxy(stdscr);
            termWidth = getmaxx(stdscr);

            
            delwin(leftWin);
            delwin(rightWin);
            leftWin = newwin(termHeight, 38, 0, 0);
            rightWin = newwin(termHeight, termWidth - 40, 0, 40);
            keypad(leftWin, TRUE);
        }
    }

    delwin(leftWin);
    delwin(rightWin);
    endwin();
}