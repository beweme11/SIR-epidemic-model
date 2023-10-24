#include <iostream>
#include <ctime>
#include <cstdlib>
#include<raylib.h>
#include<cmath>
#include<string>

using namespace std;
long int N = 10000;
long int S = 10000;
long int I = 1;
long int R = 1;
float timestep = 1;
const double beta = 0.000001;  // Transmission rate
const double gamma = 0.0001; // Recovery rate, try 10 times less

class Susceptible
{
public:
    double rate;

    Susceptible()
    {
        rate = 0.0;
    }

    void setCurrentRate(int infectious)
    {
        rate = -beta * S * infectious;
    }

    void update()
    {
        S += rate * timestep;
    }
};

class Infected
{
public:
    double rate;

    Infected()
    {
        rate = 0.0;
    }

    void setCurrentRate(int infectious)
    {
        rate = (beta * S * infectious) - (gamma * I);
    }

    void update()
    {
        I += rate * timestep;
    }
};

class Recovered
{
public:
    double rate;

    Recovered()
    {
        rate = 0.0;
    }

    void update()
    {
        R += I * gamma * timestep;
    }
};

/*

void graphics(long int S,long int I,long int R)
{
    const int screenWidth = 1000;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "SIR epidemic model visualization");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(300,  500 , 100, BLACK);
        DrawText(to_string(S).c_str(), 300, 650, 20, WHITE);
        for (int i = 0; i < S; i++)
        {
            float angle = static_cast<float>(rand() % 360);
            float distance = static_cast<float>(rand() % static_cast<int>(100));
            float x = 300 + cos(angle * DEG2RAD) * distance;
            float y = 500 + sin(angle * DEG2RAD) * distance;

            DrawCircle(x, y, 7, YELLOW);
        }
        DrawText(to_string(I).c_str(), 600, 650, 20, WHITE);
        DrawCircle(600, 500, 100, BLACK);



        for (int i = 0; i < I; i++)
        {
            float angle = static_cast<float>(rand() % 360);
            float distance = static_cast<float>(rand() % static_cast<int>(100));
            float x = 600 + cos(angle * DEG2RAD) * distance;
            float y = 500 + sin(angle * DEG2RAD) * distance;

            DrawCircle(x, y, 7, RED);
        }
        DrawText(to_string(R).c_str(), 900, 650, 20, WHITE);

        DrawCircle(900, 500, 100, BLACK);

        for (int i = 0; i < R; i++)
        {
            float angle = static_cast<float>(rand() % 360);
            float distance = static_cast<float>(rand() % static_cast<int>(100));
            float x = 900 + cos(angle * DEG2RAD) * distance;
            float y = 500 + sin(angle * DEG2RAD) * distance;

            DrawCircle(x, y, 7, GREEN);
        }
        EndDrawing();
    }

    CloseWindow();



}*/

int main()

{
    const int screenWidth = 1900;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Raylib Circle Example");
    
    srand(static_cast<unsigned>(time(nullptr)));

    Susceptible susceptible;
    Infected infected;
    Recovered recovered;
    SetTargetFPS(30);
    while ( !WindowShouldClose())
    {
      

       

        susceptible.setCurrentRate(I);
        infected.setCurrentRate(I);

        susceptible.update();


        infected.update();
        recovered.update();

        if (S < 0)
        {
            S = 0;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Discrete SIR epidemic model simulation", 10, 10, 60, WHITE);

        DrawText(("Initial simulation population = " + to_string(N)).c_str(), 1450, 20, 20, WHITE);

        DrawText(("Current transmission rate = " + to_string(beta)).c_str(), 1450, 40 , 20, WHITE);
        DrawText(("Current recovery rate = " + to_string(gamma)).c_str(), 1450, 60, 20, WHITE);


        DrawCircle(300, 500, 250, BLACK);
        DrawText(("Susceptible = " + to_string(S)).c_str(), 300, 850, 20, WHITE);
        for (int i = 0; i < S; i++)
        {
            float angle = static_cast<float>(rand() % 360);
            float distance = static_cast<float>(rand() % static_cast<int>(250));
            float x = 300 + cos(angle * DEG2RAD) * distance;
            float y = 500 + sin(angle * DEG2RAD) * distance;

            DrawCircle(x, y, 7, YELLOW);
        }





        

        DrawText(("Infected = " + to_string(I)).c_str(), 900, 830, 20, WHITE);
        DrawCircle(900, 500, 250, BLACK);



        for (int i = 0; i < I; i++)
        {
            float angle = static_cast<float>(rand() % 360);
            float distance = static_cast<float>(rand() % static_cast<int>(250));
            float x = 900 + cos(angle * DEG2RAD) * distance;
            float y = 500 + sin(angle * DEG2RAD) * distance;

            DrawCircle(x, y, 7, RED);
        }









        DrawText(("Recovered = " + to_string(R)).c_str(), 1500, 850, 20, WHITE);


        DrawCircle(1500, 500, 250, BLACK);

        for (int i = 0; i < R; i++)
        {
            float angle = static_cast<float>(rand() % 360);
            float distance = static_cast<float>(rand() % static_cast<int>(250));
            float x = 1500 + cos(angle * DEG2RAD) * distance;
            float y = 500 + sin(angle * DEG2RAD) * distance;

            DrawCircle(x, y, 7, GREEN);
        }
        




        EndDrawing();

        cout << "S=" << S << "  I=" << I << "  R=" << R << "  " << timestep << endl;


        

        timestep += 0.7;
    }

    CloseWindow();

    return 0;
}



/*
int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    Susceptible susceptible;
    Infected infected;
    Recovered recovered;

    while (I >0)
    {
        susceptible.setCurrentRate(I);
        infected.setCurrentRate(I);

        susceptible.update();
        infected.update();
        recovered.update();
        if (S < 0)
        {
            S = 0;
        }


        
        graphics(S, I, R);

        cout << "S=" << S << "  I=" << I << "  R=" << R << "  " << timestep << endl;


        timestep += 0.001;

    }

    return 0;
}
*/