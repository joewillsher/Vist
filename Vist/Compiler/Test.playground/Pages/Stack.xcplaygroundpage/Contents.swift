//: [Previous](@previous)

extension UnsafeMutablePointer {
    mutating func advanceByAlignOf<T>(el: T.Type) { self = advancedBy(alignof(el)) }
    mutating func recedeByAlignOf<T>(el: T.Type) { self = advancedBy(-alignof(el)) }
}

enum StackError: ErrorType {
    case incorrectAccess
}

final class Stack {
    private var stackBuffer, stackPtr, basePtr: UnsafeMutablePointer<Int8>
    /// The maximum size of stack allocated
    private var capacity: Int
    
    /// The offset of the stack pointer
    private var offset: Int { return stackBuffer.distanceTo(stackPtr) }
    /// The offset of the base pointer
    private var baseOffset: Int { return stackBuffer.distanceTo(basePtr) }
    
    /// An array of appended types. In debug this allows checking the
    /// use of the stack for incorrect accesses and
    private var metatypeArray: [Any.Type], baseIndicies: [Int], debug: Bool
    
    init() {
        capacity = 100
        stackBuffer = UnsafeMutablePointer<Int8>.alloc(capacity)
        stackPtr = stackBuffer
        basePtr = stackPtr
        
        metatypeArray = []
//        #if DEBUG
        debug = true
        baseIndicies = [0]
//        #endif
    }
    
    deinit {
        stackBuffer.destroy(capacity)
    }
    
    /// Moves the stack into a new buffer twice the old size
    private func initialiseNewBuffer() {
        let oldCapacity = capacity
        capacity *= 2
        // create new buffer & copy into it
        let newBuffer = UnsafeMutablePointer<Int8>.alloc(capacity)
        newBuffer.moveInitializeFrom(stackBuffer, count: oldCapacity)
        // move sp & bp into this
        stackPtr = newBuffer.advancedBy(offset)
        basePtr = newBuffer.advancedBy(baseOffset)
        // remove refs to old stack buffer
        stackBuffer.destroy(oldCapacity)
        stackBuffer = newBuffer
    }
    
    /// Pushes an element onto the stack
    func push<T>(element: T) {
        if offset + alignof(T) > capacity { initialiseNewBuffer() }
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).initialize(element)
        stackPtr.advanceByAlignOf(T)
        metatypeArray.append(T)
    }
    /// Pops an element of type `type` and moves the stack
    /// pointer backwards
    func pop<T>(type: T.Type) throws -> T {
        let l = metatypeArray.removeLast()
        guard l == T.self || l == T.Type.self else { throw StackError.incorrectAccess }
        let val = read(T)
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).destroy()
        stackPtr.recedeByAlignOf(T)
        return val
    }
    
    /// Reads the current stack pointer as `type`
    func read<T>(type: T.Type, advance: Int = 0) -> T {
        return unsafeBitCast(stackPtr.advancedBy(advance), UnsafeMutablePointer<T>.self).predecessor().memory
    }
    
    /// Adds a new stack frame and creates a function
    func call<Ret, Params>(returns ret: Ret.Type, params: Params) {
        pushUninitialised(ret) // allocate return mem
        push(baseOffset) // push old base ptr
        baseIndicies.append(metatypeArray.endIndex)
        basePtr = stackPtr // this is the start of a new stack frame
        push(params) // push params
    }
    /// A tail call: calls a function by deleting this stack frame,
    /// adding its params, writing into the old return stack entry
    func tailCall<Params>(parms params: Params.Type) {
        s.destroyFrame()
        push(params)
    }

    
    /// Returns from the current function
    func ret<Ret>(val: Ret) throws {
        s.destroyFrame() // destroy stack frame, moves to
        basePtr = try stackBuffer.advancedBy(pop(Int)) // pop off the old base ptr
        try initialise(val) // flls the mem for the return value
    }
    
    
    
    /// Pushes uninitialised memory of type `type` onto the stack
    private func pushUninitialised<T>(type: T) {
        metatypeArray.append(T)
        if offset + alignof(T) > capacity { initialiseNewBuffer() }
        stackPtr.advanceByAlignOf(T)
    }
    /// Intiialises the current stack pointer with `val`
    private func initialise<T>(val: T) throws {
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).predecessor().initialize(val)
    }
    /// Destroys the contents of the current frame and moves
    /// the stack pointer back to the base pointer
    private func destroyFrame() {
        let s = basePtr.successor()
        s.destroy(s.distanceTo(stackPtr)) // remove all of this stack frame
        stackPtr = basePtr // move to return mem
        metatypeArray.removeRange(baseIndicies.removeLast()..<metatypeArray.endIndex)
    }
    
    
    var description: String {
        return stackBuffer.stride(to: stackPtr, by: 1)
            .map { String($0.memory) }
            .joinWithSeparator(" ")
    }
}

// tests

let s = Stack()
let count = 100


s.push(1)
s.metatypeArray
s.call(returns: Int.self, params: 12)
s.metatypeArray
s.description
try s.ret(1)
s.description

/*
s.call(returns: Int.self, params: 12)
try s.pop(Int)
s.push(1)
s.call(returns: Bool.self, params: false)
try s.pop(Bool)
s.push("high quality memes")
try s.ret(false)
s.push(2)
try s.ret(111)
try s.pop(Int)




for a in 0..<count {
    s.push(a)
    s.push(a*2)
    s.read(Int)
}


for a in 0..<count*2 {
    s.read(Int.self, advance: -a*8)
}

s.offset

for a in 0..<count*2-1 {
    let x = try s.pop(Int)
    let y = try s.pop(Int)
    s.push(x+y)
    s.read(Int)
}
*/


//: [Next](@next)
