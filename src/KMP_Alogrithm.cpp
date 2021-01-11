#include <iostream>
#include <string.h>

#define TEXT_LEN           100
#define MATCHED_STRING_LEN 100

using namespace std; 


int preKMPAlgorithm(char *strCmp, int arrStrCmp_pos[])
{
	int strCmpLen = strlen(strCmp);
	char arrStrCmp[strCmpLen];
	int i = 0;
	int i_next = i + 1;
	
	strcpy(arrStrCmp, strCmp);
	arrStrCmp_pos[0] = 0;
	while(i_next < strCmpLen)
	{
		if (arrStrCmp[i] == arrStrCmp[i_next])
		{
			arrStrCmp_pos[i_next] = i + 1; 
			
			i_next++ ;
			i++ ;
			continue;
		}
		else if (arrStrCmp[i] != arrStrCmp[i_next])
		{
			if (i == 0 || i == 1)
			{
				arrStrCmp_pos[i_next] = 0;
				i_next++ ;
				i = 0;
				continue;
			}
			else 
			{
				while (i > 1 )
				{
					if (arrStrCmp[arrStrCmp_pos[i - 1]] == arrStrCmp[i_next])
					{
						arrStrCmp_pos[i_next] = i + 1; 
						i_next++ ;
						i++ ;
						
						break;
					}
					else if (arrStrCmp[arrStrCmp_pos[i - 1]] != arrStrCmp[i_next])
					{
						i = arrStrCmp_pos[i - 1] - 1;
						if ( i < 0 )
						{
							arrStrCmp_pos[i_next] = 0;
							i_next++ ;
							i = 0;
							continue;
						}
					}
				}

			}
		}
		
	}
	
	return true;
}


int posKMPAlgorithm(char *strData, char *strCmp)
{
	int strCmpLen = strlen(strCmp);
	int strCmp_KMPAlgo[strCmpLen];
	
	int strDataLen = strlen(strData);
	char checkStrData[strDataLen];
	char checkStrCmp[strCmpLen];
	
	if ( strDataLen < strCmpLen )
	{
		return 0;
	}
	
	int i_strCmp = 0, i_strData = 0;
	preKMPAlgorithm(strCmp, strCmp_KMPAlgo);
	
	strcpy(checkStrData, strData);
	strcpy(checkStrCmp, strCmp);
	
	for (i_strData = 0; i_strData < strDataLen; i_strData++)
	{
		if (checkStrData[i_strData] == checkStrCmp[i_strCmp])
		{
			i_strCmp++ ;
			continue;
		}
		else if (checkStrData[i_strData] != checkStrCmp[i_strCmp])
		{
			while(i_strCmp > 1)
			{
				if (checkStrData[i_strData] == checkStrCmp[strCmp_KMPAlgo[i_strCmp - 1]])
				{
					i_strCmp = strCmp_KMPAlgo[i_strCmp - 1];
					i_strCmp ++;
					break;
				}
				else if (checkStrData[i_strData] != checkStrCmp[strCmp_KMPAlgo[i_strCmp - 1]])
				{
					i_strCmp = strCmp_KMPAlgo[i_strCmp - 1];
					if (i_strCmp <= 0)
					{
						i_strCmp = 0;
						break;
					}
				}
			}
		}
	}
	
	
	return i_strCmp;
}

int main(int argc, char const *argv[])
{
	char *strData = (char *)malloc (sizeof(char) * TEXT_LEN);
	char *strCmp  = (char *)malloc (sizeof(char) * MATCHED_STRING_LEN);
	int rst = 0;
	
	/*1. matched text*/
	strData = "abxabcabcaby";
	strCmp  = "abcaby";
	rst = posKMPAlgorithm(strData, strCmp );
	if (rst == strlen(strCmp))
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have " << "\"" << strCmp << "\"" << endl;
	}
	else
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have not " << "\"" << strCmp << "\"" << endl;
		cout << "NOT MATCHED" << endl;
	}


	/*2. not matched text*/
	strData = "aaaaaa";
	strCmp  = "aaaaaaaaaaa";
	rst = posKMPAlgorithm(strData, strCmp );
	if (rst == strlen(strCmp))
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have " << "\"" << strCmp << "\"" << endl;
	}
	else
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have not " << "\"" << strCmp << "\"" << endl;
		cout << "NOT MATCHED" << endl;
	}
	
	
	/*3. not matched text*/
	strData = "aaaaaa";
	strCmp  = "aaaaab";
	rst = posKMPAlgorithm(strData, strCmp );
	if (rst == strlen(strCmp))
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have " << "\"" << strCmp << "\"" << endl;
	}
	else
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have not " << "\"" << strCmp << "\"" << endl;
		cout << "NOT MATCHED" << endl;
	}
	
	
	/*4. not matched text*/
	strData = "aabaaaaaa";
	strCmp  = "aaaaaa";
	rst = posKMPAlgorithm(strData, strCmp );
	if (rst == strlen(strCmp))
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have " << "\"" << strCmp << "\"" << endl;
	}
	else
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have not " << "\"" << strCmp << "\"" << endl;
		cout << "NOT MATCHED" << endl;
	}	


	/*5. not matched text*/
	strData = "ABABDABACDABABCABAB";
	strCmp  = "ABABCABAB";
	rst = posKMPAlgorithm(strData, strCmp );
	if (rst == strlen(strCmp))
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have " << "\"" << strCmp << "\"" << endl;
	}
	else
	{
		cout << "string:" << " " << "\"" << strData << "\"" << " have not " << "\"" << strCmp << "\"" << endl;
		cout << "NOT MATCHED" << endl;
	}
}