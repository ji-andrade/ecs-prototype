#include "renderer.h"

void setConsoleFont(int size)
{
    CONSOLE_FONT_INFOEX cfi = {};
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = size;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void mainCurses(World& world)
{
    Menu currentMenu = Menu::mainMenu;

    setConsoleFont(30);
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    while (currentMenu != Menu::quit)
    {
        switch (currentMenu)
        {
        case Menu::mainMenu:   cursesMainMenu(currentMenu);           break;
        case Menu::personMenu: cursesPersonMenu(world, currentMenu);  break;
        case Menu::gameMenu: cursesGameMenu(world, currentMenu);      break;
        }
    }

    endwin();
}

void cursesMainMenu(Menu& currentMenu)
{
    clearok(stdscr, TRUE);
    clear();
    refresh();
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
        mvwprintw(mainWin, 3, 2, "Start Game");
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
            //if (selected == 0) currentMenu = Menu::personMenu;
            if (selected == 0) currentMenu = Menu::gameMenu;
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

void cursesGameMenu(World& world, Menu& currentMenu)
{
    clearok(stdscr, TRUE);
    clear();
    refresh();
    int termHeight = getmaxy(stdscr);
    int termWidth = getmaxx(stdscr);

    int topBotHeight = termHeight / 10;
    int midHeight = termHeight - 2 * topBotHeight;
    int leftWidth = termWidth / 5;
    int rightWidth = termWidth - leftWidth;

    WINDOW* topWin = newwin(topBotHeight, termWidth, 0, 0);
    WINDOW* botWin = newwin(topBotHeight, termWidth, termHeight - topBotHeight, 0);
    WINDOW* leftWin = newwin(midHeight, leftWidth, topBotHeight, 0);
    WINDOW* rightWin = newwin(midHeight, rightWidth, topBotHeight, leftWidth);
    keypad(botWin, TRUE);

    const std::vector<std::string> botOptions = { "Crew", "Wait" ,"Quit"};
    int selected = 0;

    while (true)
    {
        topBotHeight = termHeight / 10;

        wclear(topWin);
        wclear(botWin);
        wclear(leftWin);
        wclear(rightWin);

        box(topWin, 0, 0);
        box(botWin, 0, 0);
        box(leftWin, 0, 0);
        box(rightWin, 0, 0);

        mvwprintw(topWin, topBotHeight / 2, 1, "%s %d of %s %d",
            toString(world.time.weekDay).c_str(),
            world.time.currDay,
            toString(world.time.yearMonth).c_str(),
            world.time.year);

        int col = 2;
        for (int i = 0; i < (int)botOptions.size(); i++)
        {
            if (i == selected) wattron(botWin, A_REVERSE);
            mvwprintw(botWin, topBotHeight / 2, col, " %s ", botOptions[i].c_str());
            if (i == selected) wattroff(botWin, A_REVERSE);
            col += botOptions[i].size() + 4;
        }

        mvwprintw(leftWin, 1, 2, "lorem ipsum");
        mvwprintw(rightWin, 1, 2, "lorem ipsum");

        wrefresh(topWin);
        wrefresh(botWin);
        wrefresh(leftWin);
        wrefresh(rightWin);

        int key = wgetch(botWin);

        if (key == KEY_LEFT && selected > 0) selected--;
        if (key == KEY_RIGHT && selected < (int)botOptions.size() - 1) selected++;

        if (key == '\n' || key == KEY_ENTER)
        {
            if (selected == 0) { currentMenu = Menu::personMenu; break; }
            if (selected == 1) { systemTick(world); continue;}
            if (selected == 2) { currentMenu = Menu::mainMenu; break; }
        }

        if (key == KEY_RESIZE)
        {
            resize_term(0, 0);
   
            termHeight = getmaxy(stdscr);
            termWidth = getmaxx(stdscr);

            topBotHeight = termHeight / 10;
            midHeight = termHeight - 2 * topBotHeight;
            leftWidth = termWidth / 5;
            rightWidth = termWidth - leftWidth;

            delwin(topWin);
            delwin(botWin);
            delwin(leftWin);
            delwin(rightWin);

            topWin = newwin(topBotHeight, termWidth, 0, 0);
            botWin = newwin(topBotHeight, termWidth, termHeight - topBotHeight, 0);
            leftWin = newwin(midHeight, leftWidth, topBotHeight, 0);
            rightWin = newwin(midHeight, rightWidth, topBotHeight, leftWidth);
            keypad(botWin, TRUE);
        }
    }

    delwin(topWin);
    delwin(botWin);
    delwin(leftWin);
    delwin(rightWin);
}

void cursesPersonMenu(World& world, Menu& currentMenu)
{
    clearok(stdscr, TRUE);
    clear();
    refresh();
    int termHeight = getmaxy(stdscr);
    int termWidth = getmaxx(stdscr);

    int topBotHeight = termHeight / 10;
    int panelHeight = termHeight - 2 * topBotHeight;

    WINDOW* topWin = newwin(topBotHeight, termWidth, 0, 0);
    WINDOW* botWin = newwin(topBotHeight, termWidth, termHeight - topBotHeight, 0);
    WINDOW* leftWin = newwin(panelHeight, 25, topBotHeight, 0);
    WINDOW* rightWin = newwin(panelHeight, termWidth - 27, topBotHeight, 27);

    box(topWin, 0, 0);
    box(botWin, 0, 0);
    box(leftWin, 0, 0);
    box(rightWin, 0, 0);

    keypad(leftWin, TRUE);

    int scrollOffset = 0;
    int currentID = 0;
    int maxID = 20;

    // bottom bar options
    const std::vector<std::string> botOptions = { "Quit" };
    int botSelected = 0;
    bool botFocused = false; // false =  names, true = bottom bar focused

    while (true)
    {
        wclear(topWin);
        wclear(botWin);
        wclear(leftWin);
        wclear(rightWin);

        box(topWin, 0, 0);
        box(botWin, 0, 0);
        box(leftWin, 0, 0);
        box(rightWin, 0, 0);

        // Top bar time
        mvwprintw(topWin, topBotHeight / 2, 1, "%s %d of %s %d",
            toString(world.time.weekDay).c_str(),
            world.time.currDay,
            toString(world.time.yearMonth).c_str(),
            world.time.year);

        // Bottom bar options
        int col = 2;
        for (int i = 0; i < (int)botOptions.size(); i++)
        {
            if (botFocused && i == botSelected) wattron(botWin, A_REVERSE);
            mvwprintw(botWin, topBotHeight / 2, col, " %s ", botOptions[i].c_str());
            if (botFocused && i == botSelected) wattroff(botWin, A_REVERSE);
            col += botOptions[i].size() + 4;
        }

        // Left panel: person list
        int row = 1;
        for (auto& [id, name] : world.nameMap)
        {
            if (!botFocused && id == currentID)
            {
                wattron(leftWin, A_REVERSE);
                mvwprintw(leftWin, row++, 1, " %s", name.val.c_str());
                wattroff(leftWin, A_REVERSE);
            }
            else
                mvwprintw(leftWin, row++, 1, "  %s", name.val.c_str());
        }

        // person description with word wrap
        std::string desc = describePerson(world, currentID);
        std::istringstream stream(desc);
        std::string line;
        int maxWidth = (termWidth - 27) - 4;
        row = 1 - scrollOffset;
        while (std::getline(stream, line) && row < panelHeight - 1)
        {
            while (line.size() > maxWidth)
            {
                std::string chunk = line.substr(0, maxWidth);
                int         lastSpace = chunk.rfind(' ');
                if (lastSpace != std::string::npos)
                    chunk = line.substr(0, lastSpace);
                if (row >= 1 && row < panelHeight - 1)
                    mvwprintw(rightWin, row, 2, chunk.c_str());
                row++;
                line = line.substr(chunk.size() + 1);
                if (row >= panelHeight - 1) break;
            }
            if (row < panelHeight - 1)
            {
                if (row >= 1)
                    mvwprintw(rightWin, row, 2, line.c_str());
                row++;
            }
        }

        wrefresh(topWin);
        wrefresh(botWin);
        wrefresh(leftWin);
        wrefresh(rightWin);

        int key = wgetch(leftWin);

        if (key == KEY_UP)
        {
            if (botFocused)
                botFocused = false; // go back to list
            else if (currentID > 0)
            {
                currentID--; scrollOffset = 0;
            }
        }
        if (key == KEY_DOWN)
        {
            if (!botFocused && currentID < maxID - 1)
            {
                currentID++; scrollOffset = 0;
            }
            else if (!botFocused)
                botFocused = true; // reached bottom, drop into bottom bar
        }
        if (key == KEY_LEFT && botFocused && botSelected > 0) botSelected--;
        if (key == KEY_RIGHT && botFocused && botSelected < (int)botOptions.size() - 1) botSelected++;
        if (key == 'j') scrollOffset++;
        if (key == 'k' && scrollOffset > 0) scrollOffset--;
        if (key == '\n' || key == KEY_ENTER)
        {
            if (botFocused && botSelected == 0)
            {
                currentMenu = Menu::gameMenu;
                break;
            }
        }

        if (key == KEY_RESIZE)
        {
            resize_term(0, 0);
  
            termHeight = getmaxy(stdscr);
            termWidth = getmaxx(stdscr);
            topBotHeight = termHeight / 10;
            panelHeight = termHeight - 2 * topBotHeight;

            delwin(topWin);
            delwin(botWin);
            delwin(leftWin);
            delwin(rightWin);

            topWin = newwin(topBotHeight, termWidth, 0, 0);
            botWin = newwin(topBotHeight, termWidth, termHeight - topBotHeight, 0);
            leftWin = newwin(panelHeight, 38, topBotHeight, 0);
            rightWin = newwin(panelHeight, termWidth - 40, topBotHeight, 40);
            keypad(leftWin, TRUE);
        }
    }

    delwin(topWin);
    delwin(botWin);
    delwin(leftWin);
    delwin(rightWin);
}