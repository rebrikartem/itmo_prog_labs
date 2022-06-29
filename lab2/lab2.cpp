#include <chrono>
#include <thread>
#include <map>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "classes.h"

using namespace std;
using namespace nlohmann;

std::function<void(int)> shutdown_handler;

void handler(int s)
{
    shutdown_handler(s);
}

int main()
{
    DataLoader data_loader;
    ValutesStorage storage;
    ValutesParser parser;

    signal(SIGINT, handler);
    shutdown_handler = [&](int signal)
    {
        cout << endl;
        cout << storage << endl;
        exit(0);
    };

    while (true)
    {
        string url = "https://www.cbr-xml-daily.ru/daily_json.js";
        string response;

        if (data_loader.get_json(url, response) == -1)
        {
            cout << "Error ";
            return -1;
        }

        cout << "Current values: " << endl;
        cout << response << endl;
        cout << endl;

        auto valutes = parser.parse(response);

        storage.save_data(valutes);

        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }

    return 0;
}