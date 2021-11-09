#include <bits/stdc++.h>
#include "DES.h"
using namespace std;


int main(int argc, char* argv[])
{
	if(argc<3)
	{
		cout << "Invalid Parameters\n";
		return 0;
	}

	string action = argv[1];
	string data   = argv[2];
	string key    = argv[3];


	DES d(key);

	if (action == "encrypt")
	{
		cout<<"cipher: "<<d.Encrypt(data);

	}

	else if (action == "decrypt")
	{
		cout<<"plain: "<<d.Decrypt(data);
	}


}
