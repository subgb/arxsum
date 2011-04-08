/*

#include <Windows.h>

*/
/*
#include <locale>
#include <iostream>
#include <fstream>

typedef std::codecvt<wchar_t, char, mbstate_t> Mybase; 

// CLASS Simple_codecvt 
class Simple_codecvt : public Mybase 
{ 
public: 
	typedef wchar_t  _E; 
	typedef char  _To; 
	typedef mbstate_t _St; 

	explicit Simple_codecvt(size_t _R = 0) 
		: Mybase(_R) {} 

protected: 
	virtual result do_in(_St& _State, const _To *_F1, const _To *_L1, const _To *&_Mid1, _E *F2, _E *_L2, _E *&_Mid2) const 
	{return (noconv);} 

	virtual result do_out(_St& _State, const _E *_F1, const _E *_L1, const _E *&_Mid1, _To *F2, _E *_L2, _To *&_Mid2) const 
	{return (noconv);} 

	virtual result do_unshift(_St& _State, _To *_F2, _To *_L2, _To *&_Mid2) const 
	{return (noconv);} 

	virtual int do_length(_St& _State, const _To *_F1, const _To *_L1, size_t _N2) const _THROW0() 
	{return (_N2 < (size_t)(_L1 - _F1) ? _N2 : _L1 - _F1); } 

	virtual bool do_always_noconv() const _THROW0() 
	{return (true);} 

	virtual int do_max_length() const _THROW0() 
	{return (2);} 

	virtual int do_encoding() const _THROW0() 
	{return (2);} 
};

int wmain(int argc, wchar_t* argv[])
{
	wchar_t* buf = L"おはよう！";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), buf, 14, NULL, NULL);
	//WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), buf, 7, NULL, NULL);

	std::wofstream stream;
	std::locale loc = std::locale(std::locale::classic(), new Simple_codecvt);
	stream.imbue(loc);
	stream.open("out.txt", std::ios_base::out|std::ios_base::binary);
	stream << "hello world";
	stream << static_cast<wchar_t>(0x03C8);
	stream.close();
}
*/
/*
#include <string>

#include <stdio.h>
#include <io.h>

using namespace std;

void out(const std::string& str) {
	int fn = fileno(stdout);
	bool atty = _isatty(fn);
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD count;
	if(atty)
		WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), str.c_str(), str.size(), &count, NULL);
	else
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), str.c_str(), str.size() * sizeof(wchar_t), &count, NULL);
}


#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include <iostream>

namespace fs = boost::filesystem;

int wmain( int argc, wchar_t* argv[] )
{
	//boost::progress_timer t( std::clog );

	fs::path full_path( fs::initial_path<fs::path>() );

	if ( argc > 1 )
		full_path = fs::system_complete( fs::path( argv[1], fs::native ) );
	else
		out(L"\nusage:   simple_ls [path]\n");

	unsigned long file_count = 0;
	unsigned long dir_count = 0;
	unsigned long other_count = 0;
	unsigned long err_count = 0;

	if ( !fs::exists( full_path ) )
	{
		out(L"\nNot found: ");out(full_path.native_file_string());out(L"\n");
		return 1;
	}

	if ( fs::is_directory( full_path ) )
	{
		out(L"\nIn directory: "); out(full_path.native_directory_string()); out(L"\n\n");
		fs::directory_iterator end_iter;
		for ( fs::directory_iterator dir_itr( full_path );
			dir_itr != end_iter;
			++dir_itr )
		{
			try
			{
				if ( fs::is_directory( dir_itr->status() ) )
				{
					++dir_count;
					out(dir_itr->path().leaf()); out(L" [directory]\n");
				}
				else if ( fs::is_regular( dir_itr->status() ) )
				{
					++file_count;
					out(dir_itr->path().leaf()); out(L"\n");
				}
				else
				{
					++other_count;
					out(dir_itr->path().leaf()); out(L" [other]\n");
				}

			}
			catch ( const std::exception & ex )
			{
				++err_count;
				out(dir_itr->path().leaf()); out(L" "); out(L"\n");
			}
		}
	}
	else // must be a file
	{
		out(L"\nFound: "); out(full_path.native_file_string()); out(L"\n");    
	}
	return 0;
}*/

#include "Streams.h"

int main() {
	//WideCharToMultiByte()
	//MultiByteToWideChar()
	//mbstowcs()
	//wcstombs()
	//UnicodeString s1=UNICODE_STRING("such characters are safe 123 %-.", 32);

	
}