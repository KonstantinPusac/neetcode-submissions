#include <iostream>
#include <vector>
#include <string>
#include <charconv>
#include <cctype>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string msgs = "";
        //  Helper vars
        int strs_len = strs.size();

        //  Adding elements to message
        for (int i = 0; i < strs_len; i++)
        {
            string tmp = to_string(strs[i].length());
            msgs += tmp + "#" + strs[i];
        }
        return msgs;
    }

    string extractWord(string s, int counter, int len)
    {
        string ret = "";
        for(int i = counter + 2; i < (counter + 2 + len); i++)
        {
            ret += s[i];
        }

        return ret;
    }

    int vec_to_int(vector<char> num_vec)
    {
        string tmp = "";
        for (int i = 0; i < num_vec.size(); i++)
        {
            tmp += num_vec[i];
        }

        int num = stoi(tmp);
        return num;
    }

    vector<string> decode(string s) {
        vector<string> msg_dec = {};

        if (!isdigit(s[0]))
            return msg_dec;

        int counter = 0;
        int num = 0;
        vector<char> num_vec = {};
        while (counter < s.size())
        {
            num_vec.push_back(s[counter]);
            if(s[counter+1] == '#')
            {
                int len = vec_to_int(num_vec);
                string str = extractWord(s, counter, len);
                msg_dec.push_back(str);
                counter += len + 2;

                num_vec.clear();
            }
            else if (isdigit(s[counter+1]))
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        
        return msg_dec;
    }
};