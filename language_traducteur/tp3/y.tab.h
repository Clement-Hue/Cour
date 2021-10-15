/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SI = 258,
    ALORS = 259,
    PROGRAMME = 260,
    DECLARE = 261,
    NATUREL = 262,
    CARACTERE = 263,
    BOOLEEN = 264,
    DEBUT = 265,
    FIN = 266,
    SINON = 267,
    FSI = 268,
    TANTQUE = 269,
    FAIRE = 270,
    FTQ = 271,
    OBTENIR = 272,
    AFFICHER = 273,
    AFFICHAINE = 274,
    ALALIGNE = 275,
    OU = 276,
    ET = 277,
    NON = 278,
    VRAI = 279,
    FAUX = 280,
    NOMBRE = 281,
    IDENT = 282,
    CAR = 283,
    CHAINE = 284,
    PF = 285,
    PO = 286,
    PLUS = 287,
    MINUS = 288,
    MULT = 289,
    DIVIDE = 290,
    EQUAL = 291,
    LESS = 292,
    LESS_EQUAL = 293,
    MORE = 294,
    MORE_EQUAL = 295,
    EQUAL_EQUAL = 296,
    NOT_EQUAL = 297,
    PV = 298,
    POINT = 299
  };
#endif
/* Tokens.  */
#define SI 258
#define ALORS 259
#define PROGRAMME 260
#define DECLARE 261
#define NATUREL 262
#define CARACTERE 263
#define BOOLEEN 264
#define DEBUT 265
#define FIN 266
#define SINON 267
#define FSI 268
#define TANTQUE 269
#define FAIRE 270
#define FTQ 271
#define OBTENIR 272
#define AFFICHER 273
#define AFFICHAINE 274
#define ALALIGNE 275
#define OU 276
#define ET 277
#define NON 278
#define VRAI 279
#define FAUX 280
#define NOMBRE 281
#define IDENT 282
#define CAR 283
#define CHAINE 284
#define PF 285
#define PO 286
#define PLUS 287
#define MINUS 288
#define MULT 289
#define DIVIDE 290
#define EQUAL 291
#define LESS 292
#define LESS_EQUAL 293
#define MORE 294
#define MORE_EQUAL 295
#define EQUAL_EQUAL 296
#define NOT_EQUAL 297
#define PV 298
#define POINT 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
