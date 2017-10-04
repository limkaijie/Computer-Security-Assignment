#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include "timer.h"

using namespace std;

const int a = 5;
const int b = 4;

string encryptAffine(string msg)
{
    ///Cipher Text initially empty
	string cipher = "";
	for (int i = 0; i < msg.length(); i++)
	{
		// Avoid space to be encrypted
		if(msg[i]!=' ')
			/* applying encryption formula ( a x + b ) mod m
			{here x is msg[i] and m is 26} and added 'A' to
			bring it in range of ascii alphabet[ 65-90 | A-Z ] */
			cipher = cipher + (char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
		else
			//else simply append space character
			cipher += msg[i];
	}
	return cipher;
}

string encryptCaesar(string msg, int key)
{
	string cipher = "";
	for (int i = 0; i < msg.length(); i++)
	{
		if(msg[i]!=' ')
			cipher = cipher + (char) ((((msg[i]-'A') + key) % 26) + 'A');
		else
			cipher += msg[i];
	}
	return cipher;
}

string decryptAffine(string cipher)
{
	string msg = "";
	int a_inv = 0;
	int flag = 0;

	//Find a^-1 (the multiplicative inverse of a in the group of integers modulo m.)
	for (int i = 0; i < 26; i++)
	{
		flag = (a * i) % 26;

		//Check if (a*i)%26 == 1 ,then i will be the multiplicative inverse of a
		if (flag == 1)
		{
			a_inv = i;
		}
	}
	for (int i = 0; i < cipher.length(); i++)
	{
		if(cipher[i]!=' ')
			/*Applying decryption formula a^-1 ( x - b ) mod m
			{here x is cipher[i] and m is 26} and added 'A'
			to bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
			msg = msg + (char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
		else
			//else simply append space characte
			msg += cipher[i];
	}

	return msg;
}

string decryptCaesar(string msg)
{
    const int b = 1;
	///Cipher Text initially empty
	string cipher = "";
	for (int i = 0; i < msg.length(); i++)
	{
		// Avoid space to be encrypted
		if(msg[i]!=' ')
			/* applying encryption formula ( a x + b ) mod m
			{here x is msg[i] and m is 26} and added 'A' to
			bring it in range of ascii alphabet[ 65-90 | A-Z ] */
			cipher = cipher + (char) ((((msg[i]-'A') - b) % 26) + 'A');
		else
			//else simply append space character
			cipher += msg[i];
	}
	return cipher;
}

void guessCaesar(string msg)
{

    for(int j = 1; j < 26; j++){

        ///Cipher Text initially empty
        string cipher = "";
        for (int i = 0; i < msg.length(); i++)
        {
            // Avoid space to be encrypted
            if(msg[i]!=' ')
                /* applying encryption formula ( a x + b ) mod m
                {here x is msg[i] and m is 26} and added 'A' to
                bring it in range of ascii alphabet[ 65-90 | A-Z ] */
                cipher = cipher + (char) ((((msg[i]-'A') + j) % 26) + 'A');
            else
                //else simply append space character
                cipher += msg[i];
        }
        cout << "Shift count: " << j << " " << cipher << endl;
    }

}

//Driver Program
int main(void)
{
/*	string msg = "HELLO";

	cout << "Original message is: " << msg << endl << endl;

	TICK();
	string cipherTextAffine = encryptAffine(msg);
	TOCK();
	cout << "Encrypted Message using Affine Cipher with key a = " << a << ", b = " << b << " is : " << cipherTextAffine;
	cout << "\nTime taken for Affine Cipher (in seconds): " << DURATION() << endl;

	TICK();
	string cipherTextCaesar = encryptCaesar(msg, 2);
	TOCK();
	cout << "\nEncrypted Message using Caesar Cipher is : " << cipherTextCaesar;
	cout << "\nTime taken for Caesar Cipher (in seconds): " << DURATION() << endl;

	//Calling Decryption function

	TICK();
	cout << "\nDecrypted Message using Affine Cipher with key a = " << a << ", b = " << b << " is : " << decryptAffine(cipherTextAffine);
	TOCK();
	cout << "\nTime taken for Affine Cipher (in seconds): " << DURATION() << endl;

	TICK();
	cout << "\nDecrypted Message using Caesar Cipher is: " << decryptCaesar(cipherTextCaesar);
	TOCK();
	cout << "\nTime taken for Caesar Cipher (in seconds): " << DURATION() << endl;
*/
    guessCaesar("vlr zxkklq zoxzh qefp");
	return 0;
}

