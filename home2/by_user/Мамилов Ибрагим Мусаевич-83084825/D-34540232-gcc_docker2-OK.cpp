#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

struct node {
    std::string name = "";
    std::map<std::string, node*> children;

    node() {}

    node(std::string name) : name(name) {}
};

void dfs(node *curNode, std::string &curDirectory) {
    curDirectory += curNode->name + "/";
    std::cout << curDirectory << '\n';
    for (auto [name, child] : curNode->children)
        dfs(child, curDirectory);
    for (int i = 0; i <= curNode->name.length(); i++)
        curDirectory.pop_back();
}

void addFile(std::string &path, node *curNode) {
    std::string curName = "";
    for (int i = 1; i < path.size(); i++) {
        if (path[i] == '/') {
            if (curNode->children.find(curName) == curNode->children.end())
                curNode->children.insert({curName, new node(curName)});
            curNode = curNode->children[curName];
            curName = "";
        } else {
            curName += path[i];
        }
    }
}

int main() {
    node *root = new node();
    std::string path;
    while (std::cin >> path)
        addFile(path, root);
    path = "";
    dfs(root, path);
    return 0;
}