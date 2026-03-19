#include "renderer.h"

void mainCurses(World& world)
{
    Menu currentMenu = Menu::mainMenu;

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    while (currentMenu != Menu::quit)
    {
        switch (currentMenu)
        {
        case Menu::mainMenu:   cursesMainMenu(currentMenu);        break;
        case Menu::personMenu: cursesPerson(world, currentMenu);   break;
        }
    }

    endwin();
}

void cursesMainMenu(Menu& currentMenu)
{

    int termHeight = getmaxy(stdscr);
    int termWidth = getmaxx(stdscr);

    WINDOW* bigWin = newwin(termHeight, termWidth, 0, 0);
    WINDOW* mainWin = newwin(10, 20, termHeight / 2 - 5, termWidth / 2 - 10);


    keypad(mainWin, TRUE);
    
    int selected = 0;

    while (true)
    {
        wclear(bigWin);
        wclear(mainWin);
        box(bigWin, 0, 0);
        box(mainWin, 0, 0);

        mvwprintw(mainWin, 1, 2, "Main Menu");

        if (selected == 0) wattron(mainWin, A_REVERSE);
        mvwprintw(mainWin, 3, 2, "Person Menu");
        wattroff(mainWin, A_REVERSE);

        if (selected == 1) wattron(mainWin, A_REVERSE);
        mvwprintw(mainWin, 4, 2, "Quit");
        wattroff(mainWin, A_REVERSE);


        wrefresh(bigWin);
        wrefresh(mainWin);

        int key = wgetch(mainWin);
        if (key == KEY_UP && selected > 0) selected--;
        if (key == KEY_DOWN && selected < 1) selected++;
        if (key == '\n')
        {
            if (selected == 0) currentMenu = Menu::personMenu;
            if (selected == 1) currentMenu = Menu::quit;
            break;
        }
        if (key == KEY_RESIZE) {
            resize_term(0, 0);
            termHeight = getmaxy(stdscr);
            termWidth = getmaxx(stdscr);
            delwin(bigWin);
            delwin(mainWin);
            bigWin = newwin(termHeight, termWidth, 0, 0);
            mainWin = newwin(10, 20, termHeight / 2 - 5, termWidth / 2 - 10);
            keypad(mainWin, TRUE);
        }
    }
    delwin(bigWin);
    delwin(mainWin);
}

void cursesPerson(World& world, Menu& currentMenu)
{
    int termHeight = getmaxy(stdscr);
    int termWidth = getmaxx(stdscr);

    WINDOW* leftWin = newwin(termHeight, 38, 0, 0);
    box(leftWin, 0, 0);
    WINDOW* rightWin = newwin(termHeight, termWidth - 40, 0, 40);
    box(leftWin, 0, 0);

    keypad(leftWin, TRUE);

    int scrollOffset = 0;
    int currentID = 0;
    //temporary
    int maxID = 20;

    while (true)
    {

        wclear(leftWin);
        wclear(rightWin);
        box(leftWin, 0, 0);   
        box(rightWin, 0, 0);

        mvwprintw(leftWin, 1, 1, "Day %d", world.currDay);
        mvwprintw(leftWin, termHeight - 3, 1, "UP/DOWN to cycle   j/k scroll");
        mvwprintw(leftWin, termHeight - 2, 1, "p)ass time         q)uit");
     

        int row = 3;
        for (auto& [id, name] : world.nameMap)
        {
            if (id == currentID)
            {
                wattron(leftWin, A_REVERSE);
                mvwprintw(leftWin, row++ , 1, " %s", name.val.c_str());
                wattroff(leftWin, A_REVERSE);
            }
            else
                mvwprintw(leftWin, row++ , 1, "  %s", name.val.c_str());
        }

 
        std::string desc = describePerson(world, currentID);
        std::istringstream stream(desc);
        std::string line;
        int maxWidth = (termWidth - 40) - 4;
        row = 1 - scrollOffset;
        while (std::getline(stream, line) && row < termHeight - 1) {
            while (line.size() > maxWidth) {
                std::string chunk = line.substr(0, maxWidth);
                int lastSpace = chunk.rfind(' ');
                if (lastSpace != std::string::npos)
                    chunk = line.substr(0, lastSpace);
                if (row >= 1 && row < termHeight - 1)
                    mvwprintw(rightWin, row, 2, chunk.c_str());
                row++;
                line = line.substr(chunk.size() + 1);
                if (row >= termHeight - 1) break;
            }
            if (row < termHeight - 1) {
                if (row >= 1)
                    mvwprintw(rightWin, row, 2, line.c_str());
                row++;
            }
        }

        wrefresh(leftWin);
        wrefresh(rightWin);

        int key = wgetch(leftWin);
        if (key == 'q')
        {
            currentMenu = Menu::mainMenu;
            break;
        }     
        //pass time
        if (key == 'p')
        {
            systemTime(world);
            systemNeeds(world);
            systemHealth(world);
            systemMorale(world);
            systemDisease(world);
        }
        //scrolls up and down using j/k
        if (key == KEY_UP && currentID > 0) { currentID--; scrollOffset = 0; }
        // value 20 is temporary refer to maxID
        if (key == KEY_DOWN && currentID < 20 - 1) { currentID++; scrollOffset = 0; }
        if (key == 'j') scrollOffset++;
        if (key == 'k' && scrollOffset > 0) scrollOffset--;

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
}