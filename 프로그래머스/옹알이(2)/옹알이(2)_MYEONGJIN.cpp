#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
    int count = 0;
    vector<string> sounds = {"aya", "ye", "woo", "ma"};
    
    for (auto word : babbling)
    {
        int i = 0;
        string lastSound;
        bool possible = true;

        while (i < word.length())
        {
            bool found = false;
            
            for (auto s : sounds)
            {
                if (word.compare(i, s.length(), s) == 0)
                {
                    if (s == lastSound)
                    {
                        possible = false;
                        break;
                    }
                    lastSound = s;
                    i += s.length();
                    found = true;
                    break;
                }
            }
                
            if (!found)
            {
                possible = false;
                break;
            }
        }
        if (possible)
            count++;
    }
    return count;
}
