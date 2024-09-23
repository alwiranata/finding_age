#include <iostream>
#include <chrono>
#include <ctime>
#include <limits>

using namespace std;

void log(int result)
{
    cout << "Your current age is " << result << endl;
}

void category(int result)
{
    if (result <= 10)
    {
        cout << "You're still a kid" << endl;
    }
    else if (result > 10 && result <= 30)
    {
        cout << "You're a teenager" << endl;
    }
    else
    {
        cout << "You are an adult" << endl;
    }
}

int main()
{
    int birth_year{};
    cout << "Enter your birth year: ";
    cin >> birth_year;

    // Validate input
    if (cin.fail() || birth_year < 1900 || birth_year > 2100)
    {
        cout << "Invalid input. Please enter a valid year." << endl;
        return 1;
    }

    // Get the current year
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm *local_time = localtime(&now_time);

    // Get current year as an integer
    int current_year = local_time->tm_year + 1900;

    // Display the current year
    cout << "The current year is: " << current_year << endl;

    // Calculate age
    int age = current_year - birth_year;

    // Display age
    log(age);

    // Category
    category(age);

    return 0;
}
