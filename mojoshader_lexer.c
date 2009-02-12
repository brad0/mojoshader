/* Generated by re2c 0.12.1 on Thu Feb 12 13:52:20 2009 */
#line 1 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
/**
 * MojoShader; generate shader programs from bytecode of compiled
 *  Direct3D shaders.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 *
 *  This file written by Ryan C. Gordon.
 */

// This was originally based on examples/pp-c.re from re2c: http://re2c.org/
//   re2c is public domain code.
//
// You build mojoshader_lexer_preprocessor.c from the .re file with re2c...
// re2c -is -o mojoshader_lexer_preprocessor.c mojoshader_lexer_preprocessor.re
//
// Changes to the lexer are done to the .re file, not the C code!
//
// Please note that this isn't a perfect C lexer, since it is used for both
//  HLSL and shader assembly language, and follows the quirks of Microsoft's
//  tools.

#define __MOJOSHADER_INTERNAL__ 1
#include "mojoshader_internal.h"

typedef unsigned char uchar;

#define RET(t) do { update_state(s, cursor, token); return t; } while (0)
#define YYCTYPE uchar
#define YYCURSOR cursor
#define YYLIMIT limit
#define YYMARKER s->lexer_marker
#define YYFILL(n) { if ((n) == 1) { RET(TOKEN_EOI); } }

static void update_state(IncludeState *s, const uchar *cur, const uchar *tok)
{
    s->bytes_left -= (unsigned int) (cur - ((const uchar *) s->source));
    s->source = (const char *) cur;
    s->token = (const char *) tok;
} // update_state

Token preprocessor_internal_lexer(IncludeState *s)
{
    const uchar *cursor = (const uchar *) s->source;
    const uchar *token;
    const uchar *limit = cursor + s->bytes_left;
    int saw_newline = 0;

scanner_loop:
    token = cursor;

    if (YYLIMIT == YYCURSOR)
        RET(TOKEN_EOI);

#line 67 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"



#line 61 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;

	if((YYLIMIT - YYCURSOR) < 8) YYFILL(8);
	yych = *YYCURSOR;
	switch(yych) {
	case 0x09:
	case 0x0B:
	case 0x0C:
	case ' ':	goto yy62;
	case 0x0A:	goto yy64;
	case 0x0D:	goto yy66;
	case '!':	goto yy34;
	case '"':	goto yy13;
	case '#':	goto yy36;
	case '%':	goto yy24;
	case '&':	goto yy28;
	case '\'':	goto yy9;
	case '(':	goto yy38;
	case ')':	goto yy40;
	case '*':	goto yy22;
	case '+':	goto yy18;
	case ',':	goto yy46;
	case '-':	goto yy20;
	case '.':	goto yy11;
	case '/':	goto yy2;
	case '0':	goto yy6;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy8;
	case ':':	goto yy50;
	case ';':	goto yy52;
	case '<':	goto yy16;
	case '=':	goto yy32;
	case '>':	goto yy14;
	case '?':	goto yy58;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy4;
	case '[':	goto yy42;
	case '\\':	goto yy60;
	case ']':	goto yy44;
	case '^':	goto yy26;
	case '{':	goto yy54;
	case '|':	goto yy30;
	case '}':	goto yy56;
	case '~':	goto yy48;
	default:	goto yy67;
	}
yy2:
	++YYCURSOR;
	if((yych = *YYCURSOR) <= '.') {
		if(yych == '*') goto yy230;
	} else {
		if(yych <= '/') goto yy228;
		if(yych == '=') goto yy226;
	}
#line 118 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('/'); }
#line 178 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy4:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy225;
yy5:
#line 73 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_IDENTIFIER); }
#line 186 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy6:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych <= 'X') {
		if(yych <= 'T') {
			if(yych == 'L') goto yy200;
			goto yy216;
		} else {
			if(yych <= 'U') goto yy200;
			if(yych <= 'W') goto yy216;
			goto yy217;
		}
	} else {
		if(yych <= 't') {
			if(yych == 'l') goto yy200;
			goto yy216;
		} else {
			if(yych <= 'u') goto yy200;
			if(yych == 'x') goto yy217;
			goto yy216;
		}
	}
