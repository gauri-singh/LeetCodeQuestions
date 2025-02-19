struct Node {
    public:
    map<std::string, Node*> dir;
    string content = "";
};

class FileSystem {
    Node root;
public:
    FileSystem() {
    }
    
    vector<string> ls(string path) {
        vector<string> result;
        Node* pathNode = getNode(path);
        
        if (!pathNode->content.empty() && pathNode->content != "") {
            return {path.substr(path.find_last_of('/') + 1)};
        }
        for (auto const& [name, node] : pathNode->dir) {
            result.push_back(name);
        }
        return result;
    }
    
    void mkdir(string path) {
        getNode(path);
    }
    
    void addContentToFile(string filePath, string content) {
        auto node = getNode(filePath);
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto node = getNode(filePath);
        return node->content;
    }
    
    Node* getNode(std::string path) {
        stringstream ss(path);
        string currentPath = "";
        Node *currentNode = &root;
        while(getline(ss, currentPath, '/')) {
            if (!(currentNode->dir).count(currentPath)) {
                currentNode->dir[currentPath] = new Node();
            }
            currentNode = currentNode->dir[currentPath];
        }
        return currentNode;
    }
};