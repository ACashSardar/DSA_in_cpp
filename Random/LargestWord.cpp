#include <bits/stdc++.h>
using namespace std;

// Find the longest word from the string
int main()
{
    string mystr = "Hello Guys, My name is Akash Sardar";
    int n = mystr.length();
    int maxlen = 0;
    int curlen = 0;
    vector<string> ans;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (mystr[i] == ' ' or i == n - 1)
        {
            ans.push_back(mystr.substr(start, curlen + 1));
            start = i;
        }
        if (mystr[i] == ' ')
        {
            curlen = 0;
        }

        if (maxlen < curlen)
            maxlen = curlen;
        curlen++;
    }
    cout << maxlen << endl;
    for (auto it : ans)
        cout << it << endl;

    return maxlen;
}