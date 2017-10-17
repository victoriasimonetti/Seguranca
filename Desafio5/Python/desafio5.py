#coding: utf-8
from Crypto.Cipher import AES

import threading
import time
import codecs
import re
import sys

def isAscii(text):
	try:
		codecs.decode(text, "utf-8")
	except UnicodeDecodeError:
		return False
	else:
		return codecs.decode(text, "utf-8")
		
def decText(key, cyphertext):
	obj = AES.new(key, AES.MODE_ECB)
	res = obj.decrypt(codecs.decode(cyphertext, 'hex_codec'))
	#if res:
	#	print ("É ASC - Chave: " + codecs.decode(key, "utf-8") + "\n")  
	#	print ("Texto que só tem asc:S " + cyphertext)
	to_find = re.compile("criptografia|sexto|desafio")
	if to_find.search(res):
		print ("Achou! Chave: " + codecs.decode(key, "utf-8") + "\n") 
		print ("Texto claro: " + cyphertext)

def main():

	r1 = int(sys.argv[1])
	r2 = int(sys.argv[2]) 

	print("Decodificando intervalo",r1,r2)
	cyphertext = b'83D0FA6F5B690E57C0F090573F473CD458862A9C23AF0F3C3B91D05A3E3CC9F724AE443EA022EFBB4FBC4E513304C3A313D7F041E4CB5102C987633DA40B3DF1EC1A904DC0B26D8644B2C9FED8C0B85C86EE4557F03BC893E281720978512D8FFDFB2E1B79AC1F52F5EDE15F72249D03BE8557A5DF715E29E78CF743C038EFE151E091DC80225AE86E0D8E54F48C9624F5889CB3852D83547E4848E78EB26A429C631FA9BA6371D2BD1B7EA4BF950F91C16E524554F4C4EE389E75B4E42310F56519D432C302D7D7A3BA2688E0B1E2574868ECF9DB0240105B1847433FA9B6B27E48958CF0473FB9E1AB2F078B30F8C983DA8AC47ECB828BBADCD1ED410198C3131D23D3951B15F85737C65D1B775F4DCD6709D461A58CA250A69075E722C225E2B826CC5F8F1B6C65ABE2B52915C9BB839B2153DC38959B8E964839699212201C73D26D6ED4F104B63470F271C4AA9D'

	for a in range(r1, r2):
		print (str(a) + "/126")
		for b in range(126, 32, -1):
			for c in range(126, 32, -1):
				for d in range(126, 32, -1):
					for e in range(126, 32, -1):
						key_string = "Key2Group05" + chr(a) + chr(b) + chr(c) + chr(d) + chr(e)
						key = codecs.encode(key_string, "utf-8")
						decText(key, cyphertext)

main()
