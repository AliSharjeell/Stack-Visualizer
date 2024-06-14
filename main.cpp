#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>

using namespace std;
void DrawRoundedRectangle(int posX, int posY, int width, int height, int roundness, Color color)
{
    // Draw main rectangle
    DrawRectangle(posX + roundness, posY, width - 2 * roundness, height, color);
    DrawRectangle(posX, posY + roundness, width, height - 2 * roundness, color);

    // Draw rounded corners using circles as masks
    DrawCircle(posX + roundness, posY + roundness, roundness, color);
    DrawCircle(posX + width - roundness, posY + roundness, roundness, color);
    DrawCircle(posX + roundness, posY + height - roundness, roundness, color);
    DrawCircle(posX + width - roundness, posY + height - roundness, roundness, color);
}

int main()
{
    int w = 1920;
    int h = 1080;
    int boxheight = h - 200;
    int boxcounterup = 0;
    int textheight = ((h - 200) + 100) - 30;
    int numcnt = 0;
    string textontop = "stack<int> s;";
    vector<string> numbers;
    InitWindow(w, h, "DSA Visualizer");
    SetTargetFPS(60);

    bool drawBox = false;
    string input = "";

    while (!WindowShouldClose())
    {

        // Draw
        BeginDrawing();
        DrawText(textontop.c_str(), ((w - 1160) + 200) - 320, 10, 100, WHITE);
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
            boxcounterup += 210;
        }

        EndDrawing();
        cout << "Enter command: ";
        getline(cin, input);
        if (input.find("s.push(") != string::npos)
        {
            char s = input[7];
            string si = "";
            si += s;
            numbers.push_back(si);
            textontop = input;
            drawBox = true;
        }
    }

    CloseWindow();

    return 0;
}
