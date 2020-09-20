#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

class Arena
{
private:
    int map_x, map_y,
        pos_x, pos_y,
        hot_key;

public:
    Arena(){ 
        map_x = map_y = 0;
        pos_x = pos_y = 0;
        hot_key = 0; };
    
    // Create new Map.
    char**& createMap(int mapx, int mapy)
    {
        map_x = mapx;
        map_y = mapy;

        // Dynamic two-dimensional map.
        char** map = new char* [map_x];
        for (int i = 0; i < map_x; i++)
        {
            map[i] = new char[map_y];
        }

        // Initialize every cell with '#'.
        for (int x = 0; x < map_x; x++)
        {
            for (int y = 0; y < map_y; y++)
            {
                map[x][y] = 177;                // change background
            }
        }

        return map;
    }

    // Display created map.
    void displayMap(char**& map)
    {
        for (int x = 0; x < map_x; x++)
        {
            for (int y = 0; y < map_y; y++)
            {
                cout << map[x][y];
            }
            cout << endl;
        }
    }

    // Decide to move.
    void move(char**& map, int key)
    {
        map[pos_x][pos_y] = 177;            // Clean up previous position.
        if (key == 119){ pos_x--; }         // UP 'w'
        else if (key == 115){ pos_x++; }    // DOWN 's'
        else if (key == 97){ pos_y--; }     // LEFT 'a'
        else if (key == 100){ pos_y++; }    // RIGHT 'd'
        submove(map);
    }

    // Make a move.
    void submove(char**& map) {
        system("cls");

        // Crossing the walls.
        if (pos_x == map_x) { pos_x = 0; }
        if (pos_x < 0) { pos_x = map_x - 1; }
        if (pos_y == map_y) { pos_y = 0; }
        if (pos_y < 0) { pos_y = map_y - 1; }

        map[pos_x][pos_y] = ' ';    // choose player
        displayMap(map);            // display map
    }
};

int main()
{
    Arena instance;

    char** map = instance.createMap(13, 20); 
    instance.displayMap(map);

    while (1)
    { 
        char hot_key = _getch();
        while (hot_key == 119)
        {
            instance.move(map, 119);
            if (_kbhit() != 0)
            {
                hot_key = _getch();
                instance.move(map, hot_key);
            }
            Sleep(50);
        }
        while (hot_key == 115)
        {
            instance.move(map, 115);
            if (_kbhit() != 0)
            {
                hot_key = _getch();
                instance.move(map, hot_key);
            }
            Sleep(50);
        }
        while (hot_key == 97)
        {
            instance.move(map, 97);
            if (_kbhit() != 0)
            {
                hot_key = _getch();
                instance.move(map, hot_key);
            }
            Sleep(50);
        }
        while (hot_key == 100)
        {
            instance.move(map, 100);
            if (_kbhit() != 0)
            {
                hot_key = _getch();
                instance.move(map, hot_key);
            }
            Sleep(50);
        }
    }
};