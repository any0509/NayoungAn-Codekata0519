#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    char* words[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };



    // 답을 먼저 문자열로 저장
    char answer_str[50] = "";
    int i = 0;

    while (s[i] != '\0')
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            // 해당 숫자와 문자열 끝 문자 추가 (오류 방지)
            char temp[2] = { s[i], '\0' };
            strcat(answer_str, temp);
            i++;
        }
        else
        {
            for (int j = 0; j < 10; ++j)
            {
                if (strncmp(s + i, words[j], strlen(words[j])) == 0)
                {
                    char temp[2];
                    sprintf(temp, "%d", j); // 숫자를 문자열로 변환
                    strcat(answer_str, temp);

                    i += strlen(words[j]);

                    break;
                }
            }
        }
    }



    return atoi(answer_str);
}