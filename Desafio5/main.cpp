#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;
using std::to_string;

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

bool isAsc(string &decryptedtext){

    for(int i=0; i< decryptedtext.size(); i++){
        if(decryptedtext[i] < 32){
            return false;
        }         
    }
    return true;
}

// desafio, proximo, texto
bool temPalavra(string p1, string p2, string p3, string texto){

    std::size_t found = texto.find(p1);
    if (found!=std::string::npos){
        cout << "verificando desafio..." << endl;
        return true;
    }

    found = texto.find(p2);
    if (found!=std::string::npos){
        cout << "verificando proximo..." << endl;
        return true;
    }

    found = texto.find(p3);
    if (found!=std::string::npos){
        cout << "verificando texto..." << endl;
        return true;
    }

   //cout << "Não achei nenhuma palavra!" << endl << endl;
    return false;

}


string teste(string &key_s) {
    string decryptedtext;
    byte key[16];
    for (int i = 0; i < key_s.size(); i++)
        key[i] = (byte) key_s[i];

   string ciphertext = "83D0FA6F5B690E57C0F090573F473CD4\n58862A9C23AF0F3C3B91D05A3E3CC9F7\n24AE443EA022EFBB4FBC4E513304C3A3\n13D7F041E4CB5102C987633DA40B3DF1\nEC1A904DC0B26D8644B2C9FED8C0B85C\n86EE4557F03BC893E281720978512D8F\nFDFB2E1B79AC1F52F5EDE15F72249D03\nBE8557A5DF715E29E78CF743C038EFE1\n51E091DC80225AE86E0D8E54F48C9624\nF5889CB3852D83547E4848E78EB26A42\n9C631FA9BA6371D2BD1B7EA4BF950F91\nC16E524554F4C4EE389E75B4E42310F5\n6519D432C302D7D7A3BA2688E0B1E257\n4868ECF9DB0240105B1847433FA9B6B2\n7E48958CF0473FB9E1AB2F078B30F8C9\n83DA8AC47ECB828BBADCD1ED410198C3\n131D23D3951B15F85737C65D1B775F4D\nCD6709D461A58CA250A69075E722C225\nE2B826CC5F8F1B6C65ABE2B52915C9BB\n839B2153DC38959B8E96483969921220\n1C73D26D6ED4F104B63470F271C4AA9D";
   //string ciphertext = "A506A19333F306AC2C62CBE931963AE7";
   ECB_Mode< AES >::Decryption decryptor;
                            decryptor.SetKey(key, sizeof(key));
                            CryptoPP::StringSource ss(ciphertext, true,
                                new CryptoPP::HexDecoder(
                                    new CryptoPP::StreamTransformationFilter( decryptor,
                                        new CryptoPP::StringSink( decryptedtext ), StreamTransformationFilter::NO_PADDING) ) );

    return decryptedtext;
}



int main(int argc, char* argv[]){

	byte key[16];
    string key_s = "Key2Group05XXXXX";

    for (int i = 0; i < key_s.size(); i++)
        key[i] = (byte) key_s[i];

    string decryptedtext;
    string texto_claro;


    for(int a=33; a<=126; a++){
        for(int b=33; b<=126; b++){
            cout << "Processando: " << a << "/126 " << b << "/126" << endl;
            for(int c=33; c<=126; c++){
                for(int d=33; d<=126; d++){
                    for(int e=33; e<=126; e++){
                        try{
                       
                            key_s = "Key2Group05";
                            key_s += (char)a;
                            key_s += (char)b;
                            key_s += (char)c;
                            key_s += (char)d;
                            key_s += (char)e;                                                     

                            decryptedtext =  teste(key_s);

                           int flag = 0;

                            if(isAsc(decryptedtext) == true){
                                flag = 1;  
                                cout << "só tem asc..." << endl;
                                cout << "Texto claro: " << decryptedtext << endl;  
                            }                            

                            if(flag == 1){
                                if(temPalavra("desafio", "proximo", "sexto", decryptedtext)==true){
                                    cout << "acheii" << endl;
                                    cout << "Texto claro: " << decryptedtext << endl;
                                    return 0;
                                }                     
                            }

                           

                           
	                    }
	                    catch(const CryptoPP::Exception& e){
		                    cerr << e.what() << endl;
		                    exit(1);
	                    }

                    }
            
                }
            
            }

        }


    }   
	return 0;
}

