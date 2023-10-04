#include <iostream>
#include <string>
#include <vector>

const int MAX_SIZE = 100;

class Crypto {
public:
    virtual std::string encrypt(const std::string &plaintext) = 0;
    virtual std::string decrypt(const std::string &ciphertext) = 0;
};

class ColumnarTranspositionCipher : public Crypto {
private:
    std::string key;

public:
    ColumnarTranspositionCipher(const std::string &key) : key(key) {}

    std::string encrypt(const std::string &text) {
        int keyLength = key.size();
        char matrix[MAX_SIZE][MAX_SIZE] = { { ' ' } };

        int k = 0;
        for (int i = 0; i < (text.size() / keyLength) + 1; ++i) {
            for (int j = 0; j < keyLength && k < text.size(); ++j) {
                matrix[i][j] = text[k++];
            }
        }

        std::string ciphertext;
        for (char k : key) {
            int col = k - '1';
            for (int i = 0; i < (text.size() / keyLength) + 1; ++i) {
                if (matrix[i][col] != ' ') {
                    ciphertext += matrix[i][col];
                }
            }
        }

        return ciphertext;
    }

    std::string decrypt(const std::string &text) {
        int keyLength = key.size();
        char matrix[MAX_SIZE][MAX_SIZE] = { { ' ' } };

        int fullCols = text.size() / keyLength;
        int extraChars = text.size() % keyLength;
    
        int q = 0;
        for (char k : key) {
            int col = k - '1';
            int limit = (col < extraChars) ? fullCols + 1 : fullCols;
            for (int i = 0; i < limit && q < text.size(); ++i) {
                matrix[i][col] = text[q++];
            }
        }
    
        std::string plaintext;
        for (int i = 0; i < fullCols + (extraChars > 0 ? 1 : 0); ++i) {
            for (int j = 0; j < keyLength; ++j) {
                if (matrix[i][j] != ' ') {
                    plaintext += matrix[i][j];
                }
            }
        }
    
        return plaintext;
    }

};

int main() {
    ColumnarTranspositionCipher cipher("4312");
    std::string plaintext = "HELLOWORLD";
    std::string ciphertext = cipher.encrypt(plaintext);

    std::cout << "Ciphertext: " << ciphertext << std::endl;

    std::string decryptedText = cipher.decrypt(ciphertext);
    std::cout << "Decrypted: " << decryptedText << std::endl;

    return 0;
}
