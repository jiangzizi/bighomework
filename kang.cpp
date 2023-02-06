#include <iostream>
#include <ctime>
#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

struct mo
{
    int dx, dy;

} mov[9] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int main()
{
    initscr();

    srand((unsigned int)time(NULL));
    bool map[35][35] = {0};
    int test[35][35] = {0};
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            int r = rand();
            if (r % 10 <= 5)
            {
                map[i][j] = true;
            }
            else
            {
                map[i][j] = false;
            }
        }
    }
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            if (map[i][j])
            {
                cout << "M";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl
             << '\r';
    }
    sleep(2);
    // move(4,4);
    // mvaddch(5,5,'*');
    // cout<<1;
    // getch();
    refresh();
    clear();
    while (1)
    {
        for (int i = 1; i <= 15; i++)
        {
            for (int j = 1; j <= 30; j++)
            {
                for (int k = 1; k <= 8; k++)
                {
                    if (map[i + mov[k].dx][j + mov[k].dy])
                    {
                        test[i][j]++;
                    }
                }
                if ((test[i][j] == 0 || test[i][j] == 1) && map[i][j] == 1)
                {
                    map[i][j] = 0;
                    continue;
                }
                if ((test[i][j] == 2 || test[i][j] == 3) && map[i][j] == 1)
                {
                    continue;
                }
                if (test[i][j] >= 4 && map[i][j] == 1)
                {
                    map[i][j] = 0;
                    continue;
                }
                if (test[i][j] == 3 && map[i][j] == 0)
                {
                    map[i][j] = 1;
                    continue;
                }
            }
        }
        for (int i = 1; i <= 15; i++)
        {
            for (int j = 1; j <= 30; j++)
            {
                test[i][j] = 0;
            }
        }
        for (int i = 1; i <= 15; i++)
        {
            for (int j = 1; j <= 30; j++)
            {
                if (map[i][j])
                {
                    cout << "M";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl
                 << '\r';
        }
        sleep(2);
        refresh();
        clear();

    }

    getch();
    endwin();

    return 0;
}