yy7:
#line 77 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_INT_LITERAL); }
#line 212 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy8:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	goto yy198;
yy9:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych != 0x0A) goto yy188;
yy10:
#line 147 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ printf("bad char\n"); goto scanner_loop; }
#line 224 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy11:
	++YYCURSOR;
	if((yych = *YYCURSOR) <= '/') goto yy12;
	if(yych <= '9') goto yy179;
yy12:
#line 110 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('.'); }
#line 232 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy13:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == 0x0A) goto yy10;
	goto yy170;
yy14:
	++YYCURSOR;
	if((yych = *YYCURSOR) <= '<') goto yy15;
	if(yych <= '=') goto yy163;
	if(yych <= '>') goto yy165;
yy15:
#line 121 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('>'); }
#line 246 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy16:
	++YYCURSOR;
	if((yych = *YYCURSOR) <= ';') goto yy17;
	if(yych <= '<') goto yy159;
	if(yych <= '=') goto yy157;
yy17:
#line 120 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('<'); }
#line 255 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy18:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '+') goto yy153;
	if(yych == '=') goto yy155;
#line 116 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('+'); }
#line 262 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy20:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '-') goto yy149;
	if(yych == '=') goto yy151;
#line 115 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('-'); }
#line 269 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy22:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '=') goto yy147;
#line 117 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('*'); }
#line 275 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy24:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '=') goto yy145;
#line 119 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('%'); }
#line 281 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy26:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '=') goto yy143;
#line 122 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('^'); }
#line 287 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy28:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '&') goto yy139;
	if(yych == '=') goto yy141;
#line 112 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('&'); }
#line 294 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy30:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '=') goto yy137;
	if(yych == '|') goto yy135;
#line 123 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('|'); }
#line 301 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy32:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '=') goto yy133;
#line 128 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('='); }
#line 307 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy34:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '=') goto yy131;
#line 113 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('!'); }
#line 313 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy36:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych <= 'c') {
		if(yych <= 0x1F) {
			if(yych == 0x09) goto yy72;
		} else {
			if(yych <= ' ') goto yy72;
			if(yych == '#') goto yy79;
		}
	} else {
		if(yych <= 'k') {
			if(yych <= 'e') goto yy72;
			if(yych == 'i') goto yy72;
		} else {
			if(yych <= 'l') goto yy72;
			if(yych == 'u') goto yy72;
		}
	}
yy37:
#line 131 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('#'); }
#line 336 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy38:
	++YYCURSOR;
#line 106 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('('); }
#line 341 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy40:
	++YYCURSOR;
#line 107 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(')'); }
#line 346 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy42:
	++YYCURSOR;
#line 108 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('['); }
#line 351 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy44:
	++YYCURSOR;
#line 109 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(']'); }
#line 356 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy46:
	++YYCURSOR;
#line 111 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(','); }
#line 361 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy48:
	++YYCURSOR;
#line 114 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('~'); }
#line 366 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy50:
	++YYCURSOR;
#line 124 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(':'); }
#line 371 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy52:
	++YYCURSOR;
#line 125 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(';'); }
#line 376 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy54:
	++YYCURSOR;
#line 126 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('{'); }
#line 381 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy56:
	++YYCURSOR;
#line 127 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('}'); }
#line 386 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy58:
	++YYCURSOR;
#line 129 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('?'); }
#line 391 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy60:
	++YYCURSOR;
#line 130 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET('\\'); }
#line 396 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy62:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy70;
yy63:
#line 145 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ goto scanner_loop; }
#line 404 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy64:
	++YYCURSOR;
yy65:
#line 146 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ s->line++; RET('\n'); }
#line 410 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy66:
	yych = *++YYCURSOR;
	if(yych == 0x0A) goto yy68;
	goto yy65;
yy67:
	yych = *++YYCURSOR;
	goto yy10;
