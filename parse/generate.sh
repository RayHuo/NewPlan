lex -o ../sources/lex.cpp lex.l
yacc --defines=../headfile/parse.h -o ../sources/parse.cpp parse.y
