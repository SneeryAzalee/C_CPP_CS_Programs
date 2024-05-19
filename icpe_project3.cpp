#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

using namespace std;

class Sneery
{
    public:
    
        int A = 0;
        int B = 0;
        int C = 0;
        int D = 0;
        int E = 0;
        int DISPLAY;
        
        void execute()
        {
            for(;;)
            {
                cerr << "\e[2J\e[0H";
                
                if(kbhit())
                {
                    A = cin.get();
                    A -= '0';
                }
                
                DISPLAY = 0;
                DISPLAY += (E) ? 1 : 0;
                DISPLAY += (D) ? 2 : 0;
                DISPLAY += (C) ? 4 : 0;
                DISPLAY += (B) ? 8 : 0;
                
                cerr << "BIT: " << B << C << D << E << " (" << DISPLAY << ")  |  INPUT: " << A << "\n\n>> ";
                
                // E = B'D'E' + B'CE' + CD'E' + BC'D + AB'C' + ACD' + ABD
                int tempE = ((!B && !D && !E) || (!B && C && !E) || (C && !D && !E) || (B && !C && D) || (A && !B && !C) || (A && C && !D) || (A && B && D)) ? 1 : 0;
                // D = AB'E + AB'D + B'DE + AB'C + A'D'E' + ABC'D' + A'CDE
                int tempD = ((A && !B && E) || (A && !B && D) || (!B && D && E) || (A && !B && C) || (!A && !D && !E) || (A && B && !C && !D) || (!A && C && D && E)) ? 1 : 0;
                // C = A'CD + A'CE + AC'D + AB'DE' + AB'D'E + A'C'D'E' + ACD'E'
                int tempC = ((!A && C && D) || (!A && C && E) || (A && !C && D) || (A && !B && D && !E) || (A && !B && !D && E) || (!A && !C && !D && !E) || (A && C && !D && !E)) ? 1 : 0;
                // B = A'BE + A'BD + ABC' + BCD'E' + A'B'C'D'E' + AB'CDE
                int tempB = ((!A && B && E) || (!A && B && D) || (A && B && !C) || (B && C && !D && !E) || (!A && !B && !C && !D && !E) || (A && !B && C && D && E)) ? 1 : 0;
                
                E = tempE;
                D = tempD;
                C = tempC;
                B = tempB;
                
                this_thread::sleep_for(.5s);
            }
        }
};

int main()
{
    Sneery sneery;
    sneery.execute();
    
    return 0;
}