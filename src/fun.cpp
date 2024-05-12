// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath> 

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (const char *p = str; *p!= '\0'; ++p) {
        if (!inWord &&!std::isspace(*p)) {
            inWord = true;
            hasDigit = false;
        }
        else if (inWord && std::isspace(*p)) {
            inWord = false;
            if (!hasDigit) {
                ++count;
            }
            hasDigit = false;
        }
        else if (std::isdigit(*p)) {
            hasDigit = true;
        }
    }

    if (inWord) {
        if (!hasDigit) {
            ++count;
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool wordStartedWithUppercase = false;
    for (const char *p = str; *p!= '\0'; ++p) {
        if (*p == ' ') {
            if (wordStartedWithUppercase) {
                count++;
                wordStartedWithUppercase = false;
            }
        } else if (*p == '\0') { 
            if (wordStartedWithUppercase) {
                count++;
            }
        } else {
            if (isupper(static_cast<unsigned char>(*p))) {
                wordStartedWithUppercase = true;
            } else if (!islower(static_cast<unsigned char>(*p))) {
                wordStartedWithUppercase = false;
            }
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    unsigned int currentLength = 0;

    while (*str) {
        if (!inWord && std::isspace(*str)) {
            str++;
            continue;
        }
        if (*str == ' ' || *str == '\0') {
            totalLength += currentLength;
            wordCount++;
            currentLength = 0;
            inWord = false;
        } else {
            inWord = true;
            currentLength++;
        }
        
        str++;
    }
    
    if (inWord) {
        totalLength += currentLength;
        wordCount++;
    }
    
    double averageLength = static_cast<double>(totalLength) / wordCount;

    unsigned int roundedAverageLength = static_cast<unsigned int>(std::round(averageLength));

    return roundedAverageLength;
}