yy68:
	yych = *++YYCURSOR;
	goto yy65;
yy69:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy70:
	if(yych <= 0x0A) {
		if(yych == 0x09) goto yy69;
		goto yy63;
	} else {
		if(yych <= 0x0C) goto yy69;
		if(yych == ' ') goto yy69;
		goto yy63;
	}
yy71:
	++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 7) YYFILL(7);
	yych = *YYCURSOR;
yy72:
	if(yych <= 'e') {
		if(yych <= 0x1F) {
			if(yych == 0x09) goto yy71;
		} else {
			if(yych <= ' ') goto yy71;
			if(yych <= 'c') goto yy73;
			if(yych <= 'd') goto yy77;
			goto yy74;
		}
	} else {
		if(yych <= 'k') {
			if(yych == 'i') goto yy75;
		} else {
			if(yych <= 'l') goto yy78;
			if(yych == 'u') goto yy76;
		}
	}
yy73:
	YYCURSOR = YYMARKER;
	if(yyaccept <= 2) {
		if(yyaccept <= 1) {
			if(yyaccept <= 0) {
				goto yy7;
			} else {
				goto yy10;
			}
		} else {
			goto yy37;
		}
	} else {
		if(yyaccept <= 3) {
			goto yy98;
		} else {
			goto yy181;
		}
	}
yy74:
	yych = *++YYCURSOR;
	if(yych <= 'm') {
		if(yych == 'l') goto yy114;
		goto yy73;
	} else {
		if(yych <= 'n') goto yy115;
		if(yych == 'r') goto yy116;
		goto yy73;
	}
yy75:
	yych = *++YYCURSOR;
	if(yych == 'f') goto yy97;
	if(yych == 'n') goto yy96;
	goto yy73;
yy76:
	yych = *++YYCURSOR;
	if(yych == 'n') goto yy91;
	goto yy73;
yy77:
	yych = *++YYCURSOR;
	if(yych == 'e') goto yy85;
	goto yy73;
yy78:
	yych = *++YYCURSOR;
	if(yych == 'i') goto yy81;
	goto yy73;
yy79:
	++YYCURSOR;
#line 105 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_HASHHASH); }
#line 506 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy81:
	yych = *++YYCURSOR;
	if(yych != 'n') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy73;
	++YYCURSOR;
#line 134 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_LINE); }
#line 515 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy85:
	yych = *++YYCURSOR;
	if(yych != 'f') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'i') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'n') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy73;
	++YYCURSOR;
#line 135 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_DEFINE); }
#line 528 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy91:
	yych = *++YYCURSOR;
	if(yych != 'd') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'f') goto yy73;
	++YYCURSOR;
#line 136 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_UNDEF); }
#line 539 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy96:
	yych = *++YYCURSOR;
	if(yych == 'c') goto yy108;
	goto yy73;
yy97:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == 'd') goto yy100;
	if(yych == 'n') goto yy99;
yy98:
#line 137 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_IF); }
#line 552 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy99:
	yych = *++YYCURSOR;
	if(yych == 'd') goto yy104;
	goto yy73;
yy100:
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'f') goto yy73;
	++YYCURSOR;
#line 138 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_IFDEF); }
#line 565 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy104:
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'f') goto yy73;
	++YYCURSOR;
#line 139 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_IFNDEF); }
#line 574 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy108:
	yych = *++YYCURSOR;
	if(yych != 'l') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'u') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'd') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy73;
	++YYCURSOR;
#line 133 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_INCLUDE); }
#line 587 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy114:
	yych = *++YYCURSOR;
	if(yych == 'i') goto yy125;
	if(yych == 's') goto yy126;
	goto yy73;
yy115:
	yych = *++YYCURSOR;
	if(yych == 'd') goto yy121;
	goto yy73;
yy116:
	yych = *++YYCURSOR;
	if(yych != 'r') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'o') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'r') goto yy73;
	++YYCURSOR;
