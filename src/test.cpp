#include <iostream>

#include "arx/shared_ptr.h"
#include "arx/Converter.h"
#include "arx/Streams.h"

#include <Windows.h>

#include <sstream>
#include <iomanip>

using namespace std;
using namespace arx;

class a {
public:
	virtual int lol() {
		return 0;
	}
};

class b: public a{
public:
	int lol() {
		return 1;
	}
};


class BASE {
protected:
	arx::shared_ptr<a> p;
public:
	BASE(a* ptr): p(ptr) {}
	int lol() {
		return p->lol();
	}
};

class A: public BASE {
public:
	A(): BASE(new a()) {}
	A(a* ptr): BASE(ptr) {}
};

class B: public A {
private:
	int loli;
public:
	B(): A(new b()) {}
};

void func(A aaaa) {
	cout << aaaa.lol();
}

A operator* (A, B) {
	return A();
}

int main() {

	Writer w = OutputStreamWriter(ConsoleOutputStream());

	FormatReader st = FormatReader(BufferedReader(InputStreamReader(ConsoleInputStream())));
	FormatWriter mycout = FormatWriter(w);

	mycout << 3.1 << "asdf" << 3 << L"����";

	mycout.flush();


	OutputStreamWriter(ConsoleOutputStream()).write(L"mwahaha", 7);

	unsigned int a1;
	//st >> a1;

	A (*pOperator)(A, B) = &operator*;

	//istringstream st("\n\n\n123 a 123");

	cout << /*st.tellg() << " " <<*/ st.fail() << endl;

	int h;
	wstring lllll;
	st >> h;

	cout <</* st.tellg() << " " <<*/ st.fail() << endl;

	st >> h;

	cout << /*st.tellg() << " " <<*/ st.fail() << endl;

	st >> lllll;

	cout << /*st.tellg() << " " <<*/ st.fail() << endl;

	cout << st.fail();

	st.readLine(lllll);
	w.write(lllll.c_str(), lllll.size());
	string aaaaa("asdf");
	aaaaa = aaaaa.substr(4);

	Writer wr = OutputStreamWriter(ConsoleOutputStream());
	wr.write(L"123���", 6);


	ConsoleOutputStream s;
	s.write((const unsigned char*)L"123", 6);

	{
		ToUTF16Converter toConv("UTF8");
		FromUTF16Converter fromConv("UTF8");
		string ss =  ";    244412006  11:45.30 2007-04-21 愛の\n";
		string ss1 =  ";    244412006  11:45.30 2007-04-21 愛�\n";
		wstring ww = toConv.convert(ss);

		Writer w = OutputStreamWriter(FileOutputStream(L"lol2.txt"), "UTF8");
		Reader r = InputStreamReader(FileInputStream(L"lol.txt"), "UTF8");
		for(int i = 0; i < 10000; i++) {
			r.read(const_cast<wchar_t*>(ww.c_str()), ww.size());
			w.write(ww.c_str(), ww.size());
			wr.write(ww.c_str(), ww.size());
		}
		r.close();
		w.close();



		wstring ww1 = toConv.convert(ss1);
		wstring ww2 = toConv.convertSome(ss1);

		cout << ss1;
		DWORD n;
		WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), ww.c_str(), ww.size(), &n, NULL);
		ss = fromConv.convert(ww);
	}


	arx::ToUTF16Converter toConv;
	arx::FromUTF16Converter fromConv;
	std::string ss = "���";

	std::cout << ss << endl;

	std::wstring ww = toConv.convert("���");
	ss = fromConv.convert(ww);

	DWORD n;
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), ww.c_str(), 3, &n, NULL);

	std::wcout << ww << endl;

	std::cout << ss << endl;

	arx::shared_ptr<a> p(new a());
	arx::shared_ptr<b> pb(new b());
	std::cout << p->lol() << pb->lol();
	p = pb;
	std::cout << p->lol() << std::endl;


	A aa;
	B bb;

	func(aa);
	func(bb);

	std::cout << aa.lol() << bb.lol();
	aa = bb;
	std::cout << aa.lol();


	//WideCharToMultiByte()
	//MultiByteToWideChar()
	//mbstowcs()
	//wcstombs()
	//UnicodeString s1=UNICODE_STRING("such characters are safe 123 %-.", 32);

	return 0;
}