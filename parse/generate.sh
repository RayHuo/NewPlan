lex -o ../lex.cpp lex.l
yacc --defines=../parse.h -o ../parse.cpp parse.y
