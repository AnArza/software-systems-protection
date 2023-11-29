#include <iostream>
#include <string>

std::string extendKey(const std::string& text, const std::string& key) {
    std::string longKey;
    size_t keyIndex = 0;

    for (size_t i = 0; i < text.length(); ++i) {
        longKey += key[keyIndex];
        keyIndex = (keyIndex + 1) % key.length();
    }

    return longKey;
}

std::string vigenereEncode(const std::string& text, const std::string& key) {
    std::string result;
    std::string longKey = extendKey(text, key);

    for (size_t i = 0; i < text.length(); ++i) {
        result += static_cast<char>((static_cast<unsigned char>(text[i]) + static_cast<unsigned char>(longKey[i])) % 256);
    }

    return result;
}

std::string vigenereDecode(const std::string& encodedText, const std::string& key) {
    std::string result;
    std::string longKey = extendKey(encodedText, key);

    for (size_t i = 0; i < encodedText.length(); ++i) {
        result += static_cast<char>((256 + static_cast<unsigned char>(encodedText[i]) - static_cast<unsigned char>(longKey[i])) % 256);
    }

    return result;
}

int main() {
    std::string text, key;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);
    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    std::string encodedText = vigenereEncode(text, key);
    std::cout << "Encoded Text: " << encodedText << std::endl;

    std::string decodedText = vigenereDecode(encodedText, key);
    std::cout << "Decoded Text: " << decodedText << std::endl;

    return 0;
}
