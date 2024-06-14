#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>

using namespace std;
void DrawRoundedRectangle(int posX, int posY, int width, int height, int roundness, Color color)
{
    DrawRectangle(posX + roundness, posY, width - 2 * roundness, height, color);
    DrawRectangle(posX, posY + roundness, width, height - 2 * roundness, color);

    DrawCircle(posX + roundness, posY + roundness, roundness, color);
    DrawCircle(posX + width - roundness, posY + roundness, roundness, color);
    DrawCircle(posX + roundness, posY + height - roundness, roundness, color);
    DrawCircle(posX + width - roundness, posY + height - roundness, roundness, color);
}

int main()
{
    int w = 1920;
    int h = 1080;
    int boxheight = h - 200 - 10;
    int boxcounterup = -210;
    int textheight = ((h - 200) + 100) - 30 - 10;
    int numcnt = 0;
    string textontop = "stack<int> s;";
    Color textontopcolor = WHITE;
    vector<string> numbers;
    InitWindow(w, h, "DSA Visualizer");
    SetTargetFPS(60);

    bool drawBox = false;
    string input = "";

    while (!WindowShouldClose())
    {

        BeginDrawing();
        DrawText(textontop.c_str(), ((w - 1160) + 200) - 320, 10, 100, textontopcolor);
        ClearBackground({38, 38, 38, 255});

        if (drawBox)
        {
            for (int i = 0; i <= boxcounterup; i += 210)
            {
                DrawRoundedRectangle(w - 1160, boxheight - i, 400, 200, 40, {17, 17, 17, 255});
                // DrawRectangle(w - 1160, boxheight - i, 400, 200, {17, 17, 17, 255});
                DrawText(numbers[numcnt].c_str(), ((w - 1160) + 200) - 30, textheight - i - 10, 100, WHITE);
                numcnt++;
            }
            numcnt = 0;
        }

        EndDrawing();
        cout << "Enter Command: ";
        getline(cin, input);
        if (input.find("s.push(") != string::npos)
        {
            char s = input[7];
            string si = "";
            si += s;
            numbers.push_back(si);
            textontop = input;
            drawBox = true;
            textontopcolor = WHITE;
            boxcounterup += 210;
        }
        else if (input.find("s.pop();") != string::npos)
        {
            numbers.pop_back();
            textontop = input;
            textontopcolor = WHITE;
            drawBox = true;
            boxcounterup -= 210;
        }
        else
        {
            textontop = "wrong cmd";
            textontopcolor = RED;
        }
    }

    CloseWindow();

    return 0;
}
