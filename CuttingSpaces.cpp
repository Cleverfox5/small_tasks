#include <iostream>

void TrimRight(char* s) {
    size_t last_letter = 0, i = 0;
    
    for (; s[i]; ++i) {
        if (s[i] != ' ') {
            last_letter = i;
        }
    }

    if (i) {
        if (last_letter == 0 && s[last_letter] == ' ') {
            s[0] = '\0';
        }
        s[last_letter + 1] = '\0';
    }
}

int main()
{
    setlocale(0, "");

    std::cout << "*Пример работы*" << std::endl;
    char s_1[] = "Ура, строка   ";
    std::cout << "\"" << s_1 << "\"" << std::endl;
    TrimRight(s_1);
    std::cout << "\"" << s_1 << "\"" << std::endl;
    std::cout << std::endl;

    std::cout << "*Крайний случай - одни проблел*" << std::endl;
    char s_2[] = "      ";
    std::cout << "\"" << s_2 << "\"" << std::endl;
    TrimRight(s_2);
    std::cout << "\"" << s_2 << "\"" << std::endl;
    std::cout << std::endl;

    std::cout << "*Крайний случай - пустая строка*" << std::endl;
    char s_3[] = "";
    std::cout << "\"" << s_3 << "\"" << std::endl;
    TrimRight(s_3);
    std::cout << "\"" << s_3 << "\"" << std::endl;
    std::cout << std::endl;

    std::cout << "*Карйний случай - символ и пробел*" << std::endl;
    char s_4[] = "т ";
    std::cout << "\"" << s_4 << "\"" << std::endl;
    TrimRight(s_4);
    std::cout << "\"" << s_4 << "\"" << std::endl;
    std::cout << std::endl;

    std::cout << "*Карйний случай - последний символ не пробел*" << std::endl;
    char s_5[] = "тут последний символ не пробел.";
    std::cout << "\"" << s_5 << "\"" << std::endl;
    TrimRight(s_5);
    std::cout << "\"" << s_5 << "\"" << std::endl;
    std::cout << std::endl;

    return 0;
}