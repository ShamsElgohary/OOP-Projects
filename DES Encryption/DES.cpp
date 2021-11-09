/*
 * DES.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: Shams
 */

#include "DES.h"


/*////////////////////////////////////////////////////////////////////////////

                     	 	 	 DATA USED IN DES METHODS

////////////////////////////////////////////////////////////////////////////*/


///////////////////////             FOR KEY                 ////////////////////


   int KeyInitialPermutation[] = { 57, 49, 41, 33, 25, 17, 9,
								  1, 58, 50, 42, 34, 26, 18,
								  10, 2, 59, 51, 43, 35, 27,
								  19, 11, 3, 60, 52, 44, 36,
								  63, 55, 47, 39, 31, 23, 15,
								  7, 62, 54, 46, 38, 30, 22,
								  14, 6, 61, 53, 45, 37, 29,
								  21, 13, 5, 28, 20, 12, 4 };

   int PermutationChoice2[] =   {14, 17, 11, 24,  1,  5,
   								 3, 28, 15,  6, 21, 10,
   								23, 19, 12,  4, 26,  8,
   								16,  7, 27, 20, 13,  2,
   								41, 52, 31, 37, 47, 55,
   								30, 40, 51, 45, 33, 48,
   								44, 49, 39, 56, 34, 53,
   								46, 42, 50, 36, 29, 32};

   int ShiftTable[] =      {1, 1, 2, 2,
                            2, 2, 2, 2,
                            1, 2, 2, 2,
                            2, 2, 2, 1 };


