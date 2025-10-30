#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Sneery
{
    public:

        string mainInput;
        vector<int> referenceStringInput;
        vector<int> output;
        int frameCount;

        void getMainInputString()
        {
            cout << "\n\n(SPACE SEPARATED)";
            cout << "\nEnter the reference string: ";
            getline(cin, mainInput);
        }

        void getReferenceString()
        {
            stringstream sstream(mainInput);
            int extractor;

            while(sstream >> extractor)
            {
                referenceStringInput.push_back(extractor);
            }
        }

        void getFrameCount()
        {
            cout << "\nEnter the number of frames: ";
            cin >> frameCount;
        }

        bool isAlreadyPresent(vector<int> referenceString, int input)
        {
            for(int i = 0; i < referenceString.size(); i++)
            {
                if(input == referenceString[i])
                {
                    return true;
                }
            }
            return false;
        }

        int getIndexToReplace(vector<int> referenceString, vector<int> output, int currentIndex)
        {
            vector<int> pageCounts;

            for(int i = 0; i < output.size(); i++)
            {
                bool matchFound = false;
                int pageCount = 0;

                for(int j = currentIndex; j < referenceString.size(); j++)
                {
                    if(output[i] == referenceString[j])
                    {
                        pageCounts.push_back(pageCount);
                        matchFound = true;
                        break;
                    }
                    else
                    {
                        pageCount++;
                    }
                }

                if(!matchFound)
                {
                    for(int j = 0; j < currentIndex; j++)
                    {
                        if(output[i] == referenceString[j])
                        {
                            pageCounts.push_back(pageCount);
                            matchFound = true;
                            break;
                        }
                        else
                        {
                            pageCount++;
                        }
                    }
                }
            }

            int highestCount = 0;
            for(int i : pageCounts)
            {
                if(i > highestCount)
                {
                    highestCount = i;
                }
            }

            for(int i = 0; i < pageCounts.size(); i++)
            {
                if(highestCount == pageCounts[i])
                {
                    return i;
                }
            }
            return -1;
        }

        void referenceStringLooper()
        {
            cout << "\n\nOUTPUT:\n";

            int pageFaultCount = 0;
            for(int i = 0; i < referenceStringInput.size(); i++)
            {
                cout << "\n";

                bool frameUpdated = false;

                if(!isAlreadyPresent(output, referenceStringInput[i]))
                {
                    if(output.size() < frameCount)
                    {
                        output.push_back(referenceStringInput[i]);
                    }
                    else
                    {
                        int indexToReplace = getIndexToReplace(referenceStringInput, output, i);
                        output[indexToReplace] = referenceStringInput[i];
                    }

                    pageFaultCount++;
                    frameUpdated = true;
                }

                printOutput();

                if(frameUpdated)
                {
                    cout << "  >>  PF " << pageFaultCount;
                }
            }
        }

        void printOutput()
        {
            for(int i : output)
            {
                cout << i << " ";
            }
        }
};

int main()
{
    Sneery sneery;
    sneery.getMainInputString();
    sneery.getReferenceString();
    sneery.getFrameCount();
    sneery.referenceStringLooper();

    cout << "\n\n\n";

    return 0;
}