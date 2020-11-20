#include <map>
using std::map;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;
using std::getline;

#include <stdexcept>
using std::runtime_error;

map<string, string> build_map(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it == m.end())
        return s;
    else
        return map_it->second;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = build_map(map_file);
    
    cout << "Here is our transformation map:\n\n";
    for (auto entry : trans_map)
        cout << "key:" << entry.first << "\tvalue:" << entry.second << endl;
    cout << "\n\n";

    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main(int agrc, char **argv)
{
    if (agrc != 3)
        throw runtime_error("wrong number of arguments");

    ifstream map_file(argv[1]);
    if (!map_file)
        throw runtime_error("no transformation file");
    
    ifstream input(argv[2]);
    if (!input)
        throw runtime_error("no input file");
    
    word_transform(map_file, input);

    return 0;
}