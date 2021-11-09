/*
 * DES.h
 *
 *  Created on: Nov 9, 2021
 *      Author: Shams
 */

#ifndef DES_H_
#define DES_H_

#include <bits/stdc++.h>

using namespace std;


class DES {
private:
	/* PRIVATE ATTRIBUTES */
	vector<string> RoundKeys;
	string PlainText;

	/* PRIVATE METHODS */
	vector<string> CalculateRoundKeys(string Key);
	string Hex2Binary(string hexString);
	string Permute(string Data, int PermChoice[] , int size);
	string RotateLeftRound(string Str, int ShiftBy);
	string XOR (string RightPT, string KEY);
	string SBOX (string RightPT);
	string Binary2Hex(string binaryString);
public:
	DES(string Key);
	string Encrypt(string PlainText);
	string Decrypt(string EncryptedText);
	virtual ~DES();
};

#endif /* DES_H_ */