#line 143 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_ERROR); }
#line 607 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy121:
	yych = *++YYCURSOR;
	if(yych != 'i') goto yy73;
	yych = *++YYCURSOR;
	if(yych != 'f') goto yy73;
	++YYCURSOR;
#line 142 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_ENDIF); }
#line 616 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy125:
	yych = *++YYCURSOR;
	if(yych == 'f') goto yy129;
	goto yy73;
yy126:
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy73;
	++YYCURSOR;
#line 140 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_ELSE); }
#line 627 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy129:
	++YYCURSOR;
#line 141 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_PP_ELIF); }
#line 632 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy131:
	++YYCURSOR;
#line 104 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_NEQ); }
#line 637 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy133:
	++YYCURSOR;
#line 103 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_EQL); }
#line 642 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy135:
	++YYCURSOR;
#line 100 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_OROR); }
#line 647 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy137:
	++YYCURSOR;
#line 94 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_ORASSIGN); }
#line 652 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy139:
	++YYCURSOR;
#line 99 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_ANDAND); }
#line 657 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy141:
	++YYCURSOR;
#line 93 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_ANDASSIGN); }
#line 662 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy143:
	++YYCURSOR;
#line 92 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_XORASSIGN); }
#line 667 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy145:
	++YYCURSOR;
#line 91 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_MODASSIGN); }
#line 672 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy147:
	++YYCURSOR;
#line 89 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_MULTASSIGN); }
#line 677 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy149:
	++YYCURSOR;
#line 96 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_DECREMENT); }
#line 682 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy151:
	++YYCURSOR;
#line 88 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_SUBASSIGN); }
#line 687 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy153:
	++YYCURSOR;
#line 95 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_INCREMENT); }
#line 692 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy155:
	++YYCURSOR;
#line 87 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_ADDASSIGN); }
#line 697 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy157:
	++YYCURSOR;
#line 101 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_LEQ); }
#line 702 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy159:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '=') goto yy161;
#line 98 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_LSHIFT); }
#line 708 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy161:
	++YYCURSOR;
#line 86 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_LSHIFTASSIGN); }
#line 713 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy163:
	++YYCURSOR;
#line 102 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_GEQ); }
#line 718 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy165:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '=') goto yy167;
#line 97 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_RSHIFT); }
#line 724 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy167:
	++YYCURSOR;
#line 85 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_RSHIFTASSIGN); }
#line 729 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy169:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy170:
	if(yych <= '!') {
		if(yych == 0x0A) goto yy73;
		goto yy169;
	} else {
		if(yych <= '"') goto yy172;
		if(yych != '\\') goto yy169;
	}
yy171:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'b') {
		if(yych <= '7') {
			if(yych <= '&') {
				if(yych == '"') goto yy169;
				goto yy73;
			} else {
				if(yych <= '\'') goto yy169;
				if(yych <= '/') goto yy73;
				goto yy175;
			}
		} else {
			if(yych <= '[') {
				if(yych == '?') goto yy169;
				goto yy73;
			} else {
				if(yych <= '\\') goto yy169;
				if(yych <= '`') goto yy73;
				goto yy169;
			}
		}
	} else {
		if(yych <= 'r') {
			if(yych <= 'm') {
				if(yych == 'f') goto yy169;
				goto yy73;
			} else {
				if(yych <= 'n') goto yy169;
				if(yych <= 'q') goto yy73;
				goto yy169;
			}
		} else {
			if(yych <= 'u') {
				if(yych == 't') goto yy169;
				goto yy73;
			} else {
				if(yych <= 'v') goto yy169;
				if(yych == 'x') goto yy174;
				goto yy73;
			}
		}
	}
yy172:
	++YYCURSOR;
#line 83 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_STRING_LITERAL); }
#line 791 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy174:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '@') {
		if(yych <= '/') goto yy73;
		if(yych <= '9') goto yy177;
		goto yy73;
	} else {
		if(yych <= 'F') goto yy177;
		if(yych <= '`') goto yy73;
		if(yych <= 'f') goto yy177;
		goto yy73;
	}