////////////////////////         FOR PLAIN TEXT              /////////////////////////

   int MessageInitialPermutation[] =   {58, 50, 42, 34, 26, 18, 10, 2,
										60, 52, 44, 36, 28, 20, 12, 4,
										62, 54, 46, 38, 30, 22, 14, 6,
										64, 56, 48, 40, 32, 24, 16, 8,
										57, 49, 41, 33, 25, 17,  9, 1,
										59, 51, 43, 35, 27, 19, 11, 3,
										61, 53, 45, 37, 29, 21, 13, 5,
										63, 55, 47, 39, 31, 23, 15, 7};

    int ExpansionTable[] =    {32,  1,  2,  3,  4,  5,
   	 						   4,  5,  6,  7,  8,  9,
   	  						   8,  9, 10, 11, 12, 13,
   							   12, 13, 14, 15, 16, 17,
   							   16, 17, 18, 19, 20, 21,
   							   20, 21, 22, 23, 24, 25,
   							   24, 25, 26, 27, 28, 29,
   							   28, 29, 30, 31, 32,  1};

    int SBoxTable[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                            0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                            4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                            15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                          { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                            3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                            0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                            13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

                          { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                            13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                            13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                            1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                          { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                            13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                            10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                            3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                          { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                            14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                            4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                            11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                          { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                            10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                            9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                            4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                          { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                            13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                            1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                            6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                          { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                            1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                            7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                            2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

    int MessagePermutation[32] = 	 { 16, 7, 20, 21,
                       	   	   	   	   29, 12, 28, 17,
									   1, 15, 23, 26,
									   5, 18, 31, 10,
									   2, 8, 24, 14,
									   32, 27, 3, 9,
									   19, 13, 30, 6,
									   22, 11, 4, 25 };

    int FinalPermutation[] = 		   {40,  8, 48, 16, 56, 24, 64, 32,
    									39,  7, 47, 15, 55, 23, 63, 31,
    									38,  6, 46, 14, 54, 22, 62, 30,
    									37,  5, 45, 13, 53, 21, 61, 29,
    									36,  4, 44, 12, 52, 20, 60, 28,
    									35,  3, 43, 11, 51, 19, 59, 27,
    									34,  2, 42, 10, 50, 18, 58, 26,
    									33,  1, 41,  9, 49, 17, 57, 25};

/*////////////////////////////////////////////////////////////////////////////

                     	 	 	 DES CLASS METHODS

////////////////////////////////////////////////////////////////////////////*/


DES::DES(string Key)
{
	/* GET THE VECTOR THAT HAS THE KEYS FOR EACH ROUND */
	RoundKeys = CalculateRoundKeys(Key);
}

vector<string> DES::CalculateRoundKeys(string Key)
{
	vector<string> KeysForRound;
	string CombinedKeys;

	Key = Hex2Binary(Key);
	Key = Permute(Key, KeyInitialPermutation, 56);

  /* SPLITTING THE Key INTO 2 SEPERATE PARTS LEFT AND RIGHT */
  string LeftKey  = Key.substr(0, 28);
  string RightKey = Key.substr(28, 28);

  /* GETTING Key FOR EACH ROUND
   * FIRST WE LEFT ROTATE EACH PART OF THE Key
   * THEN WE COMBINE BOTH PARTS AND PERMUTATE THEM TO GET 48 BITS ONLY
   * AND ADD THEM TO A VECTOR WHICH WILL LATER BE USED IN ENCRYPTING  */
  for (int i = 0; i < 16; i++)
  {
	  LeftKey = RotateLeftRound(LeftKey, ShiftTable[i] );
	  RightKey = RotateLeftRound(RightKey, ShiftTable[i] );
	  CombinedKeys = LeftKey + RightKey;
	  CombinedKeys = Permute(CombinedKeys, PermutationChoice2, 48);
	  KeysForRound.push_back(CombinedKeys);
  }

  return KeysForRound;
}


string DES::Hex2Binary(string hexString){
	string binaryString{""};

	for (unsigned int i = 0 ; i < hexString.length() ; i++ )
	{
		hexString[i] = toupper(hexString[i]);
		switch( hexString[i]) {
			case '0':
				binaryString += "0000";
				break;
			case '1':
				binaryString += "0001";
				break;
			case '2':
				binaryString += "0010";
				break;
			case '3':
				binaryString += "0011";
				break;
			case '4':
				binaryString += "0100";
				break;
			case '5':
				binaryString += "0101";
				break;
			case '6':
				binaryString += "0110";
				break;
			case '7':
				binaryString += "0111";
				break;
			case '8':
				binaryString += "1000";
				break;
			case '9':
				binaryString += "1001";
				break;
			case 'A':
				binaryString += "1010";
				break;
			case 'B':
				binaryString += "1011";
				break;
			case 'C':
				binaryString += "1100";
				break;
			case 'D':
				binaryString += "1101";
				break;
			case 'E':
				binaryString += "1110";
				break;
			case 'F':
				binaryString += "1111";
				break;
		}
	}

	return binaryString;
}

string DES::Permute(string Data, int PermChoice[] , int size)
{
	string PermutatedData{""};
	for (int i = 0 ; i < size ; i++)
		PermutatedData += Data[PermChoice[i]-1];

	return PermutatedData;
}



string DES::RotateLeftRound(string Str, int ShiftBy)
{
	string s = Str;
    reverse(s.begin(), s.begin()+ShiftBy);
    reverse(s.begin()+ShiftBy, s.end());
    reverse(s.begin(), s.end());
    return s;
}

string DES::XOR (string RightPT, string KEY)
{
	string Result{""};
	for(unsigned int i =0; i < KEY.size() ; i++)
	{
		RightPT[i] == KEY[i] ? Result+= "0" : Result += "1";
	}
	return Result;
}


string DES::SBOX (string RightPT)
{
	string result{""};
	string ColString{""};
	string RowString{""};
	int column;
	int row;
	int SBoxValue;

	for (int i = 0, offset = 0; i < 8; i++ , offset+=6)
	{
		RowString="";
		ColString="";

		/* Parsing RightPT */
		ColString = RightPT.substr( offset, 6);
		RowString = ColString[0];
		RowString +=ColString[5];
		ColString = ColString.substr(1,4);

		/* Getting Values of Column and Row */
		column = strtol(&ColString[0],nullptr, 2);
		row = strtol(&RowString[0],nullptr, 2);

		/* Value as an integer */
		SBoxValue = SBoxTable[i][row][column];
		/* Value converted to string */
		result += bitset<4>(SBoxValue).to_string();
	}

	return result;
}


string DES::Encrypt(string PlainText)
{
	string EncryptedMessage{""};
	PlainText = Hex2Binary(PlainText);
	PlainText = Permute(PlainText, MessageInitialPermutation, 64);

	string LeftPT  = PlainText.substr(0, 32);
	string RightPT = PlainText.substr(32, 32);

	string RightPT_F;

	/* 16 ROUNDS */
	for (int i = 0; i < 16; i++)
	{
		/* EXPANDING THE RIGHT PART FROM 32 BITS TO 48 BITS FOR CONFUSION */
		RightPT_F=Permute(RightPT,ExpansionTable,48);
		/* XOR THE RIGHT PART WITH THE KEY */
		RightPT_F = XOR(RightPT_F, RoundKeys[i] );

		/* SBOX OPERATION */
		RightPT_F = SBOX(RightPT_F);

		/* PERMUTATION 32 BITS*/
		RightPT_F = Permute(RightPT_F,MessagePermutation,32);
		RightPT_F = XOR(RightPT_F, LeftPT);

		LeftPT = RightPT;
		RightPT = RightPT_F;
	}

	/* SWAP */
	EncryptedMessage = RightPT + LeftPT;
	/* FINAL PERMUTATION */
	EncryptedMessage = Permute(EncryptedMessage, FinalPermutation, 64);
	/* CONVERT MESSAGE BACK TO HEXA */
	EncryptedMessage = Binary2Hex(EncryptedMessage);

	return EncryptedMessage;
}


// MAP IDEA FROM GOOGLE
string DES::Binary2Hex(string binaryString){
	string hexString{""};

    unordered_map<string, string> mp;
    mp["0000"] = "0";
    mp["0001"] = "1";
    mp["0010"] = "2";
    mp["0011"] = "3";
    mp["0100"] = "4";
    mp["0101"] = "5";
    mp["0110"] = "6";
    mp["0111"] = "7";
    mp["1000"] = "8";
    mp["1001"] = "9";
    mp["1010"] = "A";
    mp["1011"] = "B";
    mp["1100"] = "C";
    mp["1101"] = "D";
    mp["1110"] = "E";
    mp["1111"] = "F";

    for (int i = 0; i < binaryString.length(); i += 4) {
        string ch = binaryString.substr(i,4);
        hexString += mp[ch];
    }

    return hexString;
}

string DES::Decrypt(string EncryptedText)
{
    reverse(RoundKeys.begin(), RoundKeys.end());
	/* SAME PROCESS BUT IN THE OPPOSITE ORDER ( FROM TOP TO BOTTOM ) */
	return Encrypt(EncryptedText);
}


DES::~DES() {
	// TODO Auto-generated destructor stub
}

