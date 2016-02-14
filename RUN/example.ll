; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bar.ty = type { %"(GenericType\0A  name:\22T\22\0A  concepts:(Array<ConceptType>\0A    [0]:(ConceptType\0A      name:\22Eq\22\0A      requiredFunctions:(Array<(String, FnType)>\0A      )\0A      requiredProperties:(Array<(String, Ty, Bool)>\0A      )\0A    )\0A  )\0A).ty" }
%"(GenericType\0A  name:\22T\22\0A  concepts:(Array<ConceptType>\0A    [0]:(ConceptType\0A      name:\22Eq\22\0A      requiredFunctions:(Array<(String, FnType)>\0A      )\0A      requiredProperties:(Array<(String, Ty, Bool)>\0A      )\0A    )\0A  )\0A).ty" = type { %Int.ty }
%Int.ty = type { i64 }

define void @main() {
entry:
  ret void
}

; Function Attrs: alwaysinline
define %Bar.ty @_Bar_T(%"(GenericType\0A  name:\22T\22\0A  concepts:(Array<ConceptType>\0A    [0]:(ConceptType\0A      name:\22Eq\22\0A      requiredFunctions:(Array<(String, FnType)>\0A      )\0A      requiredProperties:(Array<(String, Ty, Bool)>\0A      )\0A    )\0A  )\0A).ty" %"$0") #0 {
entry:
  %Bar = alloca %Bar.ty
  %Bar.t.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 0
  store %"(GenericType\0A  name:\22T\22\0A  concepts:(Array<ConceptType>\0A    [0]:(ConceptType\0A      name:\22Eq\22\0A      requiredFunctions:(Array<(String, FnType)>\0A      )\0A      requiredProperties:(Array<(String, Ty, Bool)>\0A      )\0A    )\0A  )\0A).ty" %"$0", %"(GenericType\0A  name:\22T\22\0A  concepts:(Array<ConceptType>\0A    [0]:(ConceptType\0A      name:\22Eq\22\0A      requiredFunctions:(Array<(String, FnType)>\0A      )\0A      requiredProperties:(Array<(String, Ty, Bool)>\0A      )\0A    )\0A  )\0A).ty"* %Bar.t.ptr
  %Bar1 = load %Bar.ty* %Bar
  ret %Bar.ty %Bar1
}

attributes #0 = { alwaysinline }
