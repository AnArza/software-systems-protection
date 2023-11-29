#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq, Node *left = nullptr, Node *right = nullptr)
        : ch(ch), freq(freq), left(left), right(right) {}
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void encode(Node* root, std::string str, std::unordered_map<char, std::string> &huffmanCode) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(std::string text) {

    std::unordered_map<char, int> charToFreq;
    for (char ch: text) {
        charToFreq[ch]++;
    }

    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    for (auto pair: charToFreq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); 
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();

    std::unordered_map<char, std::string> huffmanCode;
    encode(root, "", huffmanCode);

    std::cout << "Huffman Codes are :\n" << '\n';
    for (auto pair: huffmanCode) {
        std::cout << pair.first << " " << pair.second << '\n';
    }

    std::cout << "\nOriginal string was :\n" << text << '\n';

    std::string str;
    for (char ch: text) {
        str += huffmanCode[ch];
    }

    std::cout << "\nEncoded string is :\n" << str << '\n';
}

int main() {
    std::string text = "ANI ARZUMANYAN";
    buildHuffmanTree(text);

    return 0;
}
