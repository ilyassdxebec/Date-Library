#pragma once
#include<iostream>
#include<vector>

using namespace std;

class clsString
{
private:

	string _Value;

	static bool isVowel(char Letter)
	{
		Letter = tolower(Letter);

		return (Letter == 'a' || Letter == 'e' || Letter == 'u' || Letter == 'i' || Letter == 'o');
	}

	static char InvertLetterCase(char Letter)
	{
		return (isupper(Letter)) ? tolower(Letter) : toupper(Letter);
	}

public:

	clsString()
	{
		_Value = "";
	}

	clsString(const string& Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	void SetValue(const string& Value)
	{
		_Value = Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	static short CountWords(string S)
	{
		string delim = " ";
		string sWord;

		int pos = 0;
		short NumOfWords = 0;

		while ((pos = S.find(delim)) != string::npos)
		{
			sWord = S.substr(0, pos);

			if (sWord != "")
			{
				NumOfWords++;
			}

			S.erase(0, pos + delim.length());
		}

		if (S != "")
		{
			NumOfWords++;
		}

		return NumOfWords;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintWordsSeperately(string S)
	{
		string delim = " ";
		int pos = 0;
		string sWord;

		cout << "\n\nHere are string words seperated : " << endl;

		while ((pos = S.find(delim)) != string::npos)
		{
			sWord = S.substr(0, pos);

			if (sWord != "")
			{
				cout << sWord << endl;
			}

			S.erase(0, pos + delim.length());
		}

		if (S != "")
		{
			cout << S << endl;
		}
	}

	void PrintWordsSeperately()
	{
		return PrintWordsSeperately(_Value);
	}

	static short LetterCount(const string& String, const char& Letter)
	{
		short LetterCount = 0;

		for (short i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ')
			{
				if (String[i] == Letter)
				{
					LetterCount++;
				}
			}
		}
		return LetterCount;
	}

	short LetterCount(const char& Letter)
	{
		return LetterCount(_Value, Letter);
	}

	static int CountVowel(const string& String)
	{
		int Counter = 0;

		for (short i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ')
			{
				if (isVowel(String[i]))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}

	int CountVowel()
	{
		return CountVowel(_Value);
	}

	static string TrimLeft(string S)
	{
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
			{
				return S.substr(i, S.length() - i);
			}
		}
		return "";
	}

	string TrimLeft()
	{
		return TrimLeft(_Value);
	}

	static string TrimRight(string S)
	{
		for (int i = S.length() - 1; i >= 0; i--)
		{
			if (S[i] != ' ')
			{
				return S.substr(0, i + 1);
			}
		}
		return "";
	}

	string TrimRight()
	{
		return TrimRight(_Value);
	}

	static string Trim(string S)
	{
		return TrimRight(TrimLeft(S));
	}

	string Trim()
	{
		return Trim(_Value);
	}

	static vector <string> Split(string S, string delim = " ")
	{

		vector<string>vWords;
		int pos = 0;
		string word;

		while ((pos = S.find(delim)) != string::npos)
		{
			word = S.substr(0, pos);

			if (word != "")
			{
				vWords.push_back(word);
			}
			S.erase(0, pos + delim.length());
		}
		if (S != "")
		{
			vWords.push_back(S);
		}

		return vWords;
	}

	vector <string> Split()
	{
		return Split(_Value);
	}

	static string ReverseWords(string S)
	{
		string delim = " ";
		string reversed = "";
		vector<string>vWords = Split(S);
		vector<string>::iterator iter = vWords.end();

		while (iter != vWords.begin())
		{
			--iter;
			reversed += *iter + delim;
		}

		return reversed.substr(0, reversed.length() - delim.length());
	}

	string ReverseWords()
	{
		return ReverseWords(_Value);
	}

	static string ReplaceWord(string S, string OldWord, string NewWord)
	{
		int pos;

		while ((pos = S.find(OldWord)) != string::npos)
		{
			S.replace(pos, OldWord.length(), NewWord);
		}
		return S;
	}

	string ReplaceWord(string OldWord, string NewWord)
	{
		return ReplaceWord(_Value, OldWord, NewWord);
	}

	static short CountCapitalLetters(const string& String)
	{
		short CapitalLetters = 0;

		for (short i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ')
			{
				if (isupper(String[i]))
				{
					CapitalLetters++;
				}
			}
		}
		return CapitalLetters;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static string InvertStringLetters(string S)
	{

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
			{
				S[i] = InvertLetterCase(S[i]);
			}
		}

		return S;
	}

	string InvertStringLetters()
	{
		return InvertStringLetters(_Value);
	}

	static string UppercaseFirstLetters(string S)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S.length(); i++)
		{
			if (isFirstLetter && S[i] != ' ')
			{
				S[i] = toupper(S[i]);
			}
			isFirstLetter = (S[i] == ' ') ? true : false;
		}
		return S;
	}

	string UppercaseFirstLetters()
	{
		return UppercaseFirstLetters(_Value);
	}

	static string RemovePunctuations(string S)
	{
		string S2 = "";

		for (short i = 0; i < S.length(); i++)
		{
			if (!(ispunct(S[i])))
			{
				S2 += S[i];
			}
		}

		return S2;
	}

	string RemovePunctuations()
	{
		return RemovePunctuations(_Value);
	}

	static string LowCaseString(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
			{
				S[i] = tolower(S[i]);
			}
		}

		return S;
	}

	string LowCaseString()
	{
		return LowCaseString(_Value);
	}

	static string UpperCaseString(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
			{
				S[i] = toupper(S[i]);
			}
		}

		return S;
	}

	string UpperCaseString()
	{
		return UpperCaseString(_Value);
	}

	static short Length(const string& S)
	{
		return S.length();
	}

	short Length()
	{
		return Length(_Value);
	}

	static string JoinString(const vector <string>& vString, string delim = " ")
	{
		string Joined = "";

		for (const string& x : vString)
		{
			Joined = Joined + x + delim;
		}

		return Joined.substr(0, Joined.length() - delim.length());
	}

	static string JoinString(const string arr[], const short& arrLength, string delim = " ")
	{
		string Joined = "";

		for (short i = 0; i < arrLength; i++)
		{
			Joined = Joined + arr[i] + delim;
		}

		return Joined.substr(0, Joined.length() - delim.length());
	}

	static bool isEmpty(const string& S)
	{
		return (S == "");
	}

	bool isEmpty()
	{
		return isEmpty(_Value);
	}
};
