#include<iostream>
#include<sstream>
#include<string>
#include<regex>
 
int main()
{
        size_t sum{0};
        std::string line;
        while (std::getline(std::cin, line))
        {
                std::string digits = "";
                std::cout << "In: " << line << "\n";
                std::regex digit_regex(R"(\d)");
                for (std::smatch digit_match; std::regex_search(line, digit_match, digit_regex);)
                {
                        digits += digit_match.str();
                        line = digit_match.suffix();
                }
                std::cout << "Match: " << digits << "\n";
                if (digits.size())
                        sum += 10 * (digits[0] - '0') + digits[digits.size() - 1] - '0';
        }
        std::cout << "Sum = " << sum << "\n";
}
