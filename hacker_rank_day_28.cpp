#include <bits/stdc++.h>
#include <regex>
#include <map>
using namespace std;

vector<string> split_string(string);

void verify_the_input_and_print(multimap<string, string> record)
{
    auto it = record.begin();
    while(it != record.end())
    {
        if (std::regex_match (it->first, std::regex("[a-z]+")))
        {
            if(std::regex_match (it->second, std::regex(".+@gmail\\.com$")))
            {
                it++;
                continue;
            }
            else
            {
                record.erase(it++);
            }
        }
        else
        {
            record.erase(it++);
        }
    }

    auto it1 = record.begin();
    while(it1 != record.end())
    {
        cout<< it1->first << endl;
        it1++;
    }
}

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    multimap<string, string> record;
    for (int N_itr = 0; N_itr < N; N_itr++) {
        string firstNameEmailID_temp;
        getline(cin, firstNameEmailID_temp);

        vector<string> firstNameEmailID = split_string(firstNameEmailID_temp);

        string firstName = firstNameEmailID[0];

        string emailID = firstNameEmailID[1];
        
        record.insert(pair<string,string>(firstName,emailID));
    }
    verify_the_input_and_print(record);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
