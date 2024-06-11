#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

using namespace std;

class Sneery
{
public:

    // Main Input
    int A = 0;
    // 4-BIT Memory
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    // Decimal Representation
    int UNITS;
    int TENS;
    // Units-Place BITS
    int U1;
    int U2;
    int U3;
    int U4;
    // Tens-Place BITS
    int T1 = 0;
    int T2 = 0;
    int T3 = 0;
    int T4;

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

            // U1 = BC`D`
            U1 = ((B && !C && !D)) ? 1 : 0;
            // U2 = B`C + CD
            U2 = ((!B && C) || (C && D)) ? 1 : 0;
            // U3 = B`D + BCD`
            U3 = ((!B && D) || (B && C && !D)) ? 1 : 0;
            // U4 = E
            U4 = (E) ? 1 : 0;
            // T4 = BC + BD
            T4 = ((B && C) || (B && D)) ? 1 : 0;

            TENS = 0;
            UNITS = 0;
            TENS += (T4) ? 1 : 0;
            UNITS += (U4) ? 1 : 0;
            UNITS += (U3) ? 2 : 0;
            UNITS += (U2) ? 4 : 0;
            UNITS += (U1) ? 8 : 0;

            // E = B'D'E' + B'CE' + CD'E' + BC'D + AB'C' + ACD' + ABD
            int tempE = ((!B && !D && !E) || (!B && C && !E) || (C && !D && !E) || (B && !C && D) || (A && !B && !C) || (A && C && !D) || (A && B && D)) ? 1 : 0;
            // D = AB'E + AB'D + B'DE + AB'C + A'D'E' + ABC'D' + A'CDE
            int tempD = ((A && !B && E) || (A && !B && D) || (!B && D && E) || (A && !B && C) || (!A && !D && !E) || (A && B && !C && !D) || (!A && C && D && E)) ? 1 : 0;
            // C = A'CD + A'CE + AC'D + AB'DE' + AB'D'E + A'C'D'E' + ACD'E'
            int tempC = ((!A && C && D) || (!A && C && E) || (A && !C && D) || (A && !B && D && !E) || (A && !B && !D && E) || (!A && !C && !D && !E) || (A && C && !D && !E)) ? 1 : 0;
            // B = A'BE + A'BD + ABC' + BCD'E' + A'B'C'D'E' + AB'CDE
            int tempB = ((!A && B && E) || (!A && B && D) || (A && B && !C) || (B && C && !D && !E) || (!A && !B && !C && !D && !E) || (A && !B && C && D && E)) ? 1 : 0;

            int tempU1;
            int tempU2;
            int tempU3;
            int tempU4;
            
            int tempT4;
            
            tempU1 = ((tempB && !tempC && !tempD)) ? 1 : 0;
            tempU2 = ((!tempB && tempC) || (tempC && tempD)) ? 1 : 0;
            tempU3 = ((!tempB && tempD) || (tempB && tempC && !tempD)) ? 1 : 0;
            tempU4 = (tempE) ? 1 : 0;
            
            tempT4 = ((tempB && tempC) || (tempB && tempD)) ? 1 : 0;

            int tempTENS = 0;
            int tempUNITS = 0;
            tempTENS += (tempT4) ? 1 : 0;
            tempUNITS += (tempU4) ? 1 : 0;
            tempUNITS += (tempU3) ? 2 : 0;
            tempUNITS += (tempU2) ? 4 : 0;
            tempUNITS += (tempU1) ? 8 : 0;
            
            cerr << "INPUT:              " << A << "  |  (" << ((A) ? "ON" : "OFF") << ")" << "\n\nCURRENT BITS:    " << B << C << D << E << "  |  (" << TENS << UNITS << ")" << "\nTENS DIGIT:      " << T1 << T2 << T3 << T4 << "  |  (" << TENS << ")" << "\nUNITS DIGIT:     " << U1 << U2 << U3 << U4 << "  |  (" << UNITS << ")"   << "\n\nNEXT BITS:       " << tempB << tempC << tempD << tempE << "  |  (" << tempTENS << tempUNITS << ")\n\n>> ";

            E = tempE;
            D = tempD;
            C = tempC;
            B = tempB;

            this_thread::sleep_for(.8s);
        }
    }
};

int main()
{
    Sneery sneery;
    sneery.execute();

    return 0;
}