/* Generated by re2c 0.13.5 on Fri Oct 29 18:35:48 2010 */
#line 1 "XMLUnescape.re"
/*******************************************************************************
 * Copyright (C) 2001-2004 Quest Software, Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  - Neither the name of Quest Software, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL Quest Software, Inc. OR THE CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

/**
 * @author Dan Nuffer
 */

/* a simple lexical scanner to escape xml */
#include "miniblocxx/BLOCXX_config.h"
#include "miniblocxx/XMLUnescape.hpp"
#include "miniblocxx/StringBuffer.hpp"
#include "miniblocxx/XMLParserError.hpp"
#include <limits.h> // for CHAR_MAX
#include <stdlib.h> // for strtol

namespace XML
{

	std::string XMLUnescape(const char* escapedText, unsigned len)
	{
		blocxx::StringBuffer rval(len);
		const char* begin = escapedText;
		const char* q;
		const char* thisTokStart = escapedText;
#define YYCTYPE char
#define YYCURSOR        begin
#define YYLIMIT         begin
#define YYMARKER        q
#define YYFILL(n) (void) true
	start:
		
#line 62 "XMLUnescape.cpp"
{
	YYCTYPE yych;

	if ((YYLIMIT - YYCURSOR) < 6) YYFILL(6);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy5;
	case '&':	goto yy2;
	default:	goto yy4;
	}
yy2:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '#':	goto yy7;
	case 'a':	goto yy9;
	case 'g':	goto yy12;
	case 'l':	goto yy11;
	case 'q':	goto yy10;
	default:	goto yy3;
	}
yy3:
#line 93 "XMLUnescape.re"
	{ rval += *(YYCURSOR-1); thisTokStart = YYCURSOR; goto start; }
#line 86 "XMLUnescape.cpp"
yy4:
	yych = *++YYCURSOR;
	goto yy3;
yy5:
	++YYCURSOR;
#line 94 "XMLUnescape.re"
	{ return rval.toString(); }
#line 94 "XMLUnescape.cpp"
yy7:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy34;
	case 'x':	goto yy33;
	default:	goto yy8;
	}
yy8:
	YYCURSOR = YYMARKER;
	goto yy3;
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'm':	goto yy24;
	case 'p':	goto yy25;
	default:	goto yy8;
	}
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'u':	goto yy19;
	default:	goto yy8;
	}
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
	case 't':	goto yy16;
	default:	goto yy8;
	}
yy12:
	yych = *++YYCURSOR;
	switch (yych) {
	case 't':	goto yy13;
	default:	goto yy8;
	}
yy13:
	yych = *++YYCURSOR;
	switch (yych) {
	case ';':	goto yy14;
	default:	goto yy8;
	}
yy14:
	++YYCURSOR;
#line 64 "XMLUnescape.re"
	{ rval += '>'; thisTokStart = YYCURSOR; goto start; }
#line 149 "XMLUnescape.cpp"
yy16:
	yych = *++YYCURSOR;
	switch (yych) {
	case ';':	goto yy17;
	default:	goto yy8;
	}
yy17:
	++YYCURSOR;
#line 65 "XMLUnescape.re"
	{ rval += '<'; thisTokStart = YYCURSOR; goto start; }
#line 160 "XMLUnescape.cpp"
yy19:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'o':	goto yy20;
	default:	goto yy8;
	}
yy20:
	yych = *++YYCURSOR;
	switch (yych) {
	case 't':	goto yy21;
	default:	goto yy8;
	}
yy21:
	yych = *++YYCURSOR;
	switch (yych) {
	case ';':	goto yy22;
	default:	goto yy8;
	}
yy22:
	++YYCURSOR;
#line 67 "XMLUnescape.re"
	{ rval += '\"'; thisTokStart = YYCURSOR; goto start; }
#line 183 "XMLUnescape.cpp"
yy24:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'p':	goto yy30;
	default:	goto yy8;
	}
yy25:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'o':	goto yy26;
	default:	goto yy8;
	}
yy26:
	yych = *++YYCURSOR;
	switch (yych) {
	case 's':	goto yy27;
	default:	goto yy8;
	}
yy27:
	yych = *++YYCURSOR;
	switch (yych) {
	case ';':	goto yy28;
	default:	goto yy8;
	}
yy28:
	++YYCURSOR;
#line 68 "XMLUnescape.re"
	{ rval += '\''; thisTokStart = YYCURSOR; goto start; }
#line 212 "XMLUnescape.cpp"
yy30:
	yych = *++YYCURSOR;
	switch (yych) {
	case ';':	goto yy31;
	default:	goto yy8;
	}
yy31:
	++YYCURSOR;
#line 66 "XMLUnescape.re"
	{ rval += '&'; thisTokStart = YYCURSOR; goto start; }
#line 223 "XMLUnescape.cpp"
yy33:
	yych = *++YYCURSOR;
	switch (yych) {
	case ';':	goto yy8;
	default:	goto yy39;
	}
yy34:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy34;
	case ';':	goto yy36;
	default:	goto yy8;
	}
yy36:
	++YYCURSOR;
#line 82 "XMLUnescape.re"
	{
			unsigned long lval = strtoul( thisTokStart + 2, NULL, 10 );
			if (lval > CHAR_MAX)
			{
				XML_ERROR(XMLParserError::MALFORMED_REFERENCE, stringPrint("XML escape code in unsupported range: %d", YYCURSOR - 1));
				return std::string();
			}
			char val = lval;
			rval += val;
			thisTokStart = YYCURSOR; goto start;
		}
#line 262 "XMLUnescape.cpp"
yy38:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy39:
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy38;
	case ';':	goto yy40;
	default:	goto yy8;
	}
yy40:
	++YYCURSOR;
#line 70 "XMLUnescape.re"
	{
			unsigned long lval = strtoul( thisTokStart + 3, NULL, 16 );
			if (lval > CHAR_MAX)
			{
				XML_ERROR(XMLParserError::MALFORMED_REFERENCE, stringPrint("XML escape code in unsupported range: %d", YYCURSOR - 1));
				return std::string();
			}
			char val = lval;
			rval += val;
			thisTokStart = YYCURSOR; goto start;
		}
#line 308 "XMLUnescape.cpp"
}
#line 95 "XMLUnescape.re"


		return rval.toString();
	}

} // end namespace OpenWBEM
