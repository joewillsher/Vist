

let a: Int? = 1


#if swift(>=3)
    enum Error : ErrorProtocol { case rip }
#else
    enum Error : ErrorType { case rip }
#endif

func throwing() throws { throw Error.rip }

func foo(a: Int) {
    try throwing()
}




