" Language: bI
" Maintainer: (c) Dmitry Ponyatov <dponyatov@gmail.com>, all rights reserved

au BufNewFile,BufRead src.src	set filetype=simply

au BufNewFile,BufRead log.log	set filetype=simply
au BufNewFile,BufRead log.log	set autoread
au BufNewFile,BufRead log.log	set nowrap

au BufNewFile,BufRead ypp.ypp	set filetype=yacc
au BufNewFile,BufRead lpp.lpp	set filetype=lex
au BufNewFile,BufRead hpp.hpp	set filetype=cpp
au BufNewFile,BufRead cpp.cpp	set filetype=cpp

