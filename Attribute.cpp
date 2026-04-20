#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore(); // Consume the newline after n and q

    map<string, string> hrml_map;
    vector<string> tag_stack;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        if (line.substr(0, 2) == "</") {
            // Closing tag
            tag_stack.pop_back();
        } else {
            // Opening tag: Remove brackets
            line.erase(remove(line.begin(), line.end(), '<'), line.end());
            line.erase(remove(line.begin(), line.end(), '>'), line.end());
            
            stringstream ss(line);
            string tag, attr, eq, val;
            ss >> tag;
            tag_stack.push_back(tag);

            // Create path prefix: tag1.tag2
            string path = "";
            for (const auto& t : tag_stack) {
                path += (path.empty() ? "" : ".") + t;
            }

            // Parse attributes: attr = "value"
            while (ss >> attr >> eq >> val) {
                // Remove quotes from value
                val.erase(remove(val.begin(), val.end(), '\"'), val.end());
                hrml_map[path + "~" + attr] = val;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        string query;
        getline(cin, query);
        if (hrml_map.count(query)) {
            cout << hrml_map[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
