#include <iostream>
#include <string>

int main() {
    wchar_t c = L'ї';
    std::wcout << "size of wcchar_t: " << sizeof(char) << " " << sizeof(c) << " " << c << std::endl;
    std::cout << "Upward Triangle: ▲" << std::endl;
    std::cout << "Downward Triangle: ▼" << std::endl;
    std::cout << "Leftward Triangle: ◀" << std::endl;
    std::cout << "Rightward Triangle: ▶" << std::endl;

    std::cout << "Upward Triangle: \u25B2" << std::endl;
    std::cout << "Downward Triangle: \u25BC" << std::endl;
    std::cout << "Leftward Triangle: \u25C0" << std::endl;
    std::cout << "Rightward Triangle: \u25B6" << std::endl;

    return 0;
}