yy175:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '"') {
		if(yych == 0x0A) goto yy73;
		if(yych <= '!') goto yy169;
		goto yy172;
	} else {
		if(yych <= '7') {
			if(yych <= '/') goto yy169;
			goto yy175;
		} else {
			if(yych == '\\') goto yy171;
			goto yy169;
		}
	}
yy177:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '9') {
		if(yych <= '!') {
			if(yych == 0x0A) goto yy73;
			goto yy169;
		} else {
			if(yych <= '"') goto yy172;
			if(yych <= '/') goto yy169;
			goto yy177;
		}
	} else {
		if(yych <= '[') {
			if(yych <= '@') goto yy169;
			if(yych <= 'F') goto yy177;
			goto yy169;
		} else {
			if(yych <= '\\') goto yy171;
			if(yych <= '`') goto yy169;
			if(yych <= 'f') goto yy177;
			goto yy169;
		}
	}
yy179:
	yyaccept = 4;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	if(yych <= 'K') {
		if(yych <= 'D') {
			if(yych <= '/') goto yy181;
			if(yych <= '9') goto yy179;
		} else {
			if(yych <= 'E') goto yy182;
			if(yych <= 'F') goto yy183;
		}
	} else {
		if(yych <= 'e') {
			if(yych <= 'L') goto yy183;
			if(yych >= 'e') goto yy182;
		} else {
			if(yych <= 'f') goto yy183;
			if(yych == 'l') goto yy183;
		}
	}
yy181:
#line 80 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_FLOAT_LITERAL); }
#line 873 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy182:
	yych = *++YYCURSOR;
	if(yych <= ',') {
		if(yych == '+') goto yy184;
		goto yy73;
	} else {
		if(yych <= '-') goto yy184;
		if(yych <= '/') goto yy73;
		if(yych <= '9') goto yy185;
		goto yy73;
	}
yy183:
	yych = *++YYCURSOR;
	goto yy181;
yy184:
	yych = *++YYCURSOR;
	if(yych <= '/') goto yy73;
	if(yych >= ':') goto yy73;
yy185:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'K') {
		if(yych <= '9') {
			if(yych <= '/') goto yy181;
			goto yy185;
		} else {
			if(yych == 'F') goto yy183;
			goto yy181;
		}
	} else {
		if(yych <= 'f') {
			if(yych <= 'L') goto yy183;
			if(yych <= 'e') goto yy181;
			goto yy183;
		} else {
			if(yych == 'l') goto yy183;
			goto yy181;
		}
	}
yy187:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy188:
	if(yych <= '&') {
		if(yych == 0x0A) goto yy73;
		goto yy187;
	} else {
		if(yych <= '\'') goto yy190;
		if(yych != '\\') goto yy187;
	}
yy189:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'b') {
		if(yych <= '7') {
			if(yych <= '&') {
				if(yych == '"') goto yy187;
				goto yy73;
			} else {
				if(yych <= '\'') goto yy187;
				if(yych <= '/') goto yy73;
				goto yy192;
			}
		} else {
			if(yych <= '[') {
				if(yych == '?') goto yy187;
				goto yy73;
			} else {
				if(yych <= '\\') goto yy187;
				if(yych <= '`') goto yy73;
				goto yy187;
			}
		}
	} else {
		if(yych <= 'r') {
			if(yych <= 'm') {
				if(yych == 'f') goto yy187;
				goto yy73;
			} else {
				if(yych <= 'n') goto yy187;
				if(yych <= 'q') goto yy73;
				goto yy187;
			}
		} else {
			if(yych <= 'u') {
				if(yych == 't') goto yy187;
				goto yy73;
			} else {
				if(yych <= 'v') goto yy187;
				if(yych == 'x') goto yy191;
				goto yy73;
			}
		}
	}
yy190:
	yych = *++YYCURSOR;
	goto yy7;
yy191:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '@') {
		if(yych <= '/') goto yy73;
		if(yych <= '9') goto yy194;
		goto yy73;
	} else {
		if(yych <= 'F') goto yy194;
		if(yych <= '`') goto yy73;
		if(yych <= 'f') goto yy194;
		goto yy73;
	}
yy192:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '\'') {
		if(yych == 0x0A) goto yy73;
		if(yych <= '&') goto yy187;
		goto yy190;
	} else {
		if(yych <= '7') {
			if(yych <= '/') goto yy187;
			goto yy192;
		} else {
			if(yych == '\\') goto yy189;
			goto yy187;
		}
	}
yy194:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '9') {
		if(yych <= '&') {
			if(yych == 0x0A) goto yy73;
			goto yy187;
		} else {
			if(yych <= '\'') goto yy190;
			if(yych <= '/') goto yy187;
			goto yy194;
		}
	} else {
		if(yych <= '[') {
			if(yych <= '@') goto yy187;
			if(yych <= 'F') goto yy194;
			goto yy187;
		} else {
			if(yych <= '\\') goto yy189;
			if(yych <= '`') goto yy187;
			if(yych <= 'f') goto yy194;
			goto yy187;
		}
	}
yy196:
	yyaccept = 4;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == 'E') goto yy207;
	if(yych == 'e') goto yy207;
	goto yy206;
yy197:
	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
yy198:
	if(yych <= 'L') {
		if(yych <= '9') {
			if(yych == '.') goto yy196;
			if(yych <= '/') goto yy7;
			goto yy197;
		} else {
			if(yych == 'E') goto yy199;
			if(yych <= 'K') goto yy7;
			goto yy200;
		}
	} else {
		if(yych <= 'e') {
			if(yych == 'U') goto yy200;
			if(yych <= 'd') goto yy7;
		} else {
			if(yych <= 'l') {
				if(yych <= 'k') goto yy7;
				goto yy200;
			} else {
				if(yych == 'u') goto yy200;
				goto yy7;
			}
		}
	}
yy199:
	yych = *++YYCURSOR;
	if(yych <= ',') {
		if(yych == '+') goto yy202;
		goto yy73;
	} else {
		if(yych <= '-') goto yy202;
		if(yych <= '/') goto yy73;
		if(yych <= '9') goto yy203;
		goto yy73;
	}
yy200:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'U') {
		if(yych == 'L') goto yy200;
		if(yych <= 'T') goto yy7;
		goto yy200;
	} else {
		if(yych <= 'l') {
			if(yych <= 'k') goto yy7;
			goto yy200;
		} else {
			if(yych == 'u') goto yy200;
			goto yy7;
		}
	}
yy202:
	yych = *++YYCURSOR;
	if(yych <= '/') goto yy73;
	if(yych >= ':') goto yy73;
yy203:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'K') {
		if(yych <= '9') {
			if(yych <= '/') goto yy181;
			goto yy203;
		} else {
			if(yych == 'F') goto yy183;
			goto yy181;
		}
	} else {
		if(yych <= 'f') {
			if(yych <= 'L') goto yy183;
			if(yych <= 'e') goto yy181;
			goto yy183;
		} else {
			if(yych == 'l') goto yy183;
			goto yy181;
		}
	}
yy205:
	yyaccept = 4;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
yy206:
	if(yych <= 'K') {
		if(yych <= 'D') {
			if(yych <= '/') goto yy181;
			if(yych <= '9') goto yy205;
			goto yy181;
		} else {
			if(yych <= 'E') goto yy211;
			if(yych <= 'F') goto yy183;
			goto yy181;
		}
	} else {
		if(yych <= 'e') {
			if(yych <= 'L') goto yy183;
			if(yych <= 'd') goto yy181;
			goto yy211;
		} else {
			if(yych <= 'f') goto yy183;
			if(yych == 'l') goto yy183;
			goto yy181;
		}
	}
yy207:
	yych = *++YYCURSOR;
	if(yych <= ',') {
		if(yych != '+') goto yy73;
	} else {
		if(yych <= '-') goto yy208;
		if(yych <= '/') goto yy73;
		if(yych <= '9') goto yy209;
		goto yy73;
	}
yy208:
	yych = *++YYCURSOR;
	if(yych <= '/') goto yy73;
	if(yych >= ':') goto yy73;
yy209:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'K') {
		if(yych <= '9') {
			if(yych <= '/') goto yy181;
			goto yy209;
		} else {
			if(yych == 'F') goto yy183;
			goto yy181;
		}
	} else {
		if(yych <= 'f') {
			if(yych <= 'L') goto yy183;
			if(yych <= 'e') goto yy181;
			goto yy183;
		} else {
			if(yych == 'l') goto yy183;
			goto yy181;
		}
	}
yy211:
	yych = *++YYCURSOR;
	if(yych <= ',') {
		if(yych != '+') goto yy73;
	} else {
		if(yych <= '-') goto yy212;
		if(yych <= '/') goto yy73;
		if(yych <= '9') goto yy213;
		goto yy73;
	}
yy212:
	yych = *++YYCURSOR;
	if(yych <= '/') goto yy73;
	if(yych >= ':') goto yy73;
yy213:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'K') {
		if(yych <= '9') {
			if(yych <= '/') goto yy181;
			goto yy213;
		} else {
			if(yych == 'F') goto yy183;
			goto yy181;
		}
	} else {
		if(yych <= 'f') {
			if(yych <= 'L') goto yy183;
			if(yych <= 'e') goto yy181;
			goto yy183;
		} else {
			if(yych == 'l') goto yy183;
			goto yy181;
		}
	}
yy215:
	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
yy216:
	if(yych <= 'L') {
		if(yych <= '9') {
			if(yych == '.') goto yy196;
			if(yych <= '/') goto yy7;
			goto yy215;
		} else {
			if(yych == 'E') goto yy199;
			if(yych <= 'K') goto yy7;
			goto yy222;
		}
	} else {
		if(yych <= 'e') {
			if(yych == 'U') goto yy222;
			if(yych <= 'd') goto yy7;
			goto yy199;
		} else {
			if(yych <= 'l') {
				if(yych <= 'k') goto yy7;
				goto yy222;
			} else {
				if(yych == 'u') goto yy222;
				goto yy7;
			}
		}
	}
yy217:
	yych = *++YYCURSOR;
	if(yych <= '@') {
		if(yych <= '/') goto yy73;
		if(yych >= ':') goto yy73;
	} else {
		if(yych <= 'F') goto yy218;
		if(yych <= '`') goto yy73;
		if(yych >= 'g') goto yy73;
	}
yy218:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'T') {
		if(yych <= '@') {
			if(yych <= '/') goto yy7;
			if(yych <= '9') goto yy218;
			goto yy7;
		} else {
			if(yych <= 'F') goto yy218;
			if(yych != 'L') goto yy7;
		}
	} else {
		if(yych <= 'k') {
			if(yych <= 'U') goto yy220;
			if(yych <= '`') goto yy7;
			if(yych <= 'f') goto yy218;
			goto yy7;
		} else {
			if(yych <= 'l') goto yy220;
			if(yych != 'u') goto yy7;
		}
	}
yy220:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'U') {
		if(yych == 'L') goto yy220;
		if(yych <= 'T') goto yy7;
		goto yy220;
	} else {
		if(yych <= 'l') {
			if(yych <= 'k') goto yy7;
			goto yy220;
		} else {
			if(yych == 'u') goto yy220;
			goto yy7;
		}
	}
yy222:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'U') {
		if(yych == 'L') goto yy222;
		if(yych <= 'T') goto yy7;
		goto yy222;
	} else {
		if(yych <= 'l') {
			if(yych <= 'k') goto yy7;
			goto yy222;
		} else {
			if(yych == 'u') goto yy222;
			goto yy7;
		}
	}
yy224:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy225:
	if(yych <= 'Z') {
		if(yych <= '/') goto yy5;
		if(yych <= '9') goto yy224;
		if(yych <= '@') goto yy5;
		goto yy224;
	} else {
		if(yych <= '_') {
			if(yych <= '^') goto yy5;
			goto yy224;
		} else {
			if(yych <= '`') goto yy5;
			if(yych <= 'z') goto yy224;
			goto yy5;
		}
	}
