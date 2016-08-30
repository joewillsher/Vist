" Vim syntax file
" Language: vist
" Maintainer: Josef Willsher
" Last Change: 19 May 2016

if exists("b:current_syntax")
	finish
endif

syn keyword vistKeywords for in return do return while if else typeof skipwhite

syn match vistAttribute /@\<\w\+\>/ skipwhite nextgroup=vistTypeKeyword,vistFuncKeyword,vistInitKeyword,vistAttribute

syn keyword vistRefKeyword ref skipwhite nextgroup=vistTypeKeyword
syn keyword vistTypeKeyword type concept skipwhite nextgroup=vistTypeName
syn match vistTypeName /\<[A-Za-z_][A-Za-z_0-9\.]*\>/ skipwhite contained nextgroup=vistTypeName

syn keyword vistBoolean true false
syn match vistDecimal /[+\-]\?\<\([0-9][0-9_]*\)\([.][0-9_]*\)\?)\?\>/
syn match vistHex /[+\-]\?\<0x[0-9A-Fa-f][0-9A-Fa-f_]*\(\([.][0-9A-Fa-f_]*\)\?[pP][+\-]\?[0-9][0-9_]*\)\?\>/

syn region vistComment start="//" end="$"
syn region vistComment start="/\*" end="\*/"
syn region vistString start=/"/ skip=/\\\\\|\\"/ end=/"/

syn region vistTypeBody start="{" end="}" fold transparent

syn match vistTypeConstraint /|/ nextgroup=vistTypeName skipwhite
syn match vistReturnTypeDeclaration /->/ nextgroup=vistTypeName skipwhite

syn keyword vistFuncKeyword func skipwhite nextgroup=vistFuncName
syn keyword vistInitKeyword init skipwhite nextgroup=vistTypeInstanceName

syn keyword typeCoerceKeyword as the skipwhite nextgroup=vistTypeInstanceName

syn keyword vistDeclKeyword let var skipwhite nextgroup=vistVarName
syn match vistVarName /\<[A-Za-z_][A-Za-z_0-9]*\>/ skipwhite contained nextgroup=vistTypeDeclaration
syn match vistTypeDeclaration /:/ skipwhite contained nextgroup=vistTypeInstanceName
syn match vistTypeListDeliminer /,/ contained skipwhite nextgroup=vistVarName

syn match vistTypeInstanceName /\<[A-Za-z_][A-Za-z_0-9\.]*\>/ skipwhite contained nextgroup=vistKeywords,vistTypeInstanceName,vistReturnTypeDeclaration,vistTypeListDeliminer
syn match vistFuncName /\<[A-Za-z_][A-Za-z_0-9]*\>/ skipwhite contained nextgroup=vistFunctionTypeDeclaration
syn match vistFunctionTypeDeclaration /::/ nextgroup=vistTypeInstanceName skipwhite


syn match vistImplicitVarName /\$\<[0-9]\+\>/
syn keyword vistIdentifierKeyword self

let b:current_syntax = "vist"


hi def link vistKeywords Statement
hi def link vistFuncKeyword Statement
hi def link vistInitKeyword Statement
hi def link typeCoerceKeyword Statement
hi def link vistComment	 Comment
hi def link vistBoolean	 Boolean
hi def link vistTypeName Type
hi def link vistTypeKeyword Statement
hi def link vistRefKeyword Statement
hi def link vistDecimal Number
hi def link vistHex Number
hi def link vistTypeInstanceName Type
hi def link vistTypeConstraint Special
hi def link vistReturnTypeDeclaration Special
hi def link vistTypeDeclaration Special
hi def link vistFunctionTypeDeclaration Special
hi def link vistString String
hi def link vistDeclKeyword Statement
hi def link vistIdentifierKeyword Identifier
hi def link vistImplicitVarName Identifier
hi def link vistFuncName Function
hi def link vistAttribute Statement
hi def link vistFunctions Function
hi def link vistVarName Identifier

