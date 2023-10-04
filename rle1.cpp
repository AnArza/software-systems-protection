#include <iostream>
#include <string>
#include <vector>

class Crypto {
public:
    virtual std::string encrypt(std::string plaintext) = 0;
    virtual std::string decrypt(std::string ciphertext) = 0;
};

class RLE1Crypto : public Crypto {
public:
    std::string encrypt(std::string plaintext) override {
        std::string encodedData;

        int length = plaintext.length();

        for (int i = 0; i < length; i++) {
            int count = 1;
            
            while (i < length - 1 && plaintext[i] == plaintext[i+1]) {
                count++;
                i++;
            }

            encodedData += plaintext[i];
            encodedData += std::to_string(count);
        }

        return encodedData;
    }

    std::string decrypt(std::string ciphertext) override {
        std::string decodedData;
        int length = ciphertext.length();

        for (int i = 0; i < length; i+=2) { 
            char character = ciphertext[i];
            int count = ciphertext[i+1] - '0';

            for (int j = 0; j < count; j++) {
                decodedData += character;
            }
        }

        return decodedData;
    }
};

int main() {
    RLE1Crypto rleCrypto;
    std::string input;
    std::cout << "Enter string to encrypt: ";
    std::cin >> input;

    std::string encrypted = rleCrypto.encrypt(input);
    std::cout << "Encrypted data: " << encrypted << std::endl;

    std::string decrypted = rleCrypto.decrypt(encrypted);
    std::cout << "Decrypted data: " << decrypted << std::endl;

    return 0;
}
