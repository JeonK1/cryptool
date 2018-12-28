#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <Windows.h>

#define ASCIITABLE_LEN 128
#define MOSTABLE_LEN 36
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

using namespace std;

class Cryptool {
private:
	const char **ASCII_TABLE;
	const char **MOS_TABLE;

public:
	Cryptool() {
	/*** store asciiTable information ***/
		ASCII_TABLE = new const char*[ASCIITABLE_LEN];
		ASCII_TABLE[0] = "NUL";
		ASCII_TABLE[1] = "SOH";
		ASCII_TABLE[2] = "STX";
		ASCII_TABLE[3] = "ETX";
		ASCII_TABLE[4] = "EOT";
		ASCII_TABLE[5] = "ENQ";
		ASCII_TABLE[6] = "ACK";
		ASCII_TABLE[7] = "BEL";
		ASCII_TABLE[8] = "BS";
		ASCII_TABLE[9] = "HT";
		ASCII_TABLE[10] = "LF";
		ASCII_TABLE[11] = "VT";
		ASCII_TABLE[12] = "FF";
		ASCII_TABLE[13] = "CR";
		ASCII_TABLE[14] = "SO";
		ASCII_TABLE[15] = "SI";
		ASCII_TABLE[16] = "DLE";
		ASCII_TABLE[17] = "DC1";
		ASCII_TABLE[18] = "DC2";
		ASCII_TABLE[19] = "DC3";
		ASCII_TABLE[20] = "DC4";
		ASCII_TABLE[21] = "NAK";
		ASCII_TABLE[22] = "SYN";
		ASCII_TABLE[23] = "ETB";
		ASCII_TABLE[24] = "CAN";
		ASCII_TABLE[25] = "EM";
		ASCII_TABLE[26] = "SUB";
		ASCII_TABLE[27] = "ESC";
		ASCII_TABLE[28] = "FS";
		ASCII_TABLE[29] = "GS";
		ASCII_TABLE[30] = "RS";
		ASCII_TABLE[31] = "US";
		ASCII_TABLE[32] = "SP";
		ASCII_TABLE[33] = "!";
		ASCII_TABLE[34] = "\"";
		ASCII_TABLE[35] = "#";
		ASCII_TABLE[36] = "$";
		ASCII_TABLE[37] = "%";
		ASCII_TABLE[38] = "&";
		ASCII_TABLE[39] = "\'";
		ASCII_TABLE[40] = "(";
		ASCII_TABLE[41] = ")";
		ASCII_TABLE[42] = "*";
		ASCII_TABLE[43] = "+";
		ASCII_TABLE[44] = ",";
		ASCII_TABLE[45] = "-";
		ASCII_TABLE[46] = ".";
		ASCII_TABLE[47] = "/";
		ASCII_TABLE[48] = "0";
		ASCII_TABLE[49] = "1";
		ASCII_TABLE[50] = "2";
		ASCII_TABLE[51] = "3";
		ASCII_TABLE[52] = "4";
		ASCII_TABLE[53] = "5";
		ASCII_TABLE[54] = "6";
		ASCII_TABLE[55] = "7";
		ASCII_TABLE[56] = "8";
		ASCII_TABLE[57] = "9";
		ASCII_TABLE[58] = ":";
		ASCII_TABLE[59] = ";";
		ASCII_TABLE[60] = "<";
		ASCII_TABLE[61] = "=";
		ASCII_TABLE[62] = ">";
		ASCII_TABLE[63] = "?";
		ASCII_TABLE[64] = "@";
		ASCII_TABLE[65] = "A";
		ASCII_TABLE[66] = "B";
		ASCII_TABLE[67] = "C";
		ASCII_TABLE[68] = "D";
		ASCII_TABLE[69] = "E";
		ASCII_TABLE[70] = "F";
		ASCII_TABLE[71] = "G";
		ASCII_TABLE[72] = "H";
		ASCII_TABLE[73] = "I";
		ASCII_TABLE[74] = "J";
		ASCII_TABLE[75] = "K";
		ASCII_TABLE[76] = "L";
		ASCII_TABLE[77] = "M";
		ASCII_TABLE[78] = "N";
		ASCII_TABLE[79] = "O";
		ASCII_TABLE[80] = "P";
		ASCII_TABLE[81] = "Q";
		ASCII_TABLE[82] = "R";
		ASCII_TABLE[83] = "S";
		ASCII_TABLE[84] = "T";
		ASCII_TABLE[85] = "U";
		ASCII_TABLE[86] = "V";
		ASCII_TABLE[87] = "W";
		ASCII_TABLE[88] = "X";
		ASCII_TABLE[89] = "Y";
		ASCII_TABLE[90] = "Z";
		ASCII_TABLE[91] = "[";
		ASCII_TABLE[92] = "\\";
		ASCII_TABLE[93] = "]";
		ASCII_TABLE[94] = "^";
		ASCII_TABLE[95] = "_";
		ASCII_TABLE[96] = "`";
		ASCII_TABLE[97] = "a";
		ASCII_TABLE[98] = "b";
		ASCII_TABLE[99] = "c";
		ASCII_TABLE[100] = "d";
		ASCII_TABLE[101] = "e";
		ASCII_TABLE[102] = "f";
		ASCII_TABLE[103] = "g";
		ASCII_TABLE[104] = "h";
		ASCII_TABLE[105] = "i";
		ASCII_TABLE[106] = "j";
		ASCII_TABLE[107] = "k";
		ASCII_TABLE[108] = "l";
		ASCII_TABLE[109] = "m";
		ASCII_TABLE[110] = "n";
		ASCII_TABLE[111] = "o";
		ASCII_TABLE[112] = "p";
		ASCII_TABLE[113] = "q";
		ASCII_TABLE[114] = "r";
		ASCII_TABLE[115] = "s";
		ASCII_TABLE[116] = "t";
		ASCII_TABLE[117] = "u";
		ASCII_TABLE[118] = "v";
		ASCII_TABLE[119] = "w";
		ASCII_TABLE[120] = "x";
		ASCII_TABLE[121] = "y";
		ASCII_TABLE[122] = "z";
		ASCII_TABLE[123] = "{";
		ASCII_TABLE[124] = "|";
		ASCII_TABLE[125] = "}";
		ASCII_TABLE[126] = "~";
		ASCII_TABLE[127] = "DEL";
		/*** store MosTable information ***/
		MOS_TABLE = new const char*[MOSTABLE_LEN];
		MOS_TABLE[0] = "._"; // 'A'
		MOS_TABLE[1] = "_..."; // 'B'
		MOS_TABLE[2] = "_._."; // 'C'
		MOS_TABLE[3] = "_.."; // 'D'
		MOS_TABLE[4] = "."; // 'E'
		MOS_TABLE[5] = ".._."; // 'F'
		MOS_TABLE[6] = "__."; // 'G'
		MOS_TABLE[7] = "...."; // 'H'
		MOS_TABLE[8] = ".."; // 'I'
		MOS_TABLE[9] = ".___"; // 'J'
		MOS_TABLE[10] = "_._"; // 'K'
		MOS_TABLE[11] = "._.."; // 'L'
		MOS_TABLE[12] = "__"; // 'M'
		MOS_TABLE[13] = "_."; // 'N'
		MOS_TABLE[14] = "___"; // 'O'
		MOS_TABLE[15] = ".__."; // 'P'
		MOS_TABLE[16] = "__._"; // 'Q'
		MOS_TABLE[17] = "._."; // 'R'
		MOS_TABLE[18] = "..."; // 'S'
		MOS_TABLE[19] = "_"; // 'T'
		MOS_TABLE[20] = ".._"; // 'U'
		MOS_TABLE[21] = "..._"; // 'V'
		MOS_TABLE[22] = ".__"; // 'W	'
		MOS_TABLE[23] = "_.._"; // 'X'
		MOS_TABLE[24] = "_.__"; // 'Y'
		MOS_TABLE[25] = "__.."; // 'Z'
		MOS_TABLE[26] = "_____"; // '0'
		MOS_TABLE[27] = ".____"; // '1'
		MOS_TABLE[28] = "..___"; // '2'
		MOS_TABLE[29] = "...__"; // '3'
		MOS_TABLE[30] = "...._"; // '4'
		MOS_TABLE[31] = "....."; // '5'
		MOS_TABLE[32] = "_...."; // '6'
		MOS_TABLE[33] = "__..."; // '7'
		MOS_TABLE[34] = "___.."; // '8'
		MOS_TABLE[35] = "____."; // '9'
	}
	void printAsciiTable() {
		printf("Dec\tHex\tValue\n");
		printf("-----------------------\n");
		for (int i = 0; i < ASCIITABLE_LEN; i++) {
			printf("%d\t%x\t%s\n", i, i, ASCII_TABLE[i]);
			if (i % 30 == 29) {
				getchar();
			}
		}
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void printMosTable() {
		/* print A to Z */
		for (char i = 'A'; i <= 'Z'; i++){
			printf("%c : %s\n", i, MOS_TABLE[i-'A']);
		}
		/* print 0 to 9 */
		for (int i = 0; i <= 9; i++) {
			printf("%d : %s\n", i, MOS_TABLE[26+i]);
		}
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	char cmpMosTbl(char *crypt) { // MOS_TABLE과 input값(crypt)의 비교함수
		/* 알파벳 구간 */
		char temp = 'A';
		for (int i = 0; i < 26; i++) {
			if (!strcmp(crypt, MOS_TABLE[i])) {
				return temp + i;
			}
		}
		/* 숫자 구간 */
		temp = '0';
		for (int i = 26; i < MOSTABLE_LEN; i++) {
			if (!strcmp(crypt, MOS_TABLE[i])) {
				return temp + i - 26;
			}
		}
		return '?';
	}
	void decodeMos() {
		char long_dot, short_dot, space;
		string cipher;
		cout << "input long dot : ";
		cin >> long_dot;
		cout << "input short dot : ";
		cin >> short_dot;
		cout << "input space(default = ' ') : ";
		getchar(); // 이전에 cin을 사용했어서 입력버퍼에 \n이 남아있으므로, getchar() 사용하여 제거.
		space = getchar();
		if (int(space) == 10) { // 받은 char 값이 enter키일때 (default 적용시켜주기)
			space = ' ';
		}
		else {
			getchar(); // 특정 문자를 입력했을때 뒤에 붙을 \n을 제거해주기 위한 getchar();
		}
		cout << "input cipher : ";
		getline(cin, cipher);

		/* change cipher */
		for (int i = 0; i < cipher.length(); i++) {
			if (cipher[i] == long_dot) {
				cipher.replace(i, 1, "_");
			}
			else if (cipher[i] == short_dot) {
				cipher.replace(i, 1, ".");
			}
			else if (cipher[i] == space) {
				cipher.replace(i, 1, " ");
			}
			else {
				cout << "cipher 변경중 error 감지(long dot, short dot, space 이외의 값 발견)" << endl;
			}
		}

		/* decode mos code */
		cout << "plain text : ";
		char* word;
		char* word2=NULL;
		word2 = strtok_s((char *)cipher.c_str(), " ", &word); // cipher에서 word2를 분리후, 나머지를 word에 저장한다.
		cout << cmpMosTbl(word2);
		while (strlen(word)!=0) { // word에 뭐가 남아있으면 계속 진행
			word2 = strtok_s(word, " ", &word);
			cout << cmpMosTbl(word2);
		}
		cout << endl;
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void asciiToText() {
		string cipher;
		cout << "warning : please input ascii text in two word(ex : 0a(o), a(x), \\x0a(o), \\xa(x))" << endl;
		cout << "input cipher : ";
		getline(cin, cipher);

		// if there is " \x ", reduce it!
		int idx = cipher.find("\\x");
		while (idx != -1) {
			cipher.erase(idx, 2);
			idx = cipher.find("\\x");
		}

		/* decode ascii code */
		for (int i = 0; i < cipher.length(); i += 2) {
			if (!strcmp(cipher.substr(i, 1).c_str(), " ")) {
				i--; // continue하면 +=2가 되니까 -1해주면 총 1만 오르게 됨
				cout << " "; // 띄어쓰기라 continue해주는거니까 문자열도 띄어쓰기 하나 출력해주기.
				continue;
			}
			int temp = strtol(cipher.substr(i, 2).c_str(), NULL, 16);
			cout << ASCII_TABLE[temp];
		}
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void Caesar_ALPHA_PART() {
		string cipher;
		getchar();
		cout << "input cipher : ";
		int key;
		cout << "input caesar key : ";
		cin >> key;
		getchar();
		for (int i = 0; i < cipher.length(); i++) {
			//ascii alpha : 65-90(upper case), 97-122(lower case)
			if ((cipher[i] >= 65 && cipher[i] <= 90)) {
				cipher[i] += key;
				if (cipher[i] > 90)
					cipher[i] -= 26;
				cout << cipher[i];
			}
			else if ((cipher[i] >= 97 && cipher[i] <= 122)) {
				cipher[i] += key;
				if (cipher[i] > 122)
					cipher[i] -= 26;
				cout << cipher[i];
			}
			else {
				cout << cipher[i];
			}
		}
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void Caesar_ALPHA_ALL() {
		string cipher;
		getchar();
		cout << "input cipher : ";
		for (int j = 0; j < 26; j++) {
			for (int i = 0; i < cipher.length(); i++) {
				//ascii alpha : 65-90(upper case), 97-122(lower case)
				if ((cipher[i] >= 65 && cipher[i] <= 90)) {
					cipher[i] += 1;
					if (cipher[i] > 90)
						cipher[i] -= 26;
					cout << cipher[i];
				}
				else if ((cipher[i] >= 97 && cipher[i] <= 122)) {
					cipher[i] += 1;
					if (cipher[i] > 122)
						cipher[i] -= 26;
					cout << cipher[i];
				}
				else {
					cout << cipher[i];
				}
			}
			cout << endl;
		}
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void Caesar_TEXT() {
		//ascii text : 33-126
		string cipher;
		int key;
		cout << "input cipher : ";
		getline(cin, cipher);
		cout << "input key : ";
		cin >> key;
		getchar();
		for (int i = 0; i < cipher.length(); i++) {
			if (cipher[i] >= 33 && cipher[i] <= 126) {
				cipher[i] += key;
				if (cipher[i] > 126)
					cipher[i] -= 94;
				cout << cipher[i];
			}
			else {
				cout << cipher[i];
			}
		}
		cout << endl;
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void Caesar_ASCII() {
		string cipher;
		int key;
		cout << "input cipher : ";
		getline(cin, cipher);
		cout << "input key : ";
		cin >> key;
		getchar();
		for (int i = 0; i < cipher.length(); i++) {
			cipher[i] += key;
			cout << cipher[i];
		}
		cout << endl;
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void link_Trans() { // 전치암호 페이지 오픈

//		system("start /max quipqiup.com"); // Explorer 실행
		system("start chrome quipqiup.com"); // Chrome 실행
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void link_Md5Sha1() {
//		system("start /max hashtoolkit.com"); // Explorer 실행
//		system("start /max crackstation.net"); // Explorer 실행
//		system("start /max md5hashing.net/hash"); // Explorer 실행

		system("start chrome hashtoolkit.com"); // Chrome 실행
		system("start chrome crackstation.net"); // Chrome 실행
		system("start chrome md5hashing.net/hash"); // Chrome 실행
		cout << endl << "press any key to return." << endl;
		getchar();
	}
	void link_B64URI() {
//		system("start /max ostermiller.org/calc/encode.html");
		system("start chrome ostermiller.org/calc/encode.html");
		cout << endl << "press any key to return." << endl;
		getchar();
	}
};
class CryptoolManager {
private:
	Cryptool cryptool;
public:
	void CursorView(char show)//커서숨기기
	{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = show;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}
	void printMainPage() {
		CursorView(0);
		cout << endl;
		cout << "                                            #                                         " << endl;
		cout << "        ####                                #               ######                    " << endl;
		cout << "       #    #                               #               #     #                   " << endl;
		cout << "      #         # ###   #    #   ######   ######    #####   #     #   #####   ##   ## " << endl;
		cout << "      #         ##      #    #   #     #    #      #     #  ######   #     #    # #   " << endl;
		cout << "      #         #       #    #   #     #    #      #     #  #     #  #     #     #    " << endl;
		cout << "       #    #   #       #    #   #     #    #      #     #  #     #  #     #    # #   " << endl;
		cout << "        ####    #        #####   ######      ###    #####   ######    #####   ##   ## " << endl;
		cout << "                             #   #                                                    " << endl;
		cout << "                         ####    #                                                    " << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                                       press any button                               " << endl;
		while (1) {
			if (_kbhit()) {
				_getch();
				break;
			}
		}
	}
	void printMainMenu() {
		CursorView(0);
		int menu = 1;
		while (1) {
			system("cls");
			cout << endl;
			for (int i = 1; i <= 8; i++) {
				if (menu == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				}
				switch (i) {
				case 1:
					cout << "   Encode Mos" << endl << endl;
					break;
				case 2:
					cout << "   Encode Ascii" << endl << endl;
					break;
				case 3:
					cout << "   Encode Caesar" << endl << endl;
					break;
				case 4:
					cout << "   Encode Transposition" << endl << endl;
					break;
				case 5:
					cout << "   Encode MD5, SHA1 ...." << endl << endl;
					break;
				case 6:
					cout << "   Encode Base64, URI" << endl << endl;
					break;
				case 7:
					cout << "   Print Ascii Table" << endl << endl;
					break;
				case 8:
					cout << "   Print Mos Table" << endl << endl;
					break;
				case 9:
					cout << "   Exit" << endl << endl;
					break;
				}
				if (menu == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				}
			}
			while (1) {
				if (_kbhit()) {
					char hit = _getch();

					if (hit == UP) {
						menu--;
						if (menu < 1)
							menu = 1;
						break;
					}
					else if (hit == DOWN) {
						menu++;
						if (menu > 8)
							menu = 8;
						break;
					}
					else if (hit == ENTER) {
						system("cls");
						CursorView(1);
						switch (menu) {
						case 1:
							cryptool.decodeMos();
							break;
						case 2:
							cryptool.asciiToText();
							break;
						case 3:
							caesarMenu();
							break;
						case 4:
							cryptool.link_Trans();
							break;
						case 5:
							cryptool.link_Md5Sha1();
							break;
						case 6:
							cryptool.link_B64URI();
							break;
						case 7:
							cryptool.printAsciiTable();
							break;
						case 8:
							cryptool.printMosTable();
							break;
						case 9:
							return;
						}
						break;
					}
					else
						break;
				}
			}
		}
	}
	void caesarMenu() {
		CursorView(0);
		int menu=1;
		while (1) {
			system("cls");
			cout << endl;
			for (int i = 1; i <= 4; i++) {
				if (menu == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				}
				switch (i) {
				case 1:
					cout << "   Caesar Alphabet (ABCD..abcd...)" << endl << endl;
					break;
				case 2:
					cout << "   Caesar Printable Ascii Text(ABCDabcd123!@#[]...)" << endl << endl;
					break;
				case 3:
					cout << "   Caesar All Ascii Text(ABCDabcd123!@#[] \\n\\a....)" << endl << endl;
					break;
				case 4:
					cout << "   Back" << endl << endl;
					break;
				}
				if (menu == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				}
			}
			while (1) {
				if (_kbhit()) {
					char hit = _getch();
					if (hit == UP) {
						menu--;
						if (menu < 1)
							menu = 1;
						break;
					}
					else if (hit == DOWN) {
						menu++;
						if (menu > 4)
							menu = 4;
						break;
					}
					else if (hit == ENTER) {
						CursorView(1);
						system("cls");
						CursorView(1);
						switch (menu) {
						case 1:
							caesarMenu_Alpha();
							break;
						case 2:
							cryptool.Caesar_TEXT();
							break;
						case 3:
							cryptool.Caesar_ASCII();
							break;
						case 4:
							CursorView(0);
							return;

							// 메뉴 링크 ㄱㄱ
						}
					}
					else
						break;
				}
			}
		}
	}
	void caesarMenu_Alpha() {
		CursorView(0);
		int menu = 1;
		while (1) {
			system("cls");
			cout << endl;
			for (int i = 1; i <= 3; i++) {
				if (menu == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				}
				switch (i) {
				case 1:
					cout << "   Caesar Alphabet Using Key" << endl << endl;
					break;
				case 2:
					cout << "   Caesar Alphabet Non Key(Print All Case)" << endl << endl;
					break;
				case 3:
					cout << "   Back" << endl << endl;
					break;
				}
				if (menu == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				}
			}
			while (1) {
				if (_kbhit()) {
					char hit = _getch();
					if (hit == UP) {
						menu--;
						if (menu < 1)
							menu = 1;
						break;
					}
					else if (hit == DOWN) {
						menu++;
						if (menu > 3)
							menu = 3;
						break;
					}
					else if (hit == ENTER) {
						CursorView(1);
						system("cls");
						switch (menu) {
						case 1:
							cryptool.Caesar_ALPHA_PART();
							break;
						case 2:
							cryptool.Caesar_ALPHA_ALL();
							break;
						case 3:
							CursorView(0);
							return;
						}
					}
					else
						break;
				}
			}
		}
	}
};

int main(void)
{
	system("mode con: cols=100 lines=33"); // console size setting
	CryptoolManager cryptoolManager;
	cryptoolManager.printMainPage();
	cryptoolManager.printMainMenu();
	getchar();
	return 0;
}