yy226:
	++YYCURSOR;
#line 90 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ RET(TOKEN_DIVASSIGN); }
#line 1342 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy228:
	++YYCURSOR;
#line 71 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ goto singlelinecomment; }
#line 1347 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy230:
	++YYCURSOR;
#line 70 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ goto multilinecomment; }
#line 1352 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
}
#line 148 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"


multilinecomment:
    if (YYLIMIT == YYCURSOR)
        RET(TOKEN_PP_INCOMPLETE_COMMENT);
// The "*\/" is just to avoid screwing up text editor syntax highlighting.

#line 1362 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
{
	YYCTYPE yych;
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= 0x0C) {
		if(yych == 0x0A) goto yy236;
		goto yy239;
	} else {
		if(yych <= 0x0D) goto yy238;
		if(yych != '*') goto yy239;
	}
	++YYCURSOR;
	if((yych = *YYCURSOR) == '/') goto yy241;
yy235:
#line 166 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ goto multilinecomment; }
#line 1379 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy236:
	++YYCURSOR;
yy237:
#line 160 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{
                        s->line++;
                        token = cursor-1;
                        saw_newline = 1;
                        goto multilinecomment;
                    }
#line 1390 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy238:
	yych = *++YYCURSOR;
	if(yych == 0x0A) goto yy240;
	goto yy237;
yy239:
	yych = *++YYCURSOR;
	goto yy235;
yy240:
	yych = *++YYCURSOR;
	goto yy237;
yy241:
	++YYCURSOR;
#line 155 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{
                        if (saw_newline)
                            RET('\n');
                        goto scanner_loop;
                    }
#line 1409 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
}
#line 167 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"


singlelinecomment:
    if (YYLIMIT == YYCURSOR)
        RET(TOKEN_EOI);

#line 1418 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
{
	YYCTYPE yych;
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy245;
	if(yych == 0x0D) goto yy247;
	goto yy248;
yy245:
	++YYCURSOR;
yy246:
#line 173 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ s->line++; token = cursor-1; RET('\n'); }
#line 1431 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy247:
	yych = *++YYCURSOR;
	if(yych == 0x0A) goto yy250;
	goto yy246;
yy248:
	++YYCURSOR;
#line 174 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ goto singlelinecomment; }
#line 1440 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy250:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy246;
}
#line 175 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"


// !!! FIXME
/*
bad_chars:
    if (YYLIMIT == YYCURSOR)
        RET(TOKEN_BAD_TOKEN);
*/


#line 1457 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
{
	YYCTYPE yych;
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= 0x0C) {
		if(yych <= 0x08) goto yy258;
		if(yych != 0x0A) goto yy256;
	} else {
		if(yych <= 0x0D) goto yy255;
		if(yych == ' ') goto yy256;
		goto yy258;
	}
	++YYCURSOR;
yy254:
#line 185 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ s->line++; goto scanner_loop; }
#line 1474 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy255:
	yych = *++YYCURSOR;
	if(yych == 0x0A) goto yy262;
	goto yy254;
yy256:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy261;
yy257:
#line 186 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ goto scanner_loop; }
#line 1486 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy258:
	++YYCURSOR;
#line 187 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"
	{ goto singlelinecomment; }
#line 1491 "/home/icculus/projects/mojoshader/mojoshader_lexer.c"
yy260:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy261:
	if(yych <= 0x0A) {
		if(yych == 0x09) goto yy260;
		goto yy257;
	} else {
		if(yych <= 0x0C) goto yy260;
		if(yych == ' ') goto yy260;
		goto yy257;
	}
yy262:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy254;
}
#line 188 "/home/icculus/projects/mojoshader/mojoshader_lexer.re"


    assert(0 && "Shouldn't hit this code");
    RET(TOKEN_UNKNOWN);
} // preprocessor_internal_lexer

// end of mojoshader_lexer_preprocessor.re (or .c) ...
