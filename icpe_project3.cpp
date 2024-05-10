#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

class Sneery
{
public:

    int BIT_A = 0;
    int BIT_B = 0;
    int BIT_C = 0;
    int BIT_D = 0;

    char USER_INPUT = '0';

    int DISPLAY_ONES = 0;
    int DISPLAY_TENS = 0;

    int D_ONES_SEGMENT_A = 0;
    int D_ONES_SEGMENT_B = 0;
    int D_ONES_SEGMENT_C = 0;
    int D_ONES_SEGMENT_D = 0;
    int D_ONES_SEGMENT_E = 0;
    int D_ONES_SEGMENT_F = 0;
    int D_ONES_SEGMENT_G = 0;

    int D_TENS_SEGMENT_A = 0;
    int D_TENS_SEGMENT_B = 0;
    int D_TENS_SEGMENT_C = 0;
    int D_TENS_SEGMENT_D = 0;
    int D_TENS_SEGMENT_E = 0;
    int D_TENS_SEGMENT_F = 0;
    int D_TENS_SEGMENT_G = 0;

    void executeLogic()
    {
        while(true)
        {
            cerr << "\e[2J\e[H";
            cerr << "BIT: " << BIT_A << BIT_B << BIT_C << BIT_D << " (" << DISPLAY_TENS << DISPLAY_ONES << ") • INPUT: " << USER_INPUT << " • " << ((USER_INPUT == '1') ? "ASCENDING" : "DESCENDING") << "\n\n>> ";
            this_thread::sleep_for(1s);

            if(kbhit())
            {
                USER_INPUT = cin.get();
            }

            ascendingHappyLogic();
            descendingUnhappyLogic();
        }
    }

