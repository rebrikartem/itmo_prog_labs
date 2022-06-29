#include "classes.h"

int DataLoader::writer(char *data, size_t size, size_t nmemb, std::string *response)
{
    int result = 0;

    if (response != NULL)
    {
        response->append(data, size * nmemb);

        result = size * nmemb;
    }

    return result;
}

int DataLoader::get_json(string url, string &response)
{
    CURL *curl = curl_easy_init();
    CURLcode result;
    char errorBuffer[CURL_ERROR_SIZE];

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        curl_easy_setopt(curl, CURLOPT_WRITEHEADER, 0);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        result = curl_easy_perform(curl);

        if (result != CURLE_OK)
        {
            std::cout << "Error! " << errorBuffer << std::endl;
            return -1;
        }

        curl_easy_cleanup(curl);

        return 0;
    }

    return -1;
}

void to_json(json &j, const Valute &v)
{
    j = json{{"CharCode", v.charcode}, {"Name", v.name}, {"Value", v.value}};
}

void from_json(const json &j, Valute &p)
{
    j.at("CharCode").get_to(p.charcode);
    j.at("Name").get_to(p.name);
    j.at("Value").get_to(p.value);
}

map<string, Valute> ValutesParser::parse(string &response)
{
    json my_json = json::parse(response);
    auto &vals = my_json["Valute"];
    map<string, Valute> answer;

    for (auto &v : vals)
    {
        Valute valute = v.get<Valute>();

        answer[valute.charcode] = valute;
    }

    return answer;
}

double ValutesCalculator::calculate_avg(vector<double> values)
{
    double sum = 0;
    for (int i = 0; i < values.size(); i++)
    {
        sum += values[i];
    }
    return sum / values.size();
}

double ValutesCalculator::calculate_median(vector<double> values)
{
    int size = values.size();

    if (size % 2 == 0)
    {
        return (values.at((int)size / 2) + values.at((int)size / 2 - 1)) / 2;
    }
    else
    {
        return values.at(int(size / 2));
    }
}

ValutesStorage::~ValutesStorage()
{
    delete _valutes;
}

ValutesStorage::ValutesStorage()
{
    _valutes = new map<string, vector<double>>();
}

ostream &operator<<(ostream &os, ValutesStorage &rhs)
{
    ValutesCalculator calc;

    for (auto &[key, values] : *rhs._valutes)
    {
        os << key << " " << calc.calculate_avg(values) << " " << calc.calculate_median(values) << endl;
    }

    return os;
}

void ValutesStorage::save_data(map<string, Valute> &valutes)
{
    for (auto &[_key, valute] : valutes)
    {
        string key = valute.charcode + " " + valute.name;
        double value = valute.value;
        vector<double> &vector_of_values = (*_valutes)[key];

        if (vector_of_values.size() == 0)
        {
            vector_of_values.push_back(value);
        }
        else
        {
            vector_of_values.push_back(value);
            for (int i = vector_of_values.size() - 1; i > 0; i--)
            {
                if (vector_of_values.at(i - 1) <= vector_of_values.at(i))
                {
                    break;
                }
                else
                {
                    double tmp = vector_of_values.at(i);
                    vector_of_values.at(i) = vector_of_values.at(i - 1);
                    vector_of_values.at(i - 1) = tmp;
                }
            }
        }
    }
}
