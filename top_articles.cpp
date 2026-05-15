#include <bits/stdc++.h>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

vector<string> topArticles(int limit) {
    vector<pair<string, int>> articles;

    int page = 1;
    int total_pages = 1;

    while (page <= total_pages) {
        string url = "https://jsonmock.hackerrank.com/api/articles?page=" + to_string(page);

        auto response = cpr::Get(cpr::Url{url});
        json data = json::parse(response.text);

        total_pages = data["total_pages"];

        for (auto &item : data["data"]) {

            string name = "";

            if (!item["title"].is_null()) {

                name = item["title"];
            } else if (!item["story_title"].is_null()) {
                name = item["story_title"];
            } else {
                continue;
            }

            int comments = 0;

            if (!item["num_comments"].is_null()) {
                comments = item["num_comments"];
            }
            articles.push_back({name, comments});
        }
        page++;
    }
    sort(articles.begin(), articles.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
            return a.second > b.second;
            return a.first > b.first;
            });
    vector<string> result;
    for (int i = 0; i < min(limit, (int)articles.size()); i++) {
        result.push_back(articles[i].first);
    }
    return result;
}
