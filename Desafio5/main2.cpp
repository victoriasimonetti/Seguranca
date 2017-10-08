#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "cryptlib.h"
using CryptoPP::Exception;

#include "hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "aes.h"
using CryptoPP::AES;

#include "modes.h"
using CryptoPP::ECB_Mode;


int main(int argc, char* argv[]){

	byte key[AES::DEFAULT_KEYLENGTH];
    string key_s = "essasenhaehfraca";

    for (int i = 0; i < key_s.size(); i++)
        key[i] = (byte) key_s[i];

    string ciphertext = "A506A19333F306AC2C62CBE931963AE7DFCFFA940360A40FFD5DC69B9C2E53AD";
    string decryptedtext;

    try
    {
        ECB_Mode< AES >::Decryption decryptor;
        decryptor.SetKey(key, sizeof(key));
        CryptoPP::StringSource ss(ciphertext, true,
            new CryptoPP::HexDecoder(
                new CryptoPP::StreamTransformationFilter( decryptor,
                    new CryptoPP::StringSink( decryptedtext ) ) ) );
        cout << "Texto claro: " << decryptedtext << endl;
    }
    catch(const CryptoPP::Exception& e)
    {
        cerr << e.what() << endl;
        system("pause");
        exit(1);
    }


              
	return 0;
}

