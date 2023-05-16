#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
struct Dir
{
    map<string, Dir*> subs;
} dirs[50001];
int p = 1;

Dir* addDir(Dir* dir, std::string str)
{
    auto& d = dir->subs[str];
    if (!d)
        d = &dirs[p++];
    return d;
}

void print(Dir* dir, int depth = 0)
{
    for (auto s : dir->subs)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << s.first << "\n";
        print(s.second, depth + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str, dirstr;
        cin >> str;
        stringstream ss(str);
        Dir* dir = &dirs[0];
        while (getline(ss, dirstr, '\\'))
            dir = addDir(dir, dirstr);
    }
    stringstream out;
    print(&dirs[0]);
}