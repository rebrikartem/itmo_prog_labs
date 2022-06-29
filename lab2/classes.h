#pragma once

#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <string>

using namespace std;
using namespace nlohmann;

class DataLoader
{
private:
    static int writer(char *data, size_t size, size_t nmemb, std::string *response);
public:
    int get_json(string url, string &response);
};

struct Valute
{
    string charcode;
    string name;
    double value;
};

void to_json(json &j, const Valute &v);

void from_json(const json &j, Valute &p);

class ValutesParser
{
public:
    map<string, Valute> parse(string &response);
};

class ValutesCalculator {
public:
    double calculate_avg(vector<double> values);

    double calculate_median(vector<double> values);
};

class ValutesStorage
{
private:
    map<string, vector<double>> *_valutes;

public:
    ~ValutesStorage();

    ValutesStorage();

    friend ostream &operator<<(ostream &os, ValutesStorage &rhs);

    void save_data(map<string, Valute> &valutes);
};