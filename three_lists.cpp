#include <iostream>
#include <unordered_set>
#include <list>

class ThreeAsOne {
public:
    ThreeAsOne(std::list<int>& first_list, std::list<int>& second_list, 
        std::list<int>& third_list);
    
    int GetNext();
private:
    std::list<int>::iterator first, second, third;
    std::list<int>::iterator first_end, second_end, third_end;

    int ReturnValue(std::list<int>::iterator & first, std::list<int>::iterator& first_end, std::list<int>::iterator& second, std::list<int>::iterator& second_end);
};

int ThreeAsOne::ReturnValue(std::list<int>::iterator& curr_first, std::list<int>::iterator& curr_first_end, std::list<int>::iterator& curr_second, std::list<int>::iterator& curr_second_end) {
    if (curr_first == curr_first_end) {
        if (curr_second == curr_second_end) {
            throw std::runtime_error("The values are over");
        }
        else return *curr_second++;
    }
    else if (curr_second == curr_second_end) {
        return *curr_first++;
    }
    
    return *curr_first < *curr_second ? *curr_first++ : *curr_second++;
}

int ThreeAsOne::GetNext() {
    if (first == first_end) {
        return ReturnValue(second, second_end, third, third_end);
    }
    if (second == second_end) {
        return ReturnValue(first, first_end, third, third_end);
    }

    if (*first < *second) {
        return ReturnValue(first, first_end, third, third_end);
    }
    else {
        return ReturnValue(second, second_end, third, third_end);
    }
}

ThreeAsOne::ThreeAsOne(std::list<int>& first, std::list<int>& second, std::list<int>& third)
    : first(first.begin()), second(second.begin()), third(third.begin()),
        first_end(first.end()), second_end(second.end()), third_end(third.end()) {}

int main()
{
    setlocale(0, "");
    
    std::cout << "*Пример из задания*" << std::endl;
    
    std::list<int> first_1 = {1, 8, 15, 16, 35};
    std::list<int> second_1 = {2, 7, 12, 40};
    std::list<int> third_1 = {10, 13, 14};
    
    ThreeAsOne example_1(first_1, second_1, third_1);

    try {
        for (size_t i = 0; i < first_1.size() + second_1.size() + third_1.size(); ++i) {
            std::cout << example_1.GetNext() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "*Крайний случай - один из контейнеров пустой*" << std::endl;

    std::list<int> first_2;
    std::list<int> second_2 = { 2, 7, 12, 40 };
    std::list<int> third_2 = { 10, 13, 14 };

    ThreeAsOne test_2(first_2, second_2, third_2);

    try {
        for (size_t i = 0; i < first_2.size() + second_2.size() + third_2.size(); ++i) {
            std::cout << test_2.GetNext() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "*Крайний случай - все контейнеры пусты*" << std::endl;

    std::list<int> first_3;
    std::list<int> second_3;
    std::list<int> third_3;

    ThreeAsOne test_3(first_3, second_3, third_3);

    try {
        std::cout << test_3.GetNext() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "*Вызов, когда элеметнты уже все перебраны*" << std::endl;
    try {
        test_2.GetNext();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}