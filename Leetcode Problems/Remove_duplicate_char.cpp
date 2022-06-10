/* Given a string s, remove duplicate letters so that every letter appears once and only once.
 You must make sure your result is the smallest in lexicographical order among all possible results.
 https://leetcode.com/problems/remove-duplicate-letters/  */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int freqMap[26] = {0};
    int visited[26] = {0};
    string s = "cbacdcbc";
    int n = s.length();
    vector<char> ds;

    for (int i = 0; i < n; i++)
    {
        freqMap[s[i] - 'a'] += 1;
    }

    for (int i = 0; i < n; i++)
    {
        freqMap[s[i] - 'a']--;

        if (visited[s[i] - 'a'])
            continue;

        while (ds.size() > 0 and ds.back() > s[i] and freqMap[ds.back() - 'a'] > 0)
        {
            visited[ds.back() - 'a'] = 0;
            ds.pop_back();
        }

        ds.push_back(s[i]);
        visited[s[i] - 'a'] = 1;
    }

    cout << endl;

    for (auto it : ds)
    {
        cout << it << " ";
    }

    return 0;
}