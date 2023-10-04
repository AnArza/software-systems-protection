#include <iostream>
#include <string>

class Crypto {
public:
    virtual std::string encrypt(std::string plaintext) = 0;
    virtual std::string decrypt(std::string ciphertext) = 0;
};

class SubstitutionCipher : public Crypto {
private:
    std::string _key;

public:
    SubstitutionCipher(std::string key) : _key{key} {}

    std::string encrypt(std::string plaintext) override {
        std::string ciphertext = plaintext;
        for (char& c : ciphertext) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = isupper(c) ? toupper(_key[c - base]) : tolower(_key[c - base]);
            }
        }
        return ciphertext;
    }

    std::string decrypt(std::string ciphertext) override {
        return encrypt(ciphertext);
    }
};

int main() {
    SubstitutionCipher symmetricCipher("ZYXWVUTSRQPONMLKJIHGFEDCBA");
    std::string plainText = "Hello, World!";
    std::string cipherText = symmetricCipher.encrypt(plainText);
    std::string decodedtText = symmetricCipher.encrypt(cipherText);
    std::cout << "Plaintext: " << plainText << std::endl;
    std::cout << "Ciphertext: " << cipherText << std::endl;
    std::cout << "Decoded text: " << decodedtText << std::endl;

    return 0;
}
