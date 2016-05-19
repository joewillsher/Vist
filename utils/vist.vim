" Vim syntax file
" Language: vist
" Maintainer: Josef Willsher
" Last Change: 19 May 2016

if exists("b:current_syntax")
	finish
endif

syn keyword vistKeywords for in return do return if else skipwhite

syn keyword vistRefKeyword ref skipwhite nextgroup=vistTypeKeyword
syn keyword vistTypeKeyword type concept skipwhite nextgroup=vistTypeName
syn match vistTypeName /\<[A-Za-z_][A-Za-z_0-9\.]*\>/ skipwhite contained

syn keyword vistBoolean true false
syn match vistDecimal /[+\-]\?\<\([0-9][0-9_]*\)\([.][0-9_]*\)\?)\?\>/

syn region vistComment start="//" end="$"
syn region vistComment start="/\*" end="\*/"
syn region vistString start=/"/ skip=/\\\\\|\\"/ end=/"/

syn region vistTypeBody start="{" end="}" fold transparent

syn match vistTypeConstraint /|/ nextgroup=vistTypeName skipwhite
syn match vistReturnTypeDeclaration /->/ nextgroup=vistTypeName skipwhite

syn keyword vistFuncKeyword func skipwhite nextGroup=vistVarName
syn keyword vistInitKeyword init skipwhite nextGroup=vistTypeInstanceName


syn keyword vistDeclKeyword let var skipwhite nextgroup=vistVarName
syn match vistVarName /\<[A-Za-z_][A-Za-z_0-9]*\>/ skipwhite contained nextgroup=vistFunctionTypeDeclaration,vistTypeDeclaration
syn match vistTypeInstanceName /\<[A-Za-z_][A-Za-z_0-9]*\>/ skipwhite contained nextgroup=vistReturnTypeDeclaration,vistVarName
syn match vistTypeDeclaration /:/ nextgroup=vistTypeInstanceName skipwhite
syn match vistFunctionTypeDeclaration /::/ nextgroup=vistTypeInstanceName skipwhite


syn match vistImplicitVarName /\$\<[0-9]\+\>/
syn keyword vistIdentifierKeyword self

let b:current_syntax = "vist"


hi def link vistKeywords Statement
hi def link vistFuncKeyword Statement
hi def link vistInitKeyword Statement
hi def link vistComment	 Comment
hi def link vistBoolean	 Boolean
hi def link vistTypeName Type
hi def link vistTypeKeyword Statement
hi def link vistRefKeyword Statement
hi def link vistDecimal Number
hi def link vistTypeInstanceName Type
hi def link vistTypeConstraint Special
hi def link vistReturnTypeDeclaration Special
hi def link vistTypeDeclaration Special
hi def link vistFunctionTypeDeclaration Special
hi def link vistString String
hi def link vistDeclKeyword Statement
hi def link vistIdentifierKeyword Identifier
hi def link vistImplicitVarName Identifier


