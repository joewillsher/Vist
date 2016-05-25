" Vim syntax file
" Language: vir
" Maintainer: Josef Willsher
" Last Change: 19 May 2016

if exists("b:current_syntax")
	finish
endif

syn keyword virOperations struct struct_extract variable_decl builtin return call tuple tuple_extract int_literal bool_literal break i_add i_sub i_mul condfail func type store in load alloc tuple_element struct_element existential_box existential_witness existential_unbox apply string_literal utf8 utf16 skipwhite 

syn keyword virTypeDecl type existential skipwhite
syn keyword virFuncKeyword func skipwhite

syn match virGlobal /@[\-\.]*\<\w\+\>/ skipwhite 
syn match virLocal /%\<\w\+\>/ skipwhite
syn match virBlock /$\<\w\+\>/ skipwhite
syn match virType /#[\*]*\<[A-Za-z_0-9\.]*\>/ skipwhite
syn match virPath /!\<\w\+\>/ skipwhite
syn match virAttr /&\<\w\+\>/ skipwhite

syn keyword virBoolean true false
syn match virDecimal /[+\-]\?\<\([0-9][0-9_]*\)\([.][0-9_]*\)\?)\?\>/

syn region virComment start="//" end="$"
syn region virString start=/"/ skip=/\\\\\|\\"/ end=/"/


let b:current_syntax = "vir"


hi def link virOperations Statement
hi def link virGlobal Function
hi def link virTypeDecl Statement
hi def link virLocal Identifier
hi def link virBlock Special
hi def link virType Type
hi def link virPath String
hi def link virAttr Special

hi def link virFuncKeyword Statement

hi def link virComment	 Comment
hi def link virBoolean	 Boolean
hi def link virDecimal Number

