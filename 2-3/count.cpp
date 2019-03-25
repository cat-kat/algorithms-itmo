#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> suf;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.first == b.second.first) {
        if (a.second.second < b.second.second) {
            return true;
        }
        return false;
    }
    if (a.second.first < b.second.first) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    //   ifstream fin();
    //   ofstream fout();
    string s;
    cin >> s;
    suf.resize(s.length());
    vector<int> lcp;
    vector<int> inv_ans;
    for (int i = 0; i < s.length(); i++) {
        suf[i].second.first = s[i] - 'a';
        suf[i].second.second = s[i + 1] - 'a';
        suf[i].first = i;
    }
    suf[s.length() - 1].second.second = -1;
    sort(suf.begin(), suf.end(), comp);
    vector<int> cycling;
    cycling.resize(s.length());
    for (int k = 2; k < 2 * s.length(); k = k * 2) {
        int rank = 0;
        int pr_letter = suf[0].second.first;
        suf[0].second.first = rank;
        cycling[suf[0].first] = 0;
        for (int i = 1; i < s.length(); i++) {
            if (suf[i].second.first == pr_letter && suf[i].second.second == suf[i - 1].second.second) {
                pr_letter = suf[i].second.first;
                suf[i].second.first = rank;
            } else {
                pr_letter = suf[i].second.first;
                suf[i].second.first = ++rank;
            }
            cycling[suf[i].first] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            int nextcycling = suf[i].first + k / 2;
            suf[i].second.second = -1;
            if (nextcycling < s.length()) {
                suf[i].second.second = suf[cycling[nextcycling]].second.first;
            }
        }
        sort(suf.begin(), suf.end(), comp);
    }

    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
        ans.push_back(suf[i].first);


    inv_ans.resize(s.length());
    lcp.resize(s.length());
    for (int i = 0; i < s.length(); i++)
        inv_ans[ans[i]] = i;
    int k = 0;
    for (int i = 0; i < s.length(); i++) {
        if (k > 0) {
            k--;
        }
        if (inv_ans[i] == s.length() - 1) {
            k = 0;
            continue;
        }
        while ((i + k < s.length()) && (ans[inv_ans[i] + 1] + k < s.length()) &&
               (s[i + k] == s[ans[inv_ans[i] + 1] + k])) {
            k++;
        }
        lcp[inv_ans[i]] = k;
    }
    long long answer = 0, answer_ = 0;
    for (int i = 0; i < s.length(); i++) {
        answer += (s.length() - ans[i]);
        if (i != (s.length() - 1)) {
            answer_ += lcp[i];
        }
    }
    cout << answer - answer_;
}
close
