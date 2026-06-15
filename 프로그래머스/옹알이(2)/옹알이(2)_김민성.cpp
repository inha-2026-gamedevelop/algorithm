#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static const char* SOUNDS[4]   = { "aya", "ye", "woo", "ma" };
static const int SOUND_LEN[4] = { 3, 2, 3, 2 };

bool CanSpeak(const char* word)
{
    int len = (int)strlen(word);
    int i = 0;
    int prevIndex = -1;

    while (i < len)
    {
        int matched = -1;

        for (int s = 0; s < 4; ++s)
        {
            int soundLen = SOUND_LEN[s];

            if ((i + soundLen <= len) && (strncmp(word + i, SOUNDS[s], soundLen) == 0))
            {
                matched = s;
                break;
            }
        }
        
        if ((matched == -1) || (matched == prevIndex))
            return false;

        i += SOUND_LEN[matched];
        prevIndex = matched;
    }

    return true;
}

int solution(const char* babbling[], size_t babbling_len)
{
    int answer = 0;

    for (size_t i = 0; i < babbling_len; ++i)
    {
        if (CanSpeak(babbling[i]))
            ++answer;
    }

    return answer;
}

// 그리디 방식
// 주어진 단어가 "aya", "ye", "woo", "ma"로만 이루어져 있고
// 4가지 발음은 시작 글자가 전부 다르다.
// 따라서 문자열의 한 위치에서 4가지 발음 중 하나가 매칭되는지 확인하고
// 앞에서부터 그리디로 진행해도 된다.

// 예를 들어 "yeye" 인 경우
// 1. i=0: "ye" 매칭 -> prevIndex = ye, i=2
// 2. i=2: "ye" 매칭, 하지만 prevIndex == ye -> 연속 발음 -> false

// matched == -1(매칭 실패)과 matched == prevIndex(연속 발음) 두 조건만 체크하면 된다.
