#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Ускорение ввода-вывода
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> result;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        
        // Добавляем имя, только если vector пуст или новое имя отличается от предыдущего
        if (result.empty() || result.back() != name) {
            result.push_back(name);
        }
    }

    // Выводим количество уникальных элементов и сами имена
    cout << result.size() << "\n";
    for (const string& name : result) {
        cout << name << "\n";
    }

    return 0;
}