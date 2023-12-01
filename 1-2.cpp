#include<iostream>
#include<unordered_map>
#include<regex>
#include<sstream>
#include<string>
 
int main()
{
        size_t sum{0};
        std::string line;
        std::unordered_map<std::string, char> digit_map{{"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}};
        while (std::getline(std::cin, line))
        {
                std::string digits = "";
                std::cout << "In: " << line << "\n";
                std::regex digit_regex(R"(\d|one|two|three|four|five|six|seven|eight|nine)");
                for (std::smatch digit_match; std::regex_search(line, digit_match, digit_regex);)
                {
                        const std::string & match = digit_match.str();
                        if (digit_map.find(match) != digit_map.end()) // Key found
                                digits += digit_map[match];
                        else
                                digits += match;
                        line = line.substr(1);
                }
                std::cout << "Match: " << digits << "\n";
                if (digits.size())
                        sum += 10 * (digits[0] - '0') + digits[digits.size() - 1] - '0';
        }
        std::cout << "Sum = " << sum << "\n";
}