    void ascendingHappyLogic()
    {
        // 1
        if(BIT_A == 0 && BIT_B == 0 && BIT_C == 0 && BIT_D == 1)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 0;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 1;
            }
        }
        // 7
        else if(BIT_A == 0 && BIT_B == 1 && BIT_C == 1 && BIT_D == 1)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();

            if(USER_INPUT == '0')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 1;
                BIT_B = 0;
                BIT_C = 1;
                BIT_D = 0;
            }
        }
        // 10
        else if(BIT_A == 1 && BIT_B == 0 && BIT_C == 1 && BIT_D == 0)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 1;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 1;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 1;
                BIT_B = 1;
                BIT_C = 0;
                BIT_D = 1;
            }
        }
        // 13
        else if(BIT_A == 1 && BIT_B == 1 && BIT_C == 0 && BIT_D == 1)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();

            if(USER_INPUT == '0')
            {
                BIT_A = 1;
                BIT_B = 1;
                BIT_C = 0;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 1;
            }
        }
    }
    
    void descendingUnhappyLogic()
    {
        // 15
        if(BIT_A == 1 && BIT_B == 1 && BIT_C == 1 && BIT_D == 1)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 1;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 1;
            }
        }
        // 14
        else if(BIT_A == 1 && BIT_B == 1 && BIT_C == 1 && BIT_D == 0)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 1;
                BIT_B = 1;
                BIT_C = 0;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 1;
            }
        }
        // 12
        else if(BIT_A == 1 && BIT_B == 1 && BIT_C == 0 && BIT_D == 0)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 1;
                BIT_B = 0;
                BIT_C = 1;
                BIT_D = 1;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 1;
                BIT_B = 1;
                BIT_C = 0;
                BIT_D = 1;
            }
        }
        // 11
        else if(BIT_A == 1 && BIT_B == 0 && BIT_C == 1 && BIT_D == 1)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 1;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 1;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 1;
                BIT_B = 1;
                BIT_C = 0;
                BIT_D = 1;
            }
        }
        // 9
        else if(BIT_A == 1 && BIT_B == 0 && BIT_C == 0 && BIT_D == 1)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 1;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 1;
                BIT_B = 0;
                BIT_C = 1;
                BIT_D = 0;
            }
        }
        // 8
        else if(BIT_A == 1 && BIT_B == 0 && BIT_C == 0 && BIT_D == 0)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 1;
                BIT_B = 0;
                BIT_C = 1;
                BIT_D = 0;
            }
        }
        // 6
        else if(BIT_A == 0 && BIT_B == 1 && BIT_C == 1 && BIT_D == 0)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 0;
                BIT_D = 1;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 1;
            }
        }
        // 5
        else if(BIT_A == 0 && BIT_B == 1 && BIT_C == 0 && BIT_D == 1)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 0;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 1;
            }
        }
        // 4
        else if(BIT_A == 0 && BIT_B == 1 && BIT_C == 0 && BIT_D == 0)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 0;
                BIT_B = 0;
                BIT_C = 1;
                BIT_D = 1;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 1;
            }
        }
        // 3
        else if(BIT_A == 0 && BIT_B == 0 && BIT_C == 1 && BIT_D == 1)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 0;
                BIT_B = 0;
                BIT_C = 1;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 1;
            }
        }
        // 2
        else if(BIT_A == 0 && BIT_B == 0 && BIT_C == 1 && BIT_D == 0)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 0;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 0;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 1;
            }
        }
        // 0
        else if(BIT_A == 0 && BIT_B == 0 && BIT_C == 0 && BIT_D == 0)
        {
            getSegmentDisplayValues();
            getDisplayOnesValue();
            getDisplayTensValues();

            if(USER_INPUT == '0')
            {
                BIT_A = 1;
                BIT_B = 1;
                BIT_C = 1;
                BIT_D = 1;
            }
            else if(USER_INPUT == '1')
            {
                BIT_A = 0;
                BIT_B = 0;
                BIT_C = 0;
                BIT_D = 1;
            }
        }
    }

    void getSegmentDisplayValues()
    {
        // 0
        if(BIT_A == 0 && BIT_B == 0 && BIT_C == 0 && BIT_D == 0)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 1;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 0;
        }
        // 1
        else if(BIT_A == 0 && BIT_B == 0 && BIT_C == 0 && BIT_D == 1)
        {
            D_ONES_SEGMENT_A = 0;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 0;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 0;
            D_ONES_SEGMENT_G = 0;

            D_TENS_SEGMENT_A = 1;
            D_TENS_SEGMENT_B = 1;
            D_TENS_SEGMENT_C = 1;
            D_TENS_SEGMENT_D = 1;
            D_TENS_SEGMENT_E = 1;
            D_TENS_SEGMENT_F = 1;
            D_TENS_SEGMENT_G = 0;
        }
        // 2
        else if(BIT_A == 0 && BIT_B == 0 && BIT_C == 1 && BIT_D == 0)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 0;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 1;
            D_ONES_SEGMENT_F = 0;
            D_ONES_SEGMENT_G = 1;
        }
        // 3
        else if(BIT_A == 0 && BIT_B == 0 && BIT_C == 1 && BIT_D == 1)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 0;
            D_ONES_SEGMENT_G = 1;
        }
        // 4
        else if(BIT_A == 0 && BIT_B == 1 && BIT_C == 0 && BIT_D == 0)
        {
            D_ONES_SEGMENT_A = 0;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 0;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 1;
        }
        // 5
        else if(BIT_A == 0 && BIT_B == 1 && BIT_C == 0 && BIT_D == 1)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 0;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 1;
        }
        // 6
        else if(BIT_A == 0 && BIT_B == 1 && BIT_C == 1 && BIT_D == 0)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 0;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 1;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 1;
        }
        // 7
        else if(BIT_A == 0 && BIT_B == 1 && BIT_C == 1 && BIT_D == 1)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 0;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 0;
            D_ONES_SEGMENT_G = 0;
        }
        // 8
        else if(BIT_A == 1 && BIT_B == 0 && BIT_C == 0 && BIT_D == 0)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 1;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 1;
        }
        // 9
        else if(BIT_A == 1 && BIT_B == 0 && BIT_C == 0 && BIT_D == 1)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 1;
            
            D_TENS_SEGMENT_A = 1;
            D_TENS_SEGMENT_B = 1;
            D_TENS_SEGMENT_C = 1;
            D_TENS_SEGMENT_D = 1;
            D_TENS_SEGMENT_E = 1;
            D_TENS_SEGMENT_F = 1;
            D_TENS_SEGMENT_G = 0;
        }
        // 10
        else if(BIT_A == 1 && BIT_B == 0 && BIT_C == 1 && BIT_D == 0)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 1;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 0;

            D_TENS_SEGMENT_A = 0;
            D_TENS_SEGMENT_B = 1;
            D_TENS_SEGMENT_C = 1;
            D_TENS_SEGMENT_D = 0;
            D_TENS_SEGMENT_E = 0;
            D_TENS_SEGMENT_F = 0;
            D_TENS_SEGMENT_G = 0;
        }
        // 11
        else if(BIT_A == 1 && BIT_B == 0 && BIT_C == 1 && BIT_D == 1)
        {
            D_ONES_SEGMENT_A = 0;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 0;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 0;
            D_ONES_SEGMENT_G = 0;
        }
        // 12
        else if(BIT_A == 1 && BIT_B == 1 && BIT_C == 0 && BIT_D == 0)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 0;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 1;
            D_ONES_SEGMENT_F = 0;
            D_ONES_SEGMENT_G = 1;
        }
        // 13
        else if(BIT_A == 1 && BIT_B == 1 && BIT_C == 0 && BIT_D == 1)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 0;
            D_ONES_SEGMENT_G = 1;
        }
        // 14
        else if(BIT_A == 1 && BIT_B == 1 && BIT_C == 1 && BIT_D == 0)
        {
            D_ONES_SEGMENT_A = 0;
            D_ONES_SEGMENT_B = 1;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 0;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 1;
        }
        // 15
        else if(BIT_A == 1 && BIT_B == 1 && BIT_C == 1 && BIT_D == 1)
        {
            D_ONES_SEGMENT_A = 1;
            D_ONES_SEGMENT_B = 0;
            D_ONES_SEGMENT_C = 1;
            D_ONES_SEGMENT_D = 1;
            D_ONES_SEGMENT_E = 0;
            D_ONES_SEGMENT_F = 1;
            D_ONES_SEGMENT_G = 1;
            
            D_TENS_SEGMENT_A = 0;
            D_TENS_SEGMENT_B = 1;
            D_TENS_SEGMENT_C = 1;
            D_TENS_SEGMENT_D = 0;
            D_TENS_SEGMENT_E = 0;
            D_TENS_SEGMENT_F = 0;
            D_TENS_SEGMENT_G = 0;
        }
    }

    void getDisplayOnesValue()
    {
        if(D_ONES_SEGMENT_A == 1 && D_ONES_SEGMENT_B == 1 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 1 && D_ONES_SEGMENT_E == 1 && D_ONES_SEGMENT_F == 1 && D_ONES_SEGMENT_G == 0)
        {
            DISPLAY_ONES = 0;
        }
        else if(D_ONES_SEGMENT_A == 0 && D_ONES_SEGMENT_B == 1 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 0 && D_ONES_SEGMENT_E == 0 && D_ONES_SEGMENT_F == 0 && D_ONES_SEGMENT_G == 0)
        {
            DISPLAY_ONES = 1;
        }
        else if(D_ONES_SEGMENT_A == 1 && D_ONES_SEGMENT_B == 1 && D_ONES_SEGMENT_C == 0 && D_ONES_SEGMENT_D == 1 && D_ONES_SEGMENT_E == 1 && D_ONES_SEGMENT_F == 0 && D_ONES_SEGMENT_G == 1)
        {
            DISPLAY_ONES = 2;
        }
        else if(D_ONES_SEGMENT_A == 1 && D_ONES_SEGMENT_B == 1 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 1 && D_ONES_SEGMENT_E == 0 && D_ONES_SEGMENT_F == 0 && D_ONES_SEGMENT_G == 1)
        {
            DISPLAY_ONES = 3;
        }
        else if(D_ONES_SEGMENT_A == 0 && D_ONES_SEGMENT_B == 1 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 0 && D_ONES_SEGMENT_E == 0 && D_ONES_SEGMENT_F == 1 && D_ONES_SEGMENT_G == 1)
        {
            DISPLAY_ONES = 4;
        }
        else if(D_ONES_SEGMENT_A == 1 && D_ONES_SEGMENT_B == 0 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 1 && D_ONES_SEGMENT_E == 0 && D_ONES_SEGMENT_F == 1 && D_ONES_SEGMENT_G == 1)
        {
            DISPLAY_ONES = 5;
        }
        else if(D_ONES_SEGMENT_A == 1 && D_ONES_SEGMENT_B == 0 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 1 && D_ONES_SEGMENT_E == 1 && D_ONES_SEGMENT_F == 1 && D_ONES_SEGMENT_G == 1)
        {
            DISPLAY_ONES = 6;
        }
        else if(D_ONES_SEGMENT_A == 1 && D_ONES_SEGMENT_B == 1 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 0 && D_ONES_SEGMENT_E == 0 && D_ONES_SEGMENT_F == 0 && D_ONES_SEGMENT_G == 0)
        {
            DISPLAY_ONES = 7;
        }
        else if(D_ONES_SEGMENT_A == 1 && D_ONES_SEGMENT_B == 1 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 1 && D_ONES_SEGMENT_E == 1 && D_ONES_SEGMENT_F == 1 && D_ONES_SEGMENT_G == 1)
        {
            DISPLAY_ONES = 8;
        }
        else if(D_ONES_SEGMENT_A == 1 && D_ONES_SEGMENT_B == 1 && D_ONES_SEGMENT_C == 1 && D_ONES_SEGMENT_D == 1 && D_ONES_SEGMENT_E == 0 && D_ONES_SEGMENT_F == 1 && D_ONES_SEGMENT_G == 1)
        {
            DISPLAY_ONES = 9;
        }
    }

    void getDisplayTensValues()
    {
        if(D_TENS_SEGMENT_A == 1 && D_TENS_SEGMENT_B == 1 && D_TENS_SEGMENT_C == 1 && D_TENS_SEGMENT_D == 1 && D_TENS_SEGMENT_E == 1 && D_TENS_SEGMENT_F == 1 && D_TENS_SEGMENT_G == 0)
        {
            DISPLAY_TENS = 0;
        }
        else if(D_TENS_SEGMENT_A == 0 && D_TENS_SEGMENT_B == 1 && D_TENS_SEGMENT_C == 1 && D_TENS_SEGMENT_D == 0 && D_TENS_SEGMENT_E == 0 && D_TENS_SEGMENT_F == 0 && D_TENS_SEGMENT_G == 0)
        {
            DISPLAY_TENS = 1;
        }
    }
};

int main()
{
    Sneery sneery;
    sneery.executeLogic();

    return 0;
}