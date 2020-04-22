# autokey-cipher
#
# The Autokey Cipher is a polyalphabetic substitution cipher. It is closely related to the Vigenere cipher, 
# but uses a different method of generating the key. It was invented by Blaise de Vigenère in 1586, and is 
# in general more secure than the Vigenere cipher.
# CREDIT TO http://practicalcryptography.com/ FOR THE SOURCE INFORMATION
#
# I've based my implementation directly off the format presented on their website.
###########################################################################################################
# To use this implementation:
#
# to create a single instance of the cipher, 
# where the first argument is the key and the second is the plaintext:

Autokey("hello").encipher("defend the east wall of the castle");

# To create a new cipher object use the following constructor/functions:

Autokey a;
a.setKey("fortification");
std::cout << "Key: " << a.getKey() << "\n";
a.encipher("defend the east wall of the castle");
a.decipher("iswxvibje");
