#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "   Hello   World            Im Akash     ";
    s += " ";
    int n = s.length();
    vector<string> myVec;
    string temp = "";
    int i = 0;

    while (i <= n - 1)
    {
        if (s[i] == ' ')
        {
            if (temp != "")
                myVec.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
        i++;
    }

    for (auto it : myVec)
    {
        cout << it << " ";
    }
}