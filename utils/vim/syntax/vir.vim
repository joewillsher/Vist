" Vim syntax file
" Language: vir
" Maintainer: Josef Willsher
" Last Change: 19 May 2016

if exists("b:current_syntax")
	finish
endif

syn keyword virOperations struct existential refcounted struct_extract variable mutable_variable_addr variable_addr builtin return call tuple tuple_extract int_literal bool_literal break cond_break func type store in load alloc tuple_element struct_element existential_construct existential_construct_nonlocal existential_witness existential_project existential_project_member apply string_literal utf8 utf16 existential_export_buffer bitcast to destroy_val destroy_addr copy_addr alloc_object retain_object release_unowned_object release_object dealloc_unowned_object dealloc_object dealloc_stack cast_break function_ref class_project_instance skipwhite

syn keyword builtinInsts i_add i_sub i_mul i_div i_rem i_rem i_eq i_neq b_eq i_add_unchecked i_mul_unchecked i_pow cond_fail i_cmp_lte i_cmp_gte i_cmp_lt i_cmp_gt i_shl i_shr i_and i_or i_xor b_and b_or stack_alloc heap_alloc heap_free mem_copy opaque_store advance_pointer opaque_load f_add f_sub f_mul f_div f_rem f_eq f_neq f_cmp_lte f_cmp_gte f_cmp_lt f_cmp_gt trunc_int_8 trunc_int_16 trunc_int_32 skipwhite


syn keyword virTypeDecl type witness_table existential conforms skipwhite
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
hi def link builtinInsts Statement
hi def link virBlock Special
hi def link virType Type
hi def link virPath String
hi def link virAttr Special

hi def link virFuncKeyword Statement

hi def link virComment	 Comment
hi def link virBoolean	 Boolean
hi def link virDecimal Number